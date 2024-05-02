#include <msp430.h>
#include "state_machine.h"

void __interrupt_vec(WDT_VECTOR) WDT()
{
  static char blink_count = 0;
  if (++blink_count == 125)
  {
    state_transition();
    blink_count = 0;
  }
}
