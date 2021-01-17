/* Copyright Statement:
 *
 */

#ifndef __HAL_DISPLAY_COLOR_INTERNAL_H__
#define __HAL_DISPLAY_COLOR_INTERNAL_H__

#ifdef HAL_DISPLAY_COLOR_MODULE_ENABLED

#include "hal_display_color.h"

#ifdef __cplusplus
extern "C" {
#endif

#define COLOR_CUSTOM_SHARPNESS_TABLE_NUM  10
#define COLOR_CUSTOM_CONTRAST_TABLE_NUM  10
#define COLOR_CUSTOM_SATURATION_TABLE_NUM  10
#define COLOR_BYPASS_NONE               		0x00000000
#define COLOR_BYPASS_SAT                		0x00000001
#define COLOR_BYPASS_CONTRAST           	0x00000002
#define COLOR_BYPASS_SHARP              	0x00000004
#define COLOR_BYPASS_Y2R                		0x00000008
#define COLOR_BYPASS_R2Y                		0x00000010
#define COLOR_BYPASS_ALL                		0x0000001F
#define COLOR_BYPASS_STALL              		0x00000080
#define COLOR_BYPASS_MASK               		0x0000009F


typedef union {
    uint32_t	value;
    struct {
        uint32_t EN 							: 1; 	/*! Bit 0 */
        uint32_t reserved1						: 14;	/*! reserved */
        uint32_t SW_RST 						: 1; 	/*! Bit 15 */
        uint32_t reserved						: 16;	/*! reserved */
    } field;
} MM_COLOR_EN_REGISTER_T;

typedef union {
    uint32_t	value;
    struct {
        uint32_t BYPASS_SAT 					: 1; 	/*! Bit 0 */
        uint32_t BYPASS_CONTRAST				: 1; 	/*! Bit 1 */
        uint32_t BYPASS_SHARP					: 1; 	/*! Bit 2 */
        uint32_t BYPASS_Y2R 					: 1; 	/*! Bit 3 */
        uint32_t BYPASS_R2Y 					: 1; 	/*! Bit 4 */
        uint32_t reserved1						: 2; 	/*! reserved */
        uint32_t STALL							: 1; 	/*! Bit 7 */
        uint32_t reserved						: 24;	/*! reserved */
    } field;
} MM_COLOR_BYPASS_REGISTER_T;

typedef union {
    uint32_t	value;
    struct {
        uint32_t SHARP_GAIN 					: 8; 	/*! Bit 0..7 */
        uint32_t SHARP_BOUND					: 6; 	/*! Bit 8..13 */
        uint32_t reserved2						: 2; 	/*! reserved */
        uint32_t SHARP_LIMIT					: 6; 	/*! Bit 16..21 */
        uint32_t reserved1						: 2; 	/*! reserved */
        uint32_t SHARP_SOFT_RATIO				: 4; 	/*! Bit 24..27 */
        uint32_t reserved						: 4;		/*! reserved */
    } field;
} MM_COLOR_SHARP_CON_REGISTER_T;

typedef union {
    uint32_t	value;
    struct {
        uint32_t CONTRAST_POINT0				: 8; 	/*! Bit 0..7 */
        uint32_t CONTRAST_POINT1				: 8; 	/*! Bit 8..15 */
        uint32_t reserved						: 16;	/*! reserved */
    } field;
} MM_COLOR_CONTRAST_POINT_REGISTER_T;

typedef union {
    uint32_t	value;
    struct {
        uint32_t CONTRAST_OFFSET0				: 16; 	/*! Bit 0..15 */
        uint32_t CONTRAST_OFFSET1				: 16; 	/*! Bit 16..31 */
    } field;
} MM_COLOR_CONTRAST_OFFSET_REGISTER_T;

typedef union {
    uint32_t	value;
    struct {
        uint32_t CONTRAST_GAIN0 				: 8; 	/*! Bit 0..7 */
        uint32_t CONTRAST_GAIN1 				: 8; 	/*! Bit 8..15 */
        uint32_t CONTRAST_GAIN2 				: 8; 	/*! Bit 16..23 */
        uint32_t reserved						: 8;		/*! reserved */
    } field;
} MM_COLOR_CONTRAST_GAIN_REGISTER_T;

typedef union {
    uint32_t	value;
    struct {
        uint32_t SAT_COEF_B 					: 8; 	/*! Bit 0..7 */
        uint32_t SAT_COEF_A 					: 8; 	/*! Bit 8..15 */
        uint32_t SAT_CON_POINT					: 12;	/*! Bit 16..27 */
        uint32_t reserved						: 4;		/*! reserved */
    } field;
} MM_COLOR_SAT_POINT_REGISTER_T;

typedef union {
    uint32_t	value;
    struct {
        uint32_t SAT_GAIN						: 8; 	/*! Bit 0..7 */
        uint32_t reserved						: 24;	/*! reserved */
    } field;
} MM_COLOR_SAT_GAIN_REGISTER_T;

typedef union {
    uint32_t	value;
    struct {
        uint32_t SRC_W							: 8; 	/*! Bit 0..7 */
        uint32_t reserved						: 24;	/*! reserved */
    } field;
} MM_COLOR_SRC_SIZE_REGISTER_T;

typedef struct {
    MM_COLOR_EN_REGISTER_T						MM_COLOR_EN_REGISTER;				// 0x00
    MM_COLOR_BYPASS_REGISTER_T					MM_COLOR_BYPASS_REGISTER;			// 0x04
    uint32_t										reserved[2];
    MM_COLOR_SHARP_CON_REGISTER_T				MM_COLOR_SHARP_CON_REGISTER;		// 0x10
    uint32_t										reserved1[3];
    MM_COLOR_CONTRAST_POINT_REGISTER_T			MM_COLOR_CONTRAST_POINT_REGISTER;	// 0x20
    MM_COLOR_CONTRAST_OFFSET_REGISTER_T		MM_COLOR_CONTRAST_OFFSET_REGISTER;	// 0x24
    MM_COLOR_CONTRAST_GAIN_REGISTER_T			MM_COLOR_CONTRAST_GAIN_REGISTER;	// 0x28
    uint32_t										reserved3;
    MM_COLOR_SAT_POINT_REGISTER_T				MM_COLOR_SAT_POINT_REGISTER;		// 0x30
    uint32_t										reserved4;
    MM_COLOR_SAT_GAIN_REGISTER_T				MM_COLOR_SAT_GAIN_REGISTER;			// 0x38
    uint32_t										reserved5[5];
    MM_COLOR_SRC_SIZE_REGISTER_T				MM_COLOR_SRC_SIZE_REGISTER;			// 0x50
} MM_COLOR_REGISTER_T;

hal_display_color_status_t display_color_apply_color(uint32_t src_width, uint8_t CustomEnable, hal_display_color_parameter_t *color_para);
hal_display_color_status_t display_color_power_on(void);
hal_display_color_status_t display_color_power_off(void);

#ifdef __cplusplus
}
#endif

#endif /* HAL_DISPLAY_COLOR_MODULE_ENABLED */

#endif /* __HAL_DISPLAY_COLOR_INTERNAL_H__ */


