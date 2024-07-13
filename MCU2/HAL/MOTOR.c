/*
 * MOTOR.c
 *
 *  Created on: Jul 12, 2024
 *      Author: Ahmed Basem
 */


// ==================================================================================
// ==================================== INCLUDE =====================================
// ==================================================================================
#include "MOTOR.h"

// ==================================================================================
// ===================================== APIS =======================================
// ==================================================================================
void dc_motor_initialize(const dc_motor_t *_dc_motor){
	MCAL_GPIO_init(_dc_motor->MOTOR_PORT, &(_dc_motor->dc_motor_pin1));
	MCAL_GPIO_init(_dc_motor->MOTOR_PORT, &(_dc_motor->dc_motor_pin2));
}


void dc_motor_move_right(const dc_motor_t *_dc_motor){
	MCAL_write_PIN(_dc_motor->MOTOR_PORT, _dc_motor->dc_motor_pin1.PIN_number, DC_MOTOR_ON_STATUS);
	MCAL_write_PIN(_dc_motor->MOTOR_PORT, _dc_motor->dc_motor_pin2.PIN_number, DC_MOTOR_OFF_STATUS);
}


void dc_motor_move_left(const dc_motor_t *_dc_motor){
	MCAL_write_PIN(_dc_motor->MOTOR_PORT, _dc_motor->dc_motor_pin1.PIN_number, DC_MOTOR_OFF_STATUS);
	MCAL_write_PIN(_dc_motor->MOTOR_PORT, _dc_motor->dc_motor_pin1.PIN_number, DC_MOTOR_ON_STATUS);
}

void dc_motor_stop(const dc_motor_t *_dc_motor){
	MCAL_write_PIN(_dc_motor->MOTOR_PORT, _dc_motor->dc_motor_pin1.PIN_number, DC_MOTOR_OFF_STATUS);
	MCAL_write_PIN(_dc_motor->MOTOR_PORT, _dc_motor->dc_motor_pin1.PIN_number, DC_MOTOR_OFF_STATUS);
}
