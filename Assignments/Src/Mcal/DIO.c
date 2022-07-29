/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  FileName.c
 *        \brief
 *
 *      \details
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "BIT_MATH.h"
#include "Mcu_Hw.h"
#include "DIO_Types.h"
#include "DIO.h"

/**********************************************************************************************************************
 *  LOCAL MACROS CONSTANT\FUNCTION
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/******************************************************************************
 * \Syntax          : DIO_LevelType DIO_ReadChannel(DIO_ChannelType ChannelId)
 * \Description     : This function is used to read channels of DIO Ports and return High or low Value
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : ChannelId >>  Number of Channel wanted to be read
 * \Parameters (out): State of This Channel
 * \Return value:   : HIGH/LOW
 *******************************************************************************/
DIO_LevelType DIO_ReadChannel(DIO_ChannelType ChannelId)
{
    volatile uint32 LocalBaseAddress;
    DIO_LevelType DIO_ReturnValue = 0;
    switch (ChannelId)
    {
    case DIO_Channel_A0 ... DIO_Channel_A7:
        LocalBaseAddress = GPIOA_APB_BASE_ADDRESS_MASK;
        break;
    case DIO_Channel_B0 ... DIO_Channel_B7:
        LocalBaseAddress = GPIOB_APB_BASE_ADDRESS_MASK;
        break;
    case DIO_Channel_C0 ... DIO_Channel_C7:
        LocalBaseAddress = GPIOC_APB_BASE_ADDRESS_MASK;
        break;
    case DIO_Channel_D0 ... DIO_Channel_D7:
        LocalBaseAddress = GPIOD_APB_BASE_ADDRESS_MASK;
        break;
    case DIO_Channel_E0 ... DIO_Channel_E5:
        LocalBaseAddress = GPIOE_APB_BASE_ADDRESS_MASK;
        break;
    case DIO_Channel_F0 ... DIO_Channel_F4:
        LocalBaseAddress = GPIOF_APB_BASE_ADDRESS_MASK;
        break;

    default:
        break;
    }
    DIO_ReturnValue = (*(volatile uint32 *)(LocalBaseAddress + (1 << (ChannelId % 8))));

    if (DIO_ReturnValue == DIO_LevelLow)
    {
        return DIO_LevelLow;
    }
    else
    {
        return DIO_LevelHigh;
    }
}

/******************************************************************************
 * \Syntax          : Std_ReturnType FunctionName(AnyType parameterName)
 * \Description     : Describe this service
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : parameterName   Parameter Describtion
 * \Parameters (out): None
 * \Return value:   : Std_ReturnType  E_OK
 *                                    E_NOT_OK
 *******************************************************************************/
void DIO_WrtieChannel(DIO_ChannelType ChannelId, DIO_LevelType Level)
{
    volatile uint32 LocalBaseAddress;
    switch (ChannelId)
    {
    case DIO_Channel_A0 ... DIO_Channel_A7:
        LocalBaseAddress = GPIOA_APB_BASE_ADDRESS_MASK;
        break;
    case DIO_Channel_B0 ... DIO_Channel_B7:
        LocalBaseAddress = GPIOA_APB_BASE_ADDRESS_MASK;
        break;
    case DIO_Channel_C0 ... DIO_Channel_C7:
        LocalBaseAddress = GPIOA_APB_BASE_ADDRESS_MASK;
        break;
    case DIO_Channel_D0 ... DIO_Channel_D7:
        LocalBaseAddress = GPIOA_APB_BASE_ADDRESS_MASK;
        break;
    case DIO_Channel_E0 ... DIO_Channel_E5:
        LocalBaseAddress = GPIOA_APB_BASE_ADDRESS_MASK;
        break;
    case DIO_Channel_F0 ... DIO_Channel_F5:
        LocalBaseAddress = GPIOA_APB_BASE_ADDRESS_MASK;
        break;
    }

    (*(volatile uint32 *)(LocalBaseAddress + (1 << ((ChannelId % 8) + 2)))) = Level * 255;
}

/******************************************************************************
 * \Syntax          : Std_ReturnType FunctionName(AnyType parameterName)
 * \Description     : Describe this service
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : parameterName   Parameter Describtion
 * \Parameters (out): None
 * \Return value:   : Std_ReturnType  E_OK
 *                                    E_NOT_OK
 *******************************************************************************/
DIO_PortLevelType DIO_ReadPort(DIO_PortType PortId)
{
    volatile uint32 LocalBaseAddress;
    switch (PortId)
    {
    case DIO_PORTA:
        LocalBaseAddress = GPIOA_APB_BASE_ADDRESS_MASK;
        break;
    case DIO_PORTB:
        LocalBaseAddress = GPIOB_APB_BASE_ADDRESS_MASK;
        break;
    case DIO_PORTC:
        LocalBaseAddress = GPIOC_APB_BASE_ADDRESS_MASK;
        break;
    case DIO_PORTD:
        LocalBaseAddress = GPIOD_APB_BASE_ADDRESS_MASK;
        break;
    case DIO_PORTE:
        LocalBaseAddress = GPIOE_APB_BASE_ADDRESS_MASK;
        break;
    case DIO_PORTF:
        LocalBaseAddress = GPIOF_APB_BASE_ADDRESS_MASK;
        break;
    }

    return GPIO_GPIODATA(LocalBaseAddress);
}

/******************************************************************************
 * \Syntax          : Std_ReturnType FunctionName(AnyType parameterName)
 * \Description     : Describe this service
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : parameterName   Parameter Describtion
 * \Parameters (out): None
 * \Return value:   : Std_ReturnType  E_OK
 *                                    E_NOT_OK
 *******************************************************************************/
void DIO_WritePort(DIO_PortType PortId, DIO_PortLevelType Level)
{
    volatile uint32 LocalBaseAddress;
    switch (PortId)
    {
    case DIO_PORTA:
        LocalBaseAddress = GPIOA_APB_BASE_ADDRESS_MASK;
        break;
    case DIO_PORTB:
        LocalBaseAddress = GPIOB_APB_BASE_ADDRESS_MASK;
        break;
    case DIO_PORTC:
        LocalBaseAddress = GPIOC_APB_BASE_ADDRESS_MASK;
        break;
    case DIO_PORTD:
        LocalBaseAddress = GPIOD_APB_BASE_ADDRESS_MASK;
        break;
    case DIO_PORTE:
        LocalBaseAddress = GPIOE_APB_BASE_ADDRESS_MASK;
        break;
    case DIO_PORTF:
        LocalBaseAddress = GPIOF_APB_BASE_ADDRESS_MASK;
        break;
    }

    GPIO_GPIODATA(LocalBaseAddress) = Level;
}

/******************************************************************************
 * \Syntax          : Std_ReturnType FunctionName(AnyType parameterName)
 * \Description     : Describe this service
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : parameterName   Parameter Describtion
 * \Parameters (out): None
 * \Return value:   : Std_ReturnType  E_OK
 *                                    E_NOT_OK
 *******************************************************************************/
DIO_LevelType DIO_FlipChannel(DIO_ChannelType ChannelId)
{
    volatile uint32 LocalBaseAddress;
    switch (ChannelId)
    {
    case DIO_Channel_A0 ... DIO_Channel_A7:
        LocalBaseAddress = GPIOA_APB_BASE_ADDRESS_MASK;

        break;
    case DIO_Channel_B0 ... DIO_Channel_B7:
        LocalBaseAddress = GPIOB_APB_BASE_ADDRESS_MASK;
        break;
    case DIO_Channel_C0 ... DIO_Channel_C7:
        LocalBaseAddress = GPIOC_APB_BASE_ADDRESS_MASK;
        break;
    case DIO_Channel_D0 ... DIO_Channel_D7:
        LocalBaseAddress = GPIOD_APB_BASE_ADDRESS_MASK;
        break;
    case DIO_Channel_E0 ... DIO_Channel_E5:
        LocalBaseAddress = GPIOE_APB_BASE_ADDRESS_MASK;
        break;
    case DIO_Channel_F0 ... DIO_Channel_F4:
        LocalBaseAddress = GPIOF_APB_BASE_ADDRESS_MASK;
        break;
    }
    TOG_BIT(GPIO_GPIODATA(LocalBaseAddress), (ChannelId % 8));
}

/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/
