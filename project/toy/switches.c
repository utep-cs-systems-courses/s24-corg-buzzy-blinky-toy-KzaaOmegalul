#include <msp430.h>
#include "libTimer.h"

#define LED_RED BIT0
#define LED_GREEN BIT6
#define LEDS (LED_RED | LED_GREEN)
#define SW1 BIT3
#define SWITCHES SW1


void switchHandler()
{
  char p1val = P1IN;

  P1IES |= (p1val & SWITCHES);
  P1IES &= (p1val | ~SWITCHES);

  if(p1val && SW1)
    {
      P1OUT |= LED_GREEN;
      P1OUT &= ~LED_RED;
    }
  else
    {
      P1OUT |= LED_RED;
      P1OUT &= LED_GREEN;
    }
}

void switch_init() {

  P1REN |= SWITCHES;
  P1IE |= SWITCHES;
  P1OUT |= SWITCHES;
  P1DIR &= ~SWITCHES;
}
