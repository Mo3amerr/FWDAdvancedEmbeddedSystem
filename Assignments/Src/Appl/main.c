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
#include "PORT.h"
#include "IntCtrl.h"
#include "EXTI.h"
#include "GPT.h"
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

volatile uint8 Global_OnTime=1;
volatile uint8 Global_OffTime=1;
/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
void FlipChannel(void);
void ChangeOnAndOffTime (void);



/**********************************************************************************************************************
 *  MAIN FUNCTION
 *********************************************************************************************************************/
int main (void)
{
	RCGCGPIO |= 1<<1;	//Clock to Port B
 	RCGCGPIO |= 1<<5; //Clock at Port F
 	RCGCTIMER |= 1<<1; //clock at timer 1
  	RCGCTIMER |= 1<<0; //clock at timer 0
	RCGCWTIMER |= 1<<1; // clock at Wtimer1
	
	GPIO_GPIOLOCK(GPIOF_APB_BASE_ADDRESS_MASK) = 0x4C4F434B;
  while (GPIO_GPIOLOCK(GPIOF_APB_BASE_ADDRESS_MASK))
  {
  }
  SET_BIT(GPIO_GPIOCR(GPIOF_APB_BASE_ADDRESS_MASK),0);

 IntCrtl_Init();
 PORT_Init(ConfigPtr);
 GPT_Init(GPT_Config_Array);
 GPT_Attach(FlipChannel,500);
 EXTI_AttachInterrupt(EXTI_Channel_F4,EXTI_SenseFallingEdge,ChangeOnAndOffTime);
 EXTI_AttachInterrupt(EXTI_Channel_F0,EXTI_SenseFallingEdge,ChangeOnAndOffTime);



while (1);

}

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


void FlipChannel(void)
{ 	
	static boolean counter = TRUE;

	if(counter==TRUE)
	{GPT_StartTimer(GPT_16_32_BitTimer1,Global_OnTime*1000);}

	else if(counter==FALSE)
	{GPT_StartTimer(GPT_16_32_BitTimer1,Global_OffTime*1000);}

	counter =!counter;

	DIO_FlipChannel(DIO_Channel_F2);
}


void ChangeOnAndOffTime (void)
{	
	static boolean OnTimeFlag=TRUE;
	static uint8 Oncounter=0;
	if(GET_BIT(GPIO_GPIOMIS(GPIOF_APB_BASE_ADDRESS_MASK),(EXTI_Channel_F0%8))==1)
	{
		SET_BIT(GPIO_GPIOICR(GPIOF_APB_BASE_ADDRESS_MASK),(EXTI_Channel_F0%8));
		Oncounter ++;
		
	}
	else if(GET_BIT(GPIO_GPIOMIS(GPIOF_APB_BASE_ADDRESS_MASK),(EXTI_Channel_F4%8))==1)
	{
		SET_BIT(GPIO_GPIOICR(GPIOF_APB_BASE_ADDRESS_MASK),(EXTI_Channel_F4%8));
		if(OnTimeFlag==TRUE)
		{
			Global_OffTime = Oncounter;
		}
		else if(OnTimeFlag==FALSE)
		{
			
			Global_OnTime = Oncounter;
			// Oncounter=0;
		}

		OnTimeFlag = !OnTimeFlag;
		Oncounter=0;
	}

}


/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/
















