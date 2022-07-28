
#include "Std_Types.h"
#include "BIT_MATH.h"
#include "Mcu_Hw.h"
#include "PORT.h"
#include "IntCtrl.h"
#include "DIO.h"


int main (void)
{
	RCGCGPIO |= 1<<5;
    
    PORT_Init(ConfigPtr);
uint8 ValueA=0;
	uint8 ValueB=0;
IntCrtl_Init();

DIO_WritePort(DIO_PORTF,14);
	//DIO_WritePort(DIO_PORTF,1);

ValueA =DIO_ReadChannel(DIO_Channel_F4);
	ValueB =DIO_ReadChannel(DIO_Channel_F3);

ValueA = DIO_ReadPort(DIO_PORTF);
	ValueB = DIO_ReadPort(DIO_PORTF);

DIO_WrtieChannel(DIO_Channel_F3,DIO_LevelLow);
ValueA = DIO_ReadPort(DIO_PORTF);
	
	DIO_WrtieChannel(DIO_Channel_F2,DIO_LevelLow);
ValueB = DIO_ReadPort(DIO_PORTF);


DIO_FlipChannel(DIO_Channel_F3);
ValueA = DIO_ReadPort(DIO_PORTF);



DIO_FlipChannel(DIO_Channel_F1);
ValueB = DIO_ReadPort(DIO_PORTF);


while (1)
{



}

}