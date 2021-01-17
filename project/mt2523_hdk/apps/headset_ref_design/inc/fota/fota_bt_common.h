/* Copyright Statement:
 *
 */

#ifndef __BT_COMMON_H__
#define __BT_COMMON_H__

#include "syslog.h"

#ifdef __cplusplus
extern "C" {
#endif
#include "bt_type.h"
#include "bt_gap.h"
#include "bt_gap_le.h"

extern bt_status_t fota_bt_app_event_callback(bt_msg_type_t msg, bt_status_t status, void *buff);
extern bt_gap_le_local_config_req_ind_t *fota_bt_gap_le_get_local_config(void);
extern bt_gap_le_bonding_info_t* fota_bt_gap_le_get_bonding_info(const bt_addr_t remote_addr);
extern bt_status_t fota_bt_gap_le_get_pairing_config(bt_gap_le_bonding_start_ind_t *ind);
extern const bt_gap_config_t* fota_bt_gap_get_local_configuration(void);

#ifdef __cplusplus
}
#endif

#endif /* __BT_COMMON_H__ */

