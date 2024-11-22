/* 
 * ARDUINO SKETCH FOR READING A POTENTIOMETER VALUE AND DISPLAY IN ON SEVEN SEGMENT
 * VALUE IS BETWEEN 00 AND 99
*/
#define SIZE 2
unsigned char pins[] = {4, 5, 6, 7, 8, 9, 10};
unsigned char control[] = {11, 12};
unsigned char value[] = {0x01, 0x4F, 0x12, 0x06, 0x4C, 0x24, 0x20, 0x0F, 0x00, 0x04};
unsigned char digits[SIZE] = {0};
unsigned char time = 20, read = 0;

void extractDigits(void);
void function(void);
void setup()
{
  for(unsigned char i = 0; i < 7; ++i)
    pinMode(pins[i], OUTPUT);
  for(unsigned char i = 0; i < 2; ++i)
    pinMode(control[i], OUTPUT);
}
void loop()
{
  unsigned char x, position, i;
  read = (analogRead(A0) * 99.0) / 1024.0;
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
  digits[0] = 0;
  digits[1] = 0;
  unsigned char i = 0;
  while(read != 0)
  {
    digits[i++] = read % 10;
    read /= 10;
  }
}