/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Ahmed Basem
 * @brief          : Main program body
 ******************************************************************************
 */

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

#include "main.h"
// ============================== MOTOR Definitation ================================
dc_motor_t Fan1 = {GPIOB, {PIN_12, OUTPUT_PP, SPEED_10}, {PIN_13, OUTPUT_PP, SPEED_10}};
dc_motor_t Fan2 = {GPIOB, {PIN_10, OUTPUT_PP, SPEED_10}, {PIN_11, OUTPUT_PP, SPEED_10}};
dc_motor_t Pump1 = {GPIOB, {PIN_4, OUTPUT_PP, SPEED_10}, {PIN_5, OUTPUT_PP, SPEED_10}};
dc_motor_t Pump2 = {GPIOB, {PIN_14, OUTPUT_PP, SPEED_10}, {PIN_15, OUTPUT_PP, SPEED_10}};
dc_motor_t Heater1 = {GPIOB, {PIN_8, OUTPUT_PP, SPEED_10}, {PIN_9, OUTPUT_PP, SPEED_10}};
dc_motor_t Heater2 = {GPIOB, {PIN_6, OUTPUT_PP, SPEED_10}, {PIN_7, OUTPUT_PP, SPEED_10}};


USART_Config_t _Uart1;

void HW_init();
void ERROR_HANDLER() { while(1); }
void isr_uart();

int main(void)
{
	HW_init();
	while(1)
	{

	}
}

void HW_init()
{
	RCC_GPIOA_CLK_EN();
	RCC_GPIOB_CLK_EN();
	RCC_GPIOC_CLK_EN();
	RCC_AFIO_CLK_EN();
	RCC_USART1_CLK_EN();
	RCC_USART2_CLK_EN();
	RCC_USART3_CLK_EN();
	dc_motor_initialize(&Fan1);
	dc_motor_initialize(&Fan2);
	dc_motor_initialize(&Heater1);
	dc_motor_initialize(&Heater2);
	dc_motor_initialize(&Pump1);
	dc_motor_initialize(&Pump2);
	HAL_LCD_INIT();
	_Uart1.Baud_Rate = 19200;
	_Uart1.Word = EGHIT_BITS;  // Check if this is correctly defined in your header
	_Uart1.STOP = ONE_STOP_BIT;
	_Uart1.Parity = Parity_DISABLE;
	_Uart1.MODE = Asynchronous;
	_Uart1.MEC = Interrupt;
	_Uart1.HW = Disabled;
	_Uart1.P_Call_Back = isr_uart;
	MCAL_USART_init(USART1, &_Uart1);
}
void isr_uart()
{
	uint8_t letter = MCAL_USART_ReciveData(USART1);
	switch (letter) {
	case 'a':
		dc_motor_move_right(&Pump1);
		HAL_LCD_GOTO_XY(1, 1);
		HAL_LCD_WRITE_STRING("===============FIRE RIGHT===============");
		break;

	case 'b':
		dc_motor_move_right(&Pump2);
		HAL_LCD_GOTO_XY(1, 1);
		HAL_LCD_WRITE_STRING("================FIRE LEFT===============");
		break;

	case 'c':
		HAL_LCD_GOTO_XY(1, 1);
		HAL_LCD_WRITE_STRING("================Gas RIGHT===============");
		break;

	case 'd':
		HAL_LCD_GOTO_XY(1, 1);
		HAL_LCD_WRITE_STRING("================Gas LEFT================");
		break;

	case 'e':
		dc_motor_move_right(&Fan1);
		HAL_LCD_GOTO_XY(1, 1);
		HAL_LCD_WRITE_STRING("============Weather Hot Right===========");
		break;

	case 'f':
		dc_motor_move_right(&Heater1);
		HAL_LCD_GOTO_XY(1, 1);
		HAL_LCD_WRITE_STRING("===========Weather Cold Right===========");
		break;

	case 'g':
		dc_motor_move_right(&Fan2);
		HAL_LCD_GOTO_XY(1, 1);
		HAL_LCD_WRITE_STRING("============Weather Hot Left============");
		break;

	case 'h':
		dc_motor_move_right(&Heater2);
		HAL_LCD_GOTO_XY(1, 1);
		HAL_LCD_WRITE_STRING("============Weather Cold Left===========");
		break;

	case 'j':
		dc_motor_move_right(&Pump1);
		HAL_LCD_GOTO_XY(1, 1);
		HAL_LCD_WRITE_STRING("===========Water Leakage Right==========");
		break;

	case 'k':
		dc_motor_move_right(&Pump2);
		HAL_LCD_GOTO_XY(1, 1);
		HAL_LCD_WRITE_STRING("===========Water Leakage Left==========");
		break;
	case 'z' :
		HAL_LCD_GOTO_XY(1, 1);
		HAL_LCD_WRITE_STRING("===========EVERY Thing Is Okey==========");
		break;
	default :
		break;
	}
	dc_motor_stop(&Heater2);
	dc_motor_stop(&Heater2);
	dc_motor_stop(&Heater2);
	dc_motor_stop(&Fan2);
	dc_motor_stop(&Heater1);
	dc_motor_stop(&Fan1);
	dc_motor_stop(&Pump1);
	dc_motor_stop(&Pump2);
}


