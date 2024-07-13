/*
 * LCD_CFG.h
 *
 *  Created on: July 4, 2024
 *      Author: Ahmed Basem
 */

#ifndef _LCD_CFG_H_
#define _LCD_CFG_H_

// =======================================================================================
// ===================================== INCLUDES ========================================
// =======================================================================================
#include "stm32f103x6.h"
#include "GPIO_Driver.h"

// =======================================================================================
// ===================================== RS CONFIG =======================================
// =======================================================================================
//#define LCD_RS_PORT           GPIOB
//#define LCD_RS_PIN            PIN_15

#define LCD_RS_PORT           GPIOA
#define LCD_RS_PIN            PIN_6

// =======================================================================================
// ===================================== RW CONFIG =======================================
// =======================================================================================
//#define LCD_RW_PORT           GPIOB
//#define LCD_RW_PIN            PIN_14

#define LCD_RW_PORT           GPIOA
#define LCD_RW_PIN            PIN_5

// =======================================================================================
// ===================================== EN CONFIG =======================================
// =======================================================================================
//#define LCD_EN_PORT           GPIOB
//#define LCD_EN_PIN            PIN_13

#define LCD_EN_PORT           GPIOA
#define LCD_EN_PIN            PIN_4


// =======================================================================================
// ================================= DATA PINS CONFIG ====================================
// =======================================================================================
#define LCD_MODE              LCD_4_BIT_MODE


#if LCD_MODE == LCD_8_BIT_MODE
#define LCD_D0_PORT            GPIOA
#define LCD_D0_PIN             PIN_0

#define LCD_D1_PORT            GPIOA
#define LCD_D1_PIN             PIN_1

#define LCD_D2_PORT            GPIOA
#define LCD_D2_PIN             PIN_2

#define LCD_D3_PORT            GPIOA
#define LCD_D3_PIN             PIN_3
#endif

//#define LCD_D4_PORT            GPIOB
//#define LCD_D4_PIN             PIN_9
//
//#define LCD_D5_PORT            GPIOB
//#define LCD_D5_PIN             PIN_10
//
//#define LCD_D6_PORT            GPIOB
//#define LCD_D6_PIN             PIN_7
//
//#define LCD_D7_PORT            GPIOB
//#define LCD_D7_PIN             PIN_12

#define LCD_D4_PORT            GPIOA
#define LCD_D4_PIN             PIN_0

#define LCD_D5_PORT            GPIOA
#define LCD_D5_PIN             PIN_1

#define LCD_D6_PORT            GPIOA
#define LCD_D6_PIN             PIN_2

#define LCD_D7_PORT            GPIOA
#define LCD_D7_PIN             PIN_3


#endif // _LCD_CFG_H_
