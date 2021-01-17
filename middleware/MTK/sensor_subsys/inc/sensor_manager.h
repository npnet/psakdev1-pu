/* Copyright Statement:
 *
 */

#ifndef __SENSOR_MANAGER_H__
#define __SENSOR_MANAGER_H__
#include <stdint.h>
#include "queue.h"

#if defined(__CC_ARM)
    #pragma anon_unions
#elif defined(__ICCARM__)
    #pragma language=extended
#elif defined(__GNUC__)
/* anonymous unions are enabled by default */
#endif

#define SM_EVENT_TIMEOUT 1
#define SM_EVENT_DATA_READY 2
#define SM_EVENT_SUBSCRIBE 3
#define SM_EVENT_CALIBRATION 4

typedef struct cmd_event_t {
    uint32_t event;
    union {
        uint32_t data_ready; /* bitmap of sensor types for SM_EVENT_DATA_READY*/
        uint32_t period; /* period for SM_EVENT_TIMEOUT */
        uint32_t sensor_type; /*  sensor type fof SM_EVENT_SUBSCRIBE */
    };
    union {
        uint32_t timestamp; /*  ms for SM_EVENT_DATA_READY */
        uint32_t enable; /*  enable for SM_EVENT_SUBSCRIBE */
    };
    union {
        uint32_t length; /* data length for SM_EVENT_DATA_READY*/
        uint32_t delay; /*  delay in ms for SM_EVENT_SUBSCRIBE*/
    };
    uint32_t timeout; /* the timeout for batch in ms for SM_EVENT_SUBSCRIBE*/
} cmd_event_t;

extern QueueHandle_t sm_queue_handle;

/*----------------------------------------------------------------------------*/
uint32_t sensor_driver_get_ms_tick(void);
extern int send_sensor_data_via_btspp(int32_t magic, int32_t sensor_type, int32_t x, int32_t y, int32_t z, int32_t status, int32_t time_stamp);

int32_t sensor_driver_enable(uint32_t sensor_type, int32_t enable);
int32_t sensor_driver_get_data(uint32_t sensor_type, void *data_buf, int32_t size, int32_t *actual_out_size);
int32_t sensor_driver_set_delay(uint32_t sensor_type, int32_t delay);
int32_t sensor_driver_set_batch_timeout(uint32_t sensor_type, uint32_t timeout);
int32_t sensor_driver_set_cust(uint32_t sensor_type, void *out_data_buf, int32_t out_size, int32_t *actual_out_size, \
                           void *in_data_buf, int32_t in_size);
uint32_t sensor_driver_get_enable(int sensor_type);
uint32_t sensor_driver_get_delay(int sensor_type);
uint32_t sensor_driver_get_batch_timeout(int sensor_type);
int32_t sensor_driver_get_event_type(int sensor_type);
int32_t sensor_driver_get_attached(int sensor_type);

/*----------------------------------------------------------------------------*/

#endif
