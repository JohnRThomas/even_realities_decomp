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
		uint16_t font_index[4];                                                     \
                                                                                            \
		if ((check_null) && get_dashboard_state()->flash_read == NULL) {                      \
			break;                                                              \
		}                                                                           \
		if (get_dashboard_state()->flash_read(get_dashboard_state(), (idx_addr), &font_index[2], 4) != 0) { \
			G1_LOG_ERR("read flash fail\n\n");                                  \
			return -1;                                                          \
		}                                                                           \
		if (font_index[3] == 0xffff) {                                           \
			break;                                                              \
		}                                                                           \
		EXT_GLYPH_READ(font_index[3], glyph_base, glyph_size, width);            \
	} while (0)

#define EXT_GLYPH_LOOKUP_NEST(check_null, idx_addr, glyph_base, glyph_size, width)         \
	do {                                                                                \
		uint16_t font_index[4];                                                     \
                                                                                            \
		if ((check_null) && get_dashboard_state()->flash_read == NULL) {                      \
			break;                                                              \
		}                                                                           \
		if (get_dashboard_state()->flash_read(get_dashboard_state(), (idx_addr), &font_index[2], 4) != 0) { \
			G1_LOG_ERR("read flash fail\n\n");                                  \
			return -1;                                                          \
		}                                                                           \
		if (font_index[3] != 0xffff) {                                           \
			EXT_GLYPH_READ(font_index[3], glyph_base, glyph_size, width);    \
		}                                                                           \
	} while (0)

/* read glyph number raw (big-endian) and return it from the caller */
#define EXT_GLYPH_READ(raw, glyph_base, glyph_size, width)                                 \
	do {                                                                                \
		idx = ((raw) << 8) | ((raw) >> 8);                                          \
		memset(ext_glyph_buf, 0, sizeof(ext_glyph_buf));                            \
		ret = get_dashboard_state()->flash_read(get_dashboard_state(),                        \
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
#define EXT16NX(addr) EXT_GLYPH_LOOKUP_NEST(0, (addr), EXT_GLYPH16, 0xd0, 16)

/* flash_read tested before the index buffer's scope is entered */
#define EXT24O(addr)                                                                       \
	do {                                                                                \
		if (get_dashboard_state()->flash_read == NULL) {                                      \
			break;                                                              \
		}                                                                           \
		EXT24N(addr);                                                               \
	} while (0)
#define EXT24OX(addr)                                                                      \
	do {                                                                                \
		if (get_dashboard_state()->flash_read == NULL) {                                      \
			break;                                                              \
		}                                                                           \
		EXT24NX(addr);                                                              \
	} while (0)

/* 16 px variant of EXT24O */
#define EXT16O(addr)                                                                       \
	do {                                                                                \
		if (get_dashboard_state()->flash_read == NULL) {                                      \
			break;                                                              \
		}                                                                           \
		EXT16N(addr);                                                               \
	} while (0)

/*
 * index table entry address (kept out of the constant folder: base + index * 4).
 * The 16 px index is one contiguous table: 0x500000 (U+2010..), 0x5000bc (U+3001..),
 * 0x5004b4 (U+3231..), ...; 0x5154fc is the U+FF01.. part.
 */
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
			unsigned int code = id;
			uint16_t idx;
			int ret;
			/* entry offset in the index tables that start at U+00A4 */
			uint32_t offset = ((uint32_t)code - 0xa4) * 4;

			/* main table: 18 px glyphs */
			if (code >= 0xa4 && code <= 0xffe5) {
				uint16_t font_index[4];
				if (get_dashboard_state()->flash_read(get_dashboard_state(),
							    EXT_IDX_MAIN + offset, &font_index[2], 4) != 0) {
					G1_LOG_ERR("read flash fail\n\n");
					return -1;
				}
				idx = font_index[3];
				if (idx != 0xffff) {
					memset(ext_glyph_buf, 0, sizeof(ext_glyph_buf));
					ret = get_dashboard_state()->flash_read(get_dashboard_state(),
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
				uint16_t font_index[4] = {0};

				if (get_dashboard_state()->flash_read(get_dashboard_state(), 0xa1be90 + offset,
							    &font_index[2], 4) != 0) {
					G1_LOG_ERR("read flash fail\n\n");
					return -1;
				}
				font_index[0] = (font_index[2] << 8) | (font_index[2] >> 8);
				idx = (font_index[3] << 8) | (font_index[3] >> 8);
				font_index[1] = idx;
				if (idx != 0xffff) {
					memset(ext_glyph_buf, 0, sizeof(ext_glyph_buf));
					ret = get_dashboard_state()->flash_read(get_dashboard_state(),
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
			}
			if (code >= 0x302e && code <= 0x302f) {
				EXT24X(0xa145c0 + offset);
			}
			/* ret = -1: "not found in this table" */
			if (code >= 0x3131 && code <= 0x318e) {
				EXT24X(0xa141bc + offset);
				ret = -1;
			} else if (code >= 0x3200 && code <= 0x327f) {
				EXT24OX(0xa13ff8 + offset);
			} else {
				ret = -1;
			}
			if (code >= 0xac00 && code <= 0xd7ab) {
				EXT24X(0x9f59f8 + offset);
			} else {
				ret = -1;
			}

			/*
			 * Remaining tables.  sub is shared by the two full-width form
			 * tests (U+FF01..FF5E 24 px, U+FF01..FF9F 16 px).
			 */
			uint32_t sub = (uint32_t)id - 0xff01;

			if (sub <= 0x5d) {
				EXT24OX(ext_idx_addr(0xa20000, code - 0xff01 + 11654));
				ret = -1;
			} else if (code >= 0x2010 && code <= 0x203e) {
				EXT16X(ext_idx_addr(0x500000, code - 0x2010));
			} else {
				ret = -1;
			}
			if (code >= 0x3001 && code <= 0x30fe) {
				EXT16O(ext_idx_addr(0x500000, code - 0x3001 + 47));
			} else {
				ret = -1;
			}
			if (code >= 0x3231 && code <= 0x33cd && get_dashboard_state()->flash_read != NULL) {
				EXT16NX(ext_idx_addr(0x500000, code - 0x3231 + 301));
			} else if (code >= 0x4e00 && code <= 0x9f77 && get_dashboard_state()->flash_read != NULL) {
				EXT16N(ext_idx_addr(0x500000, code - 0x4e00 + 714));
			} else if (code >= 0xe001 && code <= 0xe0fd && get_dashboard_state()->flash_read != NULL) {
				EXT16N(ext_idx_addr(0x500000, code - 0xe001 + 21570));
			} else {
				ret = -1;
			}
			if (sub <= 0x9e) {
				EXT16X(ext_idx_addr(0x500000, code - 0xff01 + 21823));
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
			*data = icon_scrollbar_thumb;
			*w = 10;
			*h = 13;
			return 0;
		case 0x18:
			*data = icon_teleprompter;
			*w = 20;
			*h = 20;
			return 0;
		case 0x19:
			*data = icon_teleprompter_auto;
			*w = 20;
			*h = 20;
			return 0;
		case 0x1a:
			*data = icon_teleprompter_manual;
			*w = 20;
			*h = 20;
			return 0;
		case 0x1b:
			*data = icon_pause;
			*w = 20;
			*h = 26;
			return 0;
		case 0x3c:
			*data = icon_notification_bell;
			*w = 20;
			*h = 26;
			return 0;
		case 0x38:
			*data = icon_message;
			*w = 20;
			*h = 20;
			return 0;
		case 0x37:
			*data = icon_call_missed;
			*w = 20;
			*h = 20;
			return 0;
		case 0x36:
			*data = icon_call_incoming;
			*w = 20;
			*h = 20;
			return 0;
		case 0x3a:
			*data = icon_mail;
			*w = 20;
			*h = 20;
			return 0;
		case 0x39:
			*data = icon_calendar;
			*w = 20;
			*h = 20;
			return 0;
		case 0x3b:
			*data = icon_quicknote;
			*w = 20;
			*h = 26;
			return 0;
		case 0x1c:
			*data = icon_list_bullet;
			*w = 18;
			*h = 26;
			return 0;
		case 0x1d:
			*data = icon_list_unchecked;
			*w = 18;
			*h = 26;
			return 0;
		case 0x1e:
			*data = icon_list_checked;
			*w = 18;
			*h = 26;
			return 0;
		case 0x1f:
			*data = icon_list_number_1;
			*w = 18;
			*h = 26;
			return 0;
		case 0x20:
			*data = icon_list_number_2;
			*w = 18;
			*h = 26;
			return 0;
		case 0x21:
			*data = icon_list_number_3;
			*w = 18;
			*h = 26;
			return 0;
		case 0x22:
			*data = icon_list_number_4;
			*w = 18;
			*h = 26;
			return 0;
		case 0x23:
			*data = icon_weather_sunny;
			*w = 20;
			*h = 26;
			return 0;
		case 0x24:
			*data = icon_weather_night;
			*w = 20;
			*h = 26;
			return 0;
		case 0x25:
			*data = icon_weather_clouds;
			*w = 20;
			*h = 26;
			return 0;
		case 0x26:
			*data = icon_weather_drizzle;
			*w = 20;
			*h = 26;
			return 0;
		case 0x27:
			*data = icon_weather_heavy_drizzle;
			*w = 20;
			*h = 26;
			return 0;
		case 0x28:
			*data = icon_weather_rain;
			*w = 20;
			*h = 26;
			return 0;
		case 0x29:
			*data = icon_weather_heavy_rain;
			*w = 20;
			*h = 26;
			return 0;
		case 0x2a:
			*data = icon_weather_thunder;
			*w = 20;
			*h = 26;
			return 0;
		case 0x2b:
			*data = icon_weather_thunderstorm;
			*w = 20;
			*h = 26;
			return 0;
		case 0x2c:
			*data = icon_weather_snow;
			*w = 20;
			*h = 26;
			return 0;
		case 0x2d:
			*data = icon_weather_mist;
			*w = 20;
			*h = 26;
			return 0;
		case 0x2e:
			*data = icon_weather_fog;
			*w = 20;
			*h = 26;
			return 0;
		case 0x2f:
			*data = icon_weather_sand;
			*w = 20;
			*h = 26;
			return 0;
		case 0x30:
			*data = icon_weather_squalls;
			*w = 20;
			*h = 26;
			return 0;
		case 0x31:
			*data = icon_weather_tornado;
			*w = 20;
			*h = 26;
			return 0;
		case 0x32:
			*data = icon_weather_freezing;
			*w = 20;
			*h = 26;
			return 0;
		case 0x33:
			*data = icon_translate;
			*w = 20;
			*h = 26;
			return 0;
		case 0x3e:
			*data = icon_bluetooth_disconnected;
			*w = 20;
			*h = 26;
			return 0;
		case 0x3f:
			*data = icon_phone_disconnected;
			*w = 20;
			*h = 20;
			return 0;
		case 0x16:
			*data = icon_even_logo;
			*w = 24;
			*h = 26;
			return 0;
		case 0x41:
			*data = icon_g1_logo;
			*w = 48;
			*h = 26;
			return 0;
		case 0x55:
			*data = icon_frame_top_wide;
			*w = 402;
			*h = 2;
			return 0;
		case 0x56:
			*data = icon_frame_top_narrow;
			*w = 314;
			*h = 2;
			return 0;
		case 0x57:
			*data = icon_frame_bottom_wide;
			*w = 402;
			*h = 2;
			return 0;
		case 0x58:
			*data = icon_frame_bottom_narrow;
			*w = 314;
			*h = 2;
			return 0;
		case 0x59:
			*data = icon_pane_divider_left;
			*w = 2;
			*h = 128;
			return 0;
		case 0x5a:
			*data = icon_pane_divider_right;
			*w = 2;
			*h = 128;
			return 0;
		case 0x49:
			*data = icon_silent_mode;
			*w = 20;
			*h = 20;
			return 0;
		case 0x4a:
			*data = icon_error;
			*w = 20;
			*h = 20;
			return 0;
		case 0x4b:
			*data = icon_ai_cmd_auto_brightness;
			*w = 20;
			*h = 20;
			return 0;
		case 0x4c:
			*data = icon_ai_cmd_brightness;
			*w = 20;
			*h = 20;
			return 0;
		case 0x4d:
			*data = icon_ai_cmd_dashboard;
			*w = 20;
			*h = 20;
			return 0;
		case 0x4e:
			*data = icon_ai_cmd_head_up;
			*w = 20;
			*h = 20;
			return 0;
		case 0x4f:
			*data = icon_ai_cmd_display_distance;
			*w = 20;
			*h = 20;
			return 0;
		case 0x50:
			*data = icon_ai_cmd_display_height;
			*w = 20;
			*h = 20;
			return 0;
		case 0x51:
			*data = icon_ai_cmd_navigate;
			*w = 20;
			*h = 20;
			return 0;
		case 0x52:
			*data = icon_ai_cmd_teleprompt;
			*w = 20;
			*h = 20;
			return 0;
		case 0x53:
			*data = icon_ai_cmd_transcribe;
			*w = 20;
			*h = 20;
			return 0;
		case 0x54:
			*data = icon_ai_cmd_translate;
			*w = 20;
			*h = 20;
			return 0;
		case 0x42:
			*data = icon_low_power;
			*w = 20;
			*h = 26;
			return 0;
		case 0x43:
			*data = icon_stocks;
			*w = 20;
			*h = 20;
			return 0;
		case 0x44:
			*data = icon_stock_up;
			*w = 20;
			*h = 20;
			return 0;
		case 0x45:
			*data = icon_stock_down;
			*w = 20;
			*h = 20;
			return 0;
		case 0x46:
			*data = icon_stock_flat;
			*w = 20;
			*h = 20;
			return 0;
		case 0x47:
			*data = icon_news;
			*w = 20;
			*h = 20;
			return 0;
		case 0x48:
			*data = icon_map_pin;
			*w = 20;
			*h = 20;
			return 0;
		case 0x5f:
			*data = icon_nav_position_marker;
			*w = 14;
			*h = 13;
			return 0;
		case 0x5b:
			*data = icon_frame_corner_top_left;
			*w = 10;
			*h = 10;
			return 0;
		case 0x5c:
			*data = icon_frame_corner_bottom_left;
			*w = 10;
			*h = 10;
			return 0;
		case 0x5d:
			*data = icon_frame_corner_top_right;
			*w = 10;
			*h = 10;
			return 0;
		case 0x5e:
			*data = icon_frame_corner_bottom_right;
			*w = 10;
			*h = 10;
			return 0;
		case 0x61:
			*data = icon_nav_straight_dashed;
			*w = 50;
			*h = 50;
			return 0;
		case 0x62:
			*data = icon_nav_straight;
			*w = 50;
			*h = 50;
			return 0;
		case 0x63:
			*data = icon_nav_turn_right;
			*w = 50;
			*h = 50;
			return 0;
		case 0x64:
			*data = icon_nav_turn_left;
			*w = 50;
			*h = 50;
			return 0;
		case 0x65:
			*data = icon_nav_slight_right;
			*w = 50;
			*h = 50;
			return 0;
		case 0x66:
			*data = icon_nav_slight_left;
			*w = 50;
			*h = 50;
			return 0;
		case 0x67:
			*data = icon_nav_sharp_right;
			*w = 50;
			*h = 50;
			return 0;
		case 0x68:
			*data = icon_nav_sharp_left;
			*w = 50;
			*h = 50;
			return 0;
		case 0x69:
			*data = icon_nav_uturn_left;
			*w = 50;
			*h = 50;
			return 0;
		case 0x6a:
			*data = icon_nav_uturn_right;
			*w = 50;
			*h = 50;
			return 0;
		case 0x6b:
			*data = icon_nav_merge;
			*w = 50;
			*h = 50;
			return 0;
		case 0x6c:
			*data = icon_nav_roundabout_sharp_right_ccw;
			*w = 50;
			*h = 50;
			return 0;
		case 0x6d:
			*data = icon_nav_roundabout_sharp_right_cw;
			*w = 50;
			*h = 50;
			return 0;
		case 0x6e:
			*data = icon_nav_roundabout_right_ccw;
			*w = 50;
			*h = 50;
			return 0;
		case 0x6f:
			*data = icon_nav_roundabout_right_cw;
			*w = 50;
			*h = 50;
			return 0;
		case 0x70:
			*data = icon_nav_roundabout_slight_right_ccw;
			*w = 50;
			*h = 50;
			return 0;
		case 0x71:
			*data = icon_nav_roundabout_slight_right_cw;
			*w = 50;
			*h = 50;
			return 0;
		case 0x72:
			*data = icon_nav_roundabout_straight_ccw;
			*w = 50;
			*h = 50;
			return 0;
		case 0x73:
			*data = icon_nav_roundabout_straight_cw;
			*w = 50;
			*h = 50;
			return 0;
		case 0x74:
			*data = icon_nav_roundabout_slight_left_ccw;
			*w = 50;
			*h = 50;
			return 0;
		case 0x75:
			*data = icon_nav_roundabout_slight_left_cw;
			*w = 50;
			*h = 50;
			return 0;
		case 0x76:
			*data = icon_nav_roundabout_left_ccw;
			*w = 50;
			*h = 50;
			return 0;
		case 0x77:
			*data = icon_nav_roundabout_left_cw;
			*w = 50;
			*h = 50;
			return 0;
		case 0x78:
			*data = icon_nav_roundabout_sharp_left_ccw;
			*w = 50;
			*h = 50;
			return 0;
		case 0x79:
			*data = icon_nav_roundabout_sharp_left_cw;
			*w = 50;
			*h = 50;
			return 0;
		case 0x7a:
			*data = icon_nav_roundabout_uturn_ccw;
			*w = 50;
			*h = 50;
			return 0;
		case 0x7b:
			*data = icon_nav_roundabout_uturn_cw;
			*w = 50;
			*h = 50;
			return 0;
		case 0x7c:
			*data = icon_nav_roundabout_enter_ccw;
			*w = 50;
			*h = 50;
			return 0;
		case 0x7d:
			*data = icon_nav_roundabout_enter_cw;
			*w = 50;
			*h = 50;
			return 0;
		case 0x7e:
			*data = icon_nav_merge_left;
			*w = 50;
			*h = 50;
			return 0;
		case 0x7f:
			*data = icon_nav_merge_right;
			*w = 50;
			*h = 50;
			return 0;
		case 0x80:
			*data = icon_nav_ramp_right;
			*w = 50;
			*h = 50;
			return 0;
		case 0x81:
			*data = icon_nav_ramp_left;
			*w = 50;
			*h = 50;
			return 0;
		case 0x82:
			*data = icon_nav_fork_right;
			*w = 50;
			*h = 50;
			return 0;
		case 0x83:
			*data = icon_nav_fork_left;
			*w = 50;
			*h = 50;
			return 0;
		case 0x85:
			*data = icon_underline_left;
			*w = 34;
			*h = 1;
			return 0;
		case 0x86:
			*data = icon_underline_right;
			*w = 44;
			*h = 1;
			return 0;
		case 0x87:
			*data = icon_horizon_line;
			*w = 410;
			*h = 1;
			return 0;
		case 0x40:
			*data = icon_warning;
			*w = 20;
			*h = 20;
			return 0;
		default:
			return -1;
		}
	case 5:
		switch (id) {
		case 1:
			*data = anim_listening;
			*w = 20;
			*h = 26;
			if (frames != NULL) {
				*frames = 45;
			}
			return 0;
		case 2:
			*data = anim_head_up_hint;
			*w = 20;
			*h = 20;
			if (frames != NULL) {
				*frames = 22;
			}
			return 0;
		case 3:
			*data = anim_head_down_hint;
			*w = 20;
			*h = 20;
			if (frames != NULL) {
				*frames = 22;
			}
			return 0;
		case 4:
			*data = anim_ai_answer;
			*w = 20;
			*h = 20;
			if (frames != NULL) {
				*frames = 15;
			}
			return 0;
		case 5:
			*data = anim_message_popup;
			*w = 20;
			*h = 20;
			if (frames != NULL) {
				*frames = 9;
			}
			return 0;
		case 6:
			*data = anim_silent_mode_on;
			*w = 20;
			*h = 20;
			if (frames != NULL) {
				*frames = 10;
			}
			return 0;
		case 7:
			*data = anim_silent_mode_off;
			*w = 22;
			*h = 20;
			if (frames != NULL) {
				*frames = 9;
			}
			return 0;
		case 8:
			*data = anim_nav_route_generating;
			*w = 20;
			*h = 20;
			if (frames != NULL) {
				*frames = 34;
			}
			return 0;
		case 9:
			*data = anim_processing;
			*w = 20;
			*h = 20;
			if (frames != NULL) {
				*frames = 19;
			}
			return 0;
		case 10:
			*data = anim_teleprompter;
			*w = 20;
			*h = 20;
			if (frames != NULL) {
				*frames = 17;
			}
			return 0;
		case 11:
			*data = anim_single_tap_hint;
			*w = 20;
			*h = 20;
			if (frames != NULL) {
				*frames = 21;
			}
			return 0;
		case 12:
			*data = anim_double_tap_hint;
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
