/* Copyright Statement:
 *
 */

#ifndef __HAL_UART_INTERNAL_H__
#define __HAL_UART_INTERNAL_H__

#ifdef HAL_UART_MODULE_ENABLED

#include <assert.h>
#include "hal_pdma_internal.h"
#include "hal_log.h"

#ifdef __cplusplus
extern "C" {
#endif

//#define UART_INPUT_CLOCK_DCXO 26000000

typedef enum {
    UART_INTERRUPT_NONE,
    UART_INTERRUPT_RECEIVE_ERROR,
    UART_INTERRUPT_RECEIVE_TIMEOUT,
    UART_INTERRUPT_RECEIVE_BREAK,
    UART_INTERRUPT_RECEIVE_AVAILABLE,
    UART_INTERRUPT_SEND_AVAILABLE,
    UART_INTERRUPT_SOFTWARE_FLOWCONTROL,
    UART_INTERRUPT_HARDWARE_FLOWCONTROL
} uart_interrupt_type_t;

typedef struct {
    bool is_rx;
    hal_uart_port_t uart_port;
} uart_dma_callback_data_t;

#ifdef HAL_UART_FEATURE_SOFT_DTE_SUPPORT
/* event generated by DTE pins change */
typedef enum {
    HAL_UART_DTE_EVENT_DSR_ACTIVE = 0,
    HAL_UART_DTE_EVENT_DSR_DEACTIVE = 1,
    HAL_UART_DTE_EVENT_DCD_ACTIVE = 2,
    HAL_UART_DTE_EVENT_DCD_DEACTIVE = 3,
    HAL_UART_DTE_EVENT_RI_HIGH = 4,
    HAL_UART_DTE_EVENT_RI_LOW = 5
} hal_uart_dte_callback_event_t;

/* declare for user defined callback */
typedef void (*hal_uart_dte_callback_t)(hal_uart_dte_callback_event_t event, void *user_data);

typedef struct {
    uint32_t dsr_debounce_time;
    uint32_t dcd_debounce_time;
    uint32_t ri_debounce_time;
    bool dsr_is_active_high;
    bool dcd_is_active_high;
    bool dtr_is_active_high;
    hal_uart_dte_callback_t user_callback;
    void *user_data;
} hal_uart_dte_config_t;

typedef struct {
    hal_uart_port_t uart_port;
    hal_gpio_pin_t ri_pin;
    hal_gpio_pin_t dsr_pin;
    hal_gpio_pin_t dcd_pin;
    hal_gpio_pin_t dtr_pin;
    hal_eint_number_t dsr_eint;
    hal_eint_number_t ri_eint;
    hal_eint_number_t dcd_eint;
    hal_uart_dte_config_t dte_config;
} uart_dte_config_t;

hal_uart_status_t hal_uart_set_dte_config(hal_uart_port_t uart_port,
        hal_uart_dte_config_t *uart_dte_config);
hal_uart_status_t hal_uart_set_dte_dtr_active(hal_uart_port_t uart_port);
hal_uart_status_t hal_uart_set_dte_dtr_deactive(hal_uart_port_t uart_port);
#endif

#define UART_DMA_MAX_SETTING_VALUE (2<<16)
#ifndef __UBL__
#define UART_ASSERT() assert(0)
#else
#define UART_ASSERT() log_hal_error("assert\r\n")
#endif


#ifdef HAL_UART_FEATURE_SOFT_DTE_SUPPORT
void uart_dte_init_config(uart_dte_config_t *uart_dte_config);
#endif
vdma_channel_t uart_port_to_dma_channel(hal_uart_port_t uart_port, int32_t is_rx);
void uart_dma_channel_to_callback_data(vdma_channel_t dma_channel, uart_dma_callback_data_t *user_data);
void uart_enable_dma(UART_REGISTER_T *uartx);
void uart_interrupt_handler(hal_nvic_irq_t irq_number);


void uart_reset_default_value(UART_REGISTER_T *uartx);
void uart_query_empty(UART_REGISTER_T *uartx);
void uart_set_high_baudrate(UART_REGISTER_T *uartx, uint32_t uart_clock, uint32_t baudrate);
void uart_set_low_baudrate(UART_REGISTER_T *uartx, uint32_t uart_clock, uint32_t baudrate);
void uart_set_baudrate(UART_REGISTER_T *uartx, uint32_t actual_baudrate);
void uart_set_format(UART_REGISTER_T *uartx,
                     hal_uart_word_length_t word_length,
                     hal_uart_stop_bit_t stop_bit,
                     hal_uart_parity_t parity);
void uart_set_timeout_value(UART_REGISTER_T *uartx, uint32_t value);
int uart_probe_char(UART_REGISTER_T *uartx);
void uart_put_char_block(UART_REGISTER_T *uartx, uint8_t byte);
uint8_t uart_get_char_block(UART_REGISTER_T *uartx);
uint32_t uart_get_char_unblocking(UART_REGISTER_T *uartx);
void uart_set_hardware_flowcontrol(UART_REGISTER_T *uartx);
void uart_set_software_flowcontrol(UART_REGISTER_T *uartx,
                                   uint8_t xon,
                                   uint8_t xoff,
                                   uint8_t escape_character);
void uart_disable_flowcontrol(UART_REGISTER_T *uartx);
#ifdef HAL_SLEEP_MANAGER_ENABLED
void uart_unmask_send_interrupt(UART_REGISTER_T *uartx);
void uart_set_sleep_mode(UART_REGISTER_T *uartx);
#endif
void uart_set_fifo(UART_REGISTER_T *uartx);
vdma_channel_t uart_port_to_dma_channel(hal_uart_port_t uart_port, int32_t is_rx);
void uart_enable_dma(UART_REGISTER_T *uartx);
void uart_unmask_receive_interrupt(UART_REGISTER_T *uartx);
void uart_purge_fifo(UART_REGISTER_T *uartx, int32_t is_rx);
uart_interrupt_type_t uart_query_interrupt_type(UART_REGISTER_T *uartx);
int32_t uart_verify_error(UART_REGISTER_T *uartx);
void uart_clear_timeout_interrupt(UART_REGISTER_T *uartx);
void uart_send_handler(hal_uart_port_t uart_port, bool is_send_complete_trigger);
void uart_receive_handler(hal_uart_port_t uart_port, bool is_timeout);
void uart_error_handler(hal_uart_port_t uart_port);

#ifdef __cplusplus
}
#endif

#endif

#endif

