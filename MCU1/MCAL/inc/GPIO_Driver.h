/*
 * GPIO_Driver.h
 *
 *  Created on: Jul 3, 2024
 *      Author: Ahmed
 */

#ifndef __GPIO_DRIVER__H
#define __GPIO_DRIVER__H

// ==================================================================================
// ==================================== INCLUDE =====================================
// ==================================================================================
#include "STM32F103x6.h"

// ==================================================================================
// ============================ User type definitions ===============================
// ==================================================================================
typedef enum
{
	Analog,
	INPUT_FI,
	INPUT_PU,
	INPUT_PD,
	OUTPUT_PP,
	OUTPUT_OD,
	OUTPUT_AF_PP,
	OUTPUT_AF_OD
}MODE_t;

typedef enum
{
	SPEED_10 = 1,
	SPEED_2,
	SPEED_50
}SPEED_t;

typedef enum
{
	LOGIC_LOW,
	LOGIC_HIGH
}LOGIC_Value_t;

typedef enum
{
	PIN_0,
	PIN_1,
	PIN_2,
	PIN_3,
	PIN_4,
	PIN_5,
	PIN_6,
	PIN_7,
	PIN_8,
	PIN_9,
	PIN_10,
	PIN_11,
	PIN_12,
	PIN_13,
	PIN_14,
	PIN_15
}PIN_N;

typedef enum
{
	PORT_INPUT,
	PORT_OUTPUT
}PORT_config;

typedef struct
{
	vuint16_t		PIN_number;
	vuint8_t 	 	MODE;
	vuint8_t 		SPEED;
}PIN_config;

// ==================================================================================
// ===================================== APIS =======================================
// ==================================================================================
void MCAL_GPIO_init(GPIOx_REG* GPIOx,PIN_config* PINx);
void MCAL_SET_PORT_DIR(GPIOx_REG *GPIOx,PORT_config PORT);
void MCAL_GPIO_Deinit(GPIOx_REG* GPIOx);


void MCAL_write_PIN(GPIOx_REG* GPIOx,vuint16_t PIN_Number,vuint8_t value);
void MCAL_write_PORT(GPIOx_REG* GPIOX,vuint16_t value);

uint16_t MCAL_Read_PIN(GPIOx_REG* GPIOx,vuint16_t PIN_Number);
uint16_t MCAL_Read_PORT(GPIOx_REG* GPIOx);

void MCAL_TOGGLE_PIN(GPIOx_REG* GPIOx,vuint16_t PIN_Number);

uint8_t MCAL_LOCK_PIN(GPIOx_REG* GPIOx,vuint16_t PIN_Number);
#endif
