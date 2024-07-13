/*
 * EXTI_Driver.h
 *
 *  Created on: Jul 3, 2024
 *      Author: Ahmed
 */

#ifndef INC_EXTI_DRIVER_H_
#define INC_EXTI_DRIVER_H_

// ==================================================================================
// ==================================== INCLUDE =====================================
// ==================================================================================
#include "Platform_Types.h"
#include "GPIO_Driver.h"
#include "STM32F103x6.h"


// ==================================================================================
// ======================= User type definitions (structures) =======================
// ==================================================================================
typedef enum
{
	FALLING,
	RISEING,
	FALLING_RISEING
}Trigger;

typedef enum
{
	DISABLE,
	ENABLE
}EXT_Enable;

typedef struct
{
	uint16_t EXI_LINE;
	GPIOx_REG *GIPO;
	uint16_t PIN;
	uint16_t IVT_num;
}GPIO_CONFIG_t;

typedef struct
{
	GPIO_CONFIG_t EXTI_PIN;
	Trigger EXT_TRIGGER;
	EXT_Enable EXT_EN;
	void(*P_CallBack)(void);
}EXTI_config_t;



// ==================================================================================
// ==================================== DEFINES =====================================
// ==================================================================================
#define PORT_Detector(x) ((x==GPIOA) ? 0:\
						  (x==GPIOB) ? 1:\
						  (x==GPIOC) ? 3:\
						  (x==GPIOD) ? 4:0)
#define EXTI0 0
#define EXTI1 1
#define EXTI2 2
#define EXTI3 3
#define EXTI4 4
#define EXTI5 5
#define EXTI6 6
#define EXTI7 7
#define EXTI8 8
#define EXTI9 9
#define EXTI10 10
#define EXTI11 11
#define EXTI12 12
#define EXTI13 13
#define EXTI14 14
#define EXTI15 15


#define EXT0_IRQ 6
#define EXT1_IRQ 7
#define EXT2_IRQ 8
#define EXT3_IRQ 9
#define EXT4_IRQ 10
#define EXT5_IRQ 23
#define EXT6_IRQ 23
#define EXT7_IRQ 23
#define EXT8_IRQ 23
#define EXT9_IRQ 23
#define EXT10_IRQ 40
#define EXT11_IRQ 40
#define EXT12_IRQ 40
#define EXT13_IRQ 40
#define EXT14_IRQ 40
#define EXT15_IRQ 40

#define NVIC_EXTI0_EN (NVIC_ISER0|=(1<<EXT0_IRQ))
#define NVIC_EXTI1_EN (NVIC_ISER0|=(1<<EXT1_IRQ))
#define NVIC_EXTI2_EN (NVIC_ISER0|=(1<<EXT2_IRQ))
#define NVIC_EXTI3_EN (NVIC_ISER0|=(1<<EXT3_IRQ))
#define NVIC_EXTI4_EN (NVIC_ISER0|=(1<<EXT4_IRQ))
#define NVIC_EXTI5_EN (NVIC_ISER0|=(1<<EXT5_IRQ))
#define NVIC_EXTI6_EN (NVIC_ISER0|=(1<<EXT6_IRQ))
#define NVIC_EXTI7_EN (NVIC_ISER0|=(1<<EXT7_IRQ))
#define NVIC_EXTI8_EN (NVIC_ISER0|=(1<<EXT8_IRQ))
#define NVIC_EXTI9_EN (NVIC_ISER0|=(1<<EXT9_IRQ))
#define NVIC_EXTI10_EN (NVIC_ISER1|=(1<<8))
#define NVIC_EXTI11_EN (NVIC_ISER1|=(1<<8))
#define NVIC_EXTI12_EN (NVIC_ISER1|=(1<<8))
#define NVIC_EXTI13_EN (NVIC_ISER1|=(1<<8))
#define NVIC_EXTI14_EN (NVIC_ISER1|=(1<<8))
#define NVIC_EXTI15_EN (NVIC_ISER1|=(1<<8))
/////////////////////////////////////////////
#define NVIC_EXTI0_D (NVIC_ISER0&=~(1<<EXT0_IRQ))
#define NVIC_EXTI1_D (NVIC_ISER0&=~(1<<EXT1_IRQ))
#define NVIC_EXTI2_D (NVIC_ISER0&=~(1<<EXT2_IRQ))
#define NVIC_EXTI3_D (NVIC_ISER0&=~(1<<EXT3_IRQ))
#define NVIC_EXTI4_D (NVIC_ISER0&=~(1<<EXT4_IRQ))
#define NVIC_EXTI5_D (NVIC_ISER0&=~(1<<EXT5_IRQ))
#define NVIC_EXTI6_D (NVIC_ISER0&=~(1<<EXT6_IRQ))
#define NVIC_EXTI7_D (NVIC_ISER0&=~(1<<EXT7_IRQ))
#define NVIC_EXTI8_D (NVIC_ISER0&=~(1<<EXT8_IRQ))
#define NVIC_EXTI9_D (NVIC_ISER0&=~(1<<EXT9_IRQ))
#define NVIC_EXTI10_D (NVIC_ISER1&=~(1<<8))
#define NVIC_EXTI11_D (NVIC_ISER1&=~(1<<8))
#define NVIC_EXTI12_D (NVIC_ISER1&=~(1<<8))
#define NVIC_EXTI13_D (NVIC_ISER1&=~(1<<8))
#define NVIC_EXTI14_D (NVIC_ISER1&=~(1<<8))
#define NVIC_EXTI15_D (NVIC_ISER1&=~(1<<8))

// EXT0

#define EXT0PA0 (GPIO_CONFIG_t){EXTI0,GPIOA,PIN_0,EXT0_IRQ}
#define EXT0PB0 (GPIO_CONFIG_t){EXTI0,GPIOB,PIN_0,EXT0_IRQ}
#define EXT0PC0 (GPIO_CONFIG_t){EXTI0,GPIOC,PIN_0,EXT0_IRQ}
#define EXT0PD0 (GPIO_CONFIG_t){EXTI0,GPIOD,PIN_0,EXT0_IRQ}


// EXT1

#define EXT1PA1 (GPIO_CONFIG_t){EXTI1,GPIOA,PIN_1,EXT1_IRQ}
#define EXT1PB1 (GPIO_CONFIG_t){EXTI1,GPIOB,PIN_1,EXT1_IRQ}
#define EXT1PC1 (GPIO_CONFIG_t){EXTI1,GPIOC,PIN_1,EXT1_IRQ}
#define EXT1PD1 (GPIO_CONFIG_t){EXTI1,GPIOD,PIN_1,EXT1_IRQ}


// EXT2

#define EXT2PA2 (GPIO_CONFIG_t){EXTI2,GPIOA,PIN_2,EXT2_IRQ}
#define EXT2PB2 (GPIO_CONFIG_t){EXTI2,GPIOB,PIN_2,EXT2_IRQ}
#define EXT2PC2 (GPIO_CONFIG_t){EXTI2,GPIOC,PIN_2,EXT2_IRQ}
#define EXT2PD2 (GPIO_CONFIG_t){EXTI2,GPIOD,PIN_2,EXT2_IRQ}


// EXT3

#define EXT3PA3 (GPIO_CONFIG_t){EXTI3,GPIOA,PIN_3,EXT3_IRQ}
#define EXT3PB3 (GPIO_CONFIG_t){EXTI3,GPIOB,PIN_3,EXT3_IRQ}
#define EXT3PC3 (GPIO_CONFIG_t){EXTI3,GPIOC,PIN_3,EXT3_IRQ}
#define EXT3PD3 (GPIO_CONFIG_t){EXTI3,GPIOD,PIN_3,EXT3_IRQ}


// EXT4

#define EXT4PA4 (GPIO_CONFIG_t){EXTI4,GPIOA,PIN_4,EXT4_IRQ}
#define EXT4PB4 (GPIO_CONFIG_t){EXTI4,GPIOB,PIN_4,EXT4_IRQ}
#define EXT4PC4 (GPIO_CONFIG_t){EXTI4,GPIOC,PIN_4,EXT4_IRQ}
#define EXT4PD4 (GPIO_CONFIG_t){EXTI4,GPIOD,PIN_4,EXT4_IRQ}


// EXT5

#define EXT5PA5 (GPIO_CONFIG_t){EXTI5,GPIOA,PIN_5,EXT5_IRQ}
#define EXT5PB5 (GPIO_CONFIG_t){EXTI5,GPIOB,PIN_5,EXT5_IRQ}
#define EXT5PC5 (GPIO_CONFIG_t){EXTI5,GPIOC,PIN_5,EXT5_IRQ}
#define EXT5PD5 (GPIO_CONFIG_t){EXTI5,GPIOD,PIN_5,EXT5_IRQ}


// EXT6

#define EXT6PA6 (GPIO_CONFIG_t){EXTI6,GPIOA,PIN_6,EXT6_IRQ}
#define EXT6PB6 (GPIO_CONFIG_t){EXTI6,GPIOB,PIN_6,EXT6_IRQ}
#define EXT6PC6 (GPIO_CONFIG_t){EXTI6,GPIOC,PIN_6,EXT6_IRQ}
#define EXT6PD6 (GPIO_CONFIG_t){EXTI6,GPIOD,PIN_6,EXT6_IRQ}


// EXT7

#define EXT7PA7 (GPIO_CONFIG_t){EXTI7,GPIOA,PIN_7,EXT7_IRQ}
#define EXT7PB7 (GPIO_CONFIG_t){EXTI7,GPIOB,PIN_7,EXT7_IRQ}
#define EXT7PC7 (GPIO_CONFIG_t){EXTI7,GPIOC,PIN_7,EXT7_IRQ}
#define EXT7PD7 (GPIO_CONFIG_t){EXTI7,GPIOD,PIN_7,EXT7_IRQ}


// EXT8

#define EXT8PA8 (GPIO_CONFIG_t){EXTI8,GPIOA,PIN_8,EXT8_IRQ}
#define EXT8PB8 (GPIO_CONFIG_t){EXTI8,GPIOB,PIN_8,EXT8_IRQ}
#define EXT8PC8 (GPIO_CONFIG_t){EXTI8,GPIOC,PIN_8,EXT8_IRQ}
#define EXT8PD8 (GPIO_CONFIG_t){EXTI8,GPIOD,PIN_8,EXT8_IRQ}


// EXT9

#define EXT9PA9 (GPIO_CONFIG_t){EXTI9,GPIOA,PIN_9,EXT9_IRQ}
#define EXT9PB9 (GPIO_CONFIG_t){EXTI9,GPIOB,PIN_9,EXT9_IRQ}
#define EXT9PC9 (GPIO_CONFIG_t){EXTI9,GPIOC,PIN_9,EXT9_IRQ}
#define EXT9PD9 (GPIO_CONFIG_t){EXTI9,GPIOD,PIN_9,EXT9_IRQ}


// EXT10

#define EXT10PA10 (GPIO_CONFIG_t){EXTI10,GPIOA,PIN_10,EXT10_IRQ}
#define EXT10PB10 (GPIO_CONFIG_t){EXTI10,GPIOB,PIN_10,EXT10_IRQ}
#define EXT10PC10 (GPIO_CONFIG_t){EXTI10,GPIOC,PIN_10,EXT10_IRQ}
#define EXT10PD10 (GPIO_CONFIG_t){EXTI10,GPIOD,PIN_10,EXT10_IRQ}


// EXT11

#define EXT11PA11 (GPIO_CONFIG_t){EXTI11,GPIOA,PIN_11,EXT11_IRQ}
#define EXT11PB11 (GPIO_CONFIG_t){EXTI11,GPIOB,PIN_11,EXT11_IRQ}
#define EXT11PC11 (GPIO_CONFIG_t){EXTI11,GPIOC,PIN_11,EXT11_IRQ}
#define EXT11PD11 (GPIO_CONFIG_t){EXTI11,GPIOD,PIN_11,EXT11_IRQ}


// EXT12

#define EXT12PA12 (GPIO_CONFIG_t){EXTI12,GPIOA,PIN_12,EXT12_IRQ}
#define EXT12PB12 (GPIO_CONFIG_t){EXTI12,GPIOB,PIN_12,EXT12_IRQ}
#define EXT12PC12 (GPIO_CONFIG_t){EXTI12,GPIOC,PIN_12,EXT12_IRQ}
#define EXT12PD12 (GPIO_CONFIG_t){EXTI12,GPIOD,PIN_12,EXT12_IRQ}


//EXT13

#define EXT13PA13 (GPIO_CONFIG_t){EXTI13,GPIOA,PIN_13,EXT13_IRQ}
#define EXT13PB13 (GPIO_CONFIG_t){EXTI13,GPIOB,PIN_13,EXT13_IRQ}
#define EXT13PC13 (GPIO_CONFIG_t){EXTI13,GPIOC,PIN_13,EXT13_IRQ}
#define EXT13PD13 (GPIO_CONFIG_t){EXTI13,GPIOD,PIN_13,EXT13_IRQ}


// EXT14

#define EXT14PA14 (GPIO_CONFIG_t){EXTI14,GPIOA,PIN_14,EXT14_IRQ}
#define EXT14PB14 (GPIO_CONFIG_t){EXTI14,GPIOB,PIN_14,EXT14_IRQ}
#define EXT14PC14 (GPIO_CONFIG_t){EXTI14,GPIOC,PIN_14,EXT14_IRQ}
#define EXT14PD14 (GPIO_CONFIG_t){EXTI14,GPIOD,PIN_14,EXT14_IRQ}


// EXT15

#define EXT15PA15 (GPIO_CONFIG_t){EXTI15,GPIOA,PIN_15,EXT15_IRQ}
#define EXT15PB15 (GPIO_CONFIG_t){EXTI15,GPIOB,PIN_15,EXT15_IRQ}
#define EXT15PC15 (GPIO_CONFIG_t){EXTI15,GPIOC,PIN_15,EXT15_IRQ}
#define EXT15PD15 (GPIO_CONFIG_t){EXTI15,GPIOD,PIN_15,EXT15_IRQ}

// ==================================================================================
// ===================================== APIS =======================================
// ==================================================================================
	void MCAL_EXTI_init(EXTI_config_t *EXTI);
	void MCAL_EXTI_Deinit(void);
	void MCAL_EXTI_Update(EXTI_config_t *EXTI);



#endif /* INC_EXTI_DRIVER_H_ */
