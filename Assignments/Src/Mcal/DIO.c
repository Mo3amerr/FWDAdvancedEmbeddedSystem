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
    DIO_LevelType DIO_ReturnValue =0;
switch (ChannelId)
{
case DIO_Channel_A0 ... DIO_Channel_A7:
    DIO_ReturnValue= (*(volatile uint32*)(GPIOA_APB_BASE_ADDRESS_MASK+(1<<(ChannelId%8))));
    break;
case DIO_Channel_B0 ... DIO_Channel_B7:
    DIO_ReturnValue = (*(volatile uint32*)(GPIOB_APB_BASE_ADDRESS_MASK+(1<<(ChannelId%8))));
    break;
case DIO_Channel_C0 ... DIO_Channel_C7:
    DIO_ReturnValue = (*(volatile uint32*)(GPIOC_APB_BASE_ADDRESS_MASK+(1<<(ChannelId%8))));
    break;
case DIO_Channel_D0 ... DIO_Channel_D7:
    DIO_ReturnValue = (*(volatile uint32*)(GPIOD_APB_BASE_ADDRESS_MASK+(1<<(ChannelId%8))));
    break;
case DIO_Channel_E0 ... DIO_Channel_E5:
    DIO_ReturnValue = (*(volatile uint32*)(GPIOE_APB_BASE_ADDRESS_MASK+(1<<(ChannelId%8))));
    break;
case DIO_Channel_F0 ... DIO_Channel_F4:
    DIO_ReturnValue = (*(volatile uint32*)(GPIOF_APB_BASE_ADDRESS_MASK+(1<<(ChannelId%8)))); 
    break;

default:
    break;
}

if(DIO_ReturnValue==DIO_LevelLow)
{return DIO_LevelLow;}
else
{ return DIO_LevelHigh;}

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
void DIO_WrtieChannel(DIO_ChannelType ChannelId,DIO_LevelType Level)
{
switch (ChannelId)
{
case DIO_Channel_A0 ... DIO_Channel_A7:
    (*(volatile uint32*)(GPIOA_APB_BASE_ADDRESS_MASK+(1<<((ChannelId%8)+2))))= Level*255;
    break;
case DIO_Channel_B0 ... DIO_Channel_B7:
    (*(volatile uint32*)(GPIOB_APB_BASE_ADDRESS_MASK+(1<<((ChannelId%8)+2))))= Level*255;
    break;
case DIO_Channel_C0 ... DIO_Channel_C7:
    (*(volatile uint32*)(GPIOC_APB_BASE_ADDRESS_MASK+(1<<((ChannelId%8)+2))))= Level*255;
    break;  
case DIO_Channel_D0 ... DIO_Channel_D7:
    (*(volatile uint32*)(GPIOD_APB_BASE_ADDRESS_MASK+(1<<((ChannelId%8)+2))))= Level*255;
    break;
case DIO_Channel_E0 ... DIO_Channel_E5:
    (*(volatile uint32*)(GPIOE_APB_BASE_ADDRESS_MASK+(1<<((ChannelId%8)+2))))= Level*255;
    break;      
case DIO_Channel_F0 ... DIO_Channel_F5:
    (*(volatile uint32*)(GPIOF_APB_BASE_ADDRESS_MASK+(1<<((ChannelId%8)+2))))= Level*255;
    break;            
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
DIO_PortLevelType DIO_ReadPort (DIO_PortType PortId)
{
switch (PortId)
{
case DIO_PORTA:
    return GPIOA_GPIODATA;
    break;
case DIO_PORTB:
    return GPIOB_GPIODATA;
    break;
case DIO_PORTC:
    return GPIOC_GPIODATA;
    break;
case DIO_PORTD:
    return GPIOD_GPIODATA;
    break;
case DIO_PORTE:
    return GPIOE_GPIODATA;
    break;
    case DIO_PORTF:
    return GPIOF_GPIODATA;
    break;
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
void DIO_WritePort (DIO_PortType PortId,DIO_PortLevelType Level)
{
switch (PortId)
{
case DIO_PORTA:
     GPIOA_GPIODATA =Level;
    break;
case DIO_PORTB:
    GPIOB_GPIODATA =Level;
    break;
case DIO_PORTC:
   GPIOC_GPIODATA =Level;
    break;
case DIO_PORTD:
    GPIOD_GPIODATA =Level;
    break;
case DIO_PORTE:
    GPIOE_GPIODATA =Level;
    break;
case DIO_PORTF:
    GPIOF_GPIODATA =Level;
    break;
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
DIO_LevelType DIO_FlipChannel(DIO_ChannelType ChannelId)
{
switch (ChannelId)
{
case DIO_Channel_A0 ... DIO_Channel_A7:
    TOG_BIT(GPIOA_GPIODATA,(ChannelId%8));
    break;
case DIO_Channel_B0 ... DIO_Channel_B7:
   TOG_BIT(GPIOB_GPIODATA,(ChannelId%8));
    break;
case DIO_Channel_C0 ... DIO_Channel_C7:
    TOG_BIT(GPIOC_GPIODATA,(ChannelId%8));
    break;  
case DIO_Channel_D0 ... DIO_Channel_D7:
    TOG_BIT(GPIOD_GPIODATA,(ChannelId%8));
    break;
case DIO_Channel_E0 ... DIO_Channel_E5:
   TOG_BIT(GPIOE_GPIODATA,(ChannelId%8));
    break;      
case DIO_Channel_F0 ... DIO_Channel_F4:
   TOG_BIT(GPIOF_GPIODATA,(ChannelId%8));
    break;            
}
}



/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/
