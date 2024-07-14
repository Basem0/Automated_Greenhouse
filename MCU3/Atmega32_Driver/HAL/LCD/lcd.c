/*
 * lcd.c
 *
 * Created: 4/22/2024 8:17:40 AM
 *  Author: Ahmed 
 */ 

// =======================================================================================
// ===================================== INCLUDES ========================================
// =======================================================================================
#include "lcd.h"
#include "lcd_cfg.h"
// =======================================================================================
// ================================= Data Type Declartion ================================
// =======================================================================================



// =======================================================================================
// =============================== Private Functions =====================================
// =======================================================================================
static void HAL_LCD_KICK(void);


#if LCD_MODE == LCD_4_BIT_MODE

static void LCD_4BIT_INIT(void)
{
	// ======================= Set CTRL Switches to Output ===================

	// RS_SWITCH is Output with (push-pull) mode
	INTIAL_PIN_OUTPUT(LCD_RS_PORT, LCD_RS_PIN, OUT_OFF);
	//RW_SWITCH is Output with (push-pull) mode
	INTIAL_PIN_OUTPUT(LCD_RW_PORT, LCD_RW_PIN, OUT_OFF);
	//Enable_SWITCH is Output with (push-pull) mode
	INTIAL_PIN_OUTPUT(LCD_EN_PORT, LCD_EN_PIN, OUT_OFF);

	INTIAL_PIN_OUTPUT(LCD_D4_PORT, LCD_D4_PIN, OUT_OFF);
	INTIAL_PIN_OUTPUT(LCD_D5_PORT, LCD_D5_PIN, OUT_OFF);
	INTIAL_PIN_OUTPUT(LCD_D6_PORT, LCD_D6_PIN, OUT_OFF);
	INTIAL_PIN_OUTPUT(LCD_D7_PORT, LCD_D7_PIN, OUT_OFF);

	// Reset EN_SWITCH PIN
	WRITE_PIN(LCD_EN_PORT, LCD_EN_PIN, OUT_OFF);
	// Reset RS_SWITCH PIN
	WRITE_PIN(LCD_RS_PORT, LCD_RS_PIN, OUT_OFF);
	// Reset RW_SWITCH PIN
	WRITE_PIN(LCD_RW_PORT, LCD_RW_PIN, OUT_OFF);
}

static void HAL_4BIT_LCD_KICK(void)
{
	// Set Enable bit
	WRITE_PIN(LCD_EN_PORT, LCD_EN_PIN, OUT_ON);

	// AC Characteristics : Enable cycle time (R & W ) = 500 ns
	_delay_ms(2);

	// Reset Enable bit
	WRITE_PIN(LCD_EN_PORT, LCD_EN_PIN, OUT_OFF);
}
#endif
// =======================================================================================
// =============================== APIs Functions Definitions ============================
// =======================================================================================

// Function to clear screen of LCD
void HAL_LCD_CLEAR_SCREEN(void)
{
	HAL_LCD_WRITE_COMMAND(LCD_CMD_CLEAR_SCREEN);
}

void HAL_LCD_GOTO_XY(uint8_t line, uint8_t position)
{
	if (line == 1)
	{
		if (position < 16 && position >= 0)
		{
			HAL_LCD_WRITE_COMMAND(LCD_CMD_BEGIN_AT_FIRST_ROW + position);
		}
	}
	if (line == 2)
	{
		if (position < 16 && position >= 0)
		{
			HAL_LCD_WRITE_COMMAND(LCD_CMD_BEGIN_AT_SECOND_ROW + position);
		}
	}
}

void HAL_LCD_INIT(void)
{

#if LCD_MODE == LCD_8_BIT_MODE
	// To Do
#elif LCD_MODE == LCD_4_BIT_MODE
	_delay_ms(20);
	LCD_4BIT_INIT();
	_delay_ms(15);
	HAL_LCD_WRITE_COMMAND(0x02); // As data sheet
	HAL_LCD_WRITE_COMMAND(LCD_CMD_FUNCTION_4BIT_2LINES);
	HAL_LCD_WRITE_COMMAND(LCD_CMD_ENTRY_MODE);
	HAL_LCD_WRITE_COMMAND(LCD_CMD_BEGIN_AT_FIRST_ROW);
	HAL_LCD_WRITE_COMMAND(LCD_CMD_DISP_ON_CURSOR_BLINK);
#endif
}

// Check if LCD is Busy
void HAL_LCD_ISBUSY(void)
{
	//============== Set Port to Receive Data (input) ===============

    // DataDir_LCD_PORT &= ~(0xFF << DATA_shift);
#if LCD_MODE == LCD_8_BIT_MODE
	// TO DO
#elif LCD_MODE == LCD_4_BIT_MODE
	INTIAL_PIN_INPUT(LCD_D4_PORT, LCD_D4_PIN, Pullup_ON);
	INTIAL_PIN_INPUT(LCD_D5_PORT, LCD_D5_PIN, Pullup_ON);
	INTIAL_PIN_INPUT(LCD_D6_PORT, LCD_D6_PIN, Pullup_ON);
	INTIAL_PIN_INPUT(LCD_D7_PORT, LCD_D7_PIN, Pullup_ON);

	// LCD_CTRL |= (1 << RW_SWITCH);
	WRITE_PIN(LCD_RW_PORT, LCD_RW_PIN, OUT_ON);
	// LCD_CTRL &= ~(1 << RS_SWITCH);
	WRITE_PIN(LCD_RS_PORT, LCD_RS_PIN, OUT_OFF);

	HAL_4BIT_LCD_KICK();
	// LCD_CTRL &= ~(1 << RW_SWITCH);
	WRITE_PIN(LCD_RW_PORT, LCD_RW_PIN, OUT_OFF);

	INTIAL_PIN_OUTPUT(LCD_D4_PORT, LCD_D4_PIN, OUT_OFF);
	INTIAL_PIN_OUTPUT(LCD_D5_PORT, LCD_D5_PIN, OUT_OFF);
	INTIAL_PIN_OUTPUT(LCD_D6_PORT, LCD_D6_PIN, OUT_OFF);
	INTIAL_PIN_OUTPUT(LCD_D7_PORT, LCD_D7_PIN, OUT_OFF);
#endif
}

// Function to write commands for LCD
void HAL_LCD_WRITE_COMMAND(uint8_t command)
{
#if LCD_MODE == LCD_8_BIT_MODE
/* ====== LCD is in 8 bit Mode ====== */
	// TO DO
#elif LCD_MODE == LCD_4_BIT_MODE
	/* ====== LCD is in 4 bit Mode ====== */

	// Send last four bits of command
    WRITE_PIN(LCD_D4_PORT, LCD_D4_PIN, (command >> 4) & 0x01);
    WRITE_PIN(LCD_D5_PORT, LCD_D5_PIN, (command >> 5) & 0x01);
    WRITE_PIN(LCD_D6_PORT, LCD_D6_PIN, (command >> 6) & 0x01);
    WRITE_PIN(LCD_D7_PORT, LCD_D7_PIN, (command >> 7) & 0x01);
	WRITE_PIN(LCD_RW_PORT, LCD_RW_PIN, OUT_OFF);
	WRITE_PIN(LCD_RS_PORT, LCD_RS_PIN, OUT_OFF);
	HAL_4BIT_LCD_KICK();

	// Send first four bits of command
	WRITE_PIN(LCD_D4_PORT, LCD_D4_PIN, (command >> 0) & 0x01);
	WRITE_PIN(LCD_D5_PORT, LCD_D5_PIN, (command >> 1) & 0x01);
	WRITE_PIN(LCD_D6_PORT, LCD_D6_PIN, (command >> 2) & 0x01);
	WRITE_PIN(LCD_D7_PORT, LCD_D7_PIN, (command >> 3) & 0x01);
	WRITE_PIN(LCD_RW_PORT, LCD_RW_PIN, OUT_OFF);
	WRITE_PIN(LCD_RS_PORT, LCD_RS_PIN, OUT_OFF);
	HAL_4BIT_LCD_KICK();
#endif

}

void HAL_LCD_WRITE_CHAR(uint8_t character)
{
#if LCD_MODE == LCD_8_BIT_MODE
	/* ====== LCD is in 8 bit Mode ====== */
	// TO DO

#elif LCD_MODE == LCD_4_BIT_MODE
	/* ====== LCD is in 4 bit Mode ====== */


	// Send last four bits of command
    WRITE_PIN(LCD_D4_PORT, LCD_D4_PIN, (character >> 4) & 0x01);
    WRITE_PIN(LCD_D5_PORT, LCD_D5_PIN, (character >> 5) & 0x01);
    WRITE_PIN(LCD_D6_PORT, LCD_D6_PIN, (character >> 6) & 0x01);
    WRITE_PIN(LCD_D7_PORT, LCD_D7_PIN, (character >> 7) & 0x01);
	WRITE_PIN(LCD_RW_PORT, LCD_RW_PIN, OUT_OFF);
	WRITE_PIN(LCD_RS_PORT, LCD_RS_PIN, OUT_ON);
	HAL_4BIT_LCD_KICK();

	// Send first four bits of command
    WRITE_PIN(LCD_D4_PORT, LCD_D4_PIN, (character >> 0) & 0x01);
    WRITE_PIN(LCD_D5_PORT, LCD_D5_PIN, (character >> 1) & 0x01);
    WRITE_PIN(LCD_D6_PORT, LCD_D6_PIN, (character >> 2) & 0x01);
    WRITE_PIN(LCD_D7_PORT, LCD_D7_PIN, (character >> 3) & 0x01);
	WRITE_PIN(LCD_RW_PORT, LCD_RW_PIN, OUT_OFF);
	WRITE_PIN(LCD_RS_PORT, LCD_RS_PIN, OUT_ON);
	HAL_4BIT_LCD_KICK();
#endif

}

void HAL_LCD_WRITE_STRING(char* string)
{
	// Counter to avoid writing bigger word size than LCD screen
	int count = 0;
	while (*string > 0)
	{
		count++;
		HAL_LCD_WRITE_CHAR(*string++);
		if (count == 16) // Counter reached the end of the first row
		{
			HAL_LCD_GOTO_XY(2, 0); // Line : row num 2 , starts from position 0
		} else if (count == 32)
		{
			HAL_LCD_CLEAR_SCREEN();
			HAL_LCD_GOTO_XY(1, 0); // go to line 1 , position 0
			count = 0;
		}
	}
}

/*
void HAL_LCD_custom_characters(void)
{
	HAL_LCD_WRITE_COMMAND(64);
	HAL_LCD_WRITE_CHAR(0);
	HAL_LCD_WRITE_CHAR(14);
	HAL_LCD_WRITE_CHAR(17);
	HAL_LCD_WRITE_CHAR(2);
	HAL_LCD_WRITE_CHAR(4);
	HAL_LCD_WRITE_CHAR(4);
	HAL_LCD_WRITE_CHAR(0);
	HAL_LCD_WRITE_CHAR(4);
	HAL_LCD_WRITE_COMMAND(LCD_CMD_BEGIN_AT_FIRST_ROW);
	HAL_LCD_WRITE_CHAR(0);
	delay_ms(10);
}
*/
