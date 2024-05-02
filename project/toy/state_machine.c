#include <msp430.h>
#include "state_machine.h"
#include "led.h"

char red_green()
{
  static char state = 0;

  switch(state)
    {
    case 0:
      red_on = 1;
      state = 1;
      break;
    case 1:
      red_on = 0;
      state = 0;
      break;
    }
  return 1;
}
char green()
{
  char toggle = 0;
  if(red_on)
    {
      green_on ^= 1;
      toggle = 1;
    }
  return toggle;
}

char green_red()
{
  static char state = 0;
  switch(state)
    {
    case 0:
      green_on = 1;
      state = 1;
      break;
    case 1:
      green_on = 0;
      state = 0;
      break;
    }
  return 1;
}
char red()
{
  char toggle = 0;
  if(green_on)
    {
      red_on ^= 1;
      toggle = 1;
    }
  return toggle;
}

void state_transition()
{
  char toggle = 0;

  static enum
  {
    PATTERN1 = 0,
    PATTERN2 = 1,
    INVERSE1 = 2,
    INVERSE2 = 3
  } pattern = 0;

  switch(pattern)
    {
    case PATTERN1:
      toggle = red_green();
      pattern = PATTERN2;
      break;
    case PATTERN2:
      toggle = green();
      pattern = PATTERN1;
      break;
    case INVERSE1:
      toggle = green_red();
      pattern = INVERSE2;
      break;
    case INVERSE2:
      toggle = red();
      pattern = INVERSE1;
      break;
    }

  led_changed = toggle;
  led_update();
}
