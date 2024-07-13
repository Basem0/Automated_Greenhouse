/*
 * DHT11.c
 *
 *  Created on: Jul 12, 2024
 *      Author: Ahmed Basem
 */

#include "DHT11.h"

void LM35_Init(LM35_Config_t *config) {
    ADC_init(config->ADCx, &(config->ADC_Config));
}

float LM35_ReadTemperature(LM35_Config_t *config) {
    uint16_t adc_value = 0;
    ADC_read(config->ADCx, config->ADC_Channel, &adc_value);

    // Assuming a 12-bit ADC with Vref = 3.3V
    float voltage = (adc_value / 4096.0) * 3.3;

    // LM35 outputs 10mV per degree Celsius
    float temperature = voltage * 100.0;

    return temperature;
}
