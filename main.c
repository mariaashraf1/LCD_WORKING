#include"TM4C123GH6PM.H"
#include"lcd70000.h"

int main(){
 GPIO_init();
 LCD_init();
 LCD_Cmd(0x01);
 LCD_Cmd(0x80); /* Force cusor to begining of first row */
 delay_ms(500);
 LCD_String ("HELLO");
 delay_ms(500);

}