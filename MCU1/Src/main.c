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
void HW_init();
void ERROR_HANDLER()
{
	while(1);
}
void Right_flame_sensor();
void Left_flame_sensor();
void Left_Mq4_sensor();
void Right_Mq4_sensor();
void uart3_receive();

EXTI_config_t Right_flame = {
		.EXTI_PIN = EXT0PA0,
		.EXT_EN = ENABLE,
		.EXT_TRIGGER = RISEING,
		.P_CallBack = Right_flame_sensor
};
EXTI_config_t Left_flame = {
		.EXTI_PIN = EXT1PA1,
		.EXT_EN = ENABLE,
		.EXT_TRIGGER = RISEING,
		.P_CallBack = Left_flame_sensor
};
EXTI_config_t Right_Mq4 = {
		.EXTI_PIN = EXT2PA2,
		.EXT_EN = ENABLE,
		.EXT_TRIGGER = RISEING,
		.P_CallBack = Right_Mq4_sensor
};
EXTI_config_t Left_Mq4 = {
		.EXTI_PIN = EXT3PA3,
		.EXT_EN = ENABLE,
		.EXT_TRIGGER = RISEING,
		.P_CallBack = Left_Mq4_sensor
};
PIN_config Sarina;

USART_Config_t _Uart1;
USART_Config_t _Uart3;
uint8_t AT_DATA[4] = "    ";
uint8_t index = 1;

float temperature;
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
	HAL_LCD_INIT();
	MCAL_EXTI_init(&Right_flame);
	MCAL_EXTI_init(&Left_flame);
	MCAL_EXTI_init(&Right_Mq4);
	MCAL_EXTI_init(&Left_Mq4);
	Sarina.PIN_number = PIN_8;
	Sarina.MODE = OUTPUT_PP;
	Sarina.SPEED = SPEED_10;
	MCAL_GPIO_init(GPIOB,&Sarina);
	_Uart1.Baud_Rate = 19200;
	_Uart1.Word = EGHIT_BITS;  // Check if this is correctly defined in your header
	_Uart1.STOP = ONE_STOP_BIT;
	_Uart1.Parity = Parity_DISABLE;
	_Uart1.MODE = Asynchronous;
	_Uart1.MEC = POLLING;
	_Uart1.HW = Disabled;
	_Uart3.Baud_Rate = 19200;
	_Uart3.Word = EGHIT_BITS;  // Check if this is correctly defined in your header
	_Uart3.STOP = ONE_STOP_BIT;
	_Uart3.Parity = Parity_DISABLE;
	_Uart3.MODE = Asynchronous;
	_Uart3.MEC = Interrupt;
	_Uart3.P_Call_Back = uart3_receive;
			_Uart3.HW = Disabled;
	MCAL_USART_init(USART1, &_Uart1);
	MCAL_USART_init(USART3, &_Uart3);
}

void Right_flame_sensor()
{
	MCAL_write_PIN(GPIOB,PIN_8,LOGIC_HIGH);
	MCAL_USART_SendData(USART1,'a');
	while(MCAL_Read_PIN(GPIOB,PIN_0));
	_TIM1_delay_s(3);
	MCAL_write_PIN(GPIOB,PIN_8,LOGIC_LOW);
}
void Left_flame_sensor()
{
	MCAL_write_PIN(GPIOB,PIN_8,LOGIC_HIGH);
	MCAL_USART_SendData(USART1,'b');
	while(MCAL_Read_PIN(GPIOB,PIN_1));
	_TIM1_delay_s(3);
	MCAL_write_PIN(GPIOB,PIN_8,LOGIC_LOW);
}
void Right_Mq4_sensor()
{
	MCAL_write_PIN(GPIOB,PIN_8,LOGIC_HIGH);
	MCAL_USART_SendData(USART1,'c');
	while(MCAL_Read_PIN(GPIOB,PIN_2));
	_TIM1_delay_s(3);
	MCAL_write_PIN(GPIOB,PIN_8,LOGIC_LOW);
}
void Left_Mq4_sensor()
{
	MCAL_USART_SendData(USART1,'d');
	while(MCAL_Read_PIN(GPIOB,PIN_3));
	_TIM1_delay_s(3);
	MCAL_write_PIN(GPIOB,PIN_8,LOGIC_LOW);
}
void uart3_receive()
{
	AT_DATA[index] = MCAL_USART_ReciveData(USART3);
		HAL_LCD_WRITE_CHAR('0');
	if(index == 0)
	{
		HAL_LCD_GOTO_XY(0, 1);
		if(AT_DATA[index]>45) MCAL_USART_SendData(USART1,'e');
		if(AT_DATA[index]<25) MCAL_USART_SendData(USART1,'f');
	}
	else if(index == 1)
	{
		HAL_LCD_GOTO_XY(0, 7);
		HAL_LCD_WRITE_CHAR('1');
		if(AT_DATA[index]>45) MCAL_USART_SendData(USART1,'g');
		if(AT_DATA[index]<25) MCAL_USART_SendData(USART1,'h');
	}
	else if(index == 2)
	{
		HAL_LCD_GOTO_XY(1, 1);
		HAL_LCD_WRITE_CHAR('2');
		if(AT_DATA[index]<50) MCAL_USART_SendData(USART1,'j');
	}
	else if(index == 3)
	{
		HAL_LCD_GOTO_XY(1, 7);
		HAL_LCD_WRITE_CHAR('3');
		if(AT_DATA[index]<50) MCAL_USART_SendData(USART1,'k');
	}
	index++;
	if(index == 4)
		index = 0;
}
