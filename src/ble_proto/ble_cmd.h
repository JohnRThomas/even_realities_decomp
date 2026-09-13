/*
 * BLE application protocol command ids (byte 0 of every phone <-> glasses packet).
 *
 * Names: the firmware's own log names (BLE_REQ_PUT_* / BLE_REQ_GET_* / BLE_REQ_POST_*) where they
 * exist, otherwise the user's protocol notes (reference_material/Even Realities G1 Notes and RE.md);
 * behaviour.  ble_process_req_dispatch routes by
 * range: 0x01..0x27 PUT, 0x29..0x45 GET, 0x47..0x56 POST, 0xF1..0xF6 report.
 * 0x23 is never a command: it is ASCII '#', the prefix of the debug strings handled by
 * spec_ble_command_hook (the notes' "System Control 0x23 xx").
 */
#ifndef BLE_CMD_H_
#define BLE_CMD_H_

enum ble_cmd {
	/* PUT (ble_process_put_req, local part in master_process_put_req) */
	BLE_CMD_BRIGHTNESS_SET = 0x01,
	BLE_CMD_ANTI_SHAKE_SET = 0x02,          /* not in the notes; GET 0x2A reads it back */
	BLE_CMD_SILENT_MODE_SET = 0x03,         /* fw GET log: "DISPLAY_MODE" */
	BLE_CMD_NOTIFI_WHITELIST_SET = 0x04,    /* fw "BLE_REQ_PUT_NOTIFI_WHIHTLIST_APP"; notes: Notification App List Set */
	BLE_CMD_DEBUG_CONTROL = 0x05,           /* not in the notes: head up/down simulation, LOG_LEVEL, dashboard mode */
	BLE_CMD_DASHBOARD_SET = 0x06,
	BLE_CMD_COUNTDOWN_TIMER = 0x07,         /* fw "BLE_REQ_PUT_COUNTDOWN_TIMER"; notes: Timer Control */
	BLE_CMD_HEAD_UP_ACTION_SET = 0x08,
	BLE_CMD_TELEPROMPTER_INFO = 0x09,       /* fw "BLE_REQ_PUT_TELEPROMPTER_INFO"; notes: Teleprompter Control */
	BLE_CMD_NAVIGATION_INFO = 0x0a,         /* fw "BLE_REQ_PUT_NAVIGATION_INFO"; notes: Navigation Control */
	BLE_CMD_HEAD_UP_ANGLE_SET = 0x0b,
	BLE_CMD_TRANSLATE_SRC_TEXT = 0x0d,      /* translate, original text; notes: "Transcribe Control" */
	BLE_CMD_MICROPHONE_SET = 0x0e,
	BLE_CMD_TRANSLATE_DST_TEXT = 0x0f,      /* translate, translated text; notes: "Translate Control" */
	BLE_CMD_HEAD_UP_CALIBRATION = 0x10,
	BLE_CMD_NOTIFY_EN = 0x14,               /* fw "BLE_REQ_PUT_NOTIFY_EN": ANCS on/off; GET 0x38 reads it back */
	BLE_CMD_FILE_UPLOAD = 0x15,
	BLE_CMD_BITMAP_SHOW = 0x16,             /* CRC check of the uploaded file */
	BLE_CMD_UPGRADE_CONTROL = 0x17,         /* erase DFU */
	BLE_CMD_BITMAP_HIDE = 0x18,
	BLE_CMD_TRANSLATE_CONTROL = 0x1c,       /* not in the notes: languages, start/pause */
	BLE_CMD_QUICK_NOTE_CONTROL = 0x1e,
	BLE_CMD_TUTORIAL_CONTROL = 0x1f,        /* onboarding */
	BLE_CMD_FILE_UPLOAD_COMPLETE = 0x20,
	BLE_CMD_STATUS = 0x22,
	BLE_CMD_TELEPROMPTER_SUSPEND = 0x24,
	BLE_CMD_TELEPROMPTER_POSITION_SET = 0x25,
	BLE_CMD_HARDWARE_SET = 0x26,            /* sub-commands: enum ble_hw_sub */
	BLE_CMD_WEAR_DETECTION_SET = 0x27,

	/* GET (ble_process_get_req) */
	BLE_CMD_BRIGHTNESS_GET = 0x29,          /* fw "BLE_REQ_GET_BRIGHTNESS" */
	BLE_CMD_ANTI_SHAKE_GET = 0x2a,          /* fw "BLE_REQ_GET_ANTI_SHAKE_ENABLE" */
	BLE_CMD_SILENT_MODE_GET = 0x2b,         /* fw "BLE_REQ_GET_DISPLAY_MODE" */
	BLE_CMD_DEVICE_INFO_GET = 0x2c,         /* fw "BLE_REQ_GET_DEVICE_INFO"; notes: Info Battery and Firmware Get */
	BLE_CMD_MAC_GET = 0x2d,                 /* fw "BLE_REQ_GET_M_N_S_MAC" */
	BLE_CMD_NOTIFI_WHITELIST_GET = 0x2e,    /* notes: Notification App List Get */
	BLE_CMD_HEAD_UP_ANGLE_GET = 0x32,       /* fw "BLE_REQ_GET_WAKEUP_ANGLE" */
	BLE_CMD_GLASSES_SN_GET = 0x33,          /* fw "BLE_REQ_GET_GLASSES_SN"; notes: Info Serial Number Lens Get */
	BLE_CMD_DEVICE_SN_GET = 0x34,           /* fw "BLE_REQ_GET_DEVICE_SN"; notes: Info Serial Number Glasses Get */
	BLE_CMD_ESB_CHANNEL_GET = 0x35,         /* fw "BLE_REQ_GET_ESB_CHANNEL" */
	BLE_CMD_NOTIF_COUNT_GET = 0x36,         /* notes: Info ESB Channel Notification Count Get */
	BLE_CMD_TIME_SINCE_BOOT_GET = 0x37,
	BLE_CMD_ANCS_ENABLE_GET = 0x38,         /* fw "globle->enable_ancs"; notes: Notification Apple Specific Get */
	BLE_CMD_RUNNING_APP_GET = 0x39,         /* notes: Status Running App Get */
	BLE_CMD_WEAR_DETECTION_GET = 0x3a,      /* fw "globle->check_mode" */
	BLE_CMD_RASTER_CONFIG_GET = 0x3b,       /* fw "BLE_GET_RASTER_CONFIG"; notes: Hardware Display Get */
	BLE_CMD_NOTIF_AUTO_DISPLAY_GET = 0x3c,
	BLE_CMD_LANGUAGE_SET = 0x3d,            /* handled in the GET range */
	BLE_CMD_BURIAL_POINT_GET = 0x3e,        /* fw "BLE_GET_BURIAL_POINT_DATA"; notes: Info Buried Point Get */
	BLE_CMD_HARDWARE_GET = 0x3f,            /* sub-commands 5..8 of enum ble_hw_sub */

	/* POST (ble_process_post_req) */
	BLE_CMD_BT_UNPAIR = 0x47,               /* fw "BLE_REQ_POST_BT_UNPAIR" */
	BLE_CMD_POST_49 = 0x49,                 /* not in the notes: header to master only, no-op */
	BLE_CMD_SYNC_DISPLAY = 0x4a,            /* not in the notes: flags 2 = ESB sync packet to the slave, 1 = display refresh */
	BLE_CMD_NOTIFICATION_SEND = 0x4b,
	BLE_CMD_NOTIFICATION_CLEAR = 0x4c,      /* fw "BLE_REQ_POST_DELETE_NOTIFICATION_MSG" */
	BLE_CMD_MTU_SET = 0x4d,                 /* notes name; marks the app session as established */
	BLE_CMD_TEXT_SET = 0x4e,
	BLE_CMD_NOTIF_AUTO_DISPLAY_SET = 0x4f,
	BLE_CMD_DASHBOARD_LOCK_SET = 0x50,
	BLE_CMD_QUICK_NOTE_UPDATE_TASK = 0x51,
	BLE_CMD_TRANSCRIBE_CONTROL = 0x52,
	BLE_CMD_TRANSCRIBE_STATUS = 0x53,       /* notes: "evenai_v2 ??" */
	BLE_CMD_EVENAI = 0x54,                  /* notes: "evenai_v2 ??" */
	BLE_CMD_EVENAI_STATUS = 0x55,           /* notes: "evenai_v2 ??" */
	BLE_CMD_EVENAI_EXIT = 0x56,             /* notes: "evenai_v2 ??" */

	/* report (ble_process_report_response), glasses -> phone */
	BLE_CMD_AUDIO = 0xf1,
	BLE_CMD_DEBUG = 0xf4,
	BLE_CMD_EVENT = 0xf5,
};

/* Dashboard Set (0x06) sub-commands, data[4] */
enum ble_dashboard_sub {
	DASHBOARD_SUB_TIME_WEATHER = 1,
	DASHBOARD_SUB_WEATHER = 2,
	DASHBOARD_SUB_PANE_CALENDAR = 3,
	DASHBOARD_SUB_PANE_STOCK = 4,
	DASHBOARD_SUB_PANE_NEWS = 5,
	DASHBOARD_SUB_PANE_MODE = 6,
	DASHBOARD_SUB_PANE_CANVAS = 7, /* citywalk / map */
};

/* Hardware Set (0x26) sub-commands, data[4]; Hardware Get (0x3F) reads 5..8 back */
enum ble_hw_sub {
	HW_SUB_USER_DATA_RESET = 1,      /* notes: "Set something to 1" (f_10d5) */
	HW_SUB_HEIGHT_DEPTH = 2,
	HW_SUB_GIVE_MIC_TRANSM_SEM = 3,  /* fw "give mic_transm_sem" */
	HW_SUB_LUM_GEAR = 4,             /* fw "ble set lum gear" */
	HW_SUB_DOUBLE_TAP_ACTION = 5,
	HW_SUB_LUM_COEFFICIENT = 6,      /* fw "ble set lum coefficent" (calibration mode) */
	HW_SUB_LONG_PRESS_ENABLE = 7,
	HW_SUB_MIC_ON_HEAD_UP = 8,
};

#endif /* BLE_CMD_H_ */
