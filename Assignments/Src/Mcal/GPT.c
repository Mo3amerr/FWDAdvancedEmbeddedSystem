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
#include "GPT_Types.h"
#include "GPT.h"
#include "GPT_Cfg.h"

/**********************************************************************************************************************
 *  LOCAL MACROS CONSTANT\FUNCTION
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA
 *********************************************************************************************************************/
static const uint32 Gpt_BaseAddress[MAX_NUM_OF_GPIO_GPT] = {GPT_16_32_BIT_TIMER0_BASE_ADDRESS,
                                                            GPT_16_32_BIT_TIMER1_BASE_ADDRESS,
                                                            GPT_16_32_BIT_TIMER2_BASE_ADDRESS,
                                                            GPT_16_32_BIT_TIMER3_BASE_ADDRESS,
                                                            GPT_16_32_BIT_TIMER4_BASE_ADDRESS,
                                                            GPT_16_32_BIT_TIMER5_BASE_ADDRESS,
                                                            GPT_32_64_BIT_WIDE_TIMER0_BASE_ADDRESS,
                                                            GPT_32_64_BIT_WIDE_TIMER1_BASE_ADDRESS,
                                                            GPT_32_64_BIT_WIDE_TIMER2_BASE_ADDRESS,
                                                            GPT_32_64_BIT_WIDE_TIMER3_BASE_ADDRESS,
                                                            GPT_32_64_BIT_WIDE_TIMER4_BASE_ADDRESS,
                                                            GPT_32_64_BIT_WIDE_TIMER5_BASE_ADDRESS};
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
void GPT_Init(const GPT_ConfigType *ConfigPtr)
{
    
	uint32 i,prescale;
	uint32 gptBaseAddress;
	GPT_ChannelType  					locChannel;
	GPT_ChannelMode								locChannelMode;
	GPT_ChannelTickFrequency 	locChannelTickFreq;
	GPT_ChannelTickValueMax  	locChannelTickMaxValue;
	
	for(i=0;i<NUM_ACTIVE_TIMERS;i++)
	{
		locChannel								= ConfigPtr[i].channel;
		locChannelTickFreq				= ConfigPtr[i].channelTickFreq;
		locChannelTickMaxValue		= ConfigPtr[i].channelTickMaxValue;
		locChannelMode						= ConfigPtr[i].channelMode;
		
		locGptNotification[locChannel]= ConfigPtr[i].gptNotification;
		
		gptBaseAddress = Gpt_BaseAddress[locChannel];


		GPTMCTL(gptBaseAddress) =	0;
		
		/*
		* For a 16/32-bit timer, this value selects the 16-bit timer configuration.
		* For a 32/64-bit wide timer, this value selects the 32-bit timer configuration.
		*/
		GPTMCFG(gptBaseAddress) = 0x4;
		
		/* counting up */
		GPTMTAMR(gptBaseAddress) |= (1<<TACDIR);
		
		/* channel mode */
		if (locChannelMode == GPT_ModeOneShot)
		{
			GPTMTAMR(gptBaseAddress) |= 0x1;
		}
		else if (locChannelMode == GPT_ModeContinuous)
		{
			GPTMTAMR(gptBaseAddress) |= 0x2; 
		}
		
		/* Disablling interupt notifation */
		Gpt_DisableNotification(locChannel);
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
void GPT_DisableNotification(GPT_ChannelType Channel)
{
    uint32 gptBaseAddress;
    gptBaseAddress = Gpt_BaseAddress[Channel];
    GPTMIMR(gptBaseAddress) = 0;
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
void GPT_EnableNotification(GPT_ChannelType Channel)
{

    uint32 gptBaseAddress;
    gptBaseAddress = Gpt_BaseAddress[Channel];
    GPTMIMR(gptBaseAddress) = 0x1;
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

GPT_ValueType Gpt_GetTimeElapsed( GPT_ChannelType Channel )
{
	GPT_ValueType value;
	uint32 i;
	uint32 prescale;
	uint32 gptBaseAddress;
	GPT_ChannelTickFrequency 	locChannelTickFreq;
	GPT_ChannelTickValueMax  	locChannelMaxValue;
	
	gptBaseAddress = Gpt_BaseAddress[Channel];
	for(i=0;i<MAX_NUM_OF_GPIO_GPT;i++)
	{
		if (globalGptConfig[i].channel == Channel)
		{
			locChannelTickFreq = globalGptConfig[i].channelTickFreq;
			locChannelMaxValue = globalGptConfig[i].channelTickMaxValue;
			
			break;
		}
	}
	
	prescale = 16000000 / locChannelTickFreq;
	
	for(i=2;;i*=2)
	{
		if(prescale/i == 1)
		{
			if(prescale%i <= (i/2))
			{
				prescale = i;
			}
			else
			{
				prescale = i*2;
			}
			break;
		}
	}
	value = (GPTMTAV(gptBaseAddress) / prescale) & locChannelMaxValue;
	
	return value;
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
void GPT_StartTimer(GPT_ChannelType Channel, GPT_ValueType Value)
{
    uint32 i;
	uint32 prescale;
	uint32 gptBaseAddress;
	GPT_ChannelTickFrequency 	locChannelTickFreq;
	
	gptBaseAddress = Gpt_BaseAddress[Channel];
		for(i=0;i<MAX_NUM_OF_GPIO_GPT;i++)
	{
		if (globalGptConfig[i].channel == Channel)
		{
			locChannelTickFreq = globalGptConfig[i].channelTickFreq;			
			break;
		}
	}
	
	prescale = 16000000 / locChannelTickFreq;
	
	for(i=2;;i*=2)
	{
		if(prescale/i == 1)
		{
			if(prescale%i <= (i/2))
			{
				prescale = i;
			}
			else
			{
				prescale = i*2;
			}
			break;
		}
	}
	/* adding the value deppending on the freq required */
	GPTMTAILR(gptBaseAddress) = Value * prescale;
	
	GPTMCTL(gptBaseAddress) |= (1<<TAEN);
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
void GPT_StopTimer(GPT_ChannelType Channel);
{
    uint32 gptBaseAddress;
    gptBaseAddress = Gpt_BaseAddress[Channel];

    GPTMCTL(gptBaseAddress) &= (~(1 << TAEN));
}



void TIMER0A_Handler(void)
{
	static GPT_Notification gptNotificationFn_TIMER0A;
	if (locGptNotification[GPT_ChannelA0] != NULL)
	{
		gptNotificationFn_TIMER0A = locGptNotification[GPT_ChannelA0];
		gptNotificationFn_TIMER0A();
	}
}

void TIMER1A_Handler(void)
{
	static GPT_Notification gptNotificationFn_TIMER1A;
	if (locGptNotification[GPT_ChannelA1] != NULL)
	{
		gptNotificationFn_TIMER1A = locGptNotification[GPT_ChannelA1];
		gptNotificationFn_TIMER1A();
	}
}

void TIMER2A_Handler(void)
{
	static GPT_Notification gptNotificationFn_TIMER2A;
	if (locGptNotification[GPT_ChannelA2] != NULL)
	{
		gptNotificationFn_TIMER2A = locGptNotification[GPT_ChannelA2];
		gptNotificationFn_TIMER2A();
	}
}

void TIMER3A_Handler(void)
{
	static GPT_Notification gptNotificationFn_TIMER3A;
	if (locGptNotification[GPT_ChannelA3] != NULL)
	{
		gptNotificationFn_TIMER3A = locGptNotification[GPT_ChannelA3];
		gptNotificationFn_TIMER3A();
	}
}

void TIMER4A_Handler(void)
{
	static GPT_Notification gptNotificationFn_TIMER4A;
	if (locGptNotification[GPT_ChannelA4] != NULL)
	{
		gptNotificationFn_TIMER4A = locGptNotification[GPT_ChannelA4];
		gptNotificationFn_TIMER4A();
	} 
}

void TIMER5A_Handler(void)
{
	static GPT_Notification gptNotificationFn_TIMER5A;
	if (locGptNotification[GPT_ChannelA5] != NULL)
	{
		gptNotificationFn_TIMER5A = locGptNotification[GPT_ChannelA5];
		gptNotificationFn_TIMER5A();
	}
}

/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/
