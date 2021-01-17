/* Copyright Statement:
 *
 */

#ifndef __HAL_I2C_PMIC_H__
#define __HAL_I2C_PMIC_H__



#include "hal_platform.h"


#ifdef __cplusplus
extern "C" {
#endif


/*****************************************************************************
* Enum
*****************************************************************************/

/** @defgroup hal_i2c_master_enum Enum
  * @{
  */

/** @brief This enum defines the pmic i2c master
  */
typedef enum {
    PMIC_I2C_MASTER = 0,               /**<  PMIC I2C master */
    PMIC_I2C_MASTER_MAX
} pmic_i2c_port_t;


/** @brief This enum define the pmic status. */
typedef enum {
    PMIC_I2C_STATUS_ACK_ERROR = -105,
    PMIC_I2C_STATUS_NACK_ERROR = -104,
    PMIC_I2C_STATUS_ERROR = -103,
    PMIC_I2C_STATUS_INVALID_PORT_NUMBER = -102,
    PMIC_I2C_STATUS_INVALID_PARAMETER = -101,
    PMIC_I2C_STATUS_OK = 0
} pmic_i2c_status_t;



/**
  * @}
  */

/*****************************************************************************
* Structure
*****************************************************************************/

/** @defgroup hal_i2c_master_struct Struct
  * @{
  */


/** @brief This structure define the config parameter to initialize an I2C master.  */
typedef struct {
    uint32_t transfer_frequency;             /**< 50 mean 50Kbps, 400 mean 400Kbps */
} pmic_i2c_config_t;

typedef struct {
    uint8_t slave_address;                     /**<  slave device address. */
    const uint8_t *send_data;                  /**<  the data buffer to be sent. */
    uint32_t send_length;                      /**<   the length of data to send. */
    uint8_t *receive_buffer;                   /**<  the data buffer to receive. */
    uint32_t receive_length;                     /**<  the length of data to receive. */
} pmic_i2c_send_to_receive_config_t;


/**
  * @}
  */

/*****************************************************************************
* Function
*****************************************************************************/


/**
 * @brief Initialize the I2C master before starting a transaction.
 * @param[in] i2c_port Is the I2C master port number. The value is defined in #hal_i2c_port_t.
 * @param[in] i2c_config Is the config parameter for initializing I2C. Details are described at #hal_i2c_config_t.
 * @return #HAL_I2C_STATUS_INVALID_PORT_NUMBER means an invalid port number is given; \n
 *         #HAL_I2C_STATUS_INVALID_PARAMETER means an invalid transfer_frequency is given; \n
 *         #HAL_I2C_STATUS_OK means this function completed successfully.
 * @note   #hal_i2c_master_deinit must be called when you don't use I2C, or the I2C resource will not be released and other users cannot
 *         use this I2C master.
 * @par       Example
 *    Sample code please refer to @ref HAL_I2C_Driver_Usage_Chapter
 * @sa #hal_i2c_master_deinit */
pmic_i2c_status_t pmic_i2c_init(pmic_i2c_port_t  i2c_port, const pmic_i2c_config_t *i2c_config);

/**
 * @brief Release the I2C master after the transaction is over. User must call this function if I2C is no longer in use.
 * @param[in] i2c_port is the I2C master port number. the value is defined in #hal_i2c_port_t.
 * @return  #HAL_I2C_STATUS_INVALID_PORT_NUMBER means an invalid port number is given�� \n
 *          #HAL_I2C_STATUS_OK means this function completed successfully.
 * @note   This function must be called when you don't use I2C, or the I2C resource will not be released and other users can
 *         not use this I2C master.
 * @par       Example
 *    Sample code please refer to @ref HAL_I2C_Driver_Usage_Chapter
 * @sa #hal_i2c_master_init */
pmic_i2c_status_t pmic_i2c_send_polling(pmic_i2c_port_t  i2c_port, uint8_t slave_address, const uint8_t *data, uint32_t size);



/**
 * @brief Set the transaction speed separately. User can use this function to change the transaction speed without using #hal_i2c_master_init.
 * @param[in] i2c_port is the I2C master port number. the value is defined in #hal_i2c_port_t.
 * @param[in] speed is an enum value defined in #hal_i2c_frequency_t. Don't use other value except #hal_i2c_frequency_t.
 * @return   #HAL_I2C_STATUS_INVALID_PORT_NUMBER means an invalid port number is given; \n
 *           #HAL_I2C_STATUS_INVALID_PARAMETER means an invalid speed is given; \n
 *           #HAL_I2C_STATUS_OK means this function completed successfully.
 * @par       Example
 * @code
 *       ret = hal_i2c_master_config_speed(HAL_I2C_MASTER_1,HAL_I2C_SPEED_400K);
 * @endcode
 * @sa #hal_i2c_master_init */
pmic_i2c_status_t pmic_i2c_receive_polling(pmic_i2c_port_t i2c_port, uint8_t slave_address, uint8_t *buffer, uint32_t size);


/**
 * @brief Set the transaction speed separately. User can use this function to change the transaction speed without using #hal_i2c_master_init.
 * @param[in] i2c_port is the I2C master port number. the value is defined in #hal_i2c_port_t.
 * @param[in] speed is an enum value defined in #hal_i2c_frequency_t. Don't use other value except #hal_i2c_frequency_t.
 * @return   #HAL_I2C_STATUS_INVALID_PORT_NUMBER means an invalid port number is given; \n
 *           #HAL_I2C_STATUS_INVALID_PARAMETER means an invalid speed is given; \n
 *           #HAL_I2C_STATUS_OK means this function completed successfully.
 * @par       Example
 * @code
 *       ret = hal_i2c_master_config_speed(HAL_I2C_MASTER_1,HAL_I2C_SPEED_400K);
 * @endcode
 * @sa #hal_i2c_master_init */
pmic_i2c_status_t pmic_i2c_send_to_receive_polling(pmic_i2c_port_t i2c_port, pmic_i2c_send_to_receive_config_t *i2c_send_to_receive_config);



#ifdef __cplusplus
}
#endif

/**
* @}
* @}
*/

#endif /* __HAL_I2C_MASTER_H__ */
