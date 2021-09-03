#include "Ultrasonic.h"

#include "DIO_int.h"

int main(void) {

	DIO_SetPinDirection(PORTA, PIN0, OUTPUT);  // C0: Ultrasonic1 Trigger

	DIO_SetPinDirection(PORTA, PIN1, OUTPUT);  // C0: Ultrasonic1 Trigger
	DIO_SetPinDirection(PORTA, PIN2, OUTPUT);  // C0: Ultrasonic1 Trigger
	DIO_SetPinDirection(PORTA, PIN3, OUTPUT);  // C0: Ultrasonic1 Trigger

	DIO_SetPinDirection(PORTD, PIN6, INPUT);  // D6: INPUT ( ICP Pin )

	DIO_SetPortDirection(PORTC, HIGH);

	DIO_SetPinDirection(PORTB, PIN3, OUTPUT);  // C0: Ultrasonic1 Trigger

	Ultrasonic_init(); // Ultrasonic Init

	LCD_vidInit();
	while (1) {

		Check_All_UltraSonic();

	}

	return 0;
}
