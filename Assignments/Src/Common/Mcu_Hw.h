/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Mcu_Hw.h
 *       Module:  Mcu_Hw
 *
 *  Description:  header file for Registers definition    
 *  
 *********************************************************************************************************************/
#ifndef MCU_HW_H
#define MCU_HW_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef struct 
{
    uint32 VECACT   :8;
    uint32          :3;
    uint32 RETBASE  :1;
    uint32 VECPEN  :3;
    uint32 VECPEND  :4;
    uint32          :2;
    uint32 ISRPEND  :1;
    uint32 ISRPRE   :1;
    uint32          :1;
    uint32 PENDSTCLR:1;
    uint32 PENDSTSET:1;
    uint32 UNPENDSV :1;
    uint32 PENDSV   :1;
    uint32          :2;
    uint32 NMISET   :1; 
}INTCTRL_BF;
typedef union 
{
    uint32 R;
    INTCTRL_BF B;
}INTCTRL_Tag;



/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define CORTEXM4_PERI_BASE_ADDRESS             0xE000E000
#define APINT                                  *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0xD0C))
#define INTCTRL                                *((volatile INTCTRL_Tag*)(CORTEXM4_PERI_BASE_ADDRESS+0xD04))
#define RCGCGPIO                                *((volatile uint32*)( 0x400FE000 +0x608))
/*tHIS SECTION IS FOR System Timer (SysTick) Registers*/
#define STCTRL                                   *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x010))
#define STRELOAD                                 *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x014))
#define STCURRENT                                *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x018))

/*This Section is for NVIC Registers*/


#define EN(offset)                         (*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x100+offset)))
#define EN0                                      *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x100))
#define EN1                                      *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x104))
#define EN2                                      *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x108))
#define EN3                                      *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x10C))
#define EN4                                      *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x110))

#define DIS(offset)                         (*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x180+offset)))
#define DIS0                                      *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x180))
#define DIS1                                      *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x184))
#define DIS2                                      *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x188))
#define DIS3                                      *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x18C))
#define DIS4                                      *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x190))

#define PEND0                                       *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x200))  
#define PEND1                                       *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x204))  
#define PEND2                                       *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x208))  
#define PEND3                                       *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x20C))  
#define PEND4                                       *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x210))  


#define UNPEND0                                     *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x280))  
#define UNPEND1                                     *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x284))  
#define UNPEND2                                     *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x288))  
#define UNPEND3                                     *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x28C))
#define UNPEND4                                     *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x290))

#define ACTIVE0                                   *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x300))
#define ACTIVE1                                   *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x304))
#define ACTIVE2                                   *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x308))
#define ACTIVE3                                   *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x30C))
#define ACTIVE4                                   *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x310))

#define PRI_BASE_MASK                       0xE000E400
#define PRI(offset)                         (*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x400+offset)))
#define PRI0                                     *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x400))
#define PRI1                                     *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x404))
#define PRI2                                     *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x408))
#define PRI3                                     *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x40C))
#define PRI4                                     *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x410))
#define PRI5                                     *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x414))
#define PRI6                                     *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x418))
#define PRI7                                     *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x41C))
#define PRI8                                     *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x420))
#define PRI9                                     *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x424))
#define PRI10                                     *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x428))
#define PRI11                                     *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x42C))
#define PRI12                                     *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x430))
#define PRI13                                     *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x434))
#define PRI14                                     *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x438))
#define PRI15                                     *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x43C))
#define PRI16                                     *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x440))
#define PRI17                                     *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x444))
#define PRI18                                     *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x448))
#define PRI19                                     *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x44C))
#define PRI20                                     *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x450))
#define PRI21                                     *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x454))
#define PRI22                                     *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x458))
#define PRI23                                     *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x45C))
#define PRI24                                     *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x460))
#define PRI25                                     *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x464))
#define PRI26                                     *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x468))
#define PRI27                                     *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x46C))
#define PRI28                                     *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x470))
#define PRI29                                     *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x474))
#define PRI30                                     *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x478))
#define PRI31                                     *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x47C))
#define PRI32                                     *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x480))
#define PRI33                                     *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x484))
#define PRI34                                     *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x488))



/*This section is for GPIO Registers*/

/*GPIO A*/

#define GPIOA_APB_BASE_ADDRESS_MASK                       0x40004000
#define GPIOA_AHB_BASE_MASK                       0x40058000
#define GPIOA_GPIODATA                              *((volatile uint32*)(GPIOA_APB_BASE_ADDRESS_MASK+0x3FC))
#define GPIOA_GPIODIR                               *((volatile uint32*)(GPIOA_APB_BASE_ADDRESS_MASK+0x400))
#define GPIOA_GPIOIS                                *((volatile uint32*)(GPIOA_APB_BASE_ADDRESS_MASK+0x404))
#define GPIOA_GPIOIBE                               *((volatile uint32*)(GPIOA_APB_BASE_ADDRESS_MASK+0x408))
#define GPIOA_GPIOIEV                               *((volatile uint32*)(GPIOA_APB_BASE_ADDRESS_MASK+0x40C))
#define GPIOA_GPIOIM                                *((volatile uint32*)(GPIOA_APB_BASE_ADDRESS_MASK+0x410))
#define GPIOA_GPIORIS                               *((volatile uint32*)(GPIOA_APB_BASE_ADDRESS_MASK+0x414))
#define GPIOA_GPIOMIS                               *((volatile uint32*)(GPIOA_APB_BASE_ADDRESS_MASK+0x418))
#define GPIOA_GPIOICR                               *((volatile uint32*)(GPIOA_APB_BASE_ADDRESS_MASK+0x41C))
#define GPIOA_GPIOAFSEL                             *((volatile uint32*)(GPIOA_APB_BASE_ADDRESS_MASK+0x420))
#define GPIOA_GPIODR2R                              *((volatile uint32*)(GPIOA_APB_BASE_ADDRESS_MASK+0x500))
#define GPIOA_GPIODR4R                              *((volatile uint32*)(GPIOA_APB_BASE_ADDRESS_MASK+0x504))
#define GPIOA_GPIODR8R                              *((volatile uint32*)(GPIOA_APB_BASE_ADDRESS_MASK+0x508))
#define GPIOA_GPIOODR                               *((volatile uint32*)(GPIOA_APB_BASE_ADDRESS_MASK+0x50C))
#define GPIOA_GPIOPUR                               *((volatile uint32*)(GPIOA_APB_BASE_ADDRESS_MASK+0x510))
#define GPIOA_GPIOPDR                               *((volatile uint32*)(GPIOA_APB_BASE_ADDRESS_MASK+0x514))
#define GPIOA_GPIOSLR                               *((volatile uint32*)(GPIOA_APB_BASE_ADDRESS_MASK+0x518))
#define GPIOA_GPIODEN                               *((volatile uint32*)(GPIOA_APB_BASE_ADDRESS_MASK+0x51C))
#define GPIOA_GPIOLOCK                              *((volatile uint32*)(GPIOA_APB_BASE_ADDRESS_MASK+0x520))
#define GPIOA_GPIOCR                                *((volatile uint32*)(GPIOA_APB_BASE_ADDRESS_MASK+0x524))
#define GPIOA_GPIOAMSEL                             *((volatile uint32*)(GPIOA_APB_BASE_ADDRESS_MASK+0x528))
#define GPIOA_GPIOPCTL                              *((volatile uint32*)(GPIOA_APB_BASE_ADDRESS_MASK+0x52C))
#define GPIOA_GPIOADCCTL                                *((volatile uint32*)(GPIOA_APB_BASE_ADDRESS_MASK+0x530))
#define GPIOA_GPIODMACTL                                *((volatile uint32*)(GPIOA_APB_BASE_ADDRESS_MASK+0x534))
#define GPIOA_GPIOPeriphlD4                             *((volatile uint32*)(GPIOA_APB_BASE_ADDRESS_MASK+0xFD0))
#define GPIOA_GPIOPeriphlD5                             *((volatile uint32*)(GPIOA_APB_BASE_ADDRESS_MASK+0xFD4))
#define GPIOA_GPIOPeriphlD6                             *((volatile uint32*)(GPIOA_APB_BASE_ADDRESS_MASK+0xFD8))
#define GPIOA_GPIOPeriphlD7                             *((volatile uint32*)(GPIOA_APB_BASE_ADDRESS_MASK+0xFDC))
#define GPIOA_GPIOPeriphlD0                             *((volatile uint32*)(GPIOA_APB_BASE_ADDRESS_MASK+0xFE0))
#define GPIOA_GPIOPeriphlD1                             *((volatile uint32*)(GPIOA_APB_BASE_ADDRESS_MASK+0xFE4))
#define GPIOA_GPIOPeriphlD2                             *((volatile uint32*)(GPIOA_APB_BASE_ADDRESS_MASK+0xFE8))
#define GPIOA_GPIOPeriphlD3                             *((volatile uint32*)(GPIOA_APB_BASE_ADDRESS_MASK+0xFEC))
#define GPIOA_GPIOPCellID0                              *((volatile uint32*)(GPIOA_APB_BASE_ADDRESS_MASK+0xFF0))
#define GPIOA_GPIOPCellID1                              *((volatile uint32*)(GPIOA_APB_BASE_ADDRESS_MASK+0xFF4))
#define GPIOA_GPIOPCellID2                              *((volatile uint32*)(GPIOA_APB_BASE_ADDRESS_MASK+0xFF8))
#define GPIOA_GPIOPCellID3                              *((volatile uint32*)(GPIOA_APB_BASE_ADDRESS_MASK+0xFFC))


/*GPIO B*/

#define GPIOB_APB_BASE_ADDRESS_MASK                    0x40005000
#define GPIOB_AHB_BASE_MASK                           0x40059000    
#define GPIOB_GPIODATA                              *((volatile uint32*)(GPIOB_APB_BASE_ADDRESS_MASK+0x3FC))
#define GPIOB_GPIODIR                               *((volatile uint32*)(GPIOB_APB_BASE_ADDRESS_MASK+0x400))
#define GPIOB_GPIOIS                                *((volatile uint32*)(GPIOB_APB_BASE_ADDRESS_MASK+0x404))
#define GPIOB_GPIOIBE                               *((volatile uint32*)(GPIOB_APB_BASE_ADDRESS_MASK+0x408))
#define GPIOB_GPIOIEV                               *((volatile uint32*)(GPIOB_APB_BASE_ADDRESS_MASK+0x40C))
#define GPIOB_GPIOIM                                *((volatile uint32*)(GPIOB_APB_BASE_ADDRESS_MASK+0x410))
#define GPIOB_GPIORIS                               *((volatile uint32*)(GPIOB_APB_BASE_ADDRESS_MASK+0x414))
#define GPIOB_GPIOMIS                               *((volatile uint32*)(GPIOB_APB_BASE_ADDRESS_MASK+0x418))
#define GPIOB_GPIOICR                               *((volatile uint32*)(GPIOB_APB_BASE_ADDRESS_MASK+0x41C))
#define GPIOB_GPIOAFSEL                             *((volatile uint32*)(GPIOB_APB_BASE_ADDRESS_MASK+0x420))
#define GPIOB_GPIODR2R                              *((volatile uint32*)(GPIOB_APB_BASE_ADDRESS_MASK+0x500))
#define GPIOB_GPIODR4R                              *((volatile uint32*)(GPIOB_APB_BASE_ADDRESS_MASK+0x504))
#define GPIOB_GPIODR8R                              *((volatile uint32*)(GPIOB_APB_BASE_ADDRESS_MASK+0x508))
#define GPIOB_GPIOODR                               *((volatile uint32*)(GPIOB_APB_BASE_ADDRESS_MASK+0x50C))
#define GPIOB_GPIOPUR                               *((volatile uint32*)(GPIOB_APB_BASE_ADDRESS_MASK+0x510))
#define GPIOB_GPIOPDR                               *((volatile uint32*)(GPIOB_APB_BASE_ADDRESS_MASK+0x514))
#define GPIOB_GPIOSLR                               *((volatile uint32*)(GPIOB_APB_BASE_ADDRESS_MASK+0x518))
#define GPIOB_GPIODEN                               *((volatile uint32*)(GPIOB_APB_BASE_ADDRESS_MASK+0x51C))
#define GPIOB_GPIOLOCK                              *((volatile uint32*)(GPIOB_APB_BASE_ADDRESS_MASK+0x520))
#define GPIOB_GPIOCR                                *((volatile uint32*)(GPIOB_APB_BASE_ADDRESS_MASK+0x524))
#define GPIOB_GPIOAMSEL                             *((volatile uint32*)(GPIOB_APB_BASE_ADDRESS_MASK+0x528))
#define GPIOB_GPIOPCTL                              *((volatile uint32*)(GPIOB_APB_BASE_ADDRESS_MASK+0x52C))
#define GPIOB_GPIOADCCTL                                *((volatile uint32*)(GPIOB_APB_BASE_ADDRESS_MASK+0x530))
#define GPIOB_GPIODMACTL                                *((volatile uint32*)(GPIOB_APB_BASE_ADDRESS_MASK+0x534))
#define GPIOB_GPIOPeriphlD4                             *((volatile uint32*)(GPIOB_APB_BASE_ADDRESS_MASK+0xFD0))
#define GPIOB_GPIOPeriphlD5                             *((volatile uint32*)(GPIOB_APB_BASE_ADDRESS_MASK+0xFD4))
#define GPIOB_GPIOPeriphlD6                             *((volatile uint32*)(GPIOB_APB_BASE_ADDRESS_MASK+0xFD8))
#define GPIOB_GPIOPeriphlD7                             *((volatile uint32*)(GPIOB_APB_BASE_ADDRESS_MASK+0xFDC))
#define GPIOB_GPIOPeriphlD0                             *((volatile uint32*)(GPIOB_APB_BASE_ADDRESS_MASK+0xFE0))
#define GPIOB_GPIOPeriphlD1                             *((volatile uint32*)(GPIOB_APB_BASE_ADDRESS_MASK+0xFE4))
#define GPIOB_GPIOPeriphlD2                             *((volatile uint32*)(GPIOB_APB_BASE_ADDRESS_MASK+0xFE8))
#define GPIOB_GPIOPeriphlD3                             *((volatile uint32*)(GPIOB_APB_BASE_ADDRESS_MASK+0xFEC))
#define GPIOB_GPIOPCellID0                              *((volatile uint32*)(GPIOB_APB_BASE_ADDRESS_MASK+0xFF0))
#define GPIOB_GPIOPCellID1                              *((volatile uint32*)(GPIOB_APB_BASE_ADDRESS_MASK+0xFF4))
#define GPIOB_GPIOPCellID2                              *((volatile uint32*)(GPIOB_APB_BASE_ADDRESS_MASK+0xFF8))
#define GPIOB_GPIOPCellID3                              *((volatile uint32*)(GPIOB_APB_BASE_ADDRESS_MASK+0xFFC))




/*GPIO C*/

#define GPIOC_APB_BASE_ADDRESS_MASK                    0x40006000
#define GPIOC_AHB_BASE_MASK                           0x4005A000   
#define GPIOC_GPIODATA                              *((volatile uint32*)(GPIOC_APB_BASE_ADDRESS_MASK+0x3FC))
#define GPIOC_GPIODIR                               *((volatile uint32*)(GPIOC_APB_BASE_ADDRESS_MASK+0x400))
#define GPIOC_GPIOIS                                *((volatile uint32*)(GPIOC_APB_BASE_ADDRESS_MASK+0x404))
#define GPIOC_GPIOIBE                               *((volatile uint32*)(GPIOC_APB_BASE_ADDRESS_MASK+0x408))
#define GPIOC_GPIOIEV                               *((volatile uint32*)(GPIOC_APB_BASE_ADDRESS_MASK+0x40C))
#define GPIOC_GPIOIM                                *((volatile uint32*)(GPIOC_APB_BASE_ADDRESS_MASK+0x410))
#define GPIOC_GPIORIS                               *((volatile uint32*)(GPIOC_APB_BASE_ADDRESS_MASK+0x414))
#define GPIOC_GPIOMIS                               *((volatile uint32*)(GPIOC_APB_BASE_ADDRESS_MASK+0x418))
#define GPIOC_GPIOICR                               *((volatile uint32*)(GPIOC_APB_BASE_ADDRESS_MASK+0x41C))
#define GPIOC_GPIOAFSEL                             *((volatile uint32*)(GPIOC_APB_BASE_ADDRESS_MASK+0x420))
#define GPIOC_GPIODR2R                              *((volatile uint32*)(GPIOC_APB_BASE_ADDRESS_MASK+0x500))
#define GPIOC_GPIODR4R                              *((volatile uint32*)(GPIOC_APB_BASE_ADDRESS_MASK+0x504))
#define GPIOC_GPIODR8R                              *((volatile uint32*)(GPIOC_APB_BASE_ADDRESS_MASK+0x508))
#define GPIOC_GPIOODR                               *((volatile uint32*)(GPIOC_APB_BASE_ADDRESS_MASK+0x50C))
#define GPIOC_GPIOPUR                               *((volatile uint32*)(GPIOC_APB_BASE_ADDRESS_MASK+0x510))
#define GPIOC_GPIOPDR                               *((volatile uint32*)(GPIOC_APB_BASE_ADDRESS_MASK+0x514))
#define GPIOC_GPIOSLR                               *((volatile uint32*)(GPIOC_APB_BASE_ADDRESS_MASK+0x518))
#define GPIOC_GPIODEN                               *((volatile uint32*)(GPIOC_APB_BASE_ADDRESS_MASK+0x51C))
#define GPIOC_GPIOLOCK                              *((volatile uint32*)(GPIOC_APB_BASE_ADDRESS_MASK+0x520))
#define GPIOC_GPIOCR                                *((volatile uint32*)(GPIOC_APB_BASE_ADDRESS_MASK+0x524))
#define GPIOC_GPIOAMSEL                             *((volatile uint32*)(GPIOC_APB_BASE_ADDRESS_MASK+0x528))
#define GPIOC_GPIOPCTL                              *((volatile uint32*)(GPIOC_APB_BASE_ADDRESS_MASK+0x52C))
#define GPIOC_GPIOADCCTL                                *((volatile uint32*)(GPIOC_APB_BASE_ADDRESS_MASK+0x530))
#define GPIOC_GPIODMACTL                                *((volatile uint32*)(GPIOC_APB_BASE_ADDRESS_MASK+0x534))
#define GPIOC_GPIOPeriphlD4                             *((volatile uint32*)(GPIOC_APB_BASE_ADDRESS_MASK+0xFD0))
#define GPIOC_GPIOPeriphlD5                             *((volatile uint32*)(GPIOC_APB_BASE_ADDRESS_MASK+0xFD4))
#define GPIOC_GPIOPeriphlD6                             *((volatile uint32*)(GPIOC_APB_BASE_ADDRESS_MASK+0xFD8))
#define GPIOC_GPIOPeriphlD7                             *((volatile uint32*)(GPIOC_APB_BASE_ADDRESS_MASK+0xFDC))
#define GPIOC_GPIOPeriphlD0                             *((volatile uint32*)(GPIOC_APB_BASE_ADDRESS_MASK+0xFE0))
#define GPIOC_GPIOPeriphlD1                             *((volatile uint32*)(GPIOC_APB_BASE_ADDRESS_MASK+0xFE4))
#define GPIOC_GPIOPeriphlD2                             *((volatile uint32*)(GPIOC_APB_BASE_ADDRESS_MASK+0xFE8))
#define GPIOC_GPIOPeriphlD3                             *((volatile uint32*)(GPIOC_APB_BASE_ADDRESS_MASK+0xFEC))
#define GPIOC_GPIOPCellID0                              *((volatile uint32*)(GPIOC_APB_BASE_ADDRESS_MASK+0xFF0))
#define GPIOC_GPIOPCellID1                              *((volatile uint32*)(GPIOC_APB_BASE_ADDRESS_MASK+0xFF4))
#define GPIOC_GPIOPCellID2                              *((volatile uint32*)(GPIOC_APB_BASE_ADDRESS_MASK+0xFF8))
#define GPIOC_GPIOPCellID3                              *((volatile uint32*)(GPIOC_APB_BASE_ADDRESS_MASK+0xFFC))




/*GPIO D*/

#define GPIOD_APB_BASE_ADDRESS_MASK                    0x40007000
#define GPIOD_AHB_BASE_MASK                           0x4005B000   
#define GPIOD_GPIODATA                              *((volatile uint32*)(GPIOD_APB_BASE_ADDRESS_MASK+0x3FC))
#define GPIOD_GPIODIR                               *((volatile uint32*)(GPIOD_APB_BASE_ADDRESS_MASK+0x400))
#define GPIOD_GPIOIS                                *((volatile uint32*)(GPIOD_APB_BASE_ADDRESS_MASK+0x404))
#define GPIOD_GPIOIBE                               *((volatile uint32*)(GPIOD_APB_BASE_ADDRESS_MASK+0x408))
#define GPIOD_GPIOIEV                               *((volatile uint32*)(GPIOD_APB_BASE_ADDRESS_MASK+0x40C))
#define GPIOD_GPIOIM                                *((volatile uint32*)(GPIOD_APB_BASE_ADDRESS_MASK+0x410))
#define GPIOD_GPIORIS                               *((volatile uint32*)(GPIOD_APB_BASE_ADDRESS_MASK+0x414))
#define GPIOD_GPIOMIS                               *((volatile uint32*)(GPIOD_APB_BASE_ADDRESS_MASK+0x418))
#define GPIOD_GPIOICR                               *((volatile uint32*)(GPIOD_APB_BASE_ADDRESS_MASK+0x41C))
#define GPIOD_GPIOAFSEL                             *((volatile uint32*)(GPIOD_APB_BASE_ADDRESS_MASK+0x420))
#define GPIOD_GPIODR2R                              *((volatile uint32*)(GPIOD_APB_BASE_ADDRESS_MASK+0x500))
#define GPIOD_GPIODR4R                              *((volatile uint32*)(GPIOD_APB_BASE_ADDRESS_MASK+0x504))
#define GPIOD_GPIODR8R                              *((volatile uint32*)(GPIOD_APB_BASE_ADDRESS_MASK+0x508))
#define GPIOD_GPIOODR                               *((volatile uint32*)(GPIOD_APB_BASE_ADDRESS_MASK+0x50C))
#define GPIOD_GPIOPUR                               *((volatile uint32*)(GPIOD_APB_BASE_ADDRESS_MASK+0x510))
#define GPIOD_GPIOPDR                               *((volatile uint32*)(GPIOD_APB_BASE_ADDRESS_MASK+0x514))
#define GPIOD_GPIOSLR                               *((volatile uint32*)(GPIOD_APB_BASE_ADDRESS_MASK+0x518))
#define GPIOD_GPIODEN                               *((volatile uint32*)(GPIOD_APB_BASE_ADDRESS_MASK+0x51C))
#define GPIOD_GPIOLOCK                              *((volatile uint32*)(GPIOD_APB_BASE_ADDRESS_MASK+0x520))
#define GPIOD_GPIOCR                                *((volatile uint32*)(GPIOD_APB_BASE_ADDRESS_MASK+0x524))
#define GPIOD_GPIOAMSEL                             *((volatile uint32*)(GPIOD_APB_BASE_ADDRESS_MASK+0x528))
#define GPIOD_GPIOPCTL                              *((volatile uint32*)(GPIOD_APB_BASE_ADDRESS_MASK+0x52C))
#define GPIOD_GPIOADCCTL                            *((volatile uint32*)(GPIOD_APB_BASE_ADDRESS_MASK+0x530))
#define GPIOD_GPIODMACTL                            *((volatile uint32*)(GPIOD_APB_BASE_ADDRESS_MASK+0x534))
#define GPIOD_GPIOPeriphlD4                         *((volatile uint32*)(GPIOD_APB_BASE_ADDRESS_MASK+0xFD0))
#define GPIOD_GPIOPeriphlD5                         *((volatile uint32*)(GPIOD_APB_BASE_ADDRESS_MASK+0xFD4))
#define GPIOD_GPIOPeriphlD6                         *((volatile uint32*)(GPIOD_APB_BASE_ADDRESS_MASK+0xFD8))
#define GPIOD_GPIOPeriphlD7                         *((volatile uint32*)(GPIOD_APB_BASE_ADDRESS_MASK+0xFDC))
#define GPIOD_GPIOPeriphlD0                         *((volatile uint32*)(GPIOD_APB_BASE_ADDRESS_MASK+0xFE0))
#define GPIOD_GPIOPeriphlD1                         *((volatile uint32*)(GPIOD_APB_BASE_ADDRESS_MASK+0xFE4))
#define GPIOD_GPIOPeriphlD2                         *((volatile uint32*)(GPIOD_APB_BASE_ADDRESS_MASK+0xFE8))
#define GPIOD_GPIOPeriphlD3                         *((volatile uint32*)(GPIOD_APB_BASE_ADDRESS_MASK+0xFEC))
#define GPIOD_GPIOPCellID0                          *((volatile uint32*)(GPIOD_APB_BASE_ADDRESS_MASK+0xFF0))
#define GPIOD_GPIOPCellID1                          *((volatile uint32*)(GPIOD_APB_BASE_ADDRESS_MASK+0xFF4))
#define GPIOD_GPIOPCellID2                          *((volatile uint32*)(GPIOD_APB_BASE_ADDRESS_MASK+0xFF8))
#define GPIOD_GPIOPCellID3                          *((volatile uint32*)(GPIOD_APB_BASE_ADDRESS_MASK+0xFFC))



/*GPIO E*/

#define GPIOE_APB_BASE_ADDRESS_MASK                0x40024000
#define GPIOE_AHB_BASE_MASK                           0x4005C000   
#define GPIOE_GPIODATA                              *((volatile uint32*)(GPIOE_APB_BASE_ADDRESS_MASK+0x3FC))
#define GPIOE_GPIODIR                               *((volatile uint32*)(GPIOE_APB_BASE_ADDRESS_MASK+0x400))
#define GPIOE_GPIOIS                                *((volatile uint32*)(GPIOE_APB_BASE_ADDRESS_MASK+0x404))
#define GPIOE_GPIOIBE                               *((volatile uint32*)(GPIOE_APB_BASE_ADDRESS_MASK+0x408))
#define GPIOE_GPIOIEV                               *((volatile uint32*)(GPIOE_APB_BASE_ADDRESS_MASK+0x40C))
#define GPIOE_GPIOIM                                *((volatile uint32*)(GPIOE_APB_BASE_ADDRESS_MASK+0x410))
#define GPIOE_GPIORIS                               *((volatile uint32*)(GPIOE_APB_BASE_ADDRESS_MASK+0x414))
#define GPIOE_GPIOMIS                               *((volatile uint32*)(GPIOE_APB_BASE_ADDRESS_MASK+0x418))
#define GPIOE_GPIOICR                               *((volatile uint32*)(GPIOE_APB_BASE_ADDRESS_MASK+0x41C))
#define GPIOE_GPIOAFSEL                             *((volatile uint32*)(GPIOE_APB_BASE_ADDRESS_MASK+0x420))
#define GPIOE_GPIODR2R                              *((volatile uint32*)(GPIOE_APB_BASE_ADDRESS_MASK+0x500))
#define GPIOE_GPIODR4R                              *((volatile uint32*)(GPIOE_APB_BASE_ADDRESS_MASK+0x504))
#define GPIOE_GPIODR8R                              *((volatile uint32*)(GPIOE_APB_BASE_ADDRESS_MASK+0x508))
#define GPIOE_GPIOODR                               *((volatile uint32*)(GPIOE_APB_BASE_ADDRESS_MASK+0x50C))
#define GPIOE_GPIOPUR                               *((volatile uint32*)(GPIOE_APB_BASE_ADDRESS_MASK+0x510))
#define GPIOE_GPIOPDR                               *((volatile uint32*)(GPIOE_APB_BASE_ADDRESS_MASK+0x514))
#define GPIOE_GPIOSLR                               *((volatile uint32*)(GPIOE_APB_BASE_ADDRESS_MASK+0x518))
#define GPIOE_GPIODEN                               *((volatile uint32*)(GPIOE_APB_BASE_ADDRESS_MASK+0x51C))
#define GPIOE_GPIOLOCK                              *((volatile uint32*)(GPIOE_APB_BASE_ADDRESS_MASK+0x520))
#define GPIOE_GPIOCR                                *((volatile uint32*)(GPIOE_APB_BASE_ADDRESS_MASK+0x524))
#define GPIOE_GPIOAMSEL                             *((volatile uint32*)(GPIOE_APB_BASE_ADDRESS_MASK+0x528))
#define GPIOE_GPIOPCTL                              *((volatile uint32*)(GPIOE_APB_BASE_ADDRESS_MASK+0x52C))
#define GPIOE_GPIOADCCTL                            *((volatile uint32*)(GPIOE_APB_BASE_ADDRESS_MASK+0x530))
#define GPIOE_GPIODMACTL                            *((volatile uint32*)(GPIOE_APB_BASE_ADDRESS_MASK+0x534))
#define GPIOE_GPIOPeriphlD4                         *((volatile uint32*)(GPIOE_APB_BASE_ADDRESS_MASK+0xFD0))
#define GPIOE_GPIOPeriphlD5                         *((volatile uint32*)(GPIOE_APB_BASE_ADDRESS_MASK+0xFD4))
#define GPIOE_GPIOPeriphlD6                         *((volatile uint32*)(GPIOE_APB_BASE_ADDRESS_MASK+0xFD8))
#define GPIOE_GPIOPeriphlD7                         *((volatile uint32*)(GPIOE_APB_BASE_ADDRESS_MASK+0xFDC))
#define GPIOE_GPIOPeriphlD0                         *((volatile uint32*)(GPIOE_APB_BASE_ADDRESS_MASK+0xFE0))
#define GPIOE_GPIOPeriphlD1                         *((volatile uint32*)(GPIOE_APB_BASE_ADDRESS_MASK+0xFE4))
#define GPIOE_GPIOPeriphlD2                         *((volatile uint32*)(GPIOE_APB_BASE_ADDRESS_MASK+0xFE8))
#define GPIOE_GPIOPeriphlD3                         *((volatile uint32*)(GPIOE_APB_BASE_ADDRESS_MASK+0xFEC))
#define GPIOE_GPIOPCellID0                          *((volatile uint32*)(GPIOE_APB_BASE_ADDRESS_MASK+0xFF0))
#define GPIOE_GPIOPCellID1                          *((volatile uint32*)(GPIOE_APB_BASE_ADDRESS_MASK+0xFF4))
#define GPIOE_GPIOPCellID2                          *((volatile uint32*)(GPIOE_APB_BASE_ADDRESS_MASK+0xFF8))
#define GPIOE_GPIOPCellID3                          *((volatile uint32*)(GPIOE_APB_BASE_ADDRESS_MASK+0xFFC))



/*GPIO F*/

#define GPIOF_APB_BASE_ADDRESS_MASK                0x40025000
#define GPIOF_AHB_BASE_MASK                         0x4005D000  
#define GPIOF_GPIODATA                              *((volatile uint32*)(GPIOF_APB_BASE_ADDRESS_MASK+0x3FC))
#define GPIOF_GPIODIR                               *((volatile uint32*)(GPIOF_APB_BASE_ADDRESS_MASK+0x400))
#define GPIOF_GPIOIS                                *((volatile uint32*)(GPIOF_APB_BASE_ADDRESS_MASK+0x404))
#define GPIOF_GPIOIBE                               *((volatile uint32*)(GPIOF_APB_BASE_ADDRESS_MASK+0x408))
#define GPIOF_GPIOIEV                               *((volatile uint32*)(GPIOF_APB_BASE_ADDRESS_MASK+0x40C))
#define GPIOF_GPIOIM                                *((volatile uint32*)(GPIOF_APB_BASE_ADDRESS_MASK+0x410))
#define GPIOF_GPIORIS                               *((volatile uint32*)(GPIOF_APB_BASE_ADDRESS_MASK+0x414))
#define GPIOF_GPIOMIS                               *((volatile uint32*)(GPIOF_APB_BASE_ADDRESS_MASK+0x418))
#define GPIOF_GPIOICR                               *((volatile uint32*)(GPIOF_APB_BASE_ADDRESS_MASK+0x41C))
#define GPIOF_GPIOAFSEL                             *((volatile uint32*)(GPIOF_APB_BASE_ADDRESS_MASK+0x420))
#define GPIOF_GPIODR2R                              *((volatile uint32*)(GPIOF_APB_BASE_ADDRESS_MASK+0x500))
#define GPIOF_GPIODR4R                              *((volatile uint32*)(GPIOF_APB_BASE_ADDRESS_MASK+0x504))
#define GPIOF_GPIODR8R                              *((volatile uint32*)(GPIOF_APB_BASE_ADDRESS_MASK+0x508))
#define GPIOF_GPIOODR                               *((volatile uint32*)(GPIOF_APB_BASE_ADDRESS_MASK+0x50C))
#define GPIOF_GPIOPUR                               *((volatile uint32*)(GPIOF_APB_BASE_ADDRESS_MASK+0x510))
#define GPIOF_GPIOPDR                               *((volatile uint32*)(GPIOF_APB_BASE_ADDRESS_MASK+0x514))
#define GPIOF_GPIOSLR                               *((volatile uint32*)(GPIOF_APB_BASE_ADDRESS_MASK+0x518))
#define GPIOF_GPIODEN                               *((volatile uint32*)(GPIOF_APB_BASE_ADDRESS_MASK+0x51C))
#define GPIOF_GPIOLOCK                              *((volatile uint32*)(GPIOF_APB_BASE_ADDRESS_MASK+0x520))
#define GPIOF_GPIOCR                                *((volatile uint32*)(GPIOF_APB_BASE_ADDRESS_MASK+0x524))
#define GPIOF_GPIOAMSEL                             *((volatile uint32*)(GPIOF_APB_BASE_ADDRESS_MASK+0x528))
#define GPIOF_GPIOPCTL                              *((volatile uint32*)(GPIOF_APB_BASE_ADDRESS_MASK+0x52C))
#define GPIOF_GPIOADCCTL                            *((volatile uint32*)(GPIOF_APB_BASE_ADDRESS_MASK+0x530))
#define GPIOF_GPIODMACTL                            *((volatile uint32*)(GPIOF_APB_BASE_ADDRESS_MASK+0x534))
#define GPIOF_GPIOPeriphlD4                         *((volatile uint32*)(GPIOF_APB_BASE_ADDRESS_MASK+0xFD0))
#define GPIOF_GPIOPeriphlD5                         *((volatile uint32*)(GPIOF_APB_BASE_ADDRESS_MASK+0xFD4))
#define GPIOF_GPIOPeriphlD6                         *((volatile uint32*)(GPIOF_APB_BASE_ADDRESS_MASK+0xFD8))
#define GPIOF_GPIOPeriphlD7                         *((volatile uint32*)(GPIOF_APB_BASE_ADDRESS_MASK+0xFDC))
#define GPIOF_GPIOPeriphlD0                         *((volatile uint32*)(GPIOF_APB_BASE_ADDRESS_MASK+0xFE0))
#define GPIOF_GPIOPeriphlD1                         *((volatile uint32*)(GPIOF_APB_BASE_ADDRESS_MASK+0xFE4))
#define GPIOF_GPIOPeriphlD2                         *((volatile uint32*)(GPIOF_APB_BASE_ADDRESS_MASK+0xFE8))
#define GPIOF_GPIOPeriphlD3                         *((volatile uint32*)(GPIOF_APB_BASE_ADDRESS_MASK+0xFEC))
#define GPIOF_GPIOPCellID0                          *((volatile uint32*)(GPIOF_APB_BASE_ADDRESS_MASK+0xFF0))
#define GPIOF_GPIOPCellID1                          *((volatile uint32*)(GPIOF_APB_BASE_ADDRESS_MASK+0xFF4))
#define GPIOF_GPIOPCellID2                          *((volatile uint32*)(GPIOF_APB_BASE_ADDRESS_MASK+0xFF8))
#define GPIOF_GPIOPCellID3                          *((volatile uint32*)(GPIOF_APB_BASE_ADDRESS_MASK+0xFFC))

 
/*************GPT TIMERS**************/


#define GPT_16_32_BIT_TIMER0_BASE_ADDRESS							0x40030000
#define	GPT_16_32_BIT_TIMER1_BASE_ADDRESS							0x40031000
#define	GPT_16_32_BIT_TIMER2_BASE_ADDRESS							0x40032000
#define	GPT_16_32_BIT_TIMER3_BASE_ADDRESS							0x40033000
#define	GPT_16_32_BIT_TIMER4_BASE_ADDRESS							0x40034000
#define	GPT_16_32_BIT_TIMER5_BASE_ADDRESS							0x40035000
#define	GPT_32_64_BIT_WIDE_TIMER0_BASE_ADDRESS				0x40036000
#define	GPT_32_64_BIT_WIDE_TIMER1_BASE_ADDRESS				0x40037000
#define	GPT_32_64_BIT_WIDE_TIMER2_BASE_ADDRESS				0x4004C000
#define	GPT_32_64_BIT_WIDE_TIMER3_BASE_ADDRESS				0x4004D000
#define	GPT_32_64_BIT_WIDE_TIMER4_BASE_ADDRESS				0x4004E000
#define	GPT_32_64_BIT_WIDE_TIMER5_BASE_ADDRESS				0x4004F000

#define GPTMCFG_OFFSET					0x000
#define GPTMTAMR_OFFSET					0x004
#define GPTMTBMR_OFFSET					0x008
#define GPTMCTL_OFFSET					0x00C
#define GPTMIMR_OFFSET					0x018
#define GPTMTAV_OFFSET					0x050
#define GPTMTAILR_OFFSET				0x028


#define GPTMCFG(BaseAddr)										*((volatile uint32*)(BaseAddr+GPTMCFG_OFFSET))
#define GPTMTAMR(BaseAddr)									*((volatile uint32*)(BaseAddr+GPTMTAMR_OFFSET))
#define GPTMTBMR(BaseAddr)									*((volatile uint32*)(BaseAddr+GPTMTBMR_OFFSET))
#define GPTMCTL(BaseAddr)										*((volatile uint32*)(BaseAddr+GPTMCTL_OFFSET))	
#define GPTMIMR(BaseAddr)										*((volatile uint32*)(BaseAddr+GPTMIMR_OFFSET))
#define GPTMTAV(BaseAddr)										*((volatile uint32*)(BaseAddr+GPTMTAV_OFFSET))
#define GPTMTAILR(BaseAddr)									*((volatile uint32*)(BaseAddr+GPTMTAILR_OFFSET))

#define TAEN 		0
#define TBEN 		8

#define TACDIR	4
/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 

 
#endif  /* MCU_HW_H */

/**********************************************************************************************************************
 *  END OF FILE: Mcu_Hw.h
 *********************************************************************************************************************/
