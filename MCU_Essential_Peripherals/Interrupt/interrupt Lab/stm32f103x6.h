/*
 * stm32f103x6.h
 *
 *  Created on: Dec 14, 2024
 *      Author: Ahmed Elnabawe
 */

#ifndef INC_STM32F103X6_H_
#define INC_STM32F103X6_H_

//------------------------------------------//
//---------------- INCLUDES ----------------//
//------------------------------------------//
#include "stdlib.h"
#include <stdint.h>
//----------------------------------------------------------//
//---------------- BASE ADRESESS OF MEMORY ----------------//
//----------------------------------------------------------//
#define FLASH_MEMORY_BASE 			0x08000000UL
#define SYSTEM_MEMORY_BASE		 	0x1ffff000UL
#define PERIPHERALS_BASE 			0x40000000UL
#define CORTEX_M3_PERIPHERALS_BASE 	0xE0000000UL
//------------------------------------------------------------//
//---------------- PERIPHERALS BASE ADRESESS  ----------------//
//------------------------------------------------------------//

//---------------- AHB ----------------//
// RCC //
#define 	RCC_BASE 				0x40021000UL
//---------------- APB2 ----------------//
// GPIO //
// IN LQFP48
// GPIOA and GPIOB fully included
#define 	GPIOA_BASE 				0x40010800UL
#define 	GPIOB_BASE 				0x40010C00UL

// GPIOC and GPIOD partially included
#define 	GPIOC_BASE 				0x40011000UL
#define 	GPIOD_BASE 				0x40011400UL
// GPIOE not included
#define 	GPIOE_BASE 				0x40011800UL
// EXTI //
#define 	EXTI_BASE 				0x40010400L
// AFIO //
#define 	AFIO_BASE 				0x40010000UL




//------------------------ Core Registers ----------------------//
#define NVIC_BASE					0xE000E100UL
#define NVIC_ISER0					*(volatile uint32_t *)(NVIC_BASE+0x000)
#define NVIC_ISER1					*(volatile uint32_t *)(NVIC_BASE+0x004)
#define NVIC_ISER2					*(volatile uint32_t *)(NVIC_BASE+0x008)
#define NVIC_ICER0					*(volatile uint32_t *)(NVIC_BASE+0x080)
#define NVIC_ICER1					*(volatile uint32_t *)(NVIC_BASE+0x084)
#define NVIC_ICER2					*(volatile uint32_t *)(NVIC_BASE+0x088)

//================================================================//
//--------------------------------------------------------//
//---------------- PERIPHERALS REGISTERS ----------------//
//------------------------------------------------------//
// GPIO REGISTERS //
typedef struct {
	volatile uint32_t CRL;
	volatile uint32_t CRH;
	volatile uint32_t IDR;
	volatile uint32_t ODR;
	volatile uint32_t BSRR;
	volatile uint32_t BRR;
	volatile uint32_t LCKR;
}GPIO_TypeDef;
// AFIO REGISTERS //
typedef struct {
	volatile uint32_t EVCR;
	volatile uint32_t MAPR;
	volatile uint32_t EXTICR[4];
			 uint32_t RESERVED;
	volatile uint32_t MAPR2;
}AFIO_TypeDef;
// EXTI REGISTERS //
typedef struct {
	volatile uint32_t IMR;
	volatile uint32_t EMR;
	volatile uint32_t RTSR;
	volatile uint32_t FTSR;
	volatile uint32_t SWIER;
	volatile uint32_t PR;
}EXTI_TypeDef;
// RCC REGISTERS //
typedef struct {
	volatile uint32_t CR;
	volatile uint32_t CFGR;
	volatile uint32_t CIR;
	volatile uint32_t APB2RSTR;
	volatile uint32_t APB1RSTR;
	volatile uint32_t AHBENR;
	volatile uint32_t APB2ENR;
	volatile uint32_t APB1ENR;
	volatile uint32_t BDCR;
	volatile uint32_t CSR;
	volatile uint32_t AHBSTR;
	volatile uint32_t CFGR2;
}RCC_TypeDef;

//================================================================//
//--------------------------------------------------------//
//---------------- PERIPHERALS INSTANTS ----------------//
//------------------------------------------------------//
#define GPIOA 	((GPIO_TypeDef *)GPIOA_BASE)
#define GPIOB 	((GPIO_TypeDef *)GPIOB_BASE)
#define GPIOC 	((GPIO_TypeDef *)GPIOC_BASE)
#define GPIOD 	((GPIO_TypeDef *)GPIOD_BASE)
#define GPIOE 	((GPIO_TypeDef *)GPIOE_BASE)
#define RCC 	((RCC_TypeDef *)RCC_BASE)
#define EXTI 	((EXTI_TypeDef *)EXTI_BASE)
#define AFIO 	((AFIO_TypeDef *)AFIO_BASE)
//================================================================//
//--------------------------------------------------------//
//---------------- CLK ENABLE MACROS ----------------//
//------------------------------------------------------//
#define  GPIOA_CLK_EN() 			(RCC->APB2ENR |= 1<<2)
#define  GPIOB_CLK_EN() 			(RCC->APB2ENR |= 1<<3)
#define  GPIOC_CLK_EN() 			(RCC->APB2ENR |= 1<<4)
#define  GPIOD_CLK_EN() 			(RCC->APB2ENR |= 1<<5)
#define  GPIOE_CLK_EN() 			(RCC->APB2ENR |= 1<<6)
#define  AFIO_CLK_EN() 				(RCC->APB2ENR |= 1<<0)
//--------------------------------------------------------//
//---------------- NVIC ENABLE/DISABlE MACROS -----------//
//------------------------------------------------------//
//Enable
#define NVIC_IQR6_EXTI0_Enable			(NVIC_ISER0 |= 1<<6)
#define NVIC_IQR7_EXTI1_Enable			(NVIC_ISER0 |= 1<<7)
#define NVIC_IQR8_EXTI2_Enable			(NVIC_ISER0 |= 1<<8)
#define NVIC_IQR9_EXTI3_Enable			(NVIC_ISER0 |= 1<<9)
#define NVIC_IQR10_EXTI4_Enable			(NVIC_ISER0 |= 1<<10)
#define NVIC_IQR23_EXTI5_9_Enable		(NVIC_ISER0 |= 1<<23)
#define NVIC_IQR40_EXTI10_15_Enable		(NVIC_ISER1 |= 1<<8)
//Disable
#define NVIC_IQR6_EXTI0_Disable			(NVIC_ICER0 |= 1<<6)
#define NVIC_IQR7_EXTI1_Disable			(NVIC_ICER0 |= 1<<7)
#define NVIC_IQR8_EXTI2_Disable			(NVIC_ICER0 |= 1<<8)
#define NVIC_IQR9_EXTI3_Disable			(NVIC_ICER0 |= 1<<9)
#define NVIC_IQR10_EXTI4_Disable		(NVIC_ICER0 |= 1<<10)
#define NVIC_IQR23_EXTI5_9_Disable		(NVIC_ICER0 |= 1<<23)
#define NVIC_IQR40_EXTI10_15_Disable	(NVIC_ICER1 |= 1<<8)
//================================================================//
//---------------- IVT  ----------------//
//EXTI_IRQ
#define EXTI0_IRQ    6
#define EXTI1_IRQ    7
#define EXTI2_IRQ    8
#define EXTI3_IRQ    9
#define EXTI4_IRQ    10
#define EXTI5_IRQ    23
#define EXTI6_IRQ    23
#define EXTI7_IRQ    23
#define EXTI8_IRQ    23
#define EXTI9_IRQ    23
#define EXTI10_IRQ   40
#define EXTI11_IRQ   40
#define EXTI12_IRQ   40
#define EXTI13_IRQ   40
#define EXTI14_IRQ   40
#define EXTI15_IRQ   40



#endif /* INC_STM32F103X6_H_ */
