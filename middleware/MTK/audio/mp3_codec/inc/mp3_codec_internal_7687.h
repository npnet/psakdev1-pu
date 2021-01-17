/* Copyright Statement:
 *
 */


#ifndef __MP3_CODEC_INTERNAL_H__
#define __MP3_CODEC_INTERNAL_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "syslog.h"
#include <string.h>
#include "mp3_codec.h"
#include "mp3dec_exp.h"
#include "audip_exp.h"

#ifndef MTK_I2S_ENABLED
#include "hal_audio_internal_service.h"
#include "hal_audio.h"
#endif
#include "hal_gpt.h"
#include "hal_log.h"


#ifdef MTK_I2S_ENABLED
typedef struct {
    uint32_t write_pointer;
    uint32_t read_pointer;
    uint32_t buffer_byte_count;
    uint8_t *buffer_base_pointer;
} ring_buffer_information_t;

/** @brief audio channel number define */
typedef enum {
    HAL_AUDIO_MONO    = 0, /**< A single channel.  */
    HAL_AUDIO_STEREO  = 1  /**< Two channels. */
} hal_audio_channel_number_t;

/** @brief Define audio sampling rate. */
typedef enum {
    HAL_AUDIO_SAMPLING_RATE_8KHZ      = 0, /**< 8000Hz  */
    HAL_AUDIO_SAMPLING_RATE_11_025KHZ = 1, /**< 11025Hz */
    HAL_AUDIO_SAMPLING_RATE_12KHZ     = 2, /**< 12000Hz */
    HAL_AUDIO_SAMPLING_RATE_16KHZ     = 3, /**< 16000Hz */
    HAL_AUDIO_SAMPLING_RATE_22_05KHZ  = 4, /**< 22050Hz */
    HAL_AUDIO_SAMPLING_RATE_24KHZ     = 5, /**< 24000Hz */
    HAL_AUDIO_SAMPLING_RATE_32KHZ     = 6, /**< 32000Hz */
    HAL_AUDIO_SAMPLING_RATE_44_1KHZ   = 7, /**< 44100Hz */
    HAL_AUDIO_SAMPLING_RATE_48KHZ     = 8, /**< 48000Hz */
    HAL_AUDIO_SAMPLING_RATE_96KHZ     = 9  /**< 96000Hz */
} hal_audio_sampling_rate_t;

/** @brief Audio event. */
typedef enum {
    HAL_AUDIO_EVENT_ERROR               = -1, /**<  An error occured during the function call. */
    HAL_AUDIO_EVENT_NONE                =  0, /**<  No error occurred during the function call. */
    HAL_AUDIO_EVENT_UNDERFLOW           =  1, /**<  Transmit data underflow. */
    HAL_AUDIO_EVENT_DATA_REQUEST        =  2, /**<  Send a user request to provide data. */
    HAL_AUDIO_EVENT_DATA_NOTIFICATION   =  3  /**<  This value means notify user rx data is ready. */
} hal_audio_event_t;


#endif





typedef enum {
    MP3_CODEC_QUEUE_EVENT_NONE = 0,
    MP3_CODEC_QUEUE_EVENT_DECODE,
    MP3_CODEC_QUEUE_EVENT_FILL_DATA,
    MP3_CODEC_QUEUE_EVENT_TOTAL
} mp3_codec_queue_event_id_t;


typedef struct {
    mp3_codec_media_handle_t    handle;                         /** MP3 codec handle */
    ring_buffer_information_t   decode_pcm_buff;                /** MP3 codec IP used. the mp3 codec IP will put decoded data in this buffer */
    ring_buffer_information_t   stream_out_pcm_buff;            /** This buffer contains the pcm data that are ready to play */
    Mp3dec_handle               *mp3_handle;                    /** MP3 codec IP used.  */

    void                        *working_buff1;                 /** MP3 codec IP used. The pointer to Working buffer1  */
    void                        *working_buff2;                 /** MP3 codec IP used.The pointer to Working buffer2  */
    uint8_t                     *memory_pool;

    uint32_t                    share_buff_size;                /* The share buffer size */
    uint32_t                    working_buff1_size;             /* The required Working buffer1 size in byte */
    uint32_t                    working_buff2_size;             /* The required Working buffer2 size in byte */
    uint32_t                    decode_pcm_buffer_size;         /* piter add: the required PCM buffer size for codec used. in byte */
    uint32_t                    stream_out_pcm_buff_size;       /* piter modify: stream out pcm buffer size */
} mp3_codec_internal_handle_t;


typedef struct {
    mp3_codec_queue_event_id_t id;
    void *parameter;
} mp3_codec_queue_event_t;


typedef void (*mp3_codec_internal_callback_t)(void *parameter);


#ifdef __cplusplus
}
#endif

#endif  /*__MP3_CODEC_INTERNAL_H__*/

