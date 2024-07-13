/*
 * STM32F103x6.h
 *
 *  Created on: Jul 3, 2024
 *      Author: Ahmed
 */

#ifndef INC_STM32F103X6_H_
#define INC_STM32F103X6_H_

// ==================================================================================
// ==================================== INCLUDE =====================================
// ==================================================================================
#include <Platform_Types.h>


// ==================================================================================
// ========================== Base addresses for Memories ===========================
// ==================================================================================
#define FLASH_MEMORY_BASE 	0x08000000UL
#define SYS_MEMORY_BASE 	0x1FFFF000UL
#define SRAM_MEMORY_BASE 	0x20000000UL
#define NULL (0)

// ==================== Base addresses for  AHB BUS Peripherals =====================
#define RCC_BASE 0x40021000

// ==================== Base addresses for  APB1 BUS Peripherals ====================
#define SPI2_BASE	0x40003800
#define SPI3_BASE	0x40003C00
#define I2C1_BASE	0x40005400
#define I2C2_BASE	0x40005800


// ==================== Base addresses for  APB2 BUS Peripherals ====================
#define GPIOA_BASE 	0x40010800
#define GPIOB_BASE 	0x40010C00
#define GPIOC_BASE 	0x40011000
#define GPIOD_BASE 	0x40011400
#define GPIOE_BASE 	0x40011800
#define GPIOF_BASE 	0x40011C00
#define GPIOG_BASE 	0x40012000
#define EXTI_BASE  	0x40010400
#define AFIO_BASE  	0x40010000
#define USART1_BASE	0x40013800
#define USART2_BASE 0x40004400
#define USART3_BASE 0x40004800
#define SPI1_BASE	0x40013000
#define TIMER1_BASE 0x40012C00
#define TIMER2_BASE 0x40000000
#define TIMER3_BASE 0x40000400
#define TIMER4_BASE 0x40000800
#define CAN1_BASE 	0x40006400
#define ADC1_BASE	0x40012400
#define ADC2_BASE	0x40012800




#define SysTick_BASE  0xE000E010
#define NVIC_BASE 	0xE000E100
#define NVIC_ISER0 *((vuint32_t *) (NVIC_BASE+0x00))
#define NVIC_ISER1 *((vuint32_t *) (NVIC_BASE+0x04))
#define NVIC_ISER2 *((vuint32_t *) (NVIC_BASE+0x08))
#define NVIC_ICER0 *((vuint32_t *) (NVIC_BASE+0x080))
#define NVIC_ICER1 *((vuint32_t *) (NVIC_BASE+0x084))
#define NVIC_ICER2 *((vuint32_t *) (NVIC_BASE+0x088))

#define STK_LOAD *((vuint32_t *) (SysTick_BASE+0x04))
#define STK_VALUE *((vuint32_t *) (SysTick_BASE+0x04))
#define STK_CTRL *((vuint32_t * )(SysTick_BASE+0x00))

// ============================= Peripheral register: ===============================
typedef struct {
	vuint32_t CRL;
	vuint32_t CRH;
	vuint32_t IDR;
	vuint32_t ODR;
	vuint32_t BSRR;
	vuint32_t BRR;
	vuint32_t LCKR;
}GPIOx_REG;

typedef struct {
	vuint32_t EVCR;
	vuint32_t MAPR;
	vuint32_t EXTICR[4];
	uint32_t RESERVED;
	vuint32_t MAPR2;
}AFIOx_REG;

typedef struct {
	vuint32_t IMR;
	vuint32_t EMR;
	vuint32_t RTSR;
	vuint32_t FTSR;
	vuint32_t SWIER;
	vuint32_t PR;
}EXTI_REG;

typedef struct{
	vuint32_t CR;
	vuint32_t CFGR;
	vuint32_t CIR;
	vuint32_t APB2RSTR;
	vuint32_t APB1RSTR;
	vuint32_t AHBENR;
	vuint32_t APB2ENR;
	vuint32_t APB1ENR;
	vuint32_t BDCR;
	vuint32_t CSR;
	vuint32_t AHBSTR;
	vuint32_t CFGR2;
}RCC_REG;

typedef struct{
	vuint32_t SR;
	vuint32_t DR;
	vuint32_t BRR;
	vuint32_t CR1;
	vuint32_t CR2;
	vuint32_t CR3;
	vuint32_t GTPR;

}USART_REG;

typedef union{
	vuint32_t ALL_REG;
	struct 	CR1_BITS{
		vuint32_t CPHA:1;
		vuint32_t CPOL:1;
		vuint32_t MSTR:1;
		vuint32_t BR:3;
		vuint32_t SPE:1;
		vuint32_t LSBFIRST:1;
		vuint32_t SSI:1;
		vuint32_t SSM:1;
		vuint32_t RXONLY:1;
		vuint32_t DFF:1;
		vuint32_t CRCNEXT:1;
		vuint32_t CRCEN:1;
		vuint32_t BIDIOE:1;
		vuint32_t BIDIMODE:1;
		//		vuint32_t Reserved:16;
	}Bit_Name;
}CR1;

typedef union{
	vuint32_t ALL_REG;
	struct 	CR2_BITS{
		vuint32_t RXDMAEN:1;
		vuint32_t TXDMAEN:1;
		vuint32_t SSOE:1;
		vuint32_t Reserved:2;
		vuint32_t ERRIE:1;
		vuint32_t RXNEIE:1;
		vuint32_t TXEIE:1;
		//		vuint32_t Reserved1:24;

	}Bit_Name;
}CR2;

typedef union{
	vuint32_t ALL_REG;
	struct 	SR_BITS{
		vuint32_t RXNE:1;
		vuint32_t TXE:1;
		vuint32_t CHSIDE:1;
		vuint32_t UDR:1;
		vuint32_t CRCERR:1;
		vuint32_t MODF:1;
		vuint32_t OVR:1;
		vuint32_t BSY:1;
		//		vuint32_t Reserved:24;

	}Bit_Name;
}SR;

typedef union{
	vuint32_t ALL_REG;
	struct 	DR_BITS{
		vuint32_t DR0:1;
		vuint32_t DR1:1;
		vuint32_t DR2:1;
		vuint32_t DR3:1;
		vuint32_t DR4:1;
		vuint32_t DR5:1;
		vuint32_t DR6:1;
		vuint32_t DR7:1;
		vuint32_t DR8:1;
		vuint32_t DR9:1;
		vuint32_t DR10:1;
		vuint32_t DR11:1;
		vuint32_t DR12:1;
		vuint32_t DR13:1;
		vuint32_t DR14:1;
		vuint32_t DR15:1;
		//		vuint32_t Reserved:16;
	}Bit_Name;
}DR;

typedef struct {
	volatile CR1 SPI_CR1;
	volatile CR2 SPI_CR2;
	volatile SR SPI_SR;
	volatile DR DR_reg;
	vuint32_t CRCPR;
	vuint32_t RXCRCR;
	vuint32_t TXCRCR;
	vuint32_t I2SCFGR;
	vuint32_t I2SPR;

}SPI_Reg;

// ==================================================================================

typedef union{
	vuint32_t ALL_REG;
	struct 	I2C_CR1_BITS{
		vuint32_t PE:1;
		vuint32_t SMBUS:1;
		vuint32_t :1;
		vuint32_t SMBTYPE:1;
		vuint32_t ENARP:1;
		vuint32_t ENPEC:1;
		vuint32_t ENGC:1;
		vuint32_t NOSTRETCH:1;
		vuint32_t START:1;
		vuint32_t STOP:1;
		vuint32_t ACK:1;
		vuint32_t POS:1;
		vuint32_t PEC:1;
		vuint32_t ALERT:1;
		vuint32_t :1;
		vuint32_t SWRST:1;
		//		vuint32_t Reserved:16;
	}Bit_Name;
}I2C_CR1;

// ==================================================================================

typedef union{
	vuint32_t ALL_REG;
	struct 	I2C_CR2_BITS{
		vuint32_t FREQ:6;
		vuint32_t :2;
		vuint32_t ITERREN:1;
		vuint32_t ITEVTEN:1;
		vuint32_t ITBUFEN:1;
		vuint32_t DMAEN:1;
		vuint32_t LAST:1;

	}Bit_Name;
}I2C_CR2;

// ==================================================================================

typedef union{
	vuint32_t ALL_REG;
	struct 	I2C_OAR1_BITS{
		vuint32_t ADD0:1;
		vuint32_t ADD:7;
		vuint32_t ADD_10_BIT:2;
		vuint32_t :5;
		vuint32_t ADDMODE:1;

		//		vuint32_t Reserved:16;
	}Bit_Name;
}I2C_OAR1;

// ==================================================================================

typedef union{
	vuint32_t ALL_REG;
	struct 	I2C_OAR2_BITS{
		vuint32_t ENDUAL:1;
		vuint32_t ADD2:7;

		//		vuint32_t Reserved:16;
	}Bit_Name;
}I2C_OAR2;

// ==================================================================================

typedef union{
	vuint32_t ALL_REG;
	struct 	I2C_DR_BITS{
		vuint32_t DR0:1;
		vuint32_t DR1:1;
		vuint32_t DR2:1;
		vuint32_t DR3:1;
		vuint32_t DR4:1;
		vuint32_t DR5:1;
		vuint32_t DR6:1;
		vuint32_t DR7:1;

		//		vuint32_t Reserved:16;
	}Bit_Name;
}I2C_DR;

// ==================================================================================

typedef union{
	vuint32_t ALL_REG;
	struct 	I2C_SR1_BITS{
		vuint32_t SB:1;
		vuint32_t ADDR:1;
		vuint32_t BTF:1;
		vuint32_t ADD10:1;
		vuint32_t STOPF:1;
		vuint32_t :1;
		vuint32_t RxNE:1;
		vuint32_t TxE:1;
		vuint32_t BERR:1;
		vuint32_t ARLO:1;
		vuint32_t AF:1;
		vuint32_t OVR:1;
		vuint32_t PECERR:1;
		vuint32_t :1;
		vuint32_t TIMEOUT:1;
		vuint32_t SMBALERT:1;
		//		vuint32_t Reserved:16;
	}Bit_Name;
}I2C_SR1;

// ==================================================================================

typedef union{
	vuint32_t ALL_REG;
	struct 	I2C_SR2_BITS{
		vuint32_t MSL:1;
		vuint32_t BUSY:1;
		vuint32_t TRA:1;
		vuint32_t :1;
		vuint32_t GENCALL:1;
		vuint32_t SMBDEFAULT:1;
		vuint32_t SMBHOST:1;
		vuint32_t DUALF:1;
		vuint32_t PEC:8;

		//		vuint32_t Reserved:16;
	}Bit_Name;
}I2C_SR2;

// ==================================================================================

typedef union{
	vuint32_t ALL_REG;
	struct 	I2C_CCR_BITS{
		vuint32_t CCR:12;
		vuint32_t :2;
		vuint32_t DUTY:1;
		vuint32_t F_S:1;

		//		vuint32_t Reserved:16;
	}Bit_Name;
}I2C_CCR;

// ==================================================================================

typedef union{
	vuint32_t ALL_REG;
	struct 	I2C_TRISE_BITS{
		vuint32_t TRISE:6;

		//		vuint32_t Reserved:16;
	}Bit_Name;
}I2C_TRISE;

// ================================== I2C STRUCT ====================================

typedef struct {
	volatile I2C_CR1 CR1;
	volatile I2C_CR2 CR2;
	volatile I2C_OAR1 OAR1;
	volatile I2C_OAR2 OAR2;
	volatile I2C_DR DR;
	volatile I2C_SR1 SR1;
	volatile I2C_SR2 SR2;
	volatile I2C_CCR CCR;
	volatile I2C_TRISE TRISE;
}I2C_REG;

// ================================== TIMERS 1&8 ====================================

typedef union {
	vuint32_t ALL_BITS;
	struct AD_TIMx_CR1_BITS{
		vuint32_t CEN:1;
		vuint32_t UDIS:1;
		vuint32_t URS:1;
		vuint32_t OPM:1;
		vuint32_t DIR:1;
		vuint32_t CMS:2;
		vuint32_t ARPE:1;
		vuint32_t CKD:2;
		vuint32_t :22;
	}BIT_NAME;
}AD_TIMx_CR1;

typedef union {
	vuint32_t ALL_BITS;
	struct AD_TIMx_CR2_BITS{
		vuint32_t CCPC:1;
		vuint32_t :1;
		vuint32_t CCUS:1;
		vuint32_t CCDS:1;
		vuint32_t MMS:3;
		vuint32_t TI1S:1;
		vuint32_t OIS1:1;
		vuint32_t OIS1N:1;
		vuint32_t OIS2:1;
		vuint32_t OIS2N:1;
		vuint32_t OIS3:1;
		vuint32_t OIS3N:1;
		vuint32_t OIS4:1;
		vuint32_t :17;
	}BIT_NAME;
}AD_TIMx_CR2;

typedef union {
	vuint32_t ALL_BITS;
	struct SMCR_BITS{
		vuint32_t SMS:3;
		vuint32_t :1;
		vuint32_t TS:3;
		vuint32_t MSM:1;
		vuint32_t ETF:4;
		vuint32_t ETPS:2;
		vuint32_t ECE:1;
		vuint32_t ETP:1;
		vuint32_t :16;
	}BIT_NAME;
}AD_TIMx_SMCR;

// ==================================================================================

typedef union {
	vuint32_t ALL_BITS;
	struct DIER_BITS{
		vuint32_t UIE:1;
		vuint32_t CC1IE:1;
		vuint32_t CC2IE:1;
		vuint32_t CC3IE:1;
		vuint32_t CC4IE:1;
		vuint32_t COMIE:1;
		vuint32_t TIE:1;
		vuint32_t BIE:1;
		vuint32_t UDE:1;
		vuint32_t CC1DE:1;
		vuint32_t CC2DE:1;
		vuint32_t CC3DE:1;
		vuint32_t CC4DE:1;
		vuint32_t COMDE:1;
		vuint32_t TDE:1;
		vuint32_t :17;
	}BIT_NAME;
}AD_TIMx_DIER;

// ==================================================================================

typedef union {
	vuint32_t ALL_BITS;
	struct AD_TIMx_SR_BITS{
		vuint32_t UIF:1;
		vuint32_t CC1IF:1;
		vuint32_t CC2IF:1;
		vuint32_t CC3IF:1;
		vuint32_t CC4IF:1;
		vuint32_t COMIF:1;
		vuint32_t TIF:1;
		vuint32_t BIF:1;
		vuint32_t :1;
		vuint32_t CC1OF:1;
		vuint32_t CC2OF:1;
		vuint32_t CC3OF:1;
		vuint32_t CC4OF:1;
		vuint32_t :19;
	}BIT_NAME;
}AD_TIMx_SR;

typedef union {
	vuint32_t ALL_BITS;
	struct EGR_BITS{
		vuint32_t UG:1;
		vuint32_t CC1G:1;
		vuint32_t CC2G:1;
		vuint32_t CC3G:1;
		vuint32_t CC4G:1;
		vuint32_t COMG:1;
		vuint32_t TG:1;
		vuint32_t BG:1;
		vuint32_t :24;
	}BIT_NAME;
}AD_TIMx_EGR;

typedef union {
	vuint32_t ALL_BITS;
	//  There is two REG share the same mem location (Compare_mode_BITS+input_Capture_BITS)
	struct CCMR1_Compare_mode_BITS{
		vuint32_t CC1S:2;
		vuint32_t OC1FE:1;
		vuint32_t OC1PE:1;
		vuint32_t OC1M:3;
		vuint32_t OC1CE:1;
		vuint32_t CC2S:2;
		vuint32_t OC2FE:1;
		vuint32_t OC2PE:1;
		vuint32_t OC2M:3;
		vuint32_t OC2CE:1;
		vuint32_t :16;

	}Compare_BIT_NAME;

	// ==============================================================================

	struct CCMR1_input_Capture_BITS{
		vuint32_t CC1S:2;
		vuint32_t IC1PSC:2;
		vuint32_t IC1F:4;
		vuint32_t CC2S:2;
		vuint32_t IC2PSC:2;
		vuint32_t IC2F:4;
		vuint32_t :16;
	}input_NAME;
}AD_TIMx_CCMR1;

typedef union {
	vuint32_t ALL_BITS;
	// There is two REG share the same mem location (Compare_mode_BITS+input_Capture_BITS)
	struct CCMR2_Compare_mode_BITS{
		vuint32_t CC3S:2;
		vuint32_t OC3FE:1;
		vuint32_t OC3PE:1;
		vuint32_t OC3M:3;
		vuint32_t OC3CE:1;
		vuint32_t CC4S:2;
		vuint32_t OC4FE:1;
		vuint32_t OC4PE:1;
		vuint32_t OC4M:3;
		vuint32_t O24CE:1;
		vuint32_t :16;
	}Compare_BIT_NAME;

	// ==============================================================================

	struct CCMR2_input_Capture_BITS{
		vuint32_t CC3S:2;
		vuint32_t IC3PSC:2;
		vuint32_t IC3F:4;
		vuint32_t CC4S:2;
		vuint32_t IC4PSC:2;
		vuint32_t IC4F:4;
		vuint32_t :16;
	}input_NAME;
}AD_TIMx_CCMR2;

typedef union {
	vuint32_t ALL_BITS;
	struct CCER_BITS{
		vuint32_t CC1E:1;
		vuint32_t CC1P:1;
		vuint32_t CC1NE:1;
		vuint32_t CC1NP:1;
		vuint32_t CC2E:1;
		vuint32_t CC2P:1;
		vuint32_t CC2NE:1;
		vuint32_t CC2NP:1;

		vuint32_t CC3E:1;
		vuint32_t CC3P:1;
		vuint32_t CC3NE:1;
		vuint32_t CC3NP:1;
		vuint32_t CC4E:1;
		vuint32_t CC4P:1;

		vuint32_t :18;
	}BIT_NAME;
}AD_TIMx_CCER;

typedef union {
	vuint32_t ALL_BITS;
	struct BDTR_BITS{
		vuint32_t DT:8;
		vuint32_t LOCK:2;
		vuint32_t OSSI:1;
		vuint32_t OSSR:1;
		vuint32_t BKE:1;
		vuint32_t BKP:1;
		vuint32_t AOE:1;
		vuint32_t MOE:1;
		vuint32_t :16;
	}BIT_NAME;
}AD_TIMx_BDTR;

typedef union {
	vuint32_t ALL_BITS;
	struct DCR_BITS{
		vuint32_t DBA:5;
		vuint32_t :3;
		vuint32_t DBL:5;
		vuint32_t :13;
	}BIT_NAME;
}AD_TIMx_DCR;

// ==================================================================================

typedef struct{
	volatile	AD_TIMx_CR1 	CR1;
	volatile	AD_TIMx_CR2 	CR2;
	volatile	AD_TIMx_SMCR 	SMCR;
	volatile	AD_TIMx_DIER 	DIER;
	volatile	AD_TIMx_SR 	SR;
	volatile	AD_TIMx_EGR 	EGR;
	volatile	AD_TIMx_CCMR1 	CCMR1;
	volatile	AD_TIMx_CCMR2 	CCMR2;
	volatile	AD_TIMx_CCER 	CCER;
	volatile	uint32_t 	CNT;
	volatile	uint32_t 	PSC;
	volatile	uint32_t 	ARR;
	volatile	uint32_t 	RCR;
	volatile	uint32_t 	CCR1;
	volatile	uint32_t 	CCR2;
	volatile	uint32_t 	CCR3;
	volatile	uint32_t 	CCR4;
	volatile	AD_TIMx_BDTR 	BDTR;
	volatile	AD_TIMx_DCR 	DCR;
	volatile	uint32_t 	DMAR;
}TIM1_8_REG;



// ==================================== GP_TIMERs ===================================

typedef union {
	vuint32_t ALL_BITS;
	struct GP_TIMx_CR1_BITS{
		vuint32_t CEN:1;
		vuint32_t UDIS:1;
		vuint32_t URS:1;
		vuint32_t OPM:1;
		vuint32_t DIR:1;
		vuint32_t CMS:2;
		vuint32_t ARPE:1;
		vuint32_t CKD:2;
		vuint32_t :22;
	}BIT_NAME;
}GP_TIMx_CR1;

// ================ @GP_TIMx_CR2 specify the CR2 reg from datasheet =================
typedef union {
	vuint32_t ALL_BITS;
	struct GP_TIMx_CR2_BITS{
		vuint32_t :3;
		vuint32_t CCDS:1;
		vuint32_t MMS:3;
		vuint32_t TI1S:1;
		vuint32_t :24;
	}BIT_NAME;
}GP_TIMx_CR2;

// =============== @GP_TIMx_SMCR specify the SMCR reg from datasheet ================
typedef union {
	vuint32_t ALL_BITS;
	struct GP_TIMx_SMCR_BITS{
		vuint32_t SMS:3;
		vuint32_t :1;
		vuint32_t TS:3;
		vuint32_t MSM:1;
		vuint32_t ETF:4;
		vuint32_t ETPS:2;
		vuint32_t ECE:1;
		vuint32_t ETP:1;
		vuint32_t :16;
	}BIT_NAME;
}GP_TIMx_SMCR;

// =============== @GP_TIMx_DIER specify the DIER reg from datasheet ================
typedef union {
	vuint32_t ALL_BITS;
	struct GP_TIMx_DIER_BITS{
		vuint32_t UIE:1;
		vuint32_t CC1IE:1;
		vuint32_t CC2IE:1;
		vuint32_t CC3IE:1;
		vuint32_t CC4IE:1;
		vuint32_t :1;
		vuint32_t TIE:1;
		vuint32_t :1;
		vuint32_t UDE:1;
		vuint32_t CC1DE:1;
		vuint32_t CC2DE:1;
		vuint32_t CC3DE:1;
		vuint32_t CC4DE:1;
		vuint32_t COMDE:1;
		vuint32_t TDE:1;
		vuint32_t :17;
	}BIT_NAME;
}GP_TIMx_DIER;

// ================== @GP_TIMx_SR specify the SR reg from datasheet =================
typedef union {
	vuint32_t ALL_BITS;
	struct GP_TIMx_SR_BITS{
		vuint32_t UIF:1;
		vuint32_t CC1IF:1;
		vuint32_t CC2IF:1;
		vuint32_t CC3IF:1;
		vuint32_t CC4IF:1;
		vuint32_t :1;
		vuint32_t TIF:1;
		vuint32_t :2;
		vuint32_t CC1OF:1;
		vuint32_t CC2OF:1;
		vuint32_t CC3OF:1;
		vuint32_t CC4OF:1;
		vuint32_t :19;
	}BIT_NAME;
}GP_TIMx_SR;

// ================ @GP_TIMx_DIER specify the DIER reg from datasheet ===============
typedef union {
	vuint32_t ALL_BITS;
	struct GP_TIMx_EGR_BITS{
		vuint32_t UG:1;
		vuint32_t CC1G:1;
		vuint32_t CC2G:1;
		vuint32_t CC3G:1;
		vuint32_t CC4G:1;
		vuint32_t :1;
		vuint32_t TG:1;
		vuint32_t :25;
	}BIT_NAME;
}GP_TIMx_EGR;

typedef union {
	vuint32_t ALL_BITS;
	//  There is two REG share the same mem location (Compare_mode_BITS+input_Capture_BITS)
	struct GP_TIMx_CCMR1_Compare_mode_BITS{
		vuint32_t CC1S:2;
		vuint32_t OC1FE:1;
		vuint32_t OC1PE:1;
		vuint32_t OC1M:3;
		vuint32_t OC1CE:1;
		vuint32_t CC2S:2;
		vuint32_t OC2FE:1;
		vuint32_t OC2PE:1;
		vuint32_t OC2M:3;
		vuint32_t OC2CE:1;
		vuint32_t :16;
	}Compare_BIT_NAME;

	// ==============================================================================

	struct GP_TIMx_CCMR1_input_Capture_BITS{
		vuint32_t CC1S:2;
		vuint32_t IC1PSC:2;
		vuint32_t IC1F:4;
		vuint32_t CC2S:2;
		vuint32_t IC2PSC:2;
		vuint32_t IC2F:4;
		vuint32_t :16;
	}input_NAME;
}GP_TIMx_CCMR1;

typedef union {
	vuint32_t ALL_BITS;
	//  There is two REG share the same mem location (Compare_mode_BITS+input_Capture_BITS)
	struct GP_TIMx_CCMR2_Compare_mode_BITS{
		vuint32_t CC3S:2;
		vuint32_t OC3FE:1;
		vuint32_t OC3PE:1;
		vuint32_t OC3M:3;
		vuint32_t OC3CE:1;
		vuint32_t CC4S:2;
		vuint32_t OC4FE:1;
		vuint32_t OC4PE:1;
		vuint32_t OC4M:3;
		vuint32_t O24CE:1;
		vuint32_t :16;
	}Compare_BIT_NAME;

	// ==============================================================================

	struct GP_TIMx_CCMR2_input_Capture_BITS{
		vuint32_t CC3S:2;
		vuint32_t IC3PSC:2;
		vuint32_t IC3F:4;
		vuint32_t CC4S:2;
		vuint32_t IC4PSC:2;
		vuint32_t IC4F:4;
		vuint32_t :16;
	}input_NAME;
}GP_TIMx_CCMR2;

typedef union {
	vuint32_t ALL_BITS;
	struct GP_TIMx_CCER_BITS{
		vuint32_t CC1E:1;
		vuint32_t CC1P:1;
		vuint32_t :2;
		vuint32_t CC2E:1;
		vuint32_t CC2P:1;
		vuint32_t :2;
		vuint32_t CC3E:1;
		vuint32_t CC3P:1;
		vuint32_t :2;
		vuint32_t CC4E:1;
		vuint32_t CC4P:1;

		vuint32_t :18;
	}BIT_NAME;
}GP_TIMx_CCER;

typedef union {
	vuint32_t ALL_BITS;
	struct GP_TIMx_DCR_BITS{
		vuint32_t DBA:5;
		vuint32_t :3;
		vuint32_t DBL:5;
		vuint32_t :13;
	}BIT_NAME;
}GP_TIMx_DCR;

// ==================================================================================

typedef struct{
	volatile	GP_TIMx_CR1 	CR1;
	volatile	GP_TIMx_CR2 	CR2;
	volatile	GP_TIMx_SMCR 	SMCR;
	volatile	GP_TIMx_DIER 	DIER;
	volatile	GP_TIMx_SR 		SR;
	volatile	GP_TIMx_EGR 	EGR;
	volatile	GP_TIMx_CCMR1 	CCMR1;
	volatile	GP_TIMx_CCMR2 	CCMR2;
	volatile	GP_TIMx_CCER 	CCER;
	volatile	uint32_t 	CNT;
	volatile	uint32_t 	PSC;
	volatile	uint32_t 	ARR;
	volatile	uint32_t 	RCR;
	volatile	uint32_t 	CCR1;
	volatile	uint32_t 	CCR2;
	volatile	uint32_t 	CCR3;
	volatile	uint32_t 	CCR4;
	volatile	uint32_t 	Reserved;
	volatile	GP_TIMx_DCR 	DCR;
	volatile	uint32_t 	DMAR;
}GP_TIMx_REG;


// ==================================================================================
// ====================================== ADC =======================================
// ==================================================================================

// ===================================== ADC SR =====================================
typedef union{
	volatile uint32_t ALL_Bits;
	struct ADC_SR_Bit_Name{
		volatile uint32_t AWD:1;
		volatile uint32_t EOC:1;
		volatile uint32_t JEOC:1;
		volatile uint32_t JSTRT:1;
		volatile uint32_t STRT:1;
	}Bit_Name;
}ADC_SR;

// ==================================== ADC CR1 =====================================
typedef union{
	volatile uint32_t ALL_Bits;
	struct ADC_CR1_Bit_Name{
		volatile uint32_t AWDCH:5;
		volatile uint32_t EOCIE:1;
		volatile uint32_t AWDIE:1;
		volatile uint32_t JEOCIE:1;
		volatile uint32_t SCAN:1;
		volatile uint32_t AWDSGL:1;
		volatile uint32_t JAUTO:1;
		volatile uint32_t DISCEN:1;
		volatile uint32_t JDISCEN:1;
		volatile uint32_t DISCNUM:3;
		volatile uint32_t DUALMOD:4;
		volatile uint32_t :2;
		volatile uint32_t JAWDEN:1;
		volatile uint32_t AWDEN:1;
	}Bit_Name;
}ADC_CR1;

// ==================================== ADC CR2 =====================================
typedef union{
	volatile uint32_t ALL_Bits;
	struct ADC_CR2_Bit_Name{
		volatile uint32_t ADON:1;
		volatile uint32_t CONT:1;
		volatile uint32_t CAL:1;
		volatile uint32_t RSTCAL:1;
		volatile uint32_t :4;
		volatile uint32_t DMA:1;
		volatile uint32_t :2;
		volatile uint32_t ALIGN:1;
		volatile uint32_t JEXTSEL:1;
		volatile uint32_t JEXTTRIG:1;
		volatile uint32_t :1;
		volatile uint32_t EXTSEL:3;
		volatile uint32_t EXTTRIG:1;
		volatile uint32_t JSWSTART:1;
		volatile uint32_t SWSTART:1;
		volatile uint32_t TSVREFE:1;
	}Bit_Name;
}ADC_CR2;

// =================================== ADC SMPR2 =====================================
typedef union{
	volatile uint32_t ALL_Bits;
	struct ADC_SMPR2_Bit_Name{
		volatile uint32_t SMP0:3;
		volatile uint32_t SMP1:3;
		volatile uint32_t SMP2:3;
		volatile uint32_t SMP3:3;
		volatile uint32_t SMP4:3;
		volatile uint32_t SMP5:3;
		volatile uint32_t SMP6:3;
		volatile uint32_t SMP7:3;
		volatile uint32_t SMP8:3;
		volatile uint32_t SMP9:3;
	}Bit_Name;
}ADC_SMPR2;

// =================================== ADC SMPR1 =====================================
typedef union{
	volatile uint32_t ALL_Bits;
	struct ADC_SMPR1_Bit_Name{
		volatile uint32_t SMP10:3;
		volatile uint32_t SMP11:3;
		volatile uint32_t SMP12:3;
		volatile uint32_t SMP13:3;
		volatile uint32_t SMP14:3;
		volatile uint32_t SMP15:3;
		volatile uint32_t SMP16:3;
		volatile uint32_t SMP17:3;
	}Bit_Name;
}ADC_SMPR1;

// =================================== ADC JOFR1 =====================================
typedef union{
	volatile uint32_t ALL_Bits;
	struct ADC_JOFR1_Bit_Name{
		volatile uint32_t JOFFSET1:12;

	}Bit_Name;
}ADC_JOFR1;

// =================================== ADC JOFR2 =====================================
typedef union{
	volatile uint32_t ALL_Bits;
	struct ADC_JOFR2_Bit_Name{
		volatile uint32_t JOFFSET2:12;

	}Bit_Name;
}ADC_JOFR2;

// =================================== ADC JOFR3 =====================================
typedef union{
	volatile uint32_t ALL_Bits;
	struct ADC_JOFR3_Bit_Name{
		volatile uint32_t JOFFSET3:12;

	}Bit_Name;
}ADC_JOFR3;

// =================================== ADC JOFR4 =====================================
typedef union{
	volatile uint32_t ALL_Bits;
	struct ADC_JOFR4_Bit_Name{
		volatile uint32_t JOFFSET4:12;

	}Bit_Name;
}ADC_JOFR4;

// ==================================== ADC HTR =====================================
typedef union{
	volatile uint32_t ALL_Bits;
	struct ADC_HTR_Bit_Name{
		volatile uint32_t HT:12;

	}Bit_Name;
}ADC_HTR;

// ==================================== ADC LTR =====================================
typedef union{
	volatile uint32_t ALL_Bits;
	struct ADC_LTR_Bit_Name{
		volatile uint32_t LT:12;
	}Bit_Name;
}ADC_LTR;

// ==================================== ADC SQR1 ====================================
typedef union{
	volatile uint32_t ALL_Bits;
	struct ADC_SQR1_Bit_Name{
		volatile uint32_t SQ13:5;
		volatile uint32_t SQ14:5;
		volatile uint32_t SQ15:5;
		volatile uint32_t SQ16:5;
		volatile uint32_t L:4;
	}Bit_Name;
}ADC_SQR1;

// ==================================== ADC SQR2 ====================================
typedef union{
	volatile uint32_t ALL_Bits;
	struct ADC_SQR2_Bit_Name{
		volatile uint32_t SQ7:5;
		volatile uint32_t SQ8:5;
		volatile uint32_t SQ9:5;
		volatile uint32_t SQ10:5;
		volatile uint32_t SQ11:5;
		volatile uint32_t SQ12:5;
	}Bit_Name;
}ADC_SQR2;

// ==================================== ADC SQR3 ====================================
typedef union{
	volatile uint32_t ALL_Bits;
	struct ADC_SQR3_Bit_Name{
		volatile uint32_t SQ1:5;
		volatile uint32_t SQ2:5;
		volatile uint32_t SQ3:5;
		volatile uint32_t SQ4:5;
		volatile uint32_t SQ5:5;
		volatile uint32_t SQ6:5;
	}Bit_Name;
}ADC_SQR3;

// ==================================== ADC JSQR ====================================
typedef union{
	volatile uint32_t ALL_Bits;
	struct ADC_JSQR_Bit_Name{
		volatile uint32_t JSQ1:5;
		volatile uint32_t JSQ2:5;
		volatile uint32_t JSQ3:5;
		volatile uint32_t JSQ4:5;
		volatile uint32_t JL:4;

	}Bit_Name;
}ADC_JSQR;

// ==================================== ADC JDR1 ====================================
typedef union{
	volatile uint32_t ALL_Bits;
	struct ADC_JDR1_Bit_Name{
		volatile uint32_t JDATA:16;

	}Bit_Name;
}ADC_JDR1;

// ==================================== ADC JDR2 ====================================
typedef union{
	volatile uint32_t ALL_Bits;
	struct ADC_JDR2_Bit_Name{
		volatile uint32_t JDATA:16;

	}Bit_Name;
}ADC_JDR2;

// ==================================== ADC JDR3 ====================================
typedef union{
	volatile uint32_t ALL_Bits;
	struct ADC_JDR3_Bit_Name{
		volatile uint32_t JDATA:16;

	}Bit_Name;
}ADC_JDR3;

// ==================================== ADC JDR4 ====================================
typedef union{
	volatile uint32_t ALL_Bits;
	struct ADC_JDR4_Bit_Name{
		volatile uint32_t JDATA:16;

	}Bit_Name;
}ADC_JDR4;

// ==================================== ADC DR ======================================
typedef union{
	volatile uint32_t ALL_Bits;
	struct ADC_DR_Bit_Name{
		volatile uint32_t Regular_DATA:16;
		volatile uint32_t ADC2DATA:16;


	}Bit_Name;
}ADC_DR;


// ================================ ADC FINAL STRUCT ================================
typedef struct{
	ADC_SR		SR;
	ADC_CR1		CR1;
	ADC_CR2		CR2;
	ADC_SMPR1	SMPR1;
	ADC_SMPR2	SMPR2;
	ADC_JOFR1	JOFR1 ;
	ADC_JOFR2	JOFR2;
	ADC_JOFR3	JOFR3;
	ADC_JOFR4	JOFR4;
	ADC_HTR		HTR;
	ADC_LTR		LTR;
	ADC_SQR1	SQR1;
	ADC_SQR2	SQR2;
	ADC_SQR3	SQR3;
	ADC_JSQR	JSQR;
	ADC_JDR1	JDR1;
	ADC_JDR2	JDR2;
	ADC_JDR3	JDR3;
	ADC_JDR4	JDR4;
	ADC_DR		DR;
}ADCx_REG;


// ==================================================================================
// ============================== Peripheral Instants ===============================
// ==================================================================================
#define GPIOA		((GPIOx_REG *) GPIOA_BASE)
#define GPIOB		((GPIOx_REG *) GPIOB_BASE)
#define GPIOC		((GPIOx_REG *) GPIOC_BASE)
#define GPIOD		((GPIOx_REG *) GPIOD_BASE)
#define GPIOE		((GPIOx_REG *) GPIOE_BASE)
#define GPIOF		((GPIOx_REG *) GPIOF_BASE)
#define GPIOG		((GPIOx_REG *) GPIOG_BASE)
#define RCC   		((RCC_REG   *)  RCC_BASE )
#define EXTI_REG	((EXTI_REG  *)  EXTI_BASE)
#define AFIO		((AFIOx_REG *) AFIO_BASE )
#define USART1		((USART_REG *) USART1_BASE)
#define USART2		((USART_REG *) USART2_BASE)
#define USART3		((USART_REG *) USART3_BASE)
#define SPI1		((SPI_Reg *) SPI1_BASE)
#define SPI2		((SPI_Reg *) SPI2_BASE)
#define SPI3		((SPI_Reg *) SPI3_BASE)
#define I2C1		((I2C_config_t *) I2C1_BASE)
#define I2C2		((I2C_config_t *) I2C2_BASE)
#define TIM1		((TIM1_8_REG *)TIMER1_BASE)
#define TIM2		((GP_TIMx_REG *)TIMER2_BASE)
#define TIM3		((GP_TIMx_REG *)TIMER3_BASE)
#define TIM4		((GP_TIMx_REG *)TIMER4_BASE)
#define CAN1		((CANx_REG *)(CAN1_BASE))
#define ADC1		((ADCx_REG*)ADC1_BASE)
#define ADC2		((ADCx_REG*)ADC2_BASE)

// ==================================================================================
// ============================== CLOCK Enable Macros ===============================
// ==================================================================================
//Enable clock GPIOA
#define RCC_GPIOA_CLK_EN()	( RCC->APB2ENR |= (1<<2) )
//Enable clock GPIOB
#define RCC_GPIOB_CLK_EN()	( RCC->APB2ENR |= (1<<3) )
#define RCC_GPIOC_CLK_EN()	( RCC->APB2ENR |= (1<<4) )
#define RCC_GPIOD_CLK_EN()	( RCC->APB2ENR |= (1<<5) )
#define RCC_GPIOE_CLK_EN()	( RCC->APB2ENR |= (1<<6) )

#define RCC_AFIO_CLK_EN()	( RCC->APB2ENR |= (1<<0) )

#define RCC_USART1_CLK_EN()	( RCC->APB2ENR |= (1<<14) )
#define RCC_USART2_CLK_EN()	( RCC->APB1ENR |= (1<<17) )
#define RCC_USART3_CLK_EN()	( RCC->APB1ENR |= (1<<18) )

#define RCC_SPI1_CLK_EN()	( RCC->APB2ENR |= (1<<12) )
#define RCC_SPI2_CLK_EN()	( RCC->APB1ENR |= (1<<14) )

#define RCC_I2C1_CLK_EN()	(RCC->APB1ENR |= 1<<21)
#define RCC_I2C2_CLK_EN()	(RCC->APB1ENR |= 1<<22)

//RCC_Reset
#define RCC_USART1_Reset()	( RCC->APB2RSTR |= (1<<14) )
#define RCC_USART2_Reset()	( RCC->APB1RSTR |= (1<<17) )
#define RCC_USART3_Reset()	( RCC->APB1RSTR |= (1<<18) )

#define RCC_SPI1_Reset()	( RCC->APB2RSTR |= (1<<12) )
#define RCC_SPI2_Reset()	( RCC->APB1RSTR |= (1<<14) )

#define RCC_I2C1_Reset()	(RCC->APB1RSTR |= 1<<21)
#define RCC_I2C2_Reset()	(RCC->APB1RSTR |= 1<<22)

// ==================================================================================
// ================================= Generic Macros =================================
// ==================================================================================



#endif /* INC_STM32F103X6_H_ */
