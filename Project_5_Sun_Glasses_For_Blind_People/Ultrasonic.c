#include"Ultrasonic.h"

volatile u32 count;
volatile u16 Timer1Overflow = 0;
double Distance; // range 0:400 cm  ( distance=(34300*TIMER)/2 = 17150*TIMER )

void Ultrasonic_init(void) {
// Timer1 & Timer0 Init :

	SET_BIT(SREG, PIN7); // SREG Pin7 to Enable the Global Interrupt Enable page 8

	SET_BIT(TIMSK, PIN2);  //Timer1 Overflow Interrupt Enable  (PIE)

	TCCR1A = 0; // Set all bits to zero Normal operation
	TCNT1 = 0;     // Clear timer1 counter ( 16 bit = TCNTL & TCNTH )  page: 109

	TCCR0 = 0b01101001;

	CLR_BIT(TCCR1B, PIN3);
	CLR_BIT(TCCR1B, PIN4);

	// (No prescaling)

	SET_BIT(TCCR1B, PIN0);
	CLR_BIT(TCCR1B, PIN1);
	CLR_BIT(TCCR1B, PIN2);

}

void Check_All_UltraSonic(void) {
	DIO_SetPinValue(PORTA, PIN0, HIGH); // C0: HIGH ( Connected with Trigger pin on Ultrasonic1 )
	_delay_us(10);                    // at least 10us pulse on trigger
	DIO_SetPinValue(PORTA, PIN0, LOW); // C0 : LOW
	TCNT1 = 0;
	SET_BIT(TCCR1B, PIN6);
	SET_BIT(TIFR, PIN5);
	SET_BIT(TIFR, PIN2);
	TCCR1B = 0x41; /* Capture on rising edge, No prescaler*/
	TIFR = 1 << ICF1; /* Clear ICP flag (Input Capture flag) */
	TIFR = 1 << TOV1; /* Clear Timer Overflow flag */

	while ((TIFR & (1 << ICF1)) == 0)
		;/* Wait for rising edge */
	TCNT1 = 0; /* Clear Timer counter */
	CLR_BIT(TCCR1B, PIN6);
	SET_BIT(TIFR, PIN5);
	SET_BIT(TIFR, PIN2);
	TCNT1 = 0; /* Clear Timer counter */
	TCCR1B = 0x01; /* Capture on falling edge, No prescaler */
	TIFR = 1 << ICF1; /* Clear ICP flag (Input Capture flag) */
	TIFR = 1 << TOV1; /* Clear Timer Overflow flag */
	Timer1Overflow = 0;/* Clear Timer overflow count */
	while ((TIFR & (1 << ICF1)) == 0)
		;/* Wait for falling edge */
	count = ICR1 + (65535 * Timer1Overflow);
	Distance = count / 466.4723032;
	lcd_writenumber(Distance);
	LCD_vidSendCommand(0x01);
	if (Distance >= 2 && Distance < 20) {
		OCR0 = 10; //duty cycle
	} else if (Distance >= 20 && Distance < 30) {
		TCCR0 = 0b01101001;
		OCR0 = 50;
	} else if (Distance >= 30 && Distance < 40) {
		OCR0 = 128;
	}
}

ISR(TIMER1_OVF_vect) {
	Timer1Overflow++;
}
