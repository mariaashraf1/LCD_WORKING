//#include"TM4C123GH6PM.H"
//#define RS 0x20 /* PORTB BIT5 mask */
//#define RW 0x40 /* PORTB BIT6 mask */
//#define EN 0x80 /* PORTB BIT7 mask */


#define RS 0x01 /* PORTB BIT0 mask */
#define RW 0x02 /* PORTB BIT1 mask */
#define EN 0x04 /* PORTB BIT2 mask */

#define HIGH 1
#define LOW 0

void delay_ms(int n); /* mili second delay function */
void delay_us(int n); /* micro second delay function */ 
void GPIO_init(void);  /* GPIO initialization function */
void LCD_init(void);  /* LCD initialization function */
void LCD_Cmd(unsigned char command); /*Used to send commands to LCD */
void LCD_Write_Char(unsigned char data); /* Writes ASCII character */
void LCD_Write_Nibble(unsigned char data, unsigned char control); /* Writes 4-bits */
void LCD_String (char *str);	/* Send string to LCD function */
