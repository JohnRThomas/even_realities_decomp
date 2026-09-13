/*
 * Even AI screen task (voice assistant: listening / answer text pages)
 * and its status icon helper.
 */
#define GUI_C_INTERNAL /* gui_screen_x_offset() returns int here */
#include "ui_a.h"

#define EVEN_AI_TEXT_MAX 0x1e0

struct even_ai_prv_data {
	uint8_t state;            /* 0 init, 1 running */
	uint8_t entered;
};

struct even_ai_prv_data even_ai_prv;
char even_ai_text[EVEN_AI_TEXT_MAX];
uint8_t DAT_2001c4e8;                        /* text animation running (touch_key_thread) */
int even_ai_answer_shown;                            /* page needs a clear */
int even_ai_text_drawn;                            /* text page drawn once */

/* localized messages (initialized RAM, reverse definition order) */
static char even_ai_listening_en[] = "Even AI listening...\r\rRelease to Finish Recording";
static char even_ai_offline_en[] = "Even AI is unable to connect to the network";
static char even_ai_listening_fr[] =
	"Even IA \xc3\xa9" "coute...\r\rRel\xc3\xa2" "chez pour terminer l'enregistrement";
static char even_ai_offline_fr[] =
	"Even IA ne parvient pas \xc3\xa0 se connecter au r\xc3\xa9seau.";
static char even_ai_listening_de[] = "Even KI-Abh\xc3\xb6ren...\r\rLoslassen zum Abschluss";
static char even_ai_offline_de[] = "Even KI kann keine Verbindung\rzum Netzwerk herstellen.";
static char even_ai_listening_es[] =
	"IA Even est\xc3\xa1 escuchando...\r\rSuelte para completar la grabaci\xc3\xb3n";
static char even_ai_offline_es[] =
	"No se puede conectar a la red.\rLa funci\xc3\xb3n Even AI est\xc3\xa1 fuera de l\xc3\xadnea.";
static char even_ai_listening_it[] =
	"Even IA sta ascoltando...\r\rRilascia per terminare la registrazione";
static char even_ai_offline_it[] = "Impossibile connettersi alla rete.\rFunzione Even IA offline.";
static char even_ai_offline_ko[] =
	"\xeb\x84\xa4\xed\x8a\xb8\xec\x9b\x8c\xed\x81\xac\xec\x97\x90 \xec\x97\xb0\xea\xb2\xb0\xed\x95\xa0 "
	"\xec\x88\x98 \xec\x97\x86\xec\x8a\xb5\xeb\x8b\x88\xeb\x8b\xa4.\rEven AI "
	"\xea\xb8\xb0\xeb\x8a\xa5\xec\x9d\xb4 \xec\x98\xa4\xed\x94\x84\xeb\x9d\xbc\xec\x9d\xb8 "
	"\xec\x83\x81\xed\x83\x9c\xec\x9e\x85\xeb\x8b\x88\xeb\x8b\xa4.";

static int even_ai_icon = 0xff;              /* 0x200024f4 */
static int even_ai_page = -1;                /* 0x200024f0 */

#define EVEN_AI_ICON_SWITCH(id)                                                          \
	do {                                                                             \
		if (even_ai_icon != (id)) {                                              \
			gui_dynamic_bitmap_reset();                                                  \
			even_ai_icon = (id);                                             \
			gui_icon_area_clear(gui_screen_x_offset(), gui_screen_y_offset() + 0x36);             \
			_reflash_fb_data_to_lcd(UI_GS()->panel.current_row,              \
						UI_GS()->panel.current_column, 0, 0,     \
						GUI_SCREEN_WIDTH, 199);                  \
		}                                                                        \
	} while (0)

int even_ai_draw_status_icon(const uint8_t *status)
{
	uint8_t s = *status;

	if (s <= 5) {
		EVEN_AI_ICON_SWITCH(1);
		gui_bmp_dynamic_bitmap_draw(1, gui_screen_x_offset(), gui_screen_y_offset() + 0x36, 0, 0, 0, 0);
	} else if (s == 6) {
		EVEN_AI_ICON_SWITCH(9);
		gui_bmp_dynamic_bitmap_draw(9, gui_screen_x_offset(), gui_screen_y_offset() + 0x36, 0, 0, 0, 0);
	} else if (s == 7) {
		EVEN_AI_ICON_SWITCH(4);
		gui_bmp_dynamic_bitmap_draw(4, gui_screen_x_offset(), gui_screen_y_offset() + 0x36, 0, 0, 0, 0);
	} else if (s <= 11) {
		EVEN_AI_ICON_SWITCH(0xff);
	} else if (s == 12 || s == 13) {
		/* nothing */
	} else if (s == 15) {
		/* nothing */
	} else if (s == 14 || s == 16) {
		if (even_ai_icon != 0xff) {
			gui_dynamic_bitmap_reset();
			even_ai_icon = 0xff;
		}
	}
	return 0;
}

int ui_even_ai_task(struct jbd_panel_context *panel, void *arg, int event)
{
	struct ui_gs *gs = UI_GS();
	uint8_t lang = get_current_language();
	uint8_t **fb = panel->panel_buffer;
	const char *listening_str;
	const char *offline_str;

	if (gs->ui.ai.status != 7) {
		even_ai_page = -1;
	}
	switch (lang) {
	case 4:
		listening_str = even_ai_listening_en;
		offline_str = even_ai_offline_ko;
		break;
	case LANGUAGE_FRENCH:
		listening_str = even_ai_listening_fr;
		offline_str = even_ai_offline_fr;
		break;
	case LANGUAGE_GERMAN:
		listening_str = even_ai_listening_de;
		offline_str = even_ai_offline_de;
		break;
	case LANGUAGE_SPANISH:
		listening_str = even_ai_listening_es;
		offline_str = even_ai_offline_es;
		break;
	case LANGUAGE_ITALIAN:
		listening_str = even_ai_listening_it;
		offline_str = even_ai_offline_it;
		break;
	default:
		listening_str = even_ai_listening_en;
		offline_str = even_ai_offline_en;
		break;
	}
	set_frame_buffer(fb);
	set_showing_notification_on_gui();

	switch (even_ai_prv.state) {
	case 0:
		if (event == UI_EVT_ENTER) {
			memset(even_ai_text, 0, sizeof(even_ai_text));
			G1_LOG_ERR("ENTER evenai INIT process...\n");
			if (even_ai_prv.entered) {
				return 0;
			}
			G1_LOG_ERR("SYNC_AREA_REFALSH Upgrade ....\n");
			gui_utf_adv_draw_reset();
			if (gs->ui.ai.status < 12) {
				gui_screen_clear();
			}
			even_ai_answer_shown = 0;
			gui_text_state_reset();
			text_anim.f_1c = 0x80;
			text_anim.f_08 = 0;
			text_anim.f_0c = 0;
			text_anim.text = text_anim_buf;
			text_anim.f_14 = 0;
			text_anim.f_18 = 0;
			text_anim.f_04 = 0;
			text_anim.f_10 = 0;
			even_ai_prv.entered = 1;
			even_ai_prv.state = 1;
			gui_dynamic_bitmap_reset();
			clear_showing_notification_on_gui();
			for (int i = 0; i < 8; i++) {
				uint8_t status = gs->ui.ai.status;

				if (status == 11) {
					gui_bmp_bitmap_draw(0x4a, gui_screen_x_offset(), gui_screen_y_offset() + 0x36, 0,
							    0, 0);
					gui_utf_draw_middle(0, offline_str, 0, gui_screen_x_offset() + 0x58,
							    gui_screen_y_offset() + 0x36, gui_screen_x_offset() + 0x230,
							    gui_screen_y_offset() + 0x87, 3, 0, 0, NULL, 0);
				} else if (status >= 12 && status <= 14) {
					if (status != 14) {
						goto noret;
					}
					_reflash_fb_data_to_lcd(UI_GS()->panel.current_row,
								UI_GS()->panel.current_column, 0, 0,
								GUI_SCREEN_WIDTH - 1, 199);
					break;
				} else if (status == 15 || status == 16) {
					if (status != 16) {
						goto noret;
					}
					memcpy(even_ai_text, gs->ui.ai.text, gs->ui.ai.text_len);
					gui_utf_draw(0, even_ai_text, 0, gui_screen_x_offset(), gui_screen_y_offset(),
						     gui_screen_x_offset() + 0x240, gui_screen_y_offset() + 0x88, 5, 0, 0,
						     NULL, 0);
				} else {
					gui_utf_draw_middle(0, listening_str, 0, gui_screen_x_offset(),
							    gui_screen_y_offset() + 0x36, gui_screen_x_offset() + 0x236,
							    gui_screen_y_offset() + 0x87, 3, 0, 0, NULL, 0);
				}
				for (int row = 0; row < 199; row++) {
					for (int col = 0; col < GUI_FB_ROW_BYTES; col++) {
						const uint8_t steps[8] = {1, 2, 3, 4, 5, 6, 7, 7};
						uint8_t pix = fb[row][col];

						if (pix != 0) {
							fb[row][col] =
								pix & gui_fade_mask[row % 26][steps[i]]
										   [col];
						}
					}
				}
				_reflash_fb_data_to_lcd(UI_GS()->panel.current_row,
							UI_GS()->panel.current_column, 0, 0,
							GUI_SCREEN_WIDTH, 199);
			}
			set_showing_notification_on_gui();
		} else if (event == UI_EVT_EXIT) {
			G1_LOG_INF("evenai process received exit packet ...\n");
			gui_screen_clear();
			goto reset;
		}
		break;

	case 1: {
		const uint8_t *ai = &gs->ui.ai.status;
		uint8_t sub;
		uint8_t status;

		if (event == UI_EVT_ENTER) {
			memset(even_ai_text, 0, sizeof(even_ai_text));
			k_mutex_lock(&k_mutex_2000851c, K_FOREVER);
			sub = gs->ui.ai.sub_status;
			k_mutex_unlock(&k_mutex_2000851c);
			status = gs->ui.ai.status;
			if (status == 7 && even_ai_page == -1 && sub == 3) {
				even_ai_page = gs->ui.ai.page;
				clear_showing_notification_on_gui();
				for (int i = 0; i < 8; i++) {
					memcpy(even_ai_text, gs->ui.ai.text, gs->ui.ai.text_len);
					gui_utf_draw(0, even_ai_text, 0, gui_screen_x_offset() + 0x58, gui_screen_y_offset(),
						     gui_screen_x_offset() + 0x230, gui_screen_y_offset() + 0x88, 5, 0, 0, NULL,
						     0);
					if (gs->ui.ai.hide_bar != 1) {
						gui_verticalLine_process_bar(gui_screen_x_offset() + 0x23c, gui_screen_y_offset(),
									     gui_screen_x_offset() + 0x23c,
									     gui_screen_y_offset() + 0x88, 1,
									     gs->ui.ai.percent, 0);
					}
					for (int row = 0; row < 199; row++) {
						for (int col = 0; col < GUI_FB_ROW_BYTES; col++) {
							const uint8_t steps[8] = {1, 2, 3, 4, 5, 6, 7, 7};
							uint8_t pix = fb[row][col];

							if (pix != 0) {
								fb[row][col] =
									pix & gui_fade_mask[row % 26][steps[i]]
											   [col];
							}
						}
					}
					_reflash_fb_data_to_lcd(UI_GS()->panel.current_row,
								UI_GS()->panel.current_column, 0, 0,
								GUI_SCREEN_WIDTH, 199);
				}
				set_showing_notification_on_gui();
				break;
			}
			if (sub == 4) {
				struct ui_gs *g;
				uint8_t **gfb;

				even_ai_page = gs->ui.ai.page;
				g = UI_GS();
				gfb = g->panel.panel_buffer;
				/* fade the old answer out */
				for (int k = 5; k > 3; k--) {
					for (int row = gui_screen_y_offset(); row <= gui_screen_y_offset() + 0x87; row++) {
						for (int col = gui_screen_x_offset() + 0x58;
						     col < (gui_screen_x_offset() + 0x230) / 2; col++) {
							uint8_t pix = gfb[row][col];

							if (pix != 0) {
								gfb[row][col] =
									pix & gui_fade_mask[row % 26][k][col];
							}
						}
					}
					_reflash_fb_data_to_lcd(UI_GS()->panel.current_row,
								UI_GS()->panel.current_column,
								gui_screen_x_offset() + 0x58, gui_screen_y_offset(),
								gui_screen_x_offset() + 0x230, gui_screen_y_offset() + 0x88);
				}
				_clean_fb_data(gfb, 0, 0, 0x10, GUI_SCREEN_WIDTH, 0xb8);
				even_ai_draw_status_icon(ai);
				clear_showing_notification_on_gui();
				status = gs->ui.ai.status;
				if (status <= 5) {
					gui_utf_draw_middle(0, listening_str, 0, gui_screen_x_offset(),
							    gui_screen_y_offset() + 0x36, gui_screen_x_offset() + 0x236,
							    gui_screen_y_offset() + 0x87, 3, 0, 0, NULL, 0);
				} else if (status == 11) {
					gui_bmp_bitmap_draw(0x4a, gui_screen_x_offset(), gui_screen_y_offset() + 0x36, 0, 0, 0);
					gui_utf_draw_middle(0, offline_str, 0, gui_screen_x_offset() + 0x58,
							    gui_screen_y_offset() + 0x36, gui_screen_x_offset() + 0x230,
							    gui_screen_y_offset() + 0x87, 3, 0, 0, NULL, 0);
				} else if (status >= 12 && status <= 14) {
					if (status != 14) {
						goto noret;
					}
					_reflash_fb_data_to_lcd(UI_GS()->panel.current_row,
								UI_GS()->panel.current_column, 0, 0,
								GUI_SCREEN_WIDTH - 1, 199);
				} else if (status == 15 || status == 16) {
					if (status != 16) {
						goto noret;
					}
					memcpy(even_ai_text, gs->ui.ai.text, gs->ui.ai.text_len);
					gui_utf_draw(0, even_ai_text, 0, gui_screen_x_offset(), gui_screen_y_offset(),
						     gui_screen_x_offset() + 0x240, gui_screen_y_offset() + 0x88, 5, 0, 0, NULL,
						     0);
				} else {
					memcpy(even_ai_text, gs->ui.ai.text, gs->ui.ai.text_len);
					gui_utf_draw(0, even_ai_text, 0, gui_screen_x_offset() + 0x58, gui_screen_y_offset(),
						     gui_screen_x_offset() + 0x230, gui_screen_y_offset() + 0x88, 5, 0, 0, NULL,
						     0);
					if (gs->ui.ai.hide_bar != 1) {
						gui_verticalLine_process_bar(gui_screen_x_offset() + 0x23c, gui_screen_y_offset(),
									     gui_screen_x_offset() + 0x23c,
									     gui_screen_y_offset() + 0x88, 1,
									     gs->ui.ai.percent, 0);
					}
				}
				/* fade the new page in */
				for (int i = 0; i < 8; i++) {
					int x0 = gui_screen_x_offset() + 0x58;
					int x1 = gui_screen_x_offset() + 0x230;
					int y0 = gui_screen_y_offset();
					int y1 = gui_screen_y_offset() + 0x88;
					int xh = x0 / 2;
					uint8_t **fbl = g->panel.panel_buffer + y0;

					for (int row = 0; row < y1 - y0; row++) {
						for (int col = 0; col < (x1 - x0) / 2; col++) {
							const uint8_t steps[8] = {1, 2, 3, 4, 5, 6, 7, 7};
							uint8_t *line = fbl[row];
							uint8_t pix = line[xh + col];

							if (pix != 0) {
								line[xh + col] =
									pix & gui_fade_mask[row % 26][steps[i]]
											   [col];
							}
						}
					}
					_reflash_fb_data_to_lcd(UI_GS()->panel.current_row,
								UI_GS()->panel.current_column, x0, y0, x1, y1);
				}
				set_showing_notification_on_gui();
				even_ai_draw_status_icon(ai);
				even_ai_answer_shown = 1;
				break;
			}
			if (status <= 4) {
				if (even_ai_answer_shown) {
					even_ai_answer_shown = 0;
					gui_screen_clear();
				}
				gui_utf_draw_middle(0, listening_str, 0, gui_screen_x_offset(),
						    gui_screen_y_offset() + 0x36, gui_screen_x_offset() + 0x236,
						    gui_screen_y_offset() + 0x87, 3, 0, 0, NULL, 0);
				break;
			}
			if (status == 11) {
				if (even_ai_answer_shown) {
					even_ai_answer_shown = 0;
					gui_screen_clear();
				}
				gui_bmp_bitmap_draw(0x4a, gui_screen_x_offset(), gui_screen_y_offset() + 0x36, 0, 0, 0);
				gui_utf_draw_middle(0, offline_str, 0, gui_screen_x_offset() + 0x58,
						    gui_screen_y_offset() + 0x36, gui_screen_x_offset() + 0x230,
						    gui_screen_y_offset() + 0x87, 3, 0, 0, NULL, 0);
				break;
			}
			if (status >= 12 && status <= 14) {
				if (status != 14) {
					goto noret;
				}
				_reflash_fb_data_to_lcd(UI_GS()->panel.current_row,
							UI_GS()->panel.current_column, 0, 0,
							GUI_SCREEN_WIDTH - 1, 199);
				break;
			}
			if (status == 15 || status == 16) {
				if (status != 16) {
					goto noret;
				}
				memcpy(even_ai_text, gs->ui.ai.text, gs->ui.ai.text_len);
				gui_utf_draw(0, even_ai_text, 0, gui_screen_x_offset(), gui_screen_y_offset(),
					     gui_screen_x_offset() + 0x240, gui_screen_y_offset() + 0x88, 5, 0,
					     0, NULL, 0);
				break;
			}
			if (status <= 6) {
				gui_utf_draw(0, " ", 0, gui_screen_x_offset() + 0x58, gui_screen_y_offset() + 0x36,
					     gui_screen_x_offset() + 0x230, gui_screen_y_offset() + 0x87, 5, 0, 0, NULL,
					     0);
				even_ai_answer_shown = 1;
				even_ai_text_drawn = 0;
				break;
			}
			memset(even_ai_text, 0, sizeof(even_ai_text));
			memcpy(even_ai_text, gs->ui.ai.text, gs->ui.ai.text_len);
			if (gs->ui.ai.status == 8 || gs->ui.ai.status == 9 || even_ai_text_drawn == 0) {
				if (gui_screen_y_offset() <= 32) {
					_clean_fb_data(fb, 0, gui_screen_x_offset() + 0x58,
						       gui_screen_y_offset() + 0x88, gui_screen_x_offset() + 0x230,
						       gui_screen_y_offset() + 0xa3);
				} else if (gui_screen_y_offset() > 32) {
					_clean_fb_data(fb, 0, gui_screen_x_offset() + 0x58,
						       gui_screen_y_offset() - 0x1a, gui_screen_x_offset() + 0x230,
						       gui_screen_y_offset() + 1);
				}
				gui_utf_draw(0, even_ai_text, 0, gui_screen_x_offset() + 0x58, gui_screen_y_offset(),
					     gui_screen_x_offset() + 0x230, gui_screen_y_offset() + 0x88, 5, 0, 0, NULL, 0);
				if (even_ai_text_drawn == 0) {
					even_ai_text_drawn = 1;
				}
			} else {
				DAT_2001c4e8 = 1;
				gui_utf_draw_scroll_line(0, even_ai_text, 0, gui_screen_x_offset() + 0x58, gui_screen_y_offset() + 1,
					     gui_screen_x_offset() + 0x230, gui_screen_y_offset() + 0x88, 5, 0);
				DAT_2001c4e8 = 0;
			}
			if (gs->ui.ai.hide_bar != 1) {
				gui_verticalLine_process_bar(gui_screen_x_offset() + 0x23c, gui_screen_y_offset(),
							     gui_screen_x_offset() + 0x23c, gui_screen_y_offset() + 0x88, 1,
							     gs->ui.ai.percent, 0);
			}
			even_ai_answer_shown = 1;
		} else if (event == UI_EVT_REFRESH) {
			even_ai_draw_status_icon(ai);
		} else if (event == UI_EVT_EXIT) {
			G1_LOG_INF("evenai process received exit packet ...\n");
			gui_screen_fade_out();
			goto reset;
		}
		break;
	}

	default:
		break;
	}
	return 0;

reset:
	gui_utf_adv_draw_reset();
	text_anim.f_08 = 0;
	text_anim.f_0c = 0;
	text_anim.f_14 = 0;
	text_anim.f_18 = 0;
	text_anim.f_04 = 0;
	text_anim.f_10 = 0;
	memset(&even_ai_prv, 0, sizeof(even_ai_prv));
	return 0;
noret:	/* vendor: these exits fall off the end without setting r0 */
	;
}
