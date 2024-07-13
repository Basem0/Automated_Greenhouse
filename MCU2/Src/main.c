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
dc_motor_t Fan1;
dc_motor_t Fan2;
dc_motor_t Pump1;
dc_motor_t Pump2;
dc_motor_t Heater1;
dc_motor_t Heater2;

void motors_init()
{
	Fan1.MOTOR_PORT = GPIOB;
	Fan1.dc_motor_pin1.PIN_number = PIN_12;
	Fan1.dc_motor_pin1.MODE = OUTPUT_PP;
	Fan1.dc_motor_pin1.SPEED = SPEED_10;
	Fan1.dc_motor_pin2.PIN_number = PIN_13;
	Fan1.dc_motor_pin2.MODE = OUTPUT_PP;
	Fan1.dc_motor_pin2.SPEED = SPEED_10;
	Fan2.MOTOR_PORT = GPIOB;
	Fan2.dc_motor_pin1.PIN_number = PIN_10;
	Fan2.dc_motor_pin1.MODE = OUTPUT_PP;
	Fan2.dc_motor_pin1.SPEED = SPEED_10;
	Fan2.dc_motor_pin2.PIN_number = PIN_11;
	Fan2.dc_motor_pin2.MODE = OUTPUT_PP;
	Fan2.dc_motor_pin2.SPEED = SPEED_10;
	Pump1.MOTOR_PORT = GPIOB;
	Pump1.dc_motor_pin1.PIN_number = PIN_4;
	Pump1.dc_motor_pin1.MODE = OUTPUT_PP;
	Pump1.dc_motor_pin1.SPEED = SPEED_10;
	Pump1.dc_motor_pin2.PIN_number = PIN_5;
	Pump1.dc_motor_pin2.MODE = OUTPUT_PP;
	Pump1.dc_motor_pin2.SPEED = SPEED_10;
	Pump2.MOTOR_PORT = GPIOB;
	Pump2.dc_motor_pin1.PIN_number = PIN_14;
	Pump2.dc_motor_pin1.MODE = OUTPUT_PP;
	Pump2.dc_motor_pin1.SPEED = SPEED_10;
	Pump2.dc_motor_pin2.PIN_number = PIN_15;
	Pump2.dc_motor_pin2.MODE = OUTPUT_PP;
	Pump2.dc_motor_pin2.SPEED = SPEED_10;
	Heater1.MOTOR_PORT = GPIOB;
	Heater1.dc_motor_pin1.PIN_number = PIN_8;
	Heater1.dc_motor_pin1.MODE = OUTPUT_PP;
	Heater1.dc_motor_pin1.SPEED = SPEED_10;
	Heater1.dc_motor_pin2.PIN_number = PIN_9;
	Heater1.dc_motor_pin2.MODE = OUTPUT_PP;
	Heater1.dc_motor_pin2.SPEED = SPEED_10;
	Heater2.MOTOR_PORT = GPIOB;
	Heater2.dc_motor_pin1.PIN_number = PIN_6;
	Heater2.dc_motor_pin1.MODE = OUTPUT_PP;
	Heater2.dc_motor_pin1.SPEED = SPEED_10;
	Heater2.dc_motor_pin2.PIN_number = PIN_7;
	Heater2.dc_motor_pin2.MODE = OUTPUT_PP;
	Heater2.dc_motor_pin2.SPEED = SPEED_10;
}


void HW_init();
void ERROR_HANDLER()
{
	while(1);
}


USART_Config_t _Uart1;
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
	motors_init();
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
	if(letter == 'a')
	{
		dc_motor_move_right(&Pump1);
		HAL_LCD_WRITE_STRING(" FIRE FIRE RIGHT");
		_TIM1_delay_us(20000);
		dc_motor_stop(&Pump1);
		HAL_LCD_CLEAR_SCREEN();

	}
	else if(letter == 'b')
	{
		dc_motor_move_right(&Pump2);
		HAL_LCD_WRITE_STRING(" FIRE FIRE LEFT");
		_TIM1_delay_us(200000);
		dc_motor_stop(&Pump2);
		HAL_LCD_CLEAR_SCREEN();

	}
	else if(letter == 'c')
	{
		HAL_LCD_WRITE_STRING(" Gas Gas RIGHT");
		_TIM1_delay_us(200000);
		HAL_LCD_CLEAR_SCREEN();
	}
	else if(letter == 'd')
	{
		HAL_LCD_WRITE_STRING(" Gas Gas LEFT");
		_TIM1_delay_us(200000);
		HAL_LCD_CLEAR_SCREEN();
	}
	else if(letter == 'e')
	{
		dc_motor_move_right(&Fan1);
		HAL_LCD_WRITE_STRING(" Weather Hot Right");
		_TIM1_delay_us(2000);
		dc_motor_stop(&Fan1);
		HAL_LCD_CLEAR_SCREEN();
	}
	else if(letter == 'f')
	{
		dc_motor_move_right(&Heater1);
		HAL_LCD_WRITE_STRING(" Weather Cold Right");
		_TIM1_delay_us(2000);
		dc_motor_stop(&Heater1);
		HAL_LCD_CLEAR_SCREEN();
	}
	else if(letter == 'g')
	{
		dc_motor_move_right(&Fan2);
		HAL_LCD_WRITE_STRING(" Weather Hot Left");
		_TIM1_delay_us(2000);
		dc_motor_stop(&Fan2);
		HAL_LCD_CLEAR_SCREEN();
	}
	else if(letter == 'h')
	{
		dc_motor_move_right(&Heater2);
		HAL_LCD_WRITE_STRING(" Weather Cold Left");
		_TIM1_delay_us(2000);
		dc_motor_stop(&Heater2);
		HAL_LCD_CLEAR_SCREEN();
	}
	else if(letter == 'j')
	{
		dc_motor_move_right(&Pump1);
		HAL_LCD_WRITE_STRING(" Water Leakage Right");
		_TIM1_delay_us(2000);
		dc_motor_stop(&Heater2);
		HAL_LCD_CLEAR_SCREEN();
	}
	else if(letter == 'k')
	{
		dc_motor_move_right(&Pump2);
		HAL_LCD_WRITE_STRING(" Water Leakage Left");
		_TIM1_delay_us(2000);
		dc_motor_stop(&Heater2);
		HAL_LCD_CLEAR_SCREEN();
	}

	else
	{
		HAL_LCD_WRITE_STRING(" Every Things Okey");
	}
}

