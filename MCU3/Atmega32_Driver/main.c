/*
 * Atmega32_Driver.c
 *
 * Created: 4/22/2024 11:34:52 AM
 * Author : Ahmed 
 */

#include "MCAL/ADC/ADC.h"
#include "HAL/LCD/lcd.h"
#include "MCAL/USART/usart.h"
#include "MCAL/Timer0/Timer0.h"
#define F_CPU 8000000UL

uint32_t ADC_Data;
uint32_t RLM, LLM, RSM, LSM, HIH, LDR;
USART_Config_t _Uart;

void read_and_display_sensors();
void update_usart_transmission();

int main(void)
{
    TIMER0_Config_t _pwm__;
    _pwm__.Timer_Mode = TIMER0_MODE_FAST_PWM_NONINVERTING;
    _pwm__.Clock_Source = TIMER0_CLOCK_SOURCE_INTERNAL_PRESCALER_8;
    _pwm__.P_IRQ_CallBack = NULL;
    _pwm__.IRQ_Enable = TIMER0_IRQ_ENABLE_NONE;
    MCAL_TIMER0_Init(&_pwm__);
    
    HAL_LCD_INIT();
    
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

    while (1)
    {
        read_and_display_sensors();
        update_usart_transmission();
    }
}

void read_and_display_sensors()
{
    char buffer[10];

    MCAL_ADC_Get_Result(ADC0, &ADC_Data, ADC_ENABLE);
    RLM = (((ADC_Data * 5000) / 1024) / 10);
    MCAL_ADC_Get_Result(ADC1, &ADC_Data, ADC_ENABLE);
    LLM = (((ADC_Data * 5000) / 1024) / 10);
    MCAL_ADC_Get_Result(ADC2, &ADC_Data, ADC_ENABLE);
    RSM = (((ADC_Data * 5000) / 1024) / 50);
    MCAL_ADC_Get_Result(ADC3, &ADC_Data, ADC_ENABLE);
    LSM = (((ADC_Data * 5000) / 1024) / 50);
    MCAL_ADC_Get_Result(ADC4, &ADC_Data, ADC_ENABLE);
    HIH = (((ADC_Data * 5000) / 1024));
	float voltage = (ADC_Data * 5.0) / 1024.0;
	HIH = (voltage - 0.8) / 0.03;
    MCAL_ADC_Get_Result(ADC5, &ADC_Data, ADC_ENABLE);
    LDR = (ADC_Data * 255) / 1023; // Scaling 0-1023 to 0-255
    MCAL_PWM_DutyCycle(255 - LDR);

    HAL_LCD_GOTO_XY(1, 0);
    HAL_LCD_WRITE_STRING("RTEMP=");
    sprintf(buffer, "%d", RLM);
    HAL_LCD_WRITE_STRING(buffer);
    HAL_LCD_WRITE_STRING(" LTEMP=");
    sprintf(buffer, "%d", LLM);
    HAL_LCD_WRITE_STRING(buffer);

    HAL_LCD_GOTO_XY(2, 0);
    HAL_LCD_WRITE_STRING("RWATER=");
    sprintf(buffer, "%d", RSM);
    HAL_LCD_WRITE_STRING(buffer);
    HAL_LCD_WRITE_STRING(" LWATER=");
    sprintf(buffer, "%d", LSM);
    HAL_LCD_WRITE_STRING(buffer);

    HAL_LCD_GOTO_XY(4, 0);
    HAL_LCD_WRITE_STRING("HIH=");
    sprintf(buffer, "%d", HIH);
    HAL_LCD_WRITE_STRING(buffer);
    HAL_LCD_WRITE_STRING("           ");
}

void update_usart_transmission()
{
    if (RLM > 45)
    {
        MCAL_USART_Transmit('e', USART_enable);
    }
    else if (RLM < 25)
    {
        MCAL_USART_Transmit('f', USART_enable);
    }

    if (LLM > 45)
    {
        MCAL_USART_Transmit('g', USART_enable);
    }
    else if (LLM < 25)
    {
        MCAL_USART_Transmit('h', USART_enable);
    }

    if (RSM < 50)
    {
        MCAL_USART_Transmit('j', USART_enable);
    }

    if (LSM < 50)
    {
        MCAL_USART_Transmit('k', USART_enable);
    }
}
