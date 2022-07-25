
#define MAMA *((volatile unsigned long*)(0x400FE608))

int main (void)
{

while (1)
{

MAMA |= 1>>0;

}

}