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
void ERROR_HANDLER() { while(1); }
void Right_flame_sensor();
void Left_flame_sensor();
void Left_Mq4_sensor();
void Right_Mq4_sensor();
void uart3_receive();

volatile uint8_t flagRightFlame = 0;
volatile uint8_t flagLeftFlame = 0;
volatile uint8_t flagRightMQ4 = 0;
volatile uint8_t flagLeftMQ4 = 0;
volatile uint8_t uart3Received = 0;

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
uint8_t letter;
int main(void)
{
	HW_init();
	while(1)
	{
		if(flagRightFlame || flagLeftFlame || flagRightMQ4 || flagLeftMQ4) MCAL_write_PIN(GPIOB, PIN_8, LOGIC_HIGH);
		if (uart3Received) {
		    uart3Received = 0;
//		    uint8_t letter = MCAL_USART_ReciveData(USART3);
		    MCAL_USART_SendData(USART1, letter);
		} else {
		    // Assuming uart3Received being false means checking other conditions
		    if (flagRightFlame) {
		        flagRightFlame = MCAL_Read_PIN(GPIOA, PIN_0);
		        MCAL_USART_SendData(USART1, 'a');
		    } else if (flagLeftFlame) {
		        flagLeftFlame = MCAL_Read_PIN(GPIOA, PIN_1);
		        MCAL_USART_SendData(USART1, 'b');
		    } else if (flagRightMQ4) {
		        flagRightMQ4 = MCAL_Read_PIN(GPIOA, PIN_2);
		        MCAL_USART_SendData(USART1, 'c');
		    } else if (flagLeftMQ4) {
		        flagLeftMQ4 = MCAL_Read_PIN(GPIOA, PIN_3);
		        MCAL_USART_SendData(USART1, 'd');
		    }
		    else
		    {
//		    	MCAL_USART_SendData(USART1, 'z');
		    }
		}


		if(flagRightFlame || flagLeftFlame || flagRightMQ4 || flagLeftMQ4) MCAL_write_PIN(GPIOB, PIN_8, LOGIC_HIGH);
		else MCAL_write_PIN(GPIOB, PIN_8, LOGIC_LOW);

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
	MCAL_GPIO_init(GPIOB, &Sarina);

	_Uart1.Baud_Rate = 19200;
	_Uart1.Word = EGHIT_BITS;
	_Uart1.STOP = ONE_STOP_BIT;
	_Uart1.Parity = Parity_DISABLE;
	_Uart1.MODE = Asynchronous;
	_Uart1.MEC = POLLING;
	_Uart1.HW = Disabled;
	_Uart3.Baud_Rate = 19200;
	_Uart3.Word = EGHIT_BITS;
	_Uart3.STOP = ONE_STOP_BIT;
	_Uart3.Parity = Parity_DISABLE;
	_Uart3.MODE = Asynchronous;
	_Uart3.MEC = Interrupt;
	_Uart3.P_Call_Back = uart3_receive;
	_Uart3.HW = Disabled;

	MCAL_USART_init(USART1, &_Uart1);
	MCAL_USART_init(USART3, &_Uart3);
}

void Right_flame_sensor() { flagRightFlame = 1; }
void Left_flame_sensor() { flagLeftFlame = 1; }
void Right_Mq4_sensor() { flagRightMQ4 = 1; }
void Left_Mq4_sensor() { flagLeftMQ4 = 1; }
void uart3_receive() {
	uart3Received = 1;
	letter = MCAL_USART_ReciveData(USART3);
}

