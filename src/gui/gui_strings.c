/*
 * GUI language strings: per-language string tables and the lookup by string id.
 */
#include <stdint.h>
#include <zephyr/kernel.h>

#include "gui.h"
#include "../storage/storage.h"
#include "gui_strings.h"

const char *get_string_in_language(int language, uint32_t string_id)
{
	if (string_id > GUI_STRING_COUNT - 1) {
		return "ERR_STRING";
	}

	switch (language) {
	case 1:
		return strings_chinese[string_id];
	case 6:
		return strings_german[string_id];
	case 7:
		return strings_spanish[string_id];
	case 5:
		return strings_french[string_id];
	case 14:
		return strings_italian[string_id];
	case 3:
		return strings_japanese[string_id];
	case 4:
		return strings_korean[string_id];
	default:
		return strings_english[string_id];
	}
}


const char *get_string(uint8_t string_id)
{
	uint8_t language = get_current_language();

	switch (language) {
	case 2:
	case 5:
	case 6:
	case 7:
	case 14:
		break;
	default:
		language = 2;
		break;
	}
	return get_string_in_language(language, string_id);
}
