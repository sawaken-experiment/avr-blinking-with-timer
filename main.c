#include<avr/io.h>
#include <avr/interrupt.h>

ISR(TIMER0_OVF_vect)
{
  PORTD ^= 0b10000000;
}

void init_timer() {
  // 割り込み禁止
  cli();

  // TIMSK := OCIE2 TOIE2 TICIE1 OCIE1A OCIE1B TOIE1 - TOIE0
  TIMSK = 0b00000001; // TOIE0 = 1 <=> Timer/Counter0 Overflow interrupt is enabled.

  // TCCR0 := - - - - - CS02 CS01 CS00
  TCCR0 = 0b00000100; // CS0[2:0] = 0b100 <=> 256clkごとにカウントアップ

  // 割り込み許可
  sei();
}

int main() {
  DDRD = 0b10000000;
  PORTD = 0b10000000;
  init_timer();
  while (1);
  return 0;
}
