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
#include "Mcu_Hw.h"
#include "PORT_Cfg.h"
#include "PORT_Types.h"
#include "PORT.h"



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
 * \Syntax          : void PORT_Init (const Port_ConfigType* ConfigPtr[counter] )
 * \Description     : This Function is used to Initialize Ports as they are used to be in our Application
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : ConfigPtr[counter] >> Pointer to Struct that carries the whole data of ports
 * \Parameters (out): None
 * \Return value:   : None
 *******************************************************************************/
void PORT_Init(const Port_ConfigType* ConfigPtr)
{
    uint8 counter;
    for (counter = 0; counter < NUM_OF_PINS_ACTIVE; counter++)
    {
        switch (ConfigPtr[counter].Pin_Channel)
        {
        case PORT_Channel_A0 ... PORT_Channel_A7:
        {
            switch (ConfigPtr[counter].PinType)
            {
            case Port_DIO:
                GPIOA_GPIODEN |= (1 << ((ConfigPtr[counter].Pin_Channel) % 8));
                break;

            default:
                break;
            }

            switch (ConfigPtr[counter].PinDirection)
            {
            case Port_Input:
            {
                GPIOA_GPIODIR &= ~(1 << ((ConfigPtr[counter].Pin_Channel) % 8));
                break;
            }
            case Port_Output:
            {
                GPIOA_GPIODIR |= (1 << ((ConfigPtr[counter].Pin_Channel) % 8));
                break;
            }
            default:
                break;
            }

            switch (ConfigPtr[counter].PinInternalAttach)
            {
            case Port_PullDownResistor:
                GPIOA_GPIOPDR |= (1 << ((ConfigPtr[counter].Pin_Channel) % 8));
                break;
            case Port_PullUpResistor:
                GPIOA_GPIOPUR |= (1 << ((ConfigPtr[counter].Pin_Channel) % 8));
                break;
            case Port_OpenDrain:
                GPIOA_GPIOODR |= (1 << ((ConfigPtr[counter].Pin_Channel) % 8));
                break;

            case Port_NoAttach:
                break;    

            default:
                break;
            }

            switch (ConfigPtr[counter].PinOutputCurrent)
            {
            case Port_2maCurrent:
                GPIOA_GPIODR2R |= (1 << ((ConfigPtr[counter].Pin_Channel) % 8));
                break;

            case Port_4maCurrent:
                GPIOA_GPIODR4R |= (1 << ((ConfigPtr[counter].Pin_Channel) % 8));
                break;

            case Port_8maCurrent:
                GPIOA_GPIODR8R |= (1 << ((ConfigPtr[counter].Pin_Channel) % 8));
                break;

            default:
                break;
            }
        }
        /* code */
        break;


        case PORT_Channel_B0 ... PORT_Channel_B7:
        {
            switch (ConfigPtr[counter].PinType)
            {
            case Port_DIO:
                GPIOB_GPIODEN |= (1 << ((ConfigPtr[counter].Pin_Channel) % 8));
                break;

            default:
                break;
            }

            switch (ConfigPtr[counter].PinDirection)
            {
            case Port_Input:
            {
                GPIOB_GPIODIR &= ~(1 << ((ConfigPtr[counter].Pin_Channel) % 8));
                break;
            }
            case Port_Output:
            {
                GPIOB_GPIODIR |= (1 << ((ConfigPtr[counter].Pin_Channel) % 8));
                break;
            }
            default:
                break;
            }

            switch (ConfigPtr[counter].PinInternalAttach)
            {
            case Port_PullDownResistor:
                GPIOB_GPIOPDR |= (1 << ((ConfigPtr[counter].Pin_Channel) % 8));
                break;
            case Port_PullUpResistor:
                GPIOB_GPIOPUR |= (1 << ((ConfigPtr[counter].Pin_Channel) % 8));
                break;
            case Port_OpenDrain:
                GPIOB_GPIOODR |= (1 << ((ConfigPtr[counter].Pin_Channel) % 8));
                break;

            case Port_NoAttach:
                break;  

            default:
                break;
            }

            switch (ConfigPtr[counter].PinOutputCurrent)
            {
            case Port_2maCurrent:
                GPIOB_GPIODR2R |= (1 << ((ConfigPtr[counter].Pin_Channel) % 8));
                break;

            case Port_4maCurrent:
                GPIOB_GPIODR4R |= (1 << ((ConfigPtr[counter].Pin_Channel) % 8));
                break;

            case Port_8maCurrent:
                GPIOB_GPIODR8R |= (1 << ((ConfigPtr[counter].Pin_Channel) % 8));
                break;

            default:
                break;
            }
        }
        /* code */
        break;

        case PORT_Channel_C0 ... PORT_Channel_C7:
        {
            switch (ConfigPtr[counter].PinType)
            {
            case Port_DIO:
                GPIOC_GPIODEN |= (1 << ((ConfigPtr[counter].Pin_Channel) % 8));
                break;

            default:
                break;
            }

            switch (ConfigPtr[counter].PinDirection)
            {
            case Port_Input:
            {
                GPIOC_GPIODIR &= ~(1 << ((ConfigPtr[counter].Pin_Channel) % 8));
                break;
            }
            case Port_Output:
            {
                GPIOC_GPIODIR |= (1 << ((ConfigPtr[counter].Pin_Channel) % 8));
                break;
            }
            default:
                break;
            }

            switch (ConfigPtr[counter].PinInternalAttach)
            {
            case Port_PullDownResistor:
                GPIOC_GPIOPDR |= (1 << ((ConfigPtr[counter].Pin_Channel) % 8));
                break;
            case Port_PullUpResistor:
                GPIOC_GPIOPUR |= (1 << ((ConfigPtr[counter].Pin_Channel) % 8));
                break;
            case Port_OpenDrain:
                GPIOC_GPIOODR |= (1 << ((ConfigPtr[counter].Pin_Channel) % 8));
                break;

            case Port_NoAttach:
                break;      

            default:
                break;
            }

            switch (ConfigPtr[counter].PinOutputCurrent)
            {
            case Port_2maCurrent:
                GPIOC_GPIODR2R |= (1 << ((ConfigPtr[counter].Pin_Channel) % 8));
                break;

            case Port_4maCurrent:
                GPIOC_GPIODR4R |= (1 << ((ConfigPtr[counter].Pin_Channel) % 8));
                break;

            case Port_8maCurrent:
                GPIOC_GPIODR8R |= (1 << ((ConfigPtr[counter].Pin_Channel) % 8));
                break;

            default:
                break;
            }
        }
        /* code */
        break;


        case PORT_Channel_D0 ... PORT_Channel_D7:
        {
            switch (ConfigPtr[counter].PinType)
            {
            case Port_DIO:
                GPIOD_GPIODEN |= (1 << ((ConfigPtr[counter].Pin_Channel) % 8));
                break;

            default:
                break;
            }

            switch (ConfigPtr[counter].PinDirection)
            {
            case Port_Input:
            {
                GPIOD_GPIODIR &= ~(1 << ((ConfigPtr[counter].Pin_Channel) % 8));
                break;
            }
            case Port_Output:
            {
                GPIOD_GPIODIR |= (1 << ((ConfigPtr[counter].Pin_Channel) % 8));
                break;
            }
            default:
                break;
            }

            switch (ConfigPtr[counter].PinInternalAttach)
            {
            case Port_PullDownResistor:
                GPIOD_GPIOPDR |= (1 << ((ConfigPtr[counter].Pin_Channel) % 8));
                break;
            case Port_PullUpResistor:
                GPIOD_GPIOPUR |= (1 << ((ConfigPtr[counter].Pin_Channel) % 8));
                break;
            case Port_OpenDrain:
                GPIOD_GPIOODR |= (1 << ((ConfigPtr[counter].Pin_Channel) % 8));
                break;

            case Port_NoAttach:
                break;      

            default:
                break;
            }

            switch (ConfigPtr[counter].PinOutputCurrent)
            {
            case Port_2maCurrent:
                GPIOD_GPIODR2R |= (1 << ((ConfigPtr[counter].Pin_Channel) % 8));
                break;

            case Port_4maCurrent:
                GPIOD_GPIODR4R |= (1 << ((ConfigPtr[counter].Pin_Channel) % 8));
                break;

            case Port_8maCurrent:
                GPIOD_GPIODR8R |= (1 << ((ConfigPtr[counter].Pin_Channel) % 8));
                break;

            default:
                break;
            }
        }
        /* code */
        break;


        case PORT_Channel_E0 ... PORT_Channel_E5:
        {
            switch (ConfigPtr[counter].PinType)
            {
            case Port_DIO:
                GPIOE_GPIODEN |= (1 << ((ConfigPtr[counter].Pin_Channel) % 8));
                break;

            default:
                break;
            }

            switch (ConfigPtr[counter].PinDirection)
            {
            case Port_Input:
            {
                GPIOE_GPIODIR &= ~(1 << ((ConfigPtr[counter].Pin_Channel) % 8));
                break;
            }
            case Port_Output:
            {
                GPIOE_GPIODIR |= (1 << ((ConfigPtr[counter].Pin_Channel) % 8));
                break;
            }
            default:
                break;
            }

            switch (ConfigPtr[counter].PinInternalAttach)
            {
            case Port_PullDownResistor:
                GPIOE_GPIOPDR |= (1 << ((ConfigPtr[counter].Pin_Channel) % 8));
                break;
            case Port_PullUpResistor:
                GPIOE_GPIOPUR |= (1 << ((ConfigPtr[counter].Pin_Channel) % 8));
                break;
            case Port_OpenDrain:
                GPIOE_GPIOODR |= (1 << ((ConfigPtr[counter].Pin_Channel) % 8));
                break;

            case Port_NoAttach:
                break;      

            default:
                break;
            }

            switch (ConfigPtr[counter].PinOutputCurrent)
            {
            case Port_2maCurrent:
                GPIOE_GPIODR2R |= (1 << ((ConfigPtr[counter].Pin_Channel) % 8));
                break;

            case Port_4maCurrent:
                GPIOE_GPIODR4R |= (1 << ((ConfigPtr[counter].Pin_Channel) % 8));
                break;

            case Port_8maCurrent:
                GPIOE_GPIODR8R |= (1 << ((ConfigPtr[counter].Pin_Channel) % 8));
                break;

            default:
                break;
            }
        }
        /* code */
        break;

        case PORT_Channel_F0 ... PORT_Channel_F4:
        {

            switch (ConfigPtr[counter].PinDirection)
            {
            case Port_Input:
            {
                GPIOF_GPIODIR &= ~(1 << ((ConfigPtr[counter].Pin_Channel) % 8));
                break;
            }
            case Port_Output:
            {
                GPIOF_GPIODIR |= (1 << ((ConfigPtr[counter].Pin_Channel) % 8));
                break;
            }
            default:
                break;
            }    


            switch (ConfigPtr[counter].PinType)
            {
            case Port_DIO:
                GPIOF_GPIODEN |= (1 << ((ConfigPtr[counter].Pin_Channel) % 8));
                break;

            default:
                break;
            }

            

            switch (ConfigPtr[counter].PinInternalAttach)
            {
            case Port_PullDownResistor:
                GPIOF_GPIOPDR |= (1 << ((ConfigPtr[counter].Pin_Channel) % 8));
                break;
            case Port_PullUpResistor:
                GPIOF_GPIOPUR |= (1 << ((ConfigPtr[counter].Pin_Channel) % 8));
                break;
            case Port_OpenDrain:
                GPIOF_GPIOODR |= (1 << ((ConfigPtr[counter].Pin_Channel) % 8));
                break;
            case Port_NoAttach:
                break; 

            default:
                break;
            }

            switch (ConfigPtr[counter].PinOutputCurrent)
            {
            case Port_2maCurrent:
                GPIOF_GPIODR2R |= (1 << ((ConfigPtr[counter].Pin_Channel) % 8));
                break;

            case Port_4maCurrent:
                GPIOF_GPIODR4R |= (1 << ((ConfigPtr[counter].Pin_Channel) % 8));
                break;

            case Port_8maCurrent:
                GPIOF_GPIODR8R |= (1 << ((ConfigPtr[counter].Pin_Channel) % 8));
                break;

            default:
                break;
            }
        }
        /* code */
        break;


        default:
            break;
        }
    }
}
/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/
