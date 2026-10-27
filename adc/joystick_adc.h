/**
  ******************************************************************************
  * @file    joystick_adc.h
  * @brief   joystick ADC Part Driver
  *          This file contains all the functions prototypes for the board Joystick
  *          driven by an ADC interface, whatever the STM32 family.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2026 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef JOYSTICK_ADC_H
#define JOYSTICK_ADC_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include <stdint.h>
#include "stm32_hal.h"


/* Exported macros ------------------------------------------------------------*/
/*!< Default timeout value when polling the ADC */
#define JOY_ADC_POLL_TIMEOUT        10U

/* Exported types ------------------------------------------------------------*/

/**
  * @brief enumeration defining the bit joystick key state position in a bit field.
  */
typedef enum
{
  JOY_ADC_KEY_NONE  = 0U,
  JOY_ADC_KEY_CENTER,
  JOY_ADC_KEY_DOWN,
  JOY_ADC_KEY_LEFT,
  JOY_ADC_KEY_RIGHT,
  JOY_ADC_KEY_UP
} joy_adc_key_t;

/**
  * @brief Enumeration defining the Part Status.
  */
typedef enum
{
  JOY_ADC_OK = 0U,         /*!< Success State     */
  JOY_ADC_ERROR,           /*!< Error State       */
  JOY_ADC_INVALID_PARAM,   /*!< Invalid Parameter */
} joy_adc_status_t;

/**
  * @brief Structure defining the property for a joystick on ADC.
  */
typedef struct
{
  uint32_t           id;      /*!< Part Config ID  */
  hal_adc_handle_t   *phadc;  /*!< ADC handler     */
  /* calculated adc key value to be compared later with the adc value
   to determinate the key state
  */
  int32_t key_up_max_val;
  int32_t key_up_min_val;
  int32_t key_down_max_val;
  int32_t key_down_min_val;
  int32_t key_left_max_val;
  int32_t key_left_min_val;
  int32_t key_right_max_val;
  int32_t key_right_min_val;
  int32_t key_center_max_val;
  int32_t key_center_min_val;
} joy_adc_t;


/* Exported function ---------------------------------------------------------*/
joy_adc_status_t joy_adc_init(joy_adc_t *pjoy_adc, uint32_t id);
joy_adc_status_t joy_adc_get_state(joy_adc_t *pjoy_adc, joy_adc_key_t *pkey);

/* Weak function ---------------------------------------------------------*/
int32_t joy_adc_io_init(joy_adc_t *pjoy_adc);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* JOYSTICK_ADC_H */
