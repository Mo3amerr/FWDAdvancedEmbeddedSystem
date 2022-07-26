/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  PORT_Lcfg.c
 *        \brief  Configure you GPT
 *
 *      \details  This is where you can configure your PORT to work as configured here
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

#include "PORT_Cfg.h"
#include "PORT_Types.h"


/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
const Port_ConfigType Port_ConfigPtr[NUM_OF_PINS_ACTIVE]=
{
    {PORT_Channel_F2,Port_DIO,Port_Output,Port_NoAttach,Port_8maCurrent},
    {PORT_Channel_B0,Port_DIO,Port_Input,Port_PullDownResistor,Port_8maCurrent},
    {PORT_Channel_F4,Port_DIO,Port_Input,Port_PullUpResistor,Port_8maCurrent},
    {PORT_Channel_F0,Port_DIO,Port_Input,Port_PullUpResistor,Port_8maCurrent}
};
/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/
