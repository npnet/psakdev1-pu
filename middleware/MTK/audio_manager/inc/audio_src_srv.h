/* Copyright Statement:
 *
 */

#ifndef __AUDIO_SRC_SRV_H__
#define __AUDIO_SRC_SRV_H__

#include <stdint.h>
#include <stdbool.h>


#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief This structure defines multi-source state. */
typedef enum {
    AUDIO_SRC_SRV_STATE_NONE = 0,
    AUDIO_SRC_SRV_STATE_READY,
    AUDIO_SRC_SRV_STATE_PLAYING,
} audio_src_srv_state_t;

/**
 * @brief This structure defines multi-source transient state. */
typedef enum {
    AUDIO_SRC_SRV_TRANSIENT_STATE_NONE = 0,
    AUDIO_SRC_SRV_TRANSIENT_STATE_PREPARE_PLAY,
    AUDIO_SRC_SRV_TRANSIENT_STATE_PREPARE_STOP,
} audio_src_srv_transient_state_t;

/**
 * @brief This structure defines pseudo device type. */
typedef enum {
    AUDIO_SRC_SRV_PSEUDO_DEVICE_A2DP = 0,
    AUDIO_SRC_SRV_PSEUDO_DEVICE_HFP,
    AUDIO_SRC_SRV_PSEUDO_DEVICE_MP3,
    AUDIO_SRC_SRV_PSEUDO_DEVICE_AWS_A2DP,
    AUDIO_SRC_SRV_PSEUDO_DEVICE_AWS_HFP,
    AUDIO_SRC_SRV_PSEUDO_DEVICE_AWS_MP3,
    AUDIO_SRC_SRV_PSEUDO_DEVICE_VP,
} audio_src_srv_pseudo_device_t;

/**
 * @brief This macro defines multi-source priority base. */
#define AUDIO_SRC_SRV_FLAG_USED                     (1 << 0)    /* Pseudo device handle used */
#define AUDIO_SRC_SRV_FLAG_WAITING                  (1 << 1)    /* Pseudo device in waiting list */

#define AUDIO_SRC_SRV_PSEUDO_DEVICE_NUM             (2 /* Sink A2DP */ + 2 /* Sink HFP */ + 1 /* Sink MP3 */ + 1 /* A2DP_AWS */ + 1 /* HFP_AWS */ + 1 /* MP3_AWS*/ + 1/* VP*/)


/**
 * @brief This structure defines multi-source priority. */
typedef enum {
    AUDIO_SRC_SRV_PRIORITY_LOW = 0,
    AUDIO_SRC_SRV_PRIORITY_NORMAL = 2,
    AUDIO_SRC_SRV_PRIORITY_MIDDLE = 4,
    AUDIO_SRC_SRV_PRIORITY_HIGH = 6,
} audio_src_srv_priority_t;


/**
 * @brief This structure defines multi-source event ID. */
typedef enum {
    AUDIO_SRC_SRV_EVT_UNAVAILABLE,
    AUDIO_SRC_SRV_EVT_READY,
    AUDIO_SRC_SRV_EVT_PREPARE_PLAY,
    AUDIO_SRC_SRV_EVT_PREPARE_STOP,
    AUDIO_SRC_SRV_EVT_PLAYING,
} audio_src_srv_event_t;


/**
 * @brief This structure defines multi-source handle. */
typedef struct _audio_src_srv_handle_t {
    audio_src_srv_state_t state;
    audio_src_srv_transient_state_t substate;
    audio_src_srv_pseudo_device_t type;
    uint32_t play_count;
    uint16_t flag;

    /* source should write follownig members */
    uint8_t priority;
    uint64_t dev_id;        /* Bluetooth address */
    void (*play)(struct _audio_src_srv_handle_t *handle);
    void (*stop)(struct _audio_src_srv_handle_t *handle);
    void (*suspend)(struct _audio_src_srv_handle_t *handle, struct _audio_src_srv_handle_t *int_hd);
    void (*reject)(struct _audio_src_srv_handle_t *handle);
    void (*exception_handle)(struct _audio_src_srv_handle_t *handle, int32_t event, void *param);
} audio_src_srv_handle_t;


audio_src_srv_handle_t *audio_src_srv_construct_handle(audio_src_srv_pseudo_device_t type);

void audio_src_srv_destruct_handle(audio_src_srv_handle_t *handle);

void audio_src_srv_update_state(audio_src_srv_handle_t *handle, audio_src_srv_event_t evt_id);

const audio_src_srv_handle_t *audio_src_srv_get_pseudo_device(void);

void audio_src_srv_add_waiting_list(audio_src_srv_handle_t *handle);

void audio_src_srv_del_waiting_list(audio_src_srv_handle_t *handle);

bool audio_src_srv_psedev_compare(audio_src_srv_handle_t *cur, audio_src_srv_handle_t *coming);

void audio_src_srv_mutex_lock(void);

void audio_src_srv_mutex_unlock(void);

#ifdef __cplusplus
}
#endif

#endif /* __AUDIO_SRC_SRV_H__ */

