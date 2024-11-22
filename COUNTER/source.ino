/* 
 * ARDUINO SKETCH FOR DISPLAYING NUMBERS FROM 00 TO 10
 * USING TIMER1 INTERRUPT TO INCREMENT THE COUNTER BY 1 EACH ONE SECOND
 * USING SEVEN SEGMENT TO DISPLAY THE VALUE OF COUNTER
*/
#include <TimerOne.h>

#define SIZE 2

unsigned char pins[] = {4, 5, 6, 7, 8, 9, 10};
unsigned char control[] = {11, 12};
unsigned char button = 2;
unsigned char value[] = {0x01, 0x4F, 0x12, 0x06, 0x4C, 0x24, 0x20, 0x0F, 0x00, 0x04};
unsigned char digits[SIZE] = {0};
unsigned char time = 50;

void extractDigits(void);
void function(void);

struct COUNT
{
  unsigned char counter : 4;
};

volatile struct COUNT variable;

void setup()
{
  for(unsigned char i = 0; i < 7; ++i)
    pinMode(pins[i], OUTPUT);
  for(unsigned char i = 0; i < 2; ++i)
    pinMode(control[i], OUTPUT);
  pinMode(button, INPUT);
  variable.counter = 0;
  Timer1.initialize(1000000);
  Timer1.attachInterrupt(function);
}
void loop()
{
  unsigned char x, position, i;
  extractDigits();
  x = 0;
  position = 0x01;
  i = 0;
  while(i < 2)
  {
    for(unsigned char j = 0; j != 7; ++j)
      digitalWrite(pins[j], ( value[digits[x]] & (position << j) ));
    if(i == 0)
    {
      digitalWrite(control[i+1], HIGH);
      digitalWrite(control[i], LOW);
    }
    else
    {
      digitalWrite(control[i], LOW);
      digitalWrite(control[i-1], HIGH);
    }
    delay(time);
    ++i;
    ++x;
  }
}
void extractDigits(void)
{
  if(variable.counter == 0)
  {
    digits[0] = 0;
    digits[1] = 0;
  }
  else
  {
    unsigned char value = variable.counter, i = 0;
    while(value != 0)
    {
      digits[i++] = value % 10;
      value /= 10;
    }
  }
}
void function(void)
{
  variable.counter = (variable.counter == 9 ? 0 : ++variable.counter);
}
