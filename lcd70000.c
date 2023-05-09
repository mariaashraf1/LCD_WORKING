#include"lcd70000.h"
#include"TM4C123GH6PM.H"
/*************************************************************/

void GPIO_init(void){
 SYSCTL->RCGCGPIO |=(1<<1); /* Enable Clock to GPIOB */
 while((SYSCTL-> PRGPIO & 0x2) == 0);
	GPIOB->DIR |=0xFF; /* Set GPIOB all pins a digital output pins */
	GPIOB->DEN |=0xFF; /* Declare GPIOB pins as digital pins */
  GPIOB->AFSEL=0;
  GPIOB->AMSEL=0;

}



/*************************************************************/



void LCD_init(void){
LCD_Cmd(0X02);
LCD_Cmd(0X28);
LCD_Cmd(0X0F); 
LCD_Cmd(0X06); 
 
}
/*************************************************************/


void LCD_Write_Nibble(unsigned char data, unsigned char control)
{

    data &= 0xF0;       /* Extract upper nibble for data */
    control &= 0x0F;    /* Extract lower nibble for control */
    GPIOB->DATA = data | control;       /* Set RS and R/W to zero for write operation */
    GPIOB->DATA = data | control | EN;  /* Provide Pulse to Enable pin to perform wite operation */
    delay_us(0);
    GPIOB->DATA = data; /*Send data */
    GPIOB->DATA = 0; /* stop writing data to GPIOB */
}


/*************************************************************/



void LCD_Cmd(unsigned char command)
{
    LCD_Write_Nibble(command & 0xF0, 0);   /* Write upper nibble to LCD */
    LCD_Write_Nibble(command << 4, 0);     /* Write lower nibble to LCD */
    
    if (command < 4)
        delay_ms(2);         /* 2ms delay for commands 1 and 2 */
    else
        delay_us(40);        /* 40us delay for other commands */
}

/*************************************************************/

void LCD_Write_Char(unsigned char data)
{
    LCD_Write_Nibble(data & 0xF0, RS);    /* Write upper nibble to LCD and RS = 1 to write data */
    LCD_Write_Nibble(data << 4, RS);      /* Write lower nibble to LCD and RS = 1 to write data */
    delay_us(40);
}


/*************************************************************/

void LCD_String (char *str)	
{
	int i;
	for(i=0;str[i]!=0;i++)  /* Send each char of string till the NULL */
	{
		LCD_Write_Char(str[i]);  /* Call LCD data write */
	}
}

/*************************************************************/
void delay_ms(int n)
{
 int i,j;
 for(i=0;i<n;i++)
 for(j=0;j<3180;j++)
 {}
}

/*************************************************************/
void delay_us(int n)
{
 int i,j;
 for(i=0;i<n;i++)
 for(j=0;j<3;j++)
 {}
 
}
/*************************************************************/