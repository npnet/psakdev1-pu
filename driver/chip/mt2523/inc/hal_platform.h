/* Copyright Statement:
 *
 */

#ifndef __HAL_PLATFORM_H__
#define __HAL_PLATFORM_H__


#include "hal_define.h"
#include "hal_feature_config.h"
#include "mt2523.h"
#include "hal_weak.h"
#include "memory_map.h"

#ifdef __cplusplus
extern "C" {
#endif


/*****************************************************************************
* Defines for module subfeatures.
* All the subfeatures described below are mandatory for the driver operation. No change is recommended.
*****************************************************************************/
#ifdef HAL_CACHE_MODULE_ENABLED
#define HAL_CACHE_WITH_REMAP_FEATURE     /* Enable CACHE settings with remap feature. */
#endif

#ifdef HAL_ADC_MODULE_ENABLED
#define HAL_ADC_FEATURE_SET_INPUT_AND_DISABLE_PULL /* Set the pin as input and disable the pull when the pin is in ADC mode. */
#endif

#ifdef HAL_I2C_MASTER_MODULE_ENABLED
#define HAL_I2C_MASTER_FEATURE_SEND_TO_RECEIVE  /* Enable I2C master send to receive feature. */
#define HAL_I2C_MASTER_FEATURE_EXTENDED_DMA    /* Enable I2C master extend DMA feature. */

#endif

#ifdef HAL_SPI_MASTER_MODULE_ENABLED
#define HAL_SPI_MASTER_FEATURE_ADVANCED_CONFIG       /* Enable SPI master advanced configuration feature. For more details, please refer to hal_spi_master.h. */
#define HAL_SPI_MASTER_FEATURE_DEASSERT_CONFIG       /* Enable SPI master deassert configuration feature to deassert the chip select signal after data transfer is complete. For more details, please refer to hal_spi_master.h. */
#define HAL_SPI_MASTER_FEATURE_MACRO_CONFIG          /* Enable SPI master pad_macro configuration feature to set pad_macro for related SPI pins. For more details, please refer to hal_spi_master.h. */
#define HAL_SPI_MASTER_FEATURE_CHIP_SELECT_TIMING    /* Enable SPI master chip select timing configuration feature to set timing value for chip select signal. For more details, please refer to hal_spi_master.h. */
#define HAL_SPI_MASTER_FEATURE_DMA_MODE              /* Enable SPI master DMA mode feature to do data transfer. For more details, please refer to hal_spi_master.h. */
#endif

#ifdef HAL_GPIO_MODULE_ENABLED
#define HAL_GPIO_FEATURE_INVERSE           /* Input status of the pin can be set to the reverse state. For more details, please refer to hal_gpio.h. */
#define HAL_GPIO_FEATURE_PUPD              /* Pull state of the pin can be configured with different resistors through different combinations of GPIO_PUPD_x,GPIO_RESEN0_x and GPIO_RESEN1_x. For more details, please refer to hal_gpio.h. */
#define HAL_GPIO_FEATURE_CLOCKOUT          /* The pin can be configured as an output clock. For more details, please refer to hal_gpio.h. */
#define HAL_GPIO_FEATURE_HIGH_Z            /* The pin can be configured to provide high impedance state to prevent possible electric leakage. For more details, please refer to hal_gpio.h. */
#define HAL_GPIO_FEATURE_SET_DRIVING       /* The pin can be configured to enhance driving. For more details, please refer to hal_gpio.h. */
#endif

#ifdef HAL_EINT_MODULE_ENABLED
#define HAL_EINT_FEATURE_MASK                /* Supports EINT mask interrupt. */
#define HAL_EINT_FEATURE_SW_TRIGGER_EINT     /* Supports software triggered EINT interrupt. */
#endif

#ifdef HAL_GPT_MODULE_ENABLED
#define HAL_GPT_FEATURE_US_TIMER               /* Supports a microsecond timer. */
#define HAL_GPT_SW_GPT_FEATURE                 /* Supports software GPT timer. */
#define HAL_GPT_PORT_ALLOCATE                  /* Allocates GPT communication port. */
#endif

#ifdef HAL_KEYPAD_MODULE_ENABLED
#ifdef HAL_PMU_MODULE_ENABLED
#ifndef MTK_EXTERNAL_PMIC
#define HAL_KEYPAD_FEATURE_POWERKEY             /* The powerkey can be used as a normal key.*/
#endif
#endif
#endif

#ifdef HAL_PWM_MODULE_ENABLED
#define HAL_PWM_FEATURE_ADVANCED_CONFIG        /* Supports PWM advanced configuration. */
#endif

#ifdef HAL_RTC_MODULE_ENABLED
#define HAL_RTC_FEATURE_TIME_CALLBACK           /* Supports time change notification callback. */
#endif

#ifdef HAL_SPI_SLAVE_MODULE_ENABLED
#define HAL_SPI_SLAVE_FEATURE_SW_CONTROL         /* Supports SPI slave to communicate with SPI master using software control. */
#endif

#ifdef HAL_SLEEP_MANAGER_ENABLED
#define HAL_SLEEP_MANAGER_SUPPORT_WAKEUP_SOURCE_CONFIG  /* Supports wakeup source interrupt configuration. */
#define HAL_SLEEP_MANAGER_SUPPORT_POWER_OFF             /* Supports power off mode. */
/**
 * @addtogroup HAL
 * @{
 * @addtogroup SLEEP_MANAGER
 * @{
 * @addtogroup hal_sleep_manager_enum Enum
 * @{ */
/*****************************************************************************
 * Enum
 *****************************************************************************/
/** @brief Sleep modes */
typedef enum {
    HAL_SLEEP_MODE_NONE = 0,        /**< No sleep. */
    HAL_SLEEP_MODE_IDLE,            /**< Idle state. */
    HAL_SLEEP_MODE_SLEEP,           /**< Sleep state. */
    HAL_SLEEP_MODE_DEEP_SLEEP,      /**< Deep sleep state. */
    HAL_SLEEP_MODE_NUMBER           /**< To support range detection. */
} hal_sleep_mode_t;
/** @brief sleep_manager wake up source */
typedef enum {
    HAL_SLEEP_MANAGER_WAKEUP_SOURCE_GPT = 0,                     /**< General purpose timer. */
    HAL_SLEEP_MANAGER_WAKEUP_SOURCE_EINT,                        /**< External interrupt. */
    HAL_SLEEP_MANAGER_WAKEUP_SOURCE_RESERVED,                    /**< Reserved. */
    HAL_SLEEP_MANAGER_WAKEUP_SOURCE_KP,                          /**< Keypad. */
    HAL_SLEEP_MANAGER_WAKEUP_SOURCE_MSDC1,                       /**< SD/eMMC IP.  */
    HAL_SLEEP_MANAGER_WAKEUP_SOURCE_MDIF,                        /**< Modem interface. */
    HAL_SLEEP_MANAGER_WAKEUP_SOURCE_RESERVED_2,                  /**< Reserved. */
    HAL_SLEEP_MANAGER_WAKEUP_SOURCE_MSDC2,                       /**< SD/eMMC's second IP. */
    HAL_SLEEP_MANAGER_WAKEUP_SOURCE_SPI_SLAVE,                   /**< SPI protocol slave. */
    HAL_SLEEP_MANAGER_WAKEUP_SOURCE_RGU,                         /**< Reset Generation Unit. */
    HAL_SLEEP_MANAGER_WAKEUP_SOURCE_MM_DBI,                      /**< Multimedia display bus interface. */
    HAL_SLEEP_MANAGER_WAKEUP_SOURCE_MM_DSI,                      /**< Multimedia display serial interface. */
} hal_sleep_manager_wakeup_source_t;
/**
 * @}
 * @}
 * @} */
#endif

#ifdef HAL_UART_MODULE_ENABLED
/**
 * @addtogroup HAL
 * @{
 * @addtogroup UART
 * @{
 * @addtogroup hal_uart_enum Enum
 * @{ */
/*****************************************************************************
* UART
*****************************************************************************/
/** @brief UART port index
 * There are total of four UART ports. Only UART0 and UART1 support hardware flow control.
 * | UART port | Hardware Flow Control |
 * |-----------|-----------------------|
 * |  UART0    |           V           |
 * |  UART1    |           V           |
 * |  UART2    |           X           |
 * |  UART3    |           X           | */
typedef enum {
    HAL_UART_0 = 0,                            /**< UART port 0. */
    HAL_UART_1 = 1,                            /**< UART port 1. */
    HAL_UART_2 = 2,                            /**< UART port 2. */
    HAL_UART_3 = 3,                            /**< UART port 3. */
    HAL_UART_MAX                               /**< The total number of UART ports (invalid UART port number). */
} hal_uart_port_t;

/**
  * @}
  */

/**
 * @}
 * @} */
#endif


#ifdef HAL_I2C_MASTER_MODULE_ENABLED
#ifdef HAL_I2C_MASTER_FEATURE_EXTENDED_DMA
/**
 * @addtogroup HAL
 * @{
 * @addtogroup I2C_MASTER
 * @{
 * @section HAL_I2C_Transaction_Pattern_Chapter API transaction length and packets
 *  The Transaction packet is a packet sent by the I2C master using SCL and SDA.
 *  Different APIs have different transaction packets, as shown below.
 * - \b Transaction \b length \b supported \b by \b the \b APIs \n
 *  The total transaction length is determined by 4 parameters:\n
 *  send_packet_length(Ns), which indicates the number of sent packet.\n
 *  send_bytes_in_one_packet(Ms).\n
 *  receive_packet_length(Nr).\n
 *  receive_bytes_in_one_packet(Mr).\n
 *  Next, the relationship between transaction packet and these 4 parameters is introduced.
 *  - Total transaction length = Ns * Ms + Nr * Mr.
 *   - Ns is the packet length to be sent by the I2C master.
 *   - Ms is the total number of bytes in a sent packet.
 *   - Nr is the packet length to be received by the I2C master.
 *   - Mr is the total number of bytes in a received packet.
 *  - NA means the related parameter should be ignored.
 *  - 1~8 specifies the parameter range is from 1 to 8. 1~15 specifies the parameter range is from 1 to 15. 1~255 specifies the parameter range from 1 to 255.
 *  - 1 means the parameter value can only be 1.
 *  - Note: functions with the suffix "_ex" have these 4 parameters. Other functions only have the "size" parameter and the driver splits the "size" into these 4 parameters.
 *    #hal_i2c_master_send_polling() for example, the "size" will be divided like this: send_packet_length = 1, send_bytes_in_one_packet = size.
 *          As a result, the total size should be: send_packet_length * send_bytes_in_one_packet = 1 * size = size. The range of "size" should be from 1 to 8.
 * |API                                         |send_packet_length(Ns) | send_bytes_in_one_packet(Ms) | receive_packet_length(Nr) | receive_bytes_in_one_packet(Mr) |
 * |--------------------------------------------|-----------------------|------------------------------|---------------------------|---------------------------------|
 * |hal_i2c_master_send_polling                 |          1            |            1~8               |            NA             |                NA               |
 * |hal_i2c_master_receive_polling              |          NA           |            NA                |            1              |                1~8              |
 * |hal_i2c_master_send_to_receive_polling      |          1            |            1~8               |            1              |                1~8              |
 * |hal_i2c_master_send_dma                     |          1            |            1~15              |            NA             |                NA               |
 * |hal_i2c_master_receive_dma                  |          NA           |            NA                |            1~255          |                1                |
 * |hal_i2c_master_send_to_receive_dma          |          1            |            1~15              |            1~254          |                1                |
 * |hal_i2c_master_send_dma_ex                  |          1~255        |            1~15              |            NA             |                NA               |
 * |hal_i2c_master_receive_dma_ex               |          NA           |            NA                |            1~255          |                1~15             |
 * |hal_i2c_master_send_to_receive_dma_ex       |          1            |            1~15              |            1~254          |                1~15             |
 *
 * - \b Waveform \b pattern \b supported \b by \b the \b APIs \n
 *  The 4 parameters (send_packet_length(Ns), send_bytes_in_one_packet(Ms), receive_packet_length(Nr), receive_bytes_in_one_packet(Mr) will also affect the transaction packet.
 *  The relationship between transaction packet and these 4 parameters is shown below.
 *  - Ns is the send_packet_length.
 *  - Ms is the send_bytes_in_one_packet.
 *  - Nr is the receive_packet_length.
 *  - Mr is the receive_bytes_in_one_packet.
 * |API                                          |transaction packet format                                 |
 * |---------------------------------------------|----------------------------------------------------------|
 * | hal_i2c_master_send_polling                 |  @image html hal_i2c_send_poling_waveform.png            |
 * | hal_i2c_master_receive_polling              |  @image html hal_i2c_receive_poling_waveform.png         |
 * | hal_i2c_master_send_to_receive_polling      |  @image html hal_i2c_send_to_receive_poling_waveform.png |
 * | hal_i2c_master_send_dma                     |  @image html hal_i2c_send_dma_waveform.png            |
 * | hal_i2c_master_receive_dma                  |  @image html hal_i2c_receive_dma_waveform.png         |
 * | hal_i2c_master_send_to_receive_dma          |  @image html hal_i2c_send_to_receive_dma_waveform.png |
 * | hal_i2c_master_send_dma_ex                  |  @image html hal_i2c_send_dma_ex_waveform.png            |
 * | hal_i2c_master_receive_dma_ex               |  @image html hal_i2c_receive_dma_ex_waveform.png         |
 * | hal_i2c_master_send_to_receive_dma_ex       |  @image html hal_i2c_send_to_receive_dma_ex_waveform.png |
 *
 *
 *
 * */
#endif

/** @defgroup hal_i2c_master_define Define
 * @{
  */

/** @brief  The maximum polling mode transaction size.
  */
#define HAL_I2C_MAXIMUM_POLLING_TRANSACTION_SIZE  8

/** @brief  The maximum DMA mode transaction size.
  */
#define HAL_I2C_MAXIMUM_DMA_TRANSACTION_SIZE   15

/**
  * @}
  */

/** @addtogroup hal_i2c_master_enum Enum
  * @{
  */

/*****************************************************************************
* I2C master
*****************************************************************************/
/** @brief This enum defines the I2C port.
 *  The platform supports 3 I2C masters. Two of them support polling mode and DMA mode,
 *  while the other one only supports polling mode. For more information about the polling mode,
 *  DMA mode, queue mode, please refer to @ref HAL_I2C_Features_Chapter. The details
 *  are shown below:
 *  - Supported features of I2C masters \n
 *    V : supported;  X : not supported.
 * |I2C Master   | Polling mode | DMA mode | Extended DMA mode |
 * |-------------|--------------|----------|-------------------|
 * |I2C0         |      V       |    V     |         V         |
 * |I2C1         |      V       |    V     |         V         |
 * |I2C2         |      V       |    X     |         X         |
 *
 *
*/
typedef enum {
    HAL_I2C_MASTER_0 = 0,                /**< I2C master 0. */
    HAL_I2C_MASTER_1 = 1,                /**< I2C master 1. */
    HAL_I2C_MASTER_2 = 2,                /**< I2C master 2. */
    HAL_I2C_MASTER_MAX                   /**< The total number of I2C masters (invalid I2C master number). */
} hal_i2c_port_t;

/**
  * @}
  */

/**
 * @}
 * @} */
#endif


#ifdef HAL_GPIO_MODULE_ENABLED
/**
* @addtogroup HAL
* @{
* @addtogroup GPIO
* @{
*
* @addtogroup hal_gpio_enum Enum
* @{
*/

/*****************************************************************************
* GPIO
*****************************************************************************/
/** @brief This enum defines the GPIO port.
 *  The platform supports a total of 49 GPIO pins with various functionality.
 *
*/

typedef enum {
    HAL_GPIO_0 = 0,                            /**< GPIO pin0. */
    HAL_GPIO_1 = 1,                            /**< GPIO pin1. */
    HAL_GPIO_2 = 2,                            /**< GPIO pin2. */
    HAL_GPIO_3 = 3,                            /**< GPIO pin3. */
    HAL_GPIO_4 = 4,                            /**< GPIO pin4. */
    HAL_GPIO_5 = 5,                            /**< GPIO pin5. */
    HAL_GPIO_6 = 6,                            /**< GPIO pin6. */
    HAL_GPIO_7 = 7,                            /**< GPIO pin7. */
    HAL_GPIO_8 = 8,                            /**< GPIO pin8. */
    HAL_GPIO_9 = 9,                            /**< GPIO pin9. */
    HAL_GPIO_10 = 10,                          /**< GPIO pin10. */
    HAL_GPIO_11 = 11,                          /**< GPIO pin11. */
    HAL_GPIO_12 = 12,                          /**< GPIO pin12. */
    HAL_GPIO_13 = 13,                          /**< GPIO pin13. */
    HAL_GPIO_14 = 14,                          /**< GPIO pin14. */
    HAL_GPIO_15 = 15,                          /**< GPIO pin15. */
    HAL_GPIO_16 = 16,                          /**< GPIO pin16. */
    HAL_GPIO_17 = 17,                          /**< GPIO pin17. */
    HAL_GPIO_18 = 18,                          /**< GPIO pin18. */
    HAL_GPIO_19 = 19,                          /**< GPIO pin19. */
    HAL_GPIO_20 = 20,                          /**< GPIO pin20. */
    HAL_GPIO_21 = 21,                          /**< GPIO pin21. */
    HAL_GPIO_22 = 22,                          /**< GPIO pin22. */
    HAL_GPIO_23 = 23,                          /**< GPIO pin23. */
    HAL_GPIO_24 = 24,                          /**< GPIO pin24. */
    HAL_GPIO_25 = 25,                          /**< GPIO pin25. */
    HAL_GPIO_26 = 26,                          /**< GPIO pin26. */
    HAL_GPIO_27 = 27,                          /**< GPIO pin27. */
    HAL_GPIO_28 = 28,                          /**< GPIO pin28. */
    HAL_GPIO_29 = 29,                          /**< GPIO pin29. */
    HAL_GPIO_30 = 30,                          /**< GPIO pin30. */
    HAL_GPIO_31 = 31,                          /**< GPIO pin31. */
    HAL_GPIO_32 = 32,                          /**< GPIO pin32. */
    HAL_GPIO_33 = 33,                          /**< GPIO pin33. */
    HAL_GPIO_34 = 34,                          /**< GPIO pin34. */
    HAL_GPIO_35 = 35,                          /**< GPIO pin35. */
    HAL_GPIO_36 = 36,                          /**< GPIO pin36. */
    HAL_GPIO_37 = 37,                          /**< GPIO pin37. */
    HAL_GPIO_38 = 38,                          /**< GPIO pin38. */
    HAL_GPIO_39 = 39,                          /**< GPIO pin39. */
    HAL_GPIO_40 = 40,                          /**< GPIO pin40. */
    HAL_GPIO_41 = 41,                          /**< GPIO pin41. */
    HAL_GPIO_42 = 42,                          /**< GPIO pin42. */
    HAL_GPIO_43 = 43,                          /**< GPIO pin43. */
    HAL_GPIO_44 = 44,                          /**< GPIO pin44. */
    HAL_GPIO_45 = 45,                          /**< GPIO pin45. */
    HAL_GPIO_46 = 46,                          /**< GPIO pin46. */
    HAL_GPIO_47 = 47,                          /**< GPIO pin47. */
    HAL_GPIO_48 = 48,                          /**< GPIO pin48. */
    HAL_GPIO_MAX                               /**< The total number of GPIO pins (invalid GPIO pin number). */
} hal_gpio_pin_t;

/**
  * @}
  */

/**
 * @}
 * @} */
#endif

#ifdef HAL_GPIO_FEATURE_CLOCKOUT
/**
 * @addtogroup HAL
 * @{
 * @addtogroup GPIO
 * @{
 * @addtogroup hal_gpio_enum Enum
 * @{ */
/*****************************************************************************
* CLKOUT
*****************************************************************************/
/** @brief  This enum defines output clock number of GPIO */
typedef enum {
    HAL_GPIO_CLOCK_0   = 0,              /**< define GPIO output clock 0 */
    HAL_GPIO_CLOCK_1   = 1,              /**< define GPIO output clock 1 */
    HAL_GPIO_CLOCK_2   = 2,              /**< define GPIO output clock 2 */
    HAL_GPIO_CLOCK_3   = 3,              /**< define GPIO output clock 3 */
    HAL_GPIO_CLOCK_4   = 4,              /**< define GPIO output clock 4 */
    HAL_GPIO_CLOCK_5   = 5,              /**< define GPIO output clock 5 */
    HAL_GPIO_CLOCK_MAX                   /**< define GPIO output clock max number(invalid) */
} hal_gpio_clock_t;


/** @brief This enum defines output clock mode of GPIO */
typedef enum {
    HAL_GPIO_CLOCK_MODE_26M = 1,        /**< define GPIO output clock mode as 26MHz */
    HAL_GPIO_CLOCK_MODE_32K = 4,        /**< define GPIO output clock mode as 32KHz */
    HAL_GPIO_CLOCK_MODE_MAX             /**< define GPIO output clock mode of max number(invalid) */
} hal_gpio_clock_mode_t;
/**
  * @}
  */

/**
 * @}
 * @} */
#endif

#ifdef HAL_ADC_MODULE_ENABLED
/**
* @addtogroup HAL
* @{
* @addtogroup ADC
* @{
*
* @addtogroup hal_adc_enum Enum
* @{
*/

/*****************************************************************************
* ADC
*****************************************************************************/
/** @brief ADC channel */
typedef enum {
    HAL_ADC_CHANNEL_7 = 7,                        /**< ADC channel 7. */
    HAL_ADC_CHANNEL_8 = 8,                        /**< ADC channel 8. */
    HAL_ADC_CHANNEL_11 = 11,                      /**< ADC channel 11. */
    HAL_ADC_CHANNEL_12 = 12,                      /**< ADC channel 12. */
    HAL_ADC_CHANNEL_13 = 13,                      /**< ADC channel 13. */
    HAL_ADC_CHANNEL_14 = 14,                      /**< ADC channel 14. */
    HAL_ADC_CHANNEL_15 = 15,                      /**< ADC channel 15. */
    HAL_ADC_CHANNEL_MAX                           /**< The total number of ADC channels (invalid ADC channel).*/
} hal_adc_channel_t;

/**
  * @}
  */


/**
 * @}
 * @} */
#endif



#ifdef HAL_I2S_MODULE_ENABLED
/**
* @addtogroup HAL
* @{
* @addtogroup I2S
* @{
*
* @addtogroup hal_i2s_enum Enum
* @{
*/

/*****************************************************************************
* I2S
*****************************************************************************/
/** @brief This enum defines initial type of the I2S. */

typedef enum {
    HAL_I2S_TYPE_EXTERNAL_MODE          = 0,        /**< External mode. */
    HAL_I2S_TYPE_EXTERNAL_TDM_MODE      = 1,        /**< External TDM mode (invalid). */
    HAL_I2S_TYPE_INTERNAL_MODE          = 2,        /**< Internal mode (invalid). */
    HAL_I2S_TYPE_INTERNAL_LOOPBACK_MODE = 3         /**< Internal loopback mode. */
} hal_i2s_initial_type_t;


/** @brief I2S event */
typedef enum {
    HAL_I2S_EVENT_ERROR               = -1, /**<  An error occurred during the function call. */
    HAL_I2S_EVENT_NONE                =  0, /**<  No error occurred during the function call. */
    HAL_I2S_EVENT_OVERFLOW            =  1, /**<  RX data overflow. */
    HAL_I2S_EVENT_UNDERFLOW           =  2, /**<  TX data underflow. */
    HAL_I2S_EVENT_DATA_REQUEST        =  3, /**<  Request for user-defined data. */
    HAL_I2S_EVENT_DATA_NOTIFICATION   =  4  /**<  Notify user the RX data is ready. */
} hal_i2s_event_t;


/** @brief I2S sampling rates */
typedef enum {
    HAL_I2S_SAMPLE_RATE_8K        = 0,  /**<  8000Hz  */
    HAL_I2S_SAMPLE_RATE_11_025K   = 1,  /**<  11025Hz */
    HAL_I2S_SAMPLE_RATE_12K       = 2,  /**<  12000Hz */
    HAL_I2S_SAMPLE_RATE_16K       = 3,  /**<  16000Hz */
    HAL_I2S_SAMPLE_RATE_22_05K    = 4,  /**<  22050Hz */
    HAL_I2S_SAMPLE_RATE_24K       = 5,  /**<  24000Hz */
    HAL_I2S_SAMPLE_RATE_32K       = 6,  /**<  32000Hz */
    HAL_I2S_SAMPLE_RATE_44_1K     = 7,  /**<  44100Hz */
    HAL_I2S_SAMPLE_RATE_48K       = 8,  /**<  48000Hz */
} hal_i2s_sample_rate_t;

/**
  * @}
  */

/**
 * @}
 * @} */
#endif


#ifdef HAL_SPI_MASTER_MODULE_ENABLED
/**
 * @addtogroup HAL
 * @{
 * @addtogroup SPI_MASTER
 * @{
 * @defgroup hal_spi_master_define Define
 * @{ */

/** @brief  The maximum polling mode transaction size in bytes. */
#define HAL_SPI_MAXIMUM_POLLING_TRANSACTION_SIZE  32

/** @brief  The minimum clock frequency. */
#define  HAL_SPI_MASTER_CLOCK_MIN_FREQUENCY  30000

/** @brief  The maximum clock frequency. */
#define  HAL_SPI_MASTER_CLOCK_MAX_FREQUENCY  13000000

/**
 * @} */

/**
 * @addtogroup hal_spi_master_enum Enum
 * @{ */

/*****************************************************************************
* SPI master
*****************************************************************************/
/** @brief This enum defines the SPI master port.
 *  The chip supports total of 4 SPI master ports, each of them supports polling mode
 *  and DMA mode. For more details about polling mode and DMA mode, please refer to @ref
 *  HAL_SPI_MASTER_Features_Chapter. */
typedef enum {
    HAL_SPI_MASTER_0 = 0,                              /**< SPI master port 0. */
    HAL_SPI_MASTER_1 = 1,                              /**< SPI master port 1. */
    HAL_SPI_MASTER_2 = 2,                              /**< SPI master port 2. */
    HAL_SPI_MASTER_3 = 3,                              /**< SPI master port 3. */
    HAL_SPI_MASTER_MAX                                 /**< The total number of SPI master ports (invalid SPI master port). */
} hal_spi_master_port_t;


/** @brief This enum defines the options to connect the SPI slave device to the SPI master's CS pins. */
typedef enum {
    HAL_SPI_MASTER_SLAVE_0 = 0,                       /**< The SPI slave device is connected to the SPI master's CS0 pin. */
    HAL_SPI_MASTER_SLAVE_1 = 1,                       /**< The SPI slave device is connected to the SPI master's CS1 pin. */
    HAL_SPI_MASTER_SLAVE_MAX                          /**< The total number of SPI master CS pins (invalid SPI master CS pin). */
} hal_spi_master_slave_port_t;

/** @brief SPI master clock polarity definition. */
typedef enum {
    HAL_SPI_MASTER_CLOCK_POLARITY0 = 0,                     /**< Clock polarity is 0. */
    HAL_SPI_MASTER_CLOCK_POLARITY1 = 1                      /**< Clock polarity is 1. */
} hal_spi_master_clock_polarity_t;


/** @brief SPI master clock format definition. */
typedef enum {
    HAL_SPI_MASTER_CLOCK_PHASE0 = 0,                         /**< Clock format is 0. */
    HAL_SPI_MASTER_CLOCK_PHASE1 = 1                          /**< Clock format is 1. */
} hal_spi_master_clock_phase_t;


/** @brief SPI master transaction bit order definition. */
typedef enum {
    HAL_SPI_MASTER_LSB_FIRST = 0,                       /**< Both send and receive data transfer LSB first. */
    HAL_SPI_MASTER_MSB_FIRST = 1                        /**< Both send and receive data transfer MSB first. */
} hal_spi_master_bit_order_t;

/**
 * @} */

/**
 * @}
 * @} */
#endif

#ifdef HAL_SPI_SLAVE_MODULE_ENABLED
/**
 * @addtogroup HAL
 * @{
 * @addtogroup SPI_SLAVE
 * @{
 * @addtogroup hal_spi_slave_enum Enum
 * @{ */

/*****************************************************************************
* SPI slave
*****************************************************************************/
/** @brief This enum defines the SPI slave port. This chip supports only one
 *  SPI slave port. */
typedef enum {
    HAL_SPI_SLAVE_0 = 0,                             /**< SPI slave port 0. */
    HAL_SPI_SLAVE_MAX                                /**< The total number of SPI slave ports (invalid SPI slave port number). */
} hal_spi_slave_port_t;

/** @brief SPI slave transaction bit order definition. */
typedef enum {
    HAL_SPI_SLAVE_LSB_FIRST = 0,                       /**< Both send and receive data transfer is the LSB first. */
    HAL_SPI_SLAVE_MSB_FIRST = 1                        /**< Both send and receive data transfer is the MSB first. */
} hal_spi_slave_bit_order_t;

/** @brief SPI slave clock polarity definition. */
typedef enum {
    HAL_SPI_SLAVE_CLOCK_POLARITY0 = 0,                 /**< Clock polarity is 0. */
    HAL_SPI_SLAVE_CLOCK_POLARITY1 = 1                  /**< Clock polarity is 1. */
} hal_spi_slave_clock_polarity_t;


/** @brief SPI slave clock format definition. */
typedef enum {
    HAL_SPI_SLAVE_CLOCK_PHASE0 = 0,                    /**< Clock format is 0. */
    HAL_SPI_SLAVE_CLOCK_PHASE1 = 1                     /**< Clock format is 1. */
} hal_spi_slave_clock_phase_t;

/** @brief This enum defines the SPI slave event when an interrupt occurs. */
typedef enum {
    HAL_SPI_SLAVE_EVENT_POWER_ON = SPISLV_IRQ_POWERON_IRQ_MASK,       /**< Power on command is received. */
    HAL_SPI_SLAVE_EVENT_POWER_OFF = SPISLV_IRQ_POWEROFF_IRQ_MASK,     /**< Power off command is received. */
    HAL_SPI_SLAVE_EVENT_CRD_FINISH = SPISLV_IRQ_CRD_FINISH_IRQ_MASK,  /**< Configure read command is received. */
    HAL_SPI_SLAVE_EVENT_RD_FINISH = SPISLV_IRQ_RD_FINISH_IRQ_MASK,    /**< Read command is received. */
    HAL_SPI_SLAVE_EVENT_CWR_FINISH = SPISLV_IRQ_CWR_FINISH_IRQ_MASK,  /**< Configure write command is received. */
    HAL_SPI_SLAVE_EVENT_WR_FINISH = SPISLV_IRQ_WR_FINISH_IRQ_MASK,    /**< Write command is received. */
    HAL_SPI_SLAVE_EVENT_RD_ERR = SPISLV_IRQ_RD_ERR_IRQ_MASK,          /**< An error occurred during a read command. */
    HAL_SPI_SLAVE_EVENT_WR_ERR = SPISLV_IRQ_WR_ERR_IRQ_MASK,          /**< An error occurred during a write command. */
    HAL_SPI_SLAVE_EVENT_TIMEOUT_ERR = SPISLV_IRQ_TIMEOUT_ERR_IRQ_MASK /**< A timeout is detected between configure read command and read command or configure write command and write command. */
} hal_spi_slave_callback_event_t;

/** @brief This enum defines the SPI slave commands. */
typedef enum {
    HAL_SPI_SLAVE_CMD_WS        = 0,       /**< Write Status command. */
    HAL_SPI_SLAVE_CMD_RS        = 1,       /**< Read Status command. */
    HAL_SPI_SLAVE_CMD_WR        = 2,       /**< Write Data command. */
    HAL_SPI_SLAVE_CMD_RD        = 3,       /**< Read Data command. */
    HAL_SPI_SLAVE_CMD_POWEROFF  = 4,       /**< POWER OFF command. */
    HAL_SPI_SLAVE_CMD_POWERON   = 5,       /**< POWER ON command. */
    HAL_SPI_SLAVE_CMD_CW        = 6,       /**< Configure Write command. */
    HAL_SPI_SLAVE_CMD_CR        = 7        /**< Configure Read command. */
} hal_spi_slave_command_type_t;

/**
 * @} */


/**
 * @}
 * @} */
#endif


#ifdef HAL_RTC_MODULE_ENABLED
/**
 * @addtogroup HAL
 * @{
 * @addtogroup RTC
 * @{
 * @addtogroup hal_rtc_define Define
 * @{ */

/*****************************************************************************
* rtc
*****************************************************************************/
/** @brief  This macro defines a maximum number for backup data that used in #hal_rtc_set_data(),
  * #hal_rtc_get_data(), #hal_rtc_clear_data() functions.
  */
#define HAL_RTC_BACKUP_BYTE_NUM_MAX     (13)

/**
  * @}
  */

/** @defgroup hal_rtc_struct Struct
  * @{
  */

/** @brief RTC time structure definition. */
typedef struct {
    uint8_t rtc_sec;                                  /**< Seconds after minutes   - [0,59]  */
    uint8_t rtc_min;                                  /**< Minutes after the hour  - [0,59]  */
    uint8_t rtc_hour;                                 /**< Hours after midnight    - [0,23]  */
    uint8_t rtc_day;                                  /**< Day of the month        - [1,31]  */
    uint8_t rtc_mon;                                  /**< Months                  - [1,12]  */
    uint8_t rtc_week;                                 /**< Days in a week          - [0,6]   */
    uint8_t rtc_year;                                 /**< Years                   - [0,127] */
} hal_rtc_time_t;
/**
  * @}
  */

/**
 * @defgroup hal_rtc_enum Enum
 * @{ */

/** @brief RTC current time change notification period selections. */
typedef enum {
    HAL_RTC_TIME_NOTIFICATION_NONE = 0,                     /**< No need for a time notification. */
    HAL_RTC_TIME_NOTIFICATION_EVERY_SECOND = 1,             /**< Execute a callback function set by #hal_rtc_set_time_notification_period() for every second. */
    HAL_RTC_TIME_NOTIFICATION_EVERY_MINUTE = 2,             /**< Execute a callback function set by #hal_rtc_set_time_notification_period() for every minute. */
    HAL_RTC_TIME_NOTIFICATION_EVERY_HOUR = 3,               /**< Execute a callback function set by #hal_rtc_set_time_notification_period() for every hour. */
    HAL_RTC_TIME_NOTIFICATION_EVERY_DAY = 4,                /**< Execute a callback function set by #hal_rtc_set_time_notification_period() for every day. */
    HAL_RTC_TIME_NOTIFICATION_EVERY_MONTH = 5,              /**< Execute a callback function set by #hal_rtc_set_time_notification_period() for every month. */
    HAL_RTC_TIME_NOTIFICATION_EVERY_YEAR = 6,               /**< Execute a callback function set by #hal_rtc_set_time_notification_period() for every year. */
    HAL_RTC_TIME_NOTIFICATION_EVERY_SECOND_1_2 = 7,         /**< Execute a callback function set by #hal_rtc_set_time_notification_period() for every one-half of a second. */
    HAL_RTC_TIME_NOTIFICATION_EVERY_SECOND_1_4 = 8,         /**< Execute a callback function set by #hal_rtc_set_time_notification_period() for every one-fourth of a second. */
    HAL_RTC_TIME_NOTIFICATION_EVERY_SECOND_1_8 = 9          /**< Execute a callback function set by #hal_rtc_set_time_notification_period() for every one-eighth of a second. */
} hal_rtc_time_notification_period_t;

/**
 * @} */

/**
 * @}
 * @} */
#endif


#ifdef HAL_EINT_MODULE_ENABLED
/**
 * @addtogroup HAL
 * @{
 * @addtogroup EINT
 * @{
 * @addtogroup hal_eint_enum Enum
 * @{ */

/*****************************************************************************
* EINT
*****************************************************************************/
/** @brief EINT pins. */
typedef enum {
    HAL_EINT_NUMBER_0 = 0,
    HAL_EINT_NUMBER_1 = 1,
    HAL_EINT_NUMBER_2 = 2,
    HAL_EINT_NUMBER_3 = 3,
    HAL_EINT_NUMBER_4 = 4,
    HAL_EINT_NUMBER_5 = 5,
    HAL_EINT_NUMBER_6 = 6,
    HAL_EINT_NUMBER_7 = 7,
    HAL_EINT_NUMBER_8 = 8,
    HAL_EINT_NUMBER_9 = 9,
    HAL_EINT_NUMBER_10 = 10,
    HAL_EINT_NUMBER_11 = 11,
    HAL_EINT_NUMBER_12 = 12,
    HAL_EINT_NUMBER_13 = 13,
    HAL_EINT_NUMBER_14 = 14,
    HAL_EINT_NUMBER_15 = 15,
    HAL_EINT_NUMBER_16 = 16,
    HAL_EINT_NUMBER_17 = 17,
    HAL_EINT_NUMBER_18 = 18,
    HAL_EINT_NUMBER_19 = 19,
    HAL_EINT_KEYPAD    = 20,      /**< EINT number 20:  Keypad. */
    HAL_EINT_UART_0_RX = 21,      /**< EINT number 21:  UART0 RX. */
    HAL_EINT_UART_1_RX = 22,      /**< EINT number 22:  UART1 RX. */
    HAL_EINT_UART_2_RX = 23,      /**< EINT number 23:  UART2 RX. */
    HAL_EINT_UART_3_RX = 24,      /**< EINT number 24:  BTSYS. */
    HAL_EINT_BTSYS     = 25,      /**< EINT number 25:  BTSYS BTIF. */
    HAL_EINT_BTSYS_BTIF = 26,     /**< EINT number 26:  UART3 RX. */
    HAL_EINT_USB       = 27,      /**< EINT number 27:  USB. */
    HAL_EINT_ACCDET    = 28,      /**< EINT number 28:  ACCDET. */
    HAL_EINT_RTC       = 29,      /**< EINT number 29:  RTC. */
    HAL_EINT_PMIC      = 30,      /**< EINT number 30:  PMIC. */
    HAL_EINT_GPCOUNTER = 31,      /**< EINT number 31:  GPCOUNTER. */
    HAL_EINT_NUMBER_MAX           /**< The total number of EINT channels (invalid EINT channel). */
} hal_eint_number_t;

/**
  * @}
  */
/**
 * @}
 * @} */
#endif

#ifdef HAL_GPT_MODULE_ENABLED
/**
 * @addtogroup HAL
 * @{
 * @addtogroup GPT
 * @{
 * @addtogroup hal_gpt_enum Enum
 * @{ */

/*****************************************************************************
* GPT
*****************************************************************************/
/** @brief GPT port */
typedef enum {
    HAL_GPT_0 = 0,                          /**< GPT port 0: Used for OSTD timer. */
    HAL_GPT_1 = 1,                          /**< GPT port 1: User defined. */
    HAL_GPT_2 = 2,                          /**< GPT port 2: User defined. */
    HAL_GPT_3 = 3,                          /**< GPT port 3: Used for software GPT. The clock source is 32Khz. */
    HAL_GPT_4 = 4,                          /**< GPT port 4: Use to set a microsecond delay and get microsecond free count. The clock source is 1Mhz*/
    HAL_GPT_5 = 5,                          /**< GPT port 5: Use to set a millisecond delay and get 1/32Khz free count. The clock source is 32Khz */
    HAL_GPT_MAX_PORT                        /**< The total number of GPT ports (invalid GPT port). */
} hal_gpt_port_t;

/** @brief GPT clock source */
typedef enum {
    HAL_GPT_CLOCK_SOURCE_32K = 0,            /**< Set the GPT clock source to 32kHz, 1 tick = 1/32768 seconds. */
    HAL_GPT_CLOCK_SOURCE_1M  = 1             /**< Set the GPT clock source to 1MHz, 1 tick = 1 microsecond.*/
} hal_gpt_clock_source_t;

/** @brief  The maximum time of millisecond timer.
  */
#define HAL_GPT_MAXIMUM_MS_TIMER_TIME    (130150523)

/**
  * @}
  */
/**
 * @}
 * @} */
#endif

#ifdef HAL_FLASH_MODULE_ENABLED
/**
 * @addtogroup HAL
 * @{
 * @addtogroup FLASH
 * @{ */

/*****************************************************************************
* Flash
*****************************************************************************/

/** @defgroup hal_flash_define Define
 * @{
  */

 /** @brief  This macro defines the Flash base address.
   */
#define HAL_FLASH_BASE_ADDRESS    (0x08000000)


/**
 * @}
 * @} */
#endif

#ifdef HAL_GDMA_MODULE_ENABLED
/**
 * @addtogroup HAL
 * @{
 * @addtogroup GDMA
 * @{
 * @addtogroup hal_gdma_enum Enum
 * @{ */
/*****************************************************************************
* GDMA
*****************************************************************************/
/** @brief gdma channel */
typedef enum {
    HAL_GDMA_CHANNEL_0 = 0,                        /**< GDMA channel 0. */
    HAL_GDMA_CHANNEL_MAX                           /**< The total number of GDMA channels (invalid GDMA channel). */
} hal_gdma_channel_t;

/**
  * @}
  */


/**
 * @}
 * @} */
#endif

#ifdef HAL_PWM_MODULE_ENABLED
/**
 * @addtogroup HAL
 * @{
 * @addtogroup PWM
 * @{
 * @addtogroup hal_pwm_enum Enum
 * @{ */
/*****************************************************************************
* PWM
*****************************************************************************/
/** @brief The PWM channels */
typedef enum {
    HAL_PWM_0 = 0,                            /**< PWM channel 0. */
    HAL_PWM_1 = 1,                            /**< PWM channel 1. */
    HAL_PWM_2 = 2,                            /**< PWM channel 2. */
    HAL_PWM_3 = 3,                            /**< PWM channel 3. */
    HAL_PWM_4 = 4,                            /**< PWM channel 4. */
    HAL_PWM_5 = 5,                            /**< PWM channel 5. */
    HAL_PWM_MAX_CHANNEL                     /**< The total number of PWM channels (invalid PWM channel).*/
} hal_pwm_channel_t;


/** @brief PWM clock source options */
typedef enum {
    HAL_PWM_CLOCK_13MHZ = 0,                /**< PWM clock source 13MHz. */
    HAL_PWM_CLOCK_32KHZ = 1,                /**< PWM clock srouce 32kHz. */
} hal_pwm_source_clock_t ;

/**
  * @}
  */
/**
 * @}
 * @} */
#endif

#ifdef HAL_WDT_MODULE_ENABLED
/**
 * @addtogroup HAL
 * @{
 * @addtogroup WDT
 * @{
 * @addtogroup hal_wdt_define Define
 * @{ */

/*****************************************************************************
* WDT
*****************************************************************************/
/** @brief  Define the platform related WDT restart address and magic number.
  */
#define WDT_RESTART_ADDRESS    (0xA2050008)
#define WDT_RESTART_KEY        (0x1971)

/**
 * @} */

/**
 * @}
 * @} */
#endif

#ifdef HAL_CACHE_MODULE_ENABLED
/**
 * @addtogroup HAL
 * @{
 * @addtogroup CACHE
 * @{ */

/*****************************************************************************
* Cache
*****************************************************************************/
/* NULL */

/**
 * @}
 * @} */
#endif

#ifdef HAL_GPC_MODULE_ENABLED
/**
 * @addtogroup HAL
 * @{
 * @addtogroup GPC
 * @{
 * @addtogroup hal_gpc_enum Enum
 * @{ */
/** @brief GPC port */
typedef enum {
    HAL_GPC_0 = 0,                          /**< GPC port 0. */
    HAL_GPC_MAX_PORT                        /**< The total number of GPC ports (invalid GPC port). */
} hal_gpc_port_t;


/**
  * @}
  */
/**
 * @}
 * @} */
#endif


#ifdef HAL_SD_MODULE_ENABLED
/**
 * @addtogroup HAL
 * @{
 * @addtogroup SD
 * @{
 * @addtogroup hal_sd_enum Enum
 * @{ */
/*****************************************************************************
* SD
*****************************************************************************/
/** @brief  This enum defines the SD/eMMC port. */
typedef enum {
    HAL_SD_PORT_0 = 0,                                             /**<  SD/eMMC port 0. */
    HAL_SD_PORT_1 = 1                                              /**<  SD/eMMC port 1. */
} hal_sd_port_t;

/**
  * @}
  */
/**
 * @}
 * @} */
#endif


#ifdef HAL_SDIO_MODULE_ENABLED
/**
 * @addtogroup HAL
 * @{
 * @addtogroup SDIO
 * @{
 * @addtogroup hal_sdio_enum Enum
 * @{ */
/*****************************************************************************
* SDIO
*****************************************************************************/
/** @brief  This enum defines the SDIO port.  */
typedef enum {
    HAL_SDIO_PORT_0 = 0,                                             /**< SDIO port 0. */
    HAL_SDIO_PORT_1 = 1                                              /**< SDIO port 1. */
} hal_sdio_port_t;

/**
  * @}
  */
/**
 * @}
 * @} */
#endif

#ifdef HAL_CLOCK_MODULE_ENABLED
#include "hal_pmu_internal.h"

/*****************************************************************************
* Clock
*****************************************************************************/

/**
 * @addtogroup HAL
 * @{
 * @addtogroup CLOCK
 * @{
 * @addtogroup CLOCK_GATE Clock Gate
 * @{
 *
 * @section CLOCK_CG_ID_Usage_Chapter HAL_CLOCK_CG_ID descriptions
 *
 * Each #hal_clock_cg_id is related to one CG. Please check the following parameters before controlling the clock.
 *
 * The description of API parameters for HAL_CLOCK_CG_ID is listed below:
 * | HAL_CLOCK_CG_ID            |Details                                                                            |
 * |----------------------------|-----------------------------------------------------------------------------------|
 * |\b HAL_CLOCK_CG_BT_26M      | The CG for crystal oscillator to Bluetooth. It is controlled in Bluetooth library.|
 * |\b HAL_CLOCK_CG_BT_BUSCK    | The CG for AHB bus to Bluetooth. It is controlled in Bluetooth library.|
 * |\b HAL_CLOCK_CG_BT_N9       | The CG for Bluetooth coprocessor. It is controlled in Bluetooth library.|
 * |\b HAL_CLOCK_CG_BUS         | The CG for system bus. It cannot be disabled, otherwise the system will fail.|
 * |\b HAL_CLOCK_CG_CM          | The CG for Cortex-M4. It cannot be disabled, otherwise the system will fail.|
 * |\b HAL_CLOCK_CG_DMA         | The CG for DMA. It is controlled in DMA driver.|
 * |\b HAL_CLOCK_CG_USB48M      | The CG for USB MAC. It is controlled in USB driver.|
 * |\b HAL_CLOCK_CG_MSDC0       | The CG for MSDC0. It is controlled in MSDC driver.|
 * |\b HAL_CLOCK_CG_I2C2        | The CG for I2C2. It is controlled in I2C driver.|
 * |\b HAL_CLOCK_CG_CM4_OSTIMER | The CG for OS timer. It cannot be disabled, otherwise the system will fail.|
 * |\b HAL_CLOCK_CG_DMA_AO      | The CG for DMA. It is controlled in DMA driver.|
 * |\b HAL_CLOCK_CG_UART0       | The CG for UART0. It cannot be disabled, otherwise the system will fail.|
 * |\b HAL_CLOCK_CG_UART1       | The CG for UART1. It is controlled in UART driver.|
 * |\b HAL_CLOCK_CG_UART2       | The CG for UART2. It is controlled in UART driver.|
 * |\b HAL_CLOCK_CG_UART3       | The CG for UART3. It is controlled in UART driver.|
 * |\b HAL_CLOCK_CG_SPISLV      | The CG for SPI slave. This CG should be enabled when it is connected to the master device if choosing a custom driver.|
 * |\b HAL_CLOCK_CG_SPI0        | The CG for SPI master 0. It is controlled in SPI driver.|
 * |\b HAL_CLOCK_CG_SPI1        | The CG for SPI master 1. It is controlled in SPI driver.|
 * |\b HAL_CLOCK_CG_SPI2        | The CG for SPI master 2. It is controlled in SPI driver.|
 * |\b HAL_CLOCK_CG_SPI3        | The CG for SPI master 3. It is controlled in SPI driver.|
 * |\b HAL_CLOCK_CG_PWM0        | The CG for PWM0. It is controlled in PWM driver.|
 * |\b HAL_CLOCK_CG_BTIF        | The CG for BTIF (an APB slave which transmits or receives data through DMA/VFIFO.). It is controlled in Bluetooth library.|
 * |\b HAL_CLOCK_CG_GPTIMER     | The clock for general purpose timer. It cannot be disabled, otherwise the system will fail.|
 * |\b HAL_CLOCK_CG_PWM1        | The CG for PWM1. It is controlled in PWM driver.|
 * |\b HAL_CLOCK_CG_CM_SYSROM   | The clock for system ROM. It cannot be disabled, otherwise the system will fail.|
 * |\b HAL_CLOCK_CG_SFC         | The clock for serial flash controller. It cannot be disabled, otherwise the system will fail.|
 * |\b HAL_CLOCK_CG_MSDC1       | The CG for MSDC1. It is controlled in MSDC driver.|
 * |\b HAL_CLOCK_CG_USB_DMA     | The CG for USB DMA. It is controlled in USB driver.|
 * |\b HAL_CLOCK_CG_USB_BUS     | The CG for USB bus. It is controlled in USB driver.|
 * |\b HAL_CLOCK_CG_DISP_PWM    | The CG for the PWM signal to LCM module. It is controlled in display driver.|
 * |\b HAL_CLOCK_CG_TRNG        | The CG for TRNG. It is controlled in TRNG driver.|
 * |\b HAL_CLOCK_CG_PWM2        | The CG for PWM2. It is controlled in PWM driver.|
 * |\b HAL_CLOCK_CG_PWM3        | The CG for PWM3. It is controlled in PWM driver.|
 * |\b HAL_CLOCK_CG_PWM4        | The CG for PWM4. It is controlled in PWM driver.|
 * |\b HAL_CLOCK_CG_PWM5        | The CG for PWM5. It is controlled in PWM driver.|
 * |\b HAL_CLOCK_CG_LCD         | The CG for LCD engine which processes the buffer and generates the output signal to DBI/DSI interface. It is controlled in display driver.|
 * |\b HAL_CLOCK_CG_G2D         | The CG for G2D. It is controlled in G2D driver.|
 * |\b HAL_CLOCK_CG_MM_COLOR    | The CG for color engine which adjusts the sharpness, contrast and saturation for display quality.  It is controlled in display driver.|
 * |\b HAL_CLOCK_CG_DSI0        | The CG for DSI module which processes DSI signal and outputs to LCM module. It is controlled in display driver.|
 * |\b HAL_CLOCK_CG_LCD_APB     | The CG for AHB to LCD engine. It is controlled in display driver.|
 * |\b HAL_CLOCK_CG_AUXADC      | The CG for ADC. It is controlled in ADC driver.|
 * |\b HAL_CLOCK_CG_SENSOR_DMA  | The clock for sensor DMA. This clock should be enabled when using I2C0 or I2C1 with custom driver.|
 * |\b HAL_CLOCK_CG_I2C1        | The CG for I2C1. It is controlled in I2C driver.|
 * |\b HAL_CLOCK_CG_I2C0        | The CG for I2C0. It is controlled in I2C driver.| */
/** @brief Use hal_clock_cg_id in Clock API. */
/*************************************************************************
 * Define clock gating registers and bit structure.
 * Note: Mandatory, modify clk_cg_mask in hal_clock.c source file, if hal_clock_cg_id has changed.
 *************************************************************************/
typedef enum {
    /* NR_PDN_COND0 = 7 */
    HAL_CLOCK_CG_BT_26M          =  9,        /* bit 9,   PDN_COND0_FROM */
    HAL_CLOCK_CG_CAMINF48M       = 10,        /* bit 10,  */
    HAL_CLOCK_CG_BT_BUSCK        = 13,        /* bit 13,  */
    HAL_CLOCK_CG_BT_N9           = 15,        /* bit 15,  */
    HAL_CLOCK_CG_BUS             = 20,        /* bit 20,  */
    HAL_CLOCK_CG_CM              = 21,        /* bit 21,  */
    HAL_CLOCK_CG_BSI             = 23,        /* bit 23,  PDN_COND0_TO */

    /* NR_PDN_COND1 = 17 */
    HAL_CLOCK_CG_SEJ             =  0 + 32,   /* bit 0,   PDN_COND1_FROM */
    HAL_CLOCK_CG_DMA             =  1 + 32,   /* bit 1,   */
    HAL_CLOCK_CG_USB48M          =  2 + 32,   /* bit 2,   */
    HAL_CLOCK_CG_MSDC0           =  3 + 32,   /* bit 3,   */
    HAL_CLOCK_CG_I2C_D2D         =  6 + 32,   /* bit 6,   */
    HAL_CLOCK_CG_I2C2            =  7 + 32,   /* bit 7,   */
    HAL_CLOCK_CG_CM4_OSTIMER     = 10 + 32,   /* bit 10,  */
    HAL_CLOCK_CG_DMA_AO          = 12 + 32,   /* bit 12,  */
    HAL_CLOCK_CG_UART0           = 13 + 32,   /* bit 13,  */
    HAL_CLOCK_CG_UART1           = 14 + 32,   /* bit 14,  */
    HAL_CLOCK_CG_UART2           = 15 + 32,   /* bit 15,  */
    HAL_CLOCK_CG_UART3           = 16 + 32,   /* bit 16,  */
    HAL_CLOCK_CG_SPISLV          = 19 + 32,   /* bit 19,  */
    HAL_CLOCK_CG_SPI0            = 20 + 32,   /* bit 20,  */
    HAL_CLOCK_CG_SPI1            = 21 + 32,   /* bit 21,  */
    HAL_CLOCK_CG_SPI2            = 22 + 32,   /* bit 22,  */
    HAL_CLOCK_CG_SPI3            = 23 + 32,   /* bit 23,  PDN_COND1_TO */

    /* NR_PDN_COND2 = 18 */
    HAL_CLOCK_CG_PWM0            =  0 + 64,   /* bit 0,   PDN_COND2_FROM */
    HAL_CLOCK_CG_BTIF            =  1 + 64,   /* bit 1,   */
    HAL_CLOCK_CG_GPTIMER         =  2 + 64,   /* bit 2,   */
    HAL_CLOCK_CG_GPCOUNTER       =  3 + 64,   /* bit 3,   */
    HAL_CLOCK_CG_PWM1            =  4 + 64,   /* bit 4,   */
    HAL_CLOCK_CG_EFUSE           =  6 + 64,   /* bit 6,   */
    HAL_CLOCK_CG_LPM             =  7 + 64,   /* bit 7,   */
    HAL_CLOCK_CG_CM_SYSROM       =  8 + 64,   /* bit 8,   */
    HAL_CLOCK_CG_SFC             =  9 + 64,   /* bit 9,   */
    HAL_CLOCK_CG_MSDC1           = 10 + 64,   /* bit 10,  */
    HAL_CLOCK_CG_USB_DMA         = 12 + 64,   /* bit 12,  */
    HAL_CLOCK_CG_USB_BUS         = 13 + 64,   /* bit 13,  */
    HAL_CLOCK_CG_DISP_PWM        = 14 + 64,   /* bit 14,  */
    HAL_CLOCK_CG_TRNG            = 16 + 64,   /* bit 16,  */
    HAL_CLOCK_CG_PWM2            = 19 + 64,   /* bit 19,  */
    HAL_CLOCK_CG_PWM3            = 20 + 64,   /* bit 20,  */
    HAL_CLOCK_CG_PWM4            = 21 + 64,   /* bit 21,  */
    HAL_CLOCK_CG_PWM5            = 22 + 64,   /* bit 22,  PDN_COND2_TO */

    /* NR_CM_PDN_COND0 = 10 */
    HAL_CLOCK_CG_LCD             =  0 + 96,   /* bit 0,   CM_PDN_COND0_FROM */
    HAL_CLOCK_CG_RESEIZER        =  1 + 96,   /* bit 1,   */
    HAL_CLOCK_CG_ROTDMA          =  2 + 96,   /* bit 2,   */
    HAL_CLOCK_CG_CAM_BCLK        =  3 + 96,   /* bit 3,   */
    HAL_CLOCK_CG_PAD2CAM         =  4 + 96,   /* bit 4,   */
    HAL_CLOCK_CG_G2D             =  5 + 96,   /* bit 5,   */
    HAL_CLOCK_CG_MM_COLOR        =  6 + 96,   /* bit 6,   */
    HAL_CLOCK_CG_AAL             =  7 + 96,   /* bit 7,   */
    HAL_CLOCK_CG_DSI0            =  8 + 96,   /* bit 8,   */
    HAL_CLOCK_CG_LCD_APB         =  9 + 96,   /* bit 9,   CM_PDN_COND0_TO */

    /* NR_ACFG_CLK_RG = 5 */
    HAL_CLOCK_CG_AUXADC          =  2 + 128,  /* bit 2,   ACFG_CLK_RG_FROM */
    HAL_CLOCK_CG_GPDAC           =  6 + 128,  /* bit 6,   */
    HAL_CLOCK_CG_SENSOR_DMA      =  8 + 128,  /* bit 8,   */
    HAL_CLOCK_CG_I2C1            =  9 + 128,  /* bit 9,   */
    HAL_CLOCK_CG_I2C0            = 10 + 128,  /* bit 10,  ACFG_CLK_RG_TO */
} hal_clock_cg_id;

/**
  * @}
  */

/**
 * @}
 * @} */
#endif

#ifdef __cplusplus
}
#endif

#endif /* __HAL_PLATFORM_H__ */

