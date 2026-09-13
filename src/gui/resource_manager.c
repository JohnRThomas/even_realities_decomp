/*
 * Resource manager: glyph / bitmap lookup for the GUI.
 *
 *   type 0: 26 px text font (built-in subset, rest from external flash)
 *   type 1: 32 px clock digits, type 2: 39 px clock digits, type 3: 26 px ASCII
 *   type 4: icons (id 0x16..0x87), type 5: animations (id 1..12, with frame count)
 */
#include <string.h>
#include <zephyr/kernel.h>

#include "gui.h"
#include "resource_bitmaps.h"

/* glyph buffer for glyphs read from the external flash */
static uint8_t ext_glyph_buf[0x138];

/* External flash font layout (addresses in the resource partition). */
#define EXT_IDX_MAIN      0x140000  /* 4-byte entries for U+00A4.., hi16 = 18 px glyph index */
#define EXT_GLYPH18       0x200000  /* 18 x 26 glyphs, 0xea bytes */
#define EXT_GLYPH24       0xa40000  /* 24 x 26 glyphs, 0x138 bytes */
#define EXT_GLYPH16       0x520000  /* 16 x 26 glyphs, 0xd0 bytes */

const uint8_t *font39_lookup(uint16_t code, int *w, int *h)
{
	uint16_t off = 0;
	int n = font39_glyph_count;

	for (int i = 0; i < n; i++) {
		if (font39_index[i].code == code) {
			*w = font39_index[i].width << 1;
			*h = 39;
			return font39_bitmap + off;
		}
		off += font39_index[i].width * 39;
	}
	return NULL;
}

const uint8_t *font_c_lookup(uint16_t code, int *w, int *h)
{
	uint16_t off = 0;
	int n = font_c_glyph_count;

	for (int i = 0; i < n; i++) {
		if (font_c_index[i].code == code) {
			*w = font_c_index[i].width << 1;
			*h = 32;
			return font_c_bitmap + off;
		}
		off += font_c_index[i].width * 32;
	}
	return NULL;
}

const uint8_t *font_b_lookup(uint16_t code, int *w, int *h)
{
	int off = 0;
	int n = font_b_glyph_count;

	for (int i = 0; i < n; i++) {
		if (font_b_index[i].code == code) {
			*w = font_b_index[i].width << 1;
			*h = 26;
			return font_b_bitmap + off;
		}
		off += 26 * font_b_index[i].width;
	}
	return NULL;
}

const uint8_t *font26_lookup(uint16_t code, int *w, int *h)
{
	uint16_t off = 0;
	int n = font26_glyph_count;

	for (int i = 0; i < n; i++) {
		if (font26_index[i].code == code) {
			*w = font26_index[i].width * 2;
			*h = 26;
			return font26_bitmap + off;
		}
		off += font26_index[i].width * 26;
	}
	return NULL;
}

/*
 * Look a code point up in one external-flash index table (entries are two
 * big-endian halfwords, the second one is the glyph number) and read the glyph.
 * Uses the caller's idx / ret variables; returns from the caller when found or
 * on a flash error, falls through when the table has no glyph.  check_null = 0
 * for call sites that already test flash_read in their own condition.
 * EXT_GLYPH_LOOKUP leaves on an empty entry with break, EXT_GLYPH_LOOKUP_NEST
 * nests the glyph read instead (same behaviour).
 */
#define EXT_GLYPH_LOOKUP(check_null, idx_addr, glyph_base, glyph_size, width)              \
	do {                                                                                \
		uint32_t res[2];                                                            \
		uint16_t *entry = (uint16_t *)&res[1];                                      \
                                                                                            \
		if ((check_null) && GUI_STATE()->flash_read == NULL) {                      \
			break;                                                              \
		}                                                                           \
		if (GUI_STATE()->flash_read(get_dashboard_state(), (idx_addr), entry, 4) != 0) { \
			G1_LOG_ERR("read flash fail\n\n");                                  \
			return -1;                                                          \
		}                                                                           \
		if (entry[1] == 0xffff) {                                                   \
			break;                                                              \
		}                                                                           \
		EXT_GLYPH_READ(entry[1], glyph_base, glyph_size, width);                    \
	} while (0)

#define EXT_GLYPH_LOOKUP_NEST(check_null, idx_addr, glyph_base, glyph_size, width)         \
	do {                                                                                \
		uint32_t res[2];                                                            \
		uint16_t *entry = (uint16_t *)&res[1];                                      \
                                                                                            \
		if ((check_null) && GUI_STATE()->flash_read == NULL) {                      \
			break;                                                              \
		}                                                                           \
		if (GUI_STATE()->flash_read(get_dashboard_state(), (idx_addr), entry, 4) != 0) { \
			G1_LOG_ERR("read flash fail\n\n");                                  \
			return -1;                                                          \
		}                                                                           \
		if (entry[1] != 0xffff) {                                                   \
			EXT_GLYPH_READ(entry[1], glyph_base, glyph_size, width);            \
		}                                                                           \
	} while (0)

/*
 * 4-byte index entry read at idx_addr + code * 4 for the tables after the U+00A4..FFE5 block.
 * The call is written in two arms that differ only in how the address is spelled; the
 * arms compile to identical code and are merged again after register allocation.  This
 * gives code * 4 its own register (shipped code: lsl.w ip, r7, #2; add r1, ip) instead of
 * a folded add-with-shift.  Behaviour does not depend on the (code & 1) test.
 */
#define EXT_IDX_READ_SPLIT(r, idx_addr, buf)                                                \
	do {                                                                                \
		int (*rd_)(void *gs, uint32_t addr, void *buf, uint32_t len);               \
		void *gs_;                                                                  \
		uint32_t t_;                                                                \
                                                                                            \
		rd_ = GUI_STATE()->flash_read;                                              \
		gs_ = get_dashboard_state();                                                \
		t_ = code * 4;                                                              \
		if (code & 1) {                                                             \
			(r) = rd_(gs_, (idx_addr) + t_, (buf), 4);                          \
		} else {                                                                    \
			(r) = rd_(gs_, (idx_addr) + ((uint32_t)code << 2), (buf), 4);       \
		}                                                                           \
	} while (0)

#define EXT_GLYPH_LOOKUP_T(check_null, idx_addr, glyph_base, glyph_size, width)             \
	do {                                                                                \
		uint32_t res[2];                                                            \
		uint16_t *entry = (uint16_t *)&res[1];                                      \
		int r_;                                                                     \
                                                                                            \
		if ((check_null) && GUI_STATE()->flash_read == NULL) {                      \
			break;                                                              \
		}                                                                           \
		EXT_IDX_READ_SPLIT(r_, (idx_addr), entry);                                  \
		if (r_ != 0) {                                                              \
			G1_LOG_ERR("read flash fail\n\n");                                  \
			return -1;                                                          \
		}                                                                           \
		if (entry[1] == 0xffff) {                                                   \
			break;                                                              \
		}                                                                           \
		EXT_GLYPH_READ(entry[1], glyph_base, glyph_size, width);                    \
	} while (0)

#define EXT_GLYPH_LOOKUP_NEST_T(check_null, idx_addr, glyph_base, glyph_size, width)        \
	do {                                                                                \
		uint32_t res[2];                                                            \
		uint16_t *entry = (uint16_t *)&res[1];                                      \
		int r_;                                                                     \
                                                                                            \
		if ((check_null) && GUI_STATE()->flash_read == NULL) {                      \
			break;                                                              \
		}                                                                           \
		EXT_IDX_READ_SPLIT(r_, (idx_addr), entry);                                  \
		if (r_ != 0) {                                                              \
			G1_LOG_ERR("read flash fail\n\n");                                  \
			return -1;                                                          \
		}                                                                           \
		if (entry[1] != 0xffff) {                                                   \
			EXT_GLYPH_READ(entry[1], glyph_base, glyph_size, width);            \
		}                                                                           \
	} while (0)

/* read glyph number raw (big-endian) and return it from the caller */
#define EXT_GLYPH_READ(raw, glyph_base, glyph_size, width)                                 \
	do {                                                                                \
		idx = ((raw) << 8) | ((raw) >> 8);                                          \
		memset(ext_glyph_buf, 0, sizeof(ext_glyph_buf));                            \
		ret = GUI_STATE()->flash_read(get_dashboard_state(),                        \
					      (glyph_base) + idx * (glyph_size), ext_glyph_buf, \
					      (glyph_size));                                \
		if (ret != 0) {                                                             \
			G1_LOG_ERR("read flash fail: %d\n\n", ret);                         \
			return -1;                                                          \
		}                                                                           \
		*w = (width);                                                               \
		*h = 26;                                                                    \
		*data = ext_glyph_buf;                                                      \
		return ret;                                                                 \
	} while (0)

#define EXT24(addr)   EXT_GLYPH_LOOKUP(1, (addr), EXT_GLYPH24, 0x138, 24)
#define EXT16(addr)   EXT_GLYPH_LOOKUP(1, (addr), EXT_GLYPH16, 0xd0, 16)
#define EXT24N(addr)  EXT_GLYPH_LOOKUP(0, (addr), EXT_GLYPH24, 0x138, 24)
#define EXT16N(addr)  EXT_GLYPH_LOOKUP(0, (addr), EXT_GLYPH16, 0xd0, 16)
#define EXT24X(addr)  EXT_GLYPH_LOOKUP_NEST(1, (addr), EXT_GLYPH24, 0x138, 24)
#define EXT16X(addr)  EXT_GLYPH_LOOKUP_NEST(1, (addr), EXT_GLYPH16, 0xd0, 16)
#define EXT24NX(addr) EXT_GLYPH_LOOKUP_NEST(0, (addr), EXT_GLYPH24, 0x138, 24)

/* index table entry address (kept out of the constant folder: base + index * 4) */
static inline uint32_t ext_idx_addr(uint32_t base, int index)
{
	return base + index * 4;
}

int resource_manger_get(int type, int id, int *w, int *h, const uint8_t **data, uint8_t *frames)
{
	switch (type) {
	case 0:
		if (id < 0x2714) {
			uint32_t res[2];
			*data = font26_lookup(id, (int *)&res[0], (int *)&res[1]);
			if (*data != NULL) {
				*w = res[0];
				*h = res[1];
				return 0;
			}
		}
		/* code points that are not in the built-in subset: external flash */
		{
			int code = id;
			uint16_t idx;
			int ret;

			if (code >= 0xa4 && code <= 0xffe5) {
				uint32_t offset = ((uint32_t)code - 0xa4) * 4;

				/* main table: 18 px glyphs */
				{
					uint32_t res[2];
					if (GUI_STATE()->flash_read(get_dashboard_state(),
								    EXT_IDX_MAIN + offset, &res[1], 4) != 0) {
						G1_LOG_ERR("read flash fail\n\n");
						return -1;
					}
					idx = res[1] >> 16;
					if (idx != 0xffff) {
						memset(ext_glyph_buf, 0, sizeof(ext_glyph_buf));
						ret = GUI_STATE()->flash_read(get_dashboard_state(),
									      EXT_GLYPH18 + idx * 0xea, ext_glyph_buf,
									      0xea);
						if (ret != 0) {
							G1_LOG_ERR("read flash fail: %d\n\n", ret);
							return -1;
						}
						*w = 18;
						*h = 26;
						*data = ext_glyph_buf;
						return ret;
					}
				}

				/* 24 px tables (Hangul Jamo, CJK punctuation, Hangul compatibility, ...) */
				if (code >= 0x1100 && code <= 0x11f9) {
					uint32_t res[2];
					uint16_t *font_index = (uint16_t *)res;

					res[0] = 0;
					res[1] = 0;
					if (GUI_STATE()->flash_read(get_dashboard_state(), 0xa1be90 + offset,
								    &font_index[2], 4) != 0) {
						G1_LOG_ERR("read flash fail\n\n");
						return -1;
					}
					font_index[0] = (font_index[2] << 8) | (font_index[2] >> 8);
					idx = (font_index[3] << 8) | (font_index[3] >> 8);
					font_index[1] = idx;
					if (idx != 0xffff) {
						memset(ext_glyph_buf, 0, sizeof(ext_glyph_buf));
						ret = GUI_STATE()->flash_read(get_dashboard_state(),
									      EXT_GLYPH24 + idx * 0x138,
									      ext_glyph_buf, 0x138);
						if (ret != 0) {
							G1_LOG_ERR("read flash fail: %d\n\n", ret);
							return -1;
						}
						*w = 24;
						*h = 26;
						*data = ext_glyph_buf;
						return ret;
					}
				} else if (code >= 0x302e && code <= 0x302f && GUI_STATE()->flash_read != NULL) {
					EXT24NX(0xa145c0 + offset);
				}
				if (code >= 0x3131 && code <= 0x318e && GUI_STATE()->flash_read != NULL) {
					EXT24N(0xa141bc + offset);
				}
				if (code >= 0x3200 && code <= 0x327f) {
					EXT24(0xa13ff8 + offset);
				}
				if (code >= 0xac00 && code <= 0xd7ab && GUI_STATE()->flash_read != NULL) {
					EXT24NX(0x9f59f8 + offset);
				}
			}
			/*
			 * Remaining tables.  sub is shared by the two full-width form
			 * tests (U+FF01..FF5E 24 px, U+FF01..FF9F 16 px).
			 */
			uint32_t sub = code - 0xff01;

			if (sub <= 0x5d) {
				EXT_GLYPH_LOOKUP_NEST_T(1, 0x9eba14, EXT_GLYPH24, 0x138, 24);
			} else if (code >= 0x2010 && code <= 0x203e) {
				EXT16X(ext_idx_addr(0x500000, code - 0x2010));
			}
			if (code >= 0x3001 && code <= 0x30fe) {
				EXT16X(ext_idx_addr(0x4f40b8, code));
			}
			if (code >= 0x3231 && code <= 0x33cd && GUI_STATE()->flash_read != NULL) {
				EXT16N(ext_idx_addr(0x4f3bf0, code));
			} else if (code >= 0x4e00 && code <= 0x9f77) {
				EXT16X(ext_idx_addr(0x4ed328, code));
			}
			if (code >= 0xe001 && code <= 0xe0fd) {
				EXT_GLYPH_LOOKUP_T(1, 0x4dd104, EXT_GLYPH16, 0xd0, 16);
			}
			if (sub <= 0x9e) {
				EXT_GLYPH_LOOKUP_NEST_T(1, 0x4d58f8, EXT_GLYPH16, 0xd0, 16);
			}

			G1_LOG_INF("*************** can't find resEncode = 0x%02x*****************\n", code);
			return -1;
		}
	case 1: {
		uint32_t res[2];
		*data = font_c_lookup(id, (int *)&res[0], (int *)&res[1]);
		if (*data != NULL) {
			*w = res[0];
			*h = res[1];
			return 0;
		}
		break;
	}
	case 2: {
		uint32_t res[2];
		*data = font39_lookup(id, (int *)&res[0], (int *)&res[1]);
		if (*data != NULL) {
			*w = res[0];
			*h = res[1];
			return 0;
		}
		break;
	}
	case 3: {
		uint32_t res[2];
		*data = font_b_lookup(id, (int *)&res[0], (int *)&res[1]);
		*w = res[0];
		*h = res[1];
		return 0;
	}
	case 4:
		if ((uint32_t)(id - 0x16) > 0x71) {
			G1_LOG_WRN("can't find resource ,exit .....\n");
			break;
		}
		switch (id) {
		case 0x17:
			*data = bmp_17;
			*w = 10;
			*h = 13;
			return 0;
		case 0x18:
			*data = bmp_18;
			*w = 20;
			*h = 20;
			return 0;
		case 0x19:
			*data = bmp_19;
			*w = 20;
			*h = 20;
			return 0;
		case 0x1a:
			*data = bmp_1a;
			*w = 20;
			*h = 20;
			return 0;
		case 0x1b:
			*data = bmp_1b;
			*w = 20;
			*h = 26;
			return 0;
		case 0x3c:
			*data = bmp_3c;
			*w = 20;
			*h = 26;
			return 0;
		case 0x38:
			*data = bmp_38;
			*w = 20;
			*h = 20;
			return 0;
		case 0x37:
			*data = bmp_37;
			*w = 20;
			*h = 20;
			return 0;
		case 0x36:
			*data = bmp_36;
			*w = 20;
			*h = 20;
			return 0;
		case 0x3a:
			*data = bmp_3a;
			*w = 20;
			*h = 20;
			return 0;
		case 0x39:
			*data = bmp_39;
			*w = 20;
			*h = 20;
			return 0;
		case 0x3b:
			*data = bmp_3b;
			*w = 20;
			*h = 26;
			return 0;
		case 0x1c:
			*data = bmp_1c;
			*w = 18;
			*h = 26;
			return 0;
		case 0x1d:
			*data = bmp_1d;
			*w = 18;
			*h = 26;
			return 0;
		case 0x1e:
			*data = bmp_1e;
			*w = 18;
			*h = 26;
			return 0;
		case 0x1f:
			*data = bmp_1f;
			*w = 18;
			*h = 26;
			return 0;
		case 0x20:
			*data = bmp_20;
			*w = 18;
			*h = 26;
			return 0;
		case 0x21:
			*data = bmp_21;
			*w = 18;
			*h = 26;
			return 0;
		case 0x22:
			*data = bmp_22;
			*w = 18;
			*h = 26;
			return 0;
		case 0x23:
			*data = bmp_23;
			*w = 20;
			*h = 26;
			return 0;
		case 0x24:
			*data = bmp_24;
			*w = 20;
			*h = 26;
			return 0;
		case 0x25:
			*data = bmp_25;
			*w = 20;
			*h = 26;
			return 0;
		case 0x26:
			*data = bmp_26;
			*w = 20;
			*h = 26;
			return 0;
		case 0x27:
			*data = bmp_27;
			*w = 20;
			*h = 26;
			return 0;
		case 0x28:
			*data = bmp_28;
			*w = 20;
			*h = 26;
			return 0;
		case 0x29:
			*data = bmp_29;
			*w = 20;
			*h = 26;
			return 0;
		case 0x2a:
			*data = bmp_2a;
			*w = 20;
			*h = 26;
			return 0;
		case 0x2b:
			*data = bmp_2b;
			*w = 20;
			*h = 26;
			return 0;
		case 0x2c:
			*data = bmp_2c;
			*w = 20;
			*h = 26;
			return 0;
		case 0x2d:
			*data = bmp_2d;
			*w = 20;
			*h = 26;
			return 0;
		case 0x2e:
			*data = bmp_2e;
			*w = 20;
			*h = 26;
			return 0;
		case 0x2f:
			*data = bmp_2f;
			*w = 20;
			*h = 26;
			return 0;
		case 0x30:
			*data = bmp_30;
			*w = 20;
			*h = 26;
			return 0;
		case 0x31:
			*data = bmp_31;
			*w = 20;
			*h = 26;
			return 0;
		case 0x32:
			*data = bmp_32;
			*w = 20;
			*h = 26;
			return 0;
		case 0x33:
			*data = bmp_33;
			*w = 20;
			*h = 26;
			return 0;
		case 0x3e:
			*data = bmp_3e;
			*w = 20;
			*h = 26;
			return 0;
		case 0x3f:
			*data = bmp_3f;
			*w = 20;
			*h = 20;
			return 0;
		case 0x16:
			*data = bmp_16;
			*w = 24;
			*h = 26;
			return 0;
		case 0x41:
			*data = bmp_41;
			*w = 48;
			*h = 26;
			return 0;
		case 0x55:
			*data = bmp_55;
			*w = 402;
			*h = 2;
			return 0;
		case 0x56:
			*data = bmp_56;
			*w = 314;
			*h = 2;
			return 0;
		case 0x57:
			*data = bmp_57;
			*w = 402;
			*h = 2;
			return 0;
		case 0x58:
			*data = bmp_58;
			*w = 314;
			*h = 2;
			return 0;
		case 0x59:
			*data = bmp_59;
			*w = 2;
			*h = 128;
			return 0;
		case 0x5a:
			*data = bmp_5a;
			*w = 2;
			*h = 128;
			return 0;
		case 0x49:
			*data = bmp_49;
			*w = 20;
			*h = 20;
			return 0;
		case 0x4a:
			*data = bmp_4a;
			*w = 20;
			*h = 20;
			return 0;
		case 0x4b:
			*data = bmp_4b;
			*w = 20;
			*h = 20;
			return 0;
		case 0x4c:
			*data = bmp_4c;
			*w = 20;
			*h = 20;
			return 0;
		case 0x4d:
			*data = bmp_4d;
			*w = 20;
			*h = 20;
			return 0;
		case 0x4e:
			*data = bmp_4e;
			*w = 20;
			*h = 20;
			return 0;
		case 0x4f:
			*data = bmp_4f;
			*w = 20;
			*h = 20;
			return 0;
		case 0x50:
			*data = bmp_50;
			*w = 20;
			*h = 20;
			return 0;
		case 0x51:
			*data = bmp_51;
			*w = 20;
			*h = 20;
			return 0;
		case 0x52:
			*data = bmp_52;
			*w = 20;
			*h = 20;
			return 0;
		case 0x53:
			*data = bmp_53;
			*w = 20;
			*h = 20;
			return 0;
		case 0x54:
			*data = bmp_54;
			*w = 20;
			*h = 20;
			return 0;
		case 0x42:
			*data = bmp_42;
			*w = 20;
			*h = 26;
			return 0;
		case 0x43:
			*data = bmp_43;
			*w = 20;
			*h = 20;
			return 0;
		case 0x44:
			*data = bmp_44;
			*w = 20;
			*h = 20;
			return 0;
		case 0x45:
			*data = bmp_45;
			*w = 20;
			*h = 20;
			return 0;
		case 0x46:
			*data = bmp_46;
			*w = 20;
			*h = 20;
			return 0;
		case 0x47:
			*data = bmp_47;
			*w = 20;
			*h = 20;
			return 0;
		case 0x48:
			*data = bmp_48;
			*w = 20;
			*h = 20;
			return 0;
		case 0x5f:
			*data = bmp_5f;
			*w = 14;
			*h = 13;
			return 0;
		case 0x5b:
			*data = bmp_5b;
			*w = 10;
			*h = 10;
			return 0;
		case 0x5c:
			*data = bmp_5c;
			*w = 10;
			*h = 10;
			return 0;
		case 0x5d:
			*data = bmp_5d;
			*w = 10;
			*h = 10;
			return 0;
		case 0x5e:
			*data = bmp_5e;
			*w = 10;
			*h = 10;
			return 0;
		case 0x61:
			*data = bmp_61;
			*w = 50;
			*h = 50;
			return 0;
		case 0x62:
			*data = bmp_62;
			*w = 50;
			*h = 50;
			return 0;
		case 0x63:
			*data = bmp_63;
			*w = 50;
			*h = 50;
			return 0;
		case 0x64:
			*data = bmp_64;
			*w = 50;
			*h = 50;
			return 0;
		case 0x65:
			*data = bmp_65;
			*w = 50;
			*h = 50;
			return 0;
		case 0x66:
			*data = bmp_66;
			*w = 50;
			*h = 50;
			return 0;
		case 0x67:
			*data = bmp_67;
			*w = 50;
			*h = 50;
			return 0;
		case 0x68:
			*data = bmp_68;
			*w = 50;
			*h = 50;
			return 0;
		case 0x69:
			*data = bmp_69;
			*w = 50;
			*h = 50;
			return 0;
		case 0x6a:
			*data = bmp_6a;
			*w = 50;
			*h = 50;
			return 0;
		case 0x6b:
			*data = bmp_6b;
			*w = 50;
			*h = 50;
			return 0;
		case 0x6c:
			*data = bmp_6c;
			*w = 50;
			*h = 50;
			return 0;
		case 0x6d:
			*data = bmp_6d;
			*w = 50;
			*h = 50;
			return 0;
		case 0x6e:
			*data = bmp_6e;
			*w = 50;
			*h = 50;
			return 0;
		case 0x6f:
			*data = bmp_6f;
			*w = 50;
			*h = 50;
			return 0;
		case 0x70:
			*data = bmp_70;
			*w = 50;
			*h = 50;
			return 0;
		case 0x71:
			*data = bmp_71;
			*w = 50;
			*h = 50;
			return 0;
		case 0x72:
			*data = bmp_72;
			*w = 50;
			*h = 50;
			return 0;
		case 0x73:
			*data = bmp_73;
			*w = 50;
			*h = 50;
			return 0;
		case 0x74:
			*data = bmp_74;
			*w = 50;
			*h = 50;
			return 0;
		case 0x75:
			*data = bmp_75;
			*w = 50;
			*h = 50;
			return 0;
		case 0x76:
			*data = bmp_76;
			*w = 50;
			*h = 50;
			return 0;
		case 0x77:
			*data = bmp_77;
			*w = 50;
			*h = 50;
			return 0;
		case 0x78:
			*data = bmp_78;
			*w = 50;
			*h = 50;
			return 0;
		case 0x79:
			*data = bmp_79;
			*w = 50;
			*h = 50;
			return 0;
		case 0x7a:
			*data = bmp_7a;
			*w = 50;
			*h = 50;
			return 0;
		case 0x7b:
			*data = bmp_7b;
			*w = 50;
			*h = 50;
			return 0;
		case 0x7c:
			*data = bmp_7c;
			*w = 50;
			*h = 50;
			return 0;
		case 0x7d:
			*data = bmp_7d;
			*w = 50;
			*h = 50;
			return 0;
		case 0x7e:
			*data = bmp_7e;
			*w = 50;
			*h = 50;
			return 0;
		case 0x7f:
			*data = bmp_7f;
			*w = 50;
			*h = 50;
			return 0;
		case 0x80:
			*data = bmp_80;
			*w = 50;
			*h = 50;
			return 0;
		case 0x81:
			*data = bmp_81;
			*w = 50;
			*h = 50;
			return 0;
		case 0x82:
			*data = bmp_82;
			*w = 50;
			*h = 50;
			return 0;
		case 0x83:
			*data = bmp_83;
			*w = 50;
			*h = 50;
			return 0;
		case 0x85:
			*data = bmp_85;
			*w = 34;
			*h = 1;
			return 0;
		case 0x86:
			*data = bmp_86;
			*w = 44;
			*h = 1;
			return 0;
		case 0x87:
			*data = bmp_87;
			*w = 410;
			*h = 1;
			return 0;
		case 0x40:
			*data = bmp_40;
			*w = 20;
			*h = 20;
			return 0;
		default:
			return -1;
		}
	case 5:
		switch (id) {
		case 1:
			*data = anim_01;
			*w = 20;
			*h = 26;
			if (frames != NULL) {
				*frames = 45;
			}
			return 0;
		case 2:
			*data = anim_02;
			*w = 20;
			*h = 20;
			if (frames != NULL) {
				*frames = 22;
			}
			return 0;
		case 3:
			*data = anim_03;
			*w = 20;
			*h = 20;
			if (frames != NULL) {
				*frames = 22;
			}
			return 0;
		case 4:
			*data = anim_04;
			*w = 20;
			*h = 20;
			if (frames != NULL) {
				*frames = 15;
			}
			return 0;
		case 5:
			*data = anim_05;
			*w = 20;
			*h = 20;
			if (frames != NULL) {
				*frames = 9;
			}
			return 0;
		case 6:
			*data = anim_06;
			*w = 20;
			*h = 20;
			if (frames != NULL) {
				*frames = 10;
			}
			return 0;
		case 7:
			*data = anim_07;
			*w = 22;
			*h = 20;
			if (frames != NULL) {
				*frames = 9;
			}
			return 0;
		case 8:
			*data = anim_08;
			*w = 20;
			*h = 20;
			if (frames != NULL) {
				*frames = 34;
			}
			return 0;
		case 9:
			*data = anim_09;
			*w = 20;
			*h = 20;
			if (frames != NULL) {
				*frames = 19;
			}
			return 0;
		case 10:
			*data = anim_10;
			*w = 20;
			*h = 20;
			if (frames != NULL) {
				*frames = 17;
			}
			return 0;
		case 11:
			*data = anim_11;
			*w = 20;
			*h = 20;
			if (frames != NULL) {
				*frames = 21;
			}
			return 0;
		case 12:
			*data = anim_12;
			*w = 20;
			*h = 20;
			if (frames != NULL) {
				*frames = 29;
			}
			return 0;
		default:
			break;
		}
		break;
	default:
		break;
	}
	return -1;
}

/* weather id (1..16) -> icon resource id */
int weather_icon_to_bitmap(int weather)
{
	switch (weather) {
	case 1:
		return 36;
	case 2:
		return 37;
	case 3:
		return 38;
	case 4:
		return 39;
	case 5:
		return 40;
	case 6:
		return 41;
	case 7:
		return 42;
	case 8:
		return 43;
	case 9:
		return 44;
	case 10:
		return 45;
	case 11:
		return 46;
	case 12:
		return 47;
	case 13:
		return 48;
	case 14:
		return 49;
	case 15:
		return 50;
	case 16:
		return 35;
	default:
		return -1;
	}
}
