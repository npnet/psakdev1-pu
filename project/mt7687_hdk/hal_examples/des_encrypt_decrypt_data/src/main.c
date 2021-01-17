/* Copyright Statement:
 *
 */

/* Includes ------------------------------------------------------------------*/
#include <stdint.h>
#include <stdio.h>
#include <string.h>

/* hal includes */
#include "hal.h"
#include "top.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/

/* Private functions ---------------------------------------------------------*/

#ifdef __GNUC__
int __io_putchar(int ch)
#else
int fputc(int ch, FILE *f)
#endif
{
    /* Place your implementation of fputc here */
    /* e.g. write a character to the HAL_UART_0 one at a time */
    hal_uart_put_char(HAL_UART_0, ch);
    return ch;
}

/**
*@brief Set pinmux to UART and initialize UART hardware initialization for logging.
*@param None.
*@return None.
*/
static void log_uart_init(void)
{
    hal_uart_config_t uart_config;
    /* Set Pinmux to UART */
    hal_pinmux_set_function(HAL_GPIO_0, HAL_GPIO_0_UART1_RTS_CM4);
    hal_pinmux_set_function(HAL_GPIO_1, HAL_GPIO_1_UART1_CTS_CM4);
    hal_pinmux_set_function(HAL_GPIO_2, HAL_GPIO_2_UART1_RX_CM4);
    hal_pinmux_set_function(HAL_GPIO_3, HAL_GPIO_3_UART1_TX_CM4);

    /* COM port settings */
    uart_config.baudrate = HAL_UART_BAUDRATE_115200;
    uart_config.word_length = HAL_UART_WORD_LENGTH_8;
    uart_config.stop_bit = HAL_UART_STOP_BIT_1;
    uart_config.parity = HAL_UART_PARITY_NONE;
    hal_uart_init(HAL_UART_0, &uart_config);

}
/**
*@brief Configure and initialize the systerm clock.
*@param None.
*@return None.
*/
static void SystemClock_Config(void)
{
    top_xtal_init();
}
/**
*@brief  Initialize the peripheral driver in this function. In this example, we initialize UART drivers.
*@param None.
*@return None.
*/
static void prvSetupHardware(void)
{
    /* Peripherals initialization */
    log_uart_init();

}
/**
*@brief Log the data in the format of 16 bytes per line.
*@param[in] result: pointer to the data that will be logged out.
*@param[in] length: indicates the length of the data which will be logged out.
*@return None.
*/
static void des_result_dump(uint8_t *result, uint8_t length)
{
    uint8_t i;

    for (i = 0; i < length; i++) {
        if (i % 16 == 0) {
            printf("\r\n");
        }

        printf(" %02x ", result[i]);
    }
    printf("\r\n");

}
/**
*@brief Example of DES encryption/decryption including CBC and ECB modes.
*@param None.
*@return None.
*/
static void des_encrypt_decrypt_data_example(void)
{
/*Step1: Prepare the data that will be used in DES encryption/decryption*/
    uint8_t plain[30] = {
        0, 11, 22, 33, 44, 55, 66, 77, 88, 99, 0, 11, 22, 33, 44, 55, 66,
        77, 88, 99, 0, 11, 22, 33, 44, 55, 66, 77, 88, 99
    };
    uint8_t hardware_id[8] = {
        0x4d, 0x54, 0x4b, 0x30, 0x30, 0x30, 0x30, 0x30
    };
    uint8_t des_cbc_iv[HAL_DES_CBC_IV_LENGTH] = {
        0x61, 0x33, 0x46, 0x68, 0x55, 0x38, 0x31, 0x43
    };
    uint8_t encrypted[32] = {0};
    uint8_t decrypted[32] = {0};

    hal_des_buffer_t encrypted_text = {
        .buffer = encrypted,
        .length = sizeof(encrypted)
    };
    hal_des_buffer_t origin_text = {
        .buffer = plain,
        .length = sizeof(plain)
    };
    hal_des_buffer_t key = {
        .buffer = hardware_id,
        .length = sizeof(hardware_id)
    };
/*Step2: Log out the data during DES encryption/decryption operation including CBC and ECB modes.*/
    printf("Origin:");
    des_result_dump(origin_text.buffer, origin_text.length);
    printf("Key:");
    des_result_dump(key.buffer, key.length);
    printf("IV:");
    des_result_dump(des_cbc_iv, sizeof(des_cbc_iv));

    hal_des_cbc_encrypt(&encrypted_text,
                        &origin_text,
                        &key,
                        des_cbc_iv);
    printf("Encrypted(DES CBC):");
    des_result_dump(encrypted_text.buffer, encrypted_text.length);

    hal_des_buffer_t decrypted_text = {
        .buffer = decrypted,
        .length = sizeof(decrypted)
    };
    hal_des_cbc_decrypt(&decrypted_text,
                        &encrypted_text,
                        &key,
                        des_cbc_iv);
    printf("Decrypted(DES CBC):");
    des_result_dump(decrypted_text.buffer, decrypted_text.length);


    hal_des_ecb_encrypt(&encrypted_text,
                        &origin_text,
                        &key);
    printf("Encrypted(DES ECB):");
    des_result_dump(encrypted_text.buffer, encrypted_text.length);

    hal_des_ecb_decrypt(&decrypted_text,
                        &encrypted_text,
                        &key);
    printf("Decrypted(DES ECB):");
    des_result_dump(decrypted_text.buffer, decrypted_text.length);
}

/* main function */
int main(void)
{
    /* Configure system clock */
    SystemClock_Config();

    /* Configure the hardware */
    prvSetupHardware();

    /* Enable I,F bits */
    __enable_irq();
    __enable_fault_irq();

    /* Add your application code here */
    printf("\r\n\r\n");/* The output UART used by printf is set by log_uart_init() */
    printf("welcome to main()\r\n");
    printf("\r\n\r\n");

    des_encrypt_decrypt_data_example();

    for (;;);
}

