/*
 * DHT11.h
 *
 *  Created on: Jul 12, 2024
 *      Author: Ahmed Basem
 */

#ifndef INC_DHT11_H_
#define INC_DHT11_H_

// ==================================================================================
// ==================================== INCLUDE =====================================
// ==================================================================================
#include "GPIO_Driver.h"  // Include your GPIO driver here
#include "Timer.h"
#include "Timer1_8.h"
#include "ADC.h"

// ==================================================================================
// ============================ User type definitions ===============================
// ==================================================================================


// ==================================================================================
// ===================================== APIS =======================================
// ==================================================================================

typedef struct {
    ADCx_REG *ADCx;
    uint8_t ADC_Channel;
    ADC_CONFIG ADC_Config;
} LM35_Config_t;

void LM35_Init(LM35_Config_t *config);
float LM35_ReadTemperature(LM35_Config_t *config);

#endif /* INC_DHT11_H_ */

