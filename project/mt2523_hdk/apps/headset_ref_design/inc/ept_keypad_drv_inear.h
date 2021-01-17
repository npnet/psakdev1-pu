/*
 * Generated by MTK Easy PinMux Tool Version 2.0.1 for 2523. Copyright MTK Inc. (C) 2015.
 * 2017-07-07 12:03:37:0764
 * Do Not Modify the File. */

/*****************************************************************************
*
* Filename:
* ---------
*    ***.*
*
* Project:
* --------
*
* Description:
* ------------
*
* Author:
* -------
*
*============================================================================
****************************************************************************/

#ifndef  _EPT_KEYPAD_DRV_H
#define  _EPT_KEYPAD_DRV_H


#define  __SINGLE_KEYPAD__

#if defined(__SINGLE_KEYPAD__)
#define KEYPAD_MAPPING \
DEVICE_KEY_VOL_UP, \
DEVICE_KEY_VOL_DOWN, \
DEVICE_KEY_NONE, \
DEVICE_KEY_NONE, \
DEVICE_KEY_NONE, \
DEVICE_KEY_NONE, \
DEVICE_KEY_NONE, \
DEVICE_KEY_NONE, \
DEVICE_KEY_NONE, \
DEVICE_KEY_NONE, \
DEVICE_KEY_NONE, \
DEVICE_KEY_NONE, \
DEVICE_KEY_NONE, \
DEVICE_KEY_NONE, \
DEVICE_KEY_NONE, \
DEVICE_KEY_NONE, \
DEVICE_KEY_NONE, \
DEVICE_KEY_NONE, \
DEVICE_KEY_NONE, \
DEVICE_KEY_NONE, \
DEVICE_KEY_NONE, \
DEVICE_KEY_NONE, \
DEVICE_KEY_NONE, \
DEVICE_KEY_NONE, \
DEVICE_KEY_NONE, \
DEVICE_KEY_NONE, \
DEVICE_KEY_NONE, \
DEVICE_KEY_NONE, \
DEVICE_KEY_NONE, \
DEVICE_KEY_NONE, \
DEVICE_KEY_NONE, \
DEVICE_KEY_NONE 
#elif defined(__DOUBLE_KEYPAD__)
#define KEYPAD_MAPPING \
DEVICE_KEY_NONE, \
DEVICE_KEY_NONE, \
DEVICE_KEY_NONE, \
DEVICE_KEY_NONE, \
DEVICE_KEY_NONE, \
DEVICE_KEY_NONE, \
DEVICE_KEY_NONE, \
DEVICE_KEY_NONE, \
DEVICE_KEY_NONE, \
DEVICE_KEY_NONE, \
DEVICE_KEY_NONE, \
DEVICE_KEY_NONE, \
DEVICE_KEY_NONE, \
DEVICE_KEY_ENTER, \
DEVICE_KEY_BACK, \
DEVICE_KEY_NONE, \
DEVICE_KEY_NONE, \
DEVICE_KEY_NONE, \
DEVICE_KEY_DOWN, \
DEVICE_KEY_NONE, \
DEVICE_KEY_NONE, \
DEVICE_KEY_NONE, \
DEVICE_KEY_NONE, \
DEVICE_KEY_NONE, \
DEVICE_KEY_NONE, \
DEVICE_KEY_NONE, \
DEVICE_KEY_NONE, \
DEVICE_KEY_NONE, \
DEVICE_KEY_NONE, \
DEVICE_KEY_NONE, \
DEVICE_KEY_NONE, \
DEVICE_KEY_NONE 
#endif

#define POWERKEY_POSITION DEVICE_KEY_FUNCTION

#define DRV_KBD_COL_ROW_SEL 0xc1

#define EPT_KEYPAD_DEBOUNCE_TIME 16

#define EPT_KEYPAD_LONGPRESS_TIME 2000

#define EPT_KEYPAD_REPEAT_TIME 1000


#endif /* _EPT_KEYPAD_DRV_H */