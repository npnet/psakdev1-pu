/* Copyright Statement:
 *
 */

#include "hal_platform.h"

#ifndef __HAL_DISPLAY_PWM_H__
#define __HAL_DISPLAY_PWM_H__

#ifdef HAL_DISPLAY_PWM_MODULE_ENABLED
/**
 * @addtogroup HAL
 * @{
 * @addtogroup DISPLAY_PWM
 * @{
 * This section introduces the display PWM APIs including terms and acronyms,
 * supported features, software architecture, details on how to use this API, PWM function groups, all enumerations, structures and functions.
 *
 * @section DISPLAY_PWM_Terms_Chapter Terms and acronyms
 *
 * |Terms                   |Details                                                                 |
 * |------------------------------|------------------------------------------------------------------------|
 * |\b PWM                  |Pulse-width modulation is a modulation technique to encode a message into a pulsing signal. The duty cycle percentage for backlight brightness is used. For more information, please refer to <a href="https://en.wikipedia.org/wiki/Pulse-width_modulation"> Pulse-width modulation </a> and <a href="https://en.wikipedia.org/wiki/Duty_cycle"> Duty cycle </a> in Wikipedia.
 *
 * @section DISPLAY_PWMFeatures_Chapter Supported features
 *
 * - \b Support \b 26MHz \b and \b 104MHz \b input clock. \n
 *   The input clock can be set to 26MHz or 104MHz
 *  - \b 26MHz : If the input clock is set to 26MHz, the PWM output clock will be 25.39KHz (26MHz/1024).
 *  - \b 104MHz : If the input clock is set to 104MHz, the PWM output clock will be 101.5KHz (104MHz/1024).
 *
 * - \b Support \b 10bits \b resolution. \n
 *   The resolution of display PWM is 10 bits which means the backlight has 1024 levels.
 *
 * @section DISPLAY_PWM_Driver_Usage_Chapter How to use this driver
 * - Use the PWM with 26MHz input clock and generate a 80% duty cycle PWM signal. \n
 *  - Step1: Call #hal_display_pwm_init() to initialize the PWM hardware.
 *  - Step2: Call #hal_display_pwm_set_duty() or #hal_display_pwm_set_width() to set the PWM output duty cycle.
 *  - sample code:
 *  @code
 *
 *  ret = hal_display_pwm_init(HAL_DISPLAY_PWM_CLOCK_26MHZ);
 *  if (HAL_DISPLAY_PWM_STATUS_OK != ret) {
 *      // error handle
 *  }
 *
 *  // Configure the PWM to generate 80% duty cycle PWM signal.
 *  ret = hal_display_pwm_set_duty(80);
 *  if (HAL_DISPLAY_PWM_STATUS_OK != ret) {
 *      // error handle
 *  }
 *
 *  @endcode
 * */

#ifdef __cplusplus
extern "C" {
#endif

/** @defgroup hal_display_pwm_enum Enum
  * @{
  */

/** @brief The input source clock for the PWM. */
typedef enum {
    HAL_DISPLAY_PWM_CLOCK_26MHZ = 0,                /**< 26MHz source clock. */
    HAL_DISPLAY_PWM_CLOCK_104MHZ = 1,               /**< 104MHz source clock. */
    HAL_DISPLAY_PWM_CLOCK_NUM = 2                   /**< The number of source clocks. */
} hal_display_pwm_clock_t;

/** @brief The return status of display PWM API. */
typedef enum {
    HAL_DISPLAY_PWM_STATUS_ERROR               = -2,        /**< Failed. */
    HAL_DISPLAY_PWM_STATUS_INVALID_PARAMETER   = -1,        /**< Invalid parameter. */
    HAL_DISPLAY_PWM_STATUS_OK   = 0,                        /**< Successful. */
} hal_display_pwm_status_t;

/**
  * @}
  */

/**
 * @brief This function initializes the display PWM hardware.
 *
 * @param[in] clock specifies the input clock source, please refer to #hal_display_pwm_clock_t.
 *
 * @return      To indicate whether this function call is successful or not.
 *      #HAL_DISPLAY_PWM_STATUS_OK, the operation completed successfully.
 *      #HAL_DISPLAY_PWM_STATUS_INVALID_PARAMETER, the parameter needs to be verified. The parameter is out of bound.
 *      #HAL_DISPLAY_PWM_STATUS_ERROR, an error occurred. */
hal_display_pwm_status_t hal_display_pwm_init(hal_display_pwm_clock_t clock);

/**
 * @brief This function de-initializes the display PWM hardware.
 *
 * @return      To indicate whether this function call is successful or not.
 *      #HAL_DISPLAY_PWM_STATUS_OK, the operation completed successfully.
 *      #HAL_DISPLAY_PWM_STATUS_INVALID_PARAMETER, the parameter needs to be verified. The parameter is out of bound.
 *      #HAL_DISPLAY_PWM_STATUS_ERROR, an error occurred. */
hal_display_pwm_status_t hal_display_pwm_deinit(void);

/**
 * @brief This function sets the input clock of the PWM hardware.
 *
 * @param[in] clock specifies the input clock source, please refer to #hal_display_pwm_clock_t
 *
 * @return      To indicate whether this function call is successful or not.
 *      #HAL_DISPLAY_PWM_STATUS_OK, the operation completed successfully.
 *      #HAL_DISPLAY_PWM_STATUS_INVALID_PARAMETER, the parameter needs to be verified. The parameter is out of bound.
 *      #HAL_DISPLAY_PWM_STATUS_ERROR, an error occurred. */
hal_display_pwm_status_t hal_display_pwm_set_clock(hal_display_pwm_clock_t clock);

/**
 * @brief This function sets the PWM duty cycle in percentage.
 *
 * @param[in] percentage represents the percentage of high width of output PWM signal. If it is 0,
 *                       the output PWM signal will always stay on low. If it is 100,
 *                       the output PWM signal will always stay on high and the backlight will be the brightest.
 *
 * @return      To indicate whether this function call is successful or not.
 *      #HAL_DISPLAY_PWM_STATUS_OK, the operation completed successfully.
 *      #HAL_DISPLAY_PWM_STATUS_INVALID_PARAMETER, the parameter needs to be verified. The parameter is out of bound.
 *      #HAL_DISPLAY_PWM_STATUS_ERROR, an error occurred. */
hal_display_pwm_status_t hal_display_pwm_set_duty(uint8_t percentage);

/**
 * @brief This function sets the PWM duty cycle in integer format.
 *
 * @param[in] width represents the actual width of high width of output PWM signal. The range of the width is between 0 and 1024.
 *
 * @return      To indicate whether this function call is successful or not.
 *      #HAL_DISPLAY_PWM_STATUS_OK, the operation completed successfully.
 *      #HAL_DISPLAY_PWM_STATUS_INVALID_PARAMETER, the parameter needs to be verified. The parameter is out of bound.
 *      #HAL_DISPLAY_PWM_STATUS_ERROR, an error occurred. */
hal_display_pwm_status_t hal_display_pwm_set_width(uint32_t width);

#ifdef __cplusplus
}
#endif

/**
* @}
* @}
*/

#endif /* HAL_DISPLAY_PWM_MODULE_ENABLED */
#endif /* __HAL_DISPLAY_PWM_H__ */
