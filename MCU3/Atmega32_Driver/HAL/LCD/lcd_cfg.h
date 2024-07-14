/*
 * lcd_cfg.h
 *
 * Created: 7/13/2024 4:12:41 PM
 *  Author: Ahmed Basem
 */ 


#ifndef LCD_CFG_H_
#define LCD_CFG_H_


// =======================================================================================
// ===================================== INCLUDES ========================================
// =======================================================================================
#include "../../MCAL/GPIO/GPIO.h"

// =======================================================================================
// ===================================== RS CONFIG =======================================
// =======================================================================================
#define LCD_RS_PORT           C
#define LCD_RS_PIN            PIN_0

// =======================================================================================
// ===================================== RW CONFIG =======================================
// =======================================================================================
#define LCD_RW_PORT           C
#define LCD_RW_PIN            PIN_1

// =======================================================================================
// ===================================== EN CONFIG =======================================
// =======================================================================================
#define LCD_EN_PORT           C
#define LCD_EN_PIN            PIN_2


// =======================================================================================
// ================================= DATA PINS CONFIG ====================================
// =======================================================================================
#define LCD_MODE              LCD_4_BIT_MODE


#if LCD_MODE == LCD_8_BIT_MODE
#define LCD_D0_PORT            PORTC
#define LCD_D0_PIN             PIN_0

#define LCD_D1_PORT            PORTC
#define LCD_D1_PIN             PIN_1

#define LCD_D2_PORT            PORTC
#define LCD_D2_PIN             PIN_2

#define LCD_D3_PORT            PORTC
#define LCD_D3_PIN             PIN_3
#endif

#define LCD_D4_PORT            C
#define LCD_D4_PIN             PIN_3

#define LCD_D5_PORT            C
#define LCD_D5_PIN             PIN_4

#define LCD_D6_PORT            C
#define LCD_D6_PIN             PIN_5

#define LCD_D7_PORT            C
#define LCD_D7_PIN             PIN_6

#endif /* LCD_CFG_H_ */