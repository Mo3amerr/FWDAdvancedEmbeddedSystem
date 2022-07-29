/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  <Write File Name>
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef EXTI_TYPES_H
#define EXTI_TYPES_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define NUM_OF_PORTS  (6u)

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef enum 
{
EXTI_Channel_A0 ,
EXTI_Channel_A1 ,
EXTI_Channel_A2 ,
EXTI_Channel_A3 ,
EXTI_Channel_A4 ,
EXTI_Channel_A5 ,
EXTI_Channel_A6 ,
EXTI_Channel_A7 ,
EXTI_Channel_B0 ,
EXTI_Channel_B1 ,
EXTI_Channel_B2 ,
EXTI_Channel_B3 ,
EXTI_Channel_B4 ,
EXTI_Channel_B5 ,
EXTI_Channel_B6 ,
EXTI_Channel_B7 ,
EXTI_Channel_C0 ,
EXTI_Channel_C1 ,
EXTI_Channel_C2 ,
EXTI_Channel_C3 ,
EXTI_Channel_C4 ,
EXTI_Channel_C5 ,
EXTI_Channel_C6 ,
EXTI_Channel_C7 ,
EXTI_Channel_D0 ,
EXTI_Channel_D1 ,
EXTI_Channel_D2 ,
EXTI_Channel_D3 ,
EXTI_Channel_D4 ,
EXTI_Channel_D5 ,
EXTI_Channel_D6 ,
EXTI_Channel_D7 ,
EXTI_Channel_E0 ,
EXTI_Channel_E1 ,
EXTI_Channel_E2 ,
EXTI_Channel_E3 ,
EXTI_Channel_E4 ,
EXTI_Channel_E5 ,
EXTI_Channel_F0  =40 ,
EXTI_Channel_F1 ,
EXTI_Channel_F2 ,
EXTI_Channel_F3 ,
EXTI_Channel_F4 ,
EXTI_Channel_F5
}EXTI_ChannelType;

typedef void (*EXTI_CallBackFunctionType)();


typedef enum
{
EXTI_SenseHighLevel,
EXTI_SenseLowLevel,
EXTI_SenseRisingEdge,
EXTI_SenseFallingEdge,
EXTI_SenseBothEdges
}EXTI_SenseType;


typedef enum
{
EXTI_PORTA,
EXTI_PORTB,
EXTI_PORTC,
EXTI_PORTD,
EXTI_PORTE,
EXTI_PORTF
}EXTI_PortType;

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

 
#endif  /* FILE_NAME_H */

/**********************************************************************************************************************
 *  END OF FILE: Std_Types.h
 *********************************************************************************************************************/
