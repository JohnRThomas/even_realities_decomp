/*
 * NCS (Android) notification JSON parser, called by
 * post_notification_cmd_process() (notification.c).
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <zephyr/kernel.h>
#include <zephyr/sys/printk.h>

#include "g1_log.h"
#include "notify.h"
#include "../utils/burial_point.h"

void parse_ncs_notification(char *json, struct notif_msg *msg)
{
	cJSON *root;
	cJSON *ncs;
	cJSON *app_identifier;
	cJSON *title;
	cJSON *subtitle;
	cJSON *message;
	cJSON *date;
	cJSON *display_name;
	cJSON *msg_id;
	cJSON *action;

	root = cJSON_Parse(json);
	if (root == NULL) {
		G1_LOG_ERR("error root JSON NODE!\n");
		return;
	}
	ncs = cJSON_GetObjectItem(root, "ncs_notification");
	if (ncs == NULL) {
		G1_LOG_ERR("NOT FOUND NCS JSON NODE!\n");
		cJSON_Delete(root);
		return;
	}
	app_identifier = cJSON_GetObjectItem(ncs, "app_identifier");
	title = cJSON_GetObjectItem(ncs, "title");
	subtitle = cJSON_GetObjectItem(ncs, "subtitle");
	message = cJSON_GetObjectItem(ncs, "message");
	date = cJSON_GetObjectItem(ncs, "date");
	display_name = cJSON_GetObjectItem(ncs, "display_name");
	msg_id = cJSON_GetObjectItem(ncs, "msg_id");
	action = cJSON_GetObjectItem(ncs, "action");

	memset(msg, 0, sizeof(*msg));
	if (app_identifier) {
		strncpy(msg->app_identifier, app_identifier->valuestring, 31);
		if (strcmp(app_identifier->valuestring, "com.android.phone_incall") == 0) {
			msg->start_show_time = get_date();
		}
	}
	if (title) {
		strncpy(msg->title, title->valuestring, 31);
	}
	if (message) {
		strncpy(msg->message, message->valuestring, 255);
	}
	if (subtitle) {
		strncpy(msg->subtitle, subtitle->valuestring, 31);
	}
	if (date) {
		strncpy(msg->date, date->valuestring, 32);
	}
	if (display_name) {
		strncpy(msg->display_name, display_name->valuestring, 31);
	}
	if (msg_id) {
		msg->uid = msg_id->valueint;
	}
	if (action) {
		msg->action = action->valueint;
	}
	msg->recv_time = get_date();
	cJSON_Delete(root);
	dump_ancs("#device-receiver", msg);
}
