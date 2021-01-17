/* Copyright Statement:
 *
 */

/*************************************************************************
 * Included header files
 *************************************************************************/
#include "hal_eint.h"

#ifdef HAL_EINT_MODULE_ENABLED
#include "hal_eint_internal.h"
#include "hal_nvic.h"
#include "hal_nvic_internal.h"
#include "hal_log.h"
#include "hal_gpt.h"
#include "memory_attribute.h"


hal_eint_status_t hal_eint_init(hal_eint_number_t eint_number, const hal_eint_config_t *eint_config)
{
    hal_eint_status_t status;
    uint32_t mask;
    static uint32_t ini_state = 0;

    if (ini_state == 0) {
        hal_nvic_register_isr_handler(EINT_IRQn, (hal_nvic_isr_t)hal_eint_isr);
        hal_nvic_enable_irq(EINT_IRQn);
        ini_state = 1;
    }

    if (eint_number >= HAL_EINT_NUMBER_MAX || eint_config == NULL) {
        return HAL_EINT_STATUS_INVALID_PARAMETER;
    }

    mask = save_and_set_interrupt_mask();
    eint_function_table[eint_number].eint_callback = NULL;
    eint_function_table[eint_number].user_data = NULL;
    restore_interrupt_mask(mask);
    status = hal_eint_set_trigger_mode(eint_number, eint_config->trigger_mode);
    status |= hal_eint_set_debounce_time(eint_number, eint_config->debounce_time);

    eint_ack_interrupt(eint_number);
    
    return status;
}

hal_eint_status_t hal_eint_deinit(hal_eint_number_t eint_number)
{
    uint32_t mask;

    if (eint_number >= HAL_EINT_NUMBER_MAX) {
        return HAL_EINT_STATUS_ERROR_EINT_NUMBER;
    }

    mask = save_and_set_interrupt_mask();
    eint_function_table[eint_number].eint_callback = NULL;
    eint_function_table[eint_number].user_data = NULL;

    eint_ack_interrupt(eint_number);
    hal_eint_mask(eint_number);
    restore_interrupt_mask(mask);
    return HAL_EINT_STATUS_OK;
}

hal_eint_status_t hal_eint_register_callback(hal_eint_number_t eint_number,
        hal_eint_callback_t eint_callback,
        void *user_data)
{
    uint32_t mask;

    if (eint_number >= HAL_EINT_NUMBER_MAX || eint_callback == NULL) {
        return HAL_EINT_STATUS_INVALID_PARAMETER;
    }

    mask = save_and_set_interrupt_mask();
    eint_function_table[eint_number].eint_callback = eint_callback;
    eint_function_table[eint_number].user_data = user_data;
    restore_interrupt_mask(mask);
    return HAL_EINT_STATUS_OK;
}


/***************************************** *******************************
    sensitivity:
                            1         level  (default)
                            0         edge
    polarity:               0         negative polarity  (default)
                            1         positive polarity

 *************************************************************************/
hal_eint_status_t hal_eint_set_trigger_mode(hal_eint_number_t eint_number,
        hal_eint_trigger_mode_t trigger_mode)
{
    uint32_t mask;

    if (eint_number >= HAL_EINT_NUMBER_MAX) {
        return HAL_EINT_STATUS_INVALID_PARAMETER;
    }

    mask = save_and_set_interrupt_mask();
    if (trigger_mode == HAL_EINT_LEVEL_LOW) {
        EINT_REGISTER->EINT_SENS_SET   = (1 << eint_number);
        EINT_REGISTER->EINT_POL_CLR    = (1 << eint_number);
    } else if (trigger_mode == HAL_EINT_LEVEL_HIGH) {
        EINT_REGISTER->EINT_SENS_SET   = (1 << eint_number);
        EINT_REGISTER->EINT_POL_SET    = (1 << eint_number);
    } else if (trigger_mode == HAL_EINT_EDGE_FALLING) {
        EINT_REGISTER->EINT_SENS_CLR   = (1 << eint_number);
        EINT_REGISTER->EINT_POL_CLR    = (1 << eint_number);
    } else if (trigger_mode == HAL_EINT_EDGE_RISING) {
        EINT_REGISTER->EINT_SENS_CLR   = (1 << eint_number);
       	EINT_REGISTER->EINT_POL_SET    = (1 << eint_number);
    } else if (trigger_mode == HAL_EINT_EDGE_FALLING_AND_RISING) {
        /* DUALEGE depends on SENS */
        EINT_REGISTER->EINT_SENS_CLR   = (1 << eint_number);
        EINT_REGISTER->EINT_DUALEDGE_SENS_SET = (1 << eint_number);
    } else {
        restore_interrupt_mask(mask);
        return HAL_EINT_STATUS_INVALID_PARAMETER;
    }
    restore_interrupt_mask(mask);
    hal_gpt_delay_us(100);

    return HAL_EINT_STATUS_OK;
}

/* every count = 1/32k*/
hal_eint_status_t hal_eint_set_debounce_count(hal_eint_number_t eint_number, uint32_t count)
{
    uint32_t mask, eint_con;

    if (eint_number >= HAL_EINT_NUMBER_MAX) {
        return HAL_EINT_STATUS_INVALID_PARAMETER;
    }

    if ((count & (~EINT_CON_DBC_CNT_MASK))) {
        return HAL_EINT_STATUS_INVALID_PARAMETER;
    }

    mask = save_and_set_interrupt_mask();
    eint_con =  (count | EINT_CON_DBC_EN_MASK |(EINT_CON_PRESCALER_MASK & (EINT_CON_PRESCALER_32KHZ << EINT_CON_PRESCALER_OFFSET)));
    restore_interrupt_mask(mask);
    if (count == 0) {
        /*disenable debounce bit*/
        EINT_REGISTER->EINT_CON_REGISTER[eint_number].EINT_CON_CELLS.DBC_EN = EINT_CON_DBC_DISABLE;
        /* can't reset debounce as it will cause 1/32k delay by debounce */
    }
    else {    
        EINT_REGISTER->EINT_CON_REGISTER[eint_number].EINT_CON = 0;
        EINT_REGISTER->EINT_CON_REGISTER[eint_number].EINT_CON_CELLS.DBC_EN = EINT_CON_DBC_ENABLE;
        hal_gpt_delay_us(125);
        EINT_REGISTER->EINT_CON_REGISTER[eint_number].EINT_CON = eint_con;
        EINT_REGISTER->EINT_CON_REGISTER[eint_number].EINT_CON_CELLS.RSTDBC = EINT_CON_RSTD_BC_MASK;
    }


  
    return HAL_EINT_STATUS_OK;
}


hal_eint_status_t hal_eint_set_debounce_time(hal_eint_number_t eint_number, uint32_t time_ms)
{
    uint32_t mask, count, eint_con;

    if (eint_number >= HAL_EINT_NUMBER_MAX) {
        return HAL_EINT_STATUS_INVALID_PARAMETER;
    }

    count = eint_caculate_debounce_time(time_ms);
    mask = save_and_set_interrupt_mask();
    eint_con = count;
    restore_interrupt_mask(mask);
    if (time_ms == 0) {
        /*disenable debounce bit*/
        EINT_REGISTER->EINT_CON_REGISTER[eint_number].EINT_CON_CELLS.DBC_EN = EINT_CON_DBC_DISABLE;
        /* can't reset debounce as it will cause 1/32k delay by debounce */
    }
    else {
        EINT_REGISTER->EINT_CON_REGISTER[eint_number].EINT_CON = 0;
        EINT_REGISTER->EINT_CON_REGISTER[eint_number].EINT_CON_CELLS.DBC_EN = EINT_CON_DBC_ENABLE;
        hal_gpt_delay_us(125);
        EINT_REGISTER->EINT_CON_REGISTER[eint_number].EINT_CON = eint_con;
    EINT_REGISTER->EINT_CON_REGISTER[eint_number].EINT_CON_CELLS.RSTDBC = EINT_CON_RSTD_BC_MASK;
    }

	
  
    return HAL_EINT_STATUS_OK;
}

hal_eint_status_t hal_eint_set_software_trigger(hal_eint_number_t eint_number)
{
    uint32_t mask;

    if (eint_number >= HAL_EINT_NUMBER_MAX) {
        return HAL_EINT_STATUS_INVALID_PARAMETER;
    }

    mask = save_and_set_interrupt_mask();
    EINT_REGISTER->EINT_SOFT_SET = (1 << eint_number);
    restore_interrupt_mask(mask);
  
    return HAL_EINT_STATUS_OK;
}

hal_eint_status_t hal_eint_clear_software_trigger(hal_eint_number_t eint_number)
{
    uint32_t mask;

    if (eint_number >= HAL_EINT_NUMBER_MAX) {
        return HAL_EINT_STATUS_ERROR;
    }

    mask = save_and_set_interrupt_mask();
    EINT_REGISTER->EINT_SOFT_CLR = (1 << eint_number);
    restore_interrupt_mask(mask);
    return HAL_EINT_STATUS_OK;
}

hal_eint_status_t eint_mask_wakeup_source(hal_eint_number_t eint_number)
{
    uint32_t mask;
    if (eint_number >= HAL_EINT_NUMBER_MAX) {
        return HAL_EINT_STATUS_INVALID_PARAMETER;
    }

    mask = save_and_set_interrupt_mask();
    EINT_REGISTER->EINT_WAKEUP_MASK_SET = (1 << eint_number);
    restore_interrupt_mask(mask);
    return HAL_EINT_STATUS_OK;
}

hal_eint_status_t eint_unmask_wakeup_source(hal_eint_number_t eint_number)
{
    uint32_t mask;

    if (eint_number >= HAL_EINT_NUMBER_MAX) {
        return HAL_EINT_STATUS_INVALID_PARAMETER;
    }

    mask = save_and_set_interrupt_mask();
    EINT_REGISTER->EINT_WAKEUP_MASK_CLR = (1 << eint_number);
    restore_interrupt_mask(mask);
    return HAL_EINT_STATUS_OK;
}

#ifdef HAL_EINT_FEATURE_MASK
hal_eint_status_t hal_eint_mask(hal_eint_number_t eint_number)
{
    uint32_t mask;
    if (eint_number >= HAL_EINT_NUMBER_MAX) {
        return HAL_EINT_STATUS_INVALID_PARAMETER;
    }

    mask = save_and_set_interrupt_mask();
    EINT_REGISTER->EINT_MASK_SET = (1 << eint_number);
    eint_mask_wakeup_source(eint_number);
    restore_interrupt_mask(mask);
    return HAL_EINT_STATUS_OK;
}

hal_eint_status_t hal_eint_unmask(hal_eint_number_t eint_number)
{
    uint32_t mask;

    if (eint_number >= HAL_EINT_NUMBER_MAX) {
        return HAL_EINT_STATUS_INVALID_PARAMETER;
    }

    mask = save_and_set_interrupt_mask();
    EINT_REGISTER->EINT_MASK_CLR = (1 << eint_number);
    eint_unmask_wakeup_source(eint_number);
    restore_interrupt_mask(mask);
    return HAL_EINT_STATUS_OK;
}
#endif


#ifdef __cplusplus
}
#endif

#endif /* HAL_EINT_MODULE_ENABLED */

