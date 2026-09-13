/*
 * Module-private declarations for the sensors / audio files
 * (ext_flash.c, opt3007.c, fuel_gauge.c, charger_box.c, dmic_audio.c, audio_stream.c).
 * Partial views of shared vendor structures, reconstructed from the v1.63
 * app core.
 */
#ifndef G1_SENSORS_AUDIO_H_
#define G1_SENSORS_AUDIO_H_

#include <stdint.h>
#include <stdbool.h>
#include <sys/types.h>
#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/sys/atomic.h>
#include <glasses_state.h>

/* ext_flash.c */
typedef int (*ext_flash_read_t)(struct GlassesState *gs, uint32_t offset, void *data, size_t len);
typedef int (*ext_flash_write_t)(struct GlassesState *gs, uint32_t offset, const void *data,
				 size_t len);
typedef int (*ext_flash_erase_t)(struct GlassesState *gs, uint32_t offset, size_t size);

int ext_flash_api_init(ext_flash_read_t *read, ext_flash_write_t *write, ext_flash_erase_t *erase);

/* opt3007.c */
uint8_t opt3007_get_brightness_level(struct opt3007_context *ctx);
int opt3007_read(int arg);
int opt3007_get_max_lux(void);
int opt3007_chip_init(struct opt3007_context *ctx);
void opt3007_chip_deinit(void);
void register_opt3007_context(struct opt3007_context *ctx);
int enable_power_for_panel(void);
int disable_power_for_panel(void);

/* fuel_gauge.c */
int fuel_gauge_init(const struct device *charger);
bool is_old_board(void);
int fuel_gauge_update(const struct device *charger, int unused);

/* charger_box.c */
enum { BOX_IN_BOX = 0, BOX_LID_CLOSED = 1 }; /* set_box_status() type */
int change_termination_voltage(void);
int enable_charger(void);
int set_charger_status(void);
uint8_t get_box_status_by_type(uint8_t type);
void set_box_status(uint8_t type, uint8_t status);
int is_in_box(void);
uint8_t is_box_lid_closed(void);
uint8_t is_box_charging(void);
void init_box_status(void);

/* dmic_audio.c */
#define DMIC_MSG_SIZE 200
extern atomic_t audio_stream_recording; /* audio stream record running */
extern uint8_t dmic_send_pending; /* pending 0xf1 dmic request */
int enqueue_dmic(void *msg);
uint32_t get_dmic_num_messages(void);
int dequeue_dmic(void *msg);
void app_codec_lc3_test(void *pcm, int len);
uint8_t dmic_get_stop_state(void);
/* returns int; production_test.c was built against a void prototype (register allocation
 * around its call differs) and defines DMIC_STREAM_STOP_VOID_PROTOTYPE before including this header */
#ifdef DMIC_STREAM_STOP_VOID_PROTOTYPE
void dmic_stream_stop(void);
#else
int dmic_stream_stop(void);
#endif
int dmic_stream_pause(int pause);
int dmic_stream_start(void);
int erase_audio_buffer(void);

/* audio_stream.c */
int clearAudioMessageQueue(void);
int sendAudioStram2Cache(void *data);
uint32_t getAudioMessageQueueNum(void);
int startAudioStreamRecord(void);
int stopAudioStreamRecord(void);
int delAudioStreamRecord(uint8_t num);
atomic_val_t setAudioBlockInUse(atomic_val_t num);
atomic_val_t clearAudioBlockInUse(void);
int audioStreamFileManagerHandler(void);
int request_dmic_stream_start(void);

#endif /* G1_SENSORS_AUDIO_H_ */
