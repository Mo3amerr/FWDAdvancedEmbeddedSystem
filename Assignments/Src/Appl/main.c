
#include "Std_Types.h"
#include "BIT_MATH.h"
#include "Mcu_Hw.h"
#include "PORT.h"
#include "IntCtrl.h"
#include "GPT.h"
#include "DIO.h"

void FlipChannel(void);


int main (void)
{
// 	RCGCGPIO |= 1<<5;
    
//     PORT_Init(ConfigPtr);
// uint8 ValueA=0;
// 	uint8 ValueB=0;
// IntCrtl_Init();

// DIO_WritePort(DIO_PORTF,14);
// 	//DIO_WritePort(DIO_PORTF,1);

// ValueA =DIO_ReadChannel(DIO_Channel_F4);
// 	ValueB =DIO_ReadChannel(DIO_Channel_F3);

// ValueA = DIO_ReadPort(DIO_PORTF);
// 	ValueB = DIO_ReadPort(DIO_PORTF);

// DIO_WrtieChannel(DIO_Channel_F3,DIO_LevelLow);
// ValueA = DIO_ReadPort(DIO_PORTF);
	
// 	DIO_WrtieChannel(DIO_Channel_F2,DIO_LevelLow);
// ValueB = DIO_ReadPort(DIO_PORTF);


// DIO_FlipChannel(DIO_Channel_F3);
// ValueA = DIO_ReadPort(DIO_PORTF);



// DIO_FlipChannel(DIO_Channel_F1);
// ValueB = DIO_ReadPort(DIO_PORTF);

 RCGCGPIO |= 1<<5; //Clock at port F
 RCGCTIMER |= 1<<1; //clock at timer 1
  RCGCTIMER |= 1<<0; //clock at timer 0

 IntCrtl_Init();
 PORT_Init(ConfigPtr);
 GPT_Init(GPT_Config_Array);

 GPT_EnableNotification(GPT_16_32_BitTimer1,FlipChannel);

 GPT_StartTimer(GPT_16_32_BitTimer1,0xff);


while (1)
{



}

}


void FlipChannel(void)
{
	DIO_FlipChannel(DIO_Channel_F2);
}