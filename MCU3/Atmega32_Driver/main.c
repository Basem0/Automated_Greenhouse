/*
 * Atmega32_Driver.c
 *
 * Created: 4/22/2024 11:34:52 AM
 * Author : Ahmed 
 */ 

#include "MCAL/ADC/ADC.h"
#include "HAL/LCD/lcd.h"
#include "MCAL/USART/usart.h"
#define F_CPU 8000000UL

uint32_t ADC_Data;
uint32_t RLM,LLM,RSM,LSM;
USART_Config_t _Uart;
int main(void)
{
	ADC_Config_t adc_cfg;
	adc_cfg.ADC_Mode = ADC_MODE_SINGLE_CONVERSION;
	adc_cfg.ADC_Prescaler = ADC_PRESCALER_64;
	adc_cfg.ADC_Res_presentation = ADC_RES_PRESENTATION_LEFT_ADJUSTED;
	adc_cfg.ADC_Volt_Ref = ADC_VOLT_REF_AVCC;
	adc_cfg.ADC_IRQ_Enable = ADC_IRQ_ENABLE_NONE;
	adc_cfg.P_CallBack = NULL;
	MCAL_ADC_Init(&adc_cfg);
		
	_Uart.BaudRate = USART_BaudRate_19200;
	_Uart.Parity = UART_Parity_None;
	_Uart.StopBits = UART_StopBits_1;
	_Uart.IRQ_Enable = UART_IRQ_None;
	_Uart.Payload_Length = UART_Payload_Length_8;
	_Uart.USART_Mode = USART_Mode_Async;
	MCAL_USART_Init(&_Uart);
	
	while(1){
	MCAL_ADC_Get_Result(ADC0,&ADC_Data,ADC_ENABLE);
	RLM = (((ADC_Data *5000) / 1024) /10);
	MCAL_ADC_Get_Result(ADC1,&ADC_Data,ADC_ENABLE);
	LLM = (((ADC_Data *5000) / 1024) /10);
	MCAL_ADC_Get_Result(ADC2,&ADC_Data,ADC_ENABLE);
	RSM = (((ADC_Data *5000) / 1024) /50);
	MCAL_ADC_Get_Result(ADC3,&ADC_Data,ADC_ENABLE);
	LSM = (((ADC_Data *5000) / 1024) /50);
	MCAL_USART_Transmit((uint8_t)RLM,USART_enable);
	_delay_ms(100);
	MCAL_USART_Transmit((uint8_t)LLM,USART_enable);
	_delay_ms(100);
	MCAL_USART_Transmit((uint8_t)RSM,USART_enable);
	_delay_ms(100);
	MCAL_USART_Transmit((uint8_t)LSM,USART_enable);
	_delay_ms(100);


	}
}

