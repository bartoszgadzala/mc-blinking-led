// CPU speed in HZ for delay.h
#define F_CPU	20000000UL

#include <avr/interrupt.h>
#include <util/delay.h>


/* --------------------------------------------------------------------
 * Blinks with LED connected to PD4, specified number of times.
 * -------------------------------------------------------------------- */
void blink(uint8_t count);

/* --------------------------------------------------------------------
 * Main
 * -------------------------------------------------------------------- */
int main() {
	DDRD = _BV(PD4);

	while (1) {
		blink(1);
	}
}

/* --------------------------------------------------------------------
 * Implementations
 * -------------------------------------------------------------------- */

// Funkcja mrugajaca dioda LED ustalona ilosc razy
void blink(uint8_t count) {
	while (count > 0) {
		// LED on
		PORTD = _BV(PD4);
		_delay_ms(1000);

		// LED off
		PORTD = ~_BV(PD4);
		_delay_ms(1000);
    
		count--;
	}
}
