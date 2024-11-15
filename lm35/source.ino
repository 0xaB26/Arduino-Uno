unsigned int read = 0;
unsigned char state = 0, digits[3] = {0}, neww = 0, old = 0, time = 50,
pins[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11},
values[] = {0x01, 0x4F, 0x12, 0x06, 0x4C, 0x24, 0x20, 0x0F, 0x00, 0x04};

void extractDigits(void);
void readValue(void);
void display(void);

void setup(void)
{
  for(unsigned char i = 0; i < 10; ++i)
    pinMode(pins[i], OUTPUT);
  pinMode(A0, INPUT);
  analogReference(EXTERNAL);
}

void loop(void)
{
  readValue();
  extractDigits();
  display();
}
void readValue(void)
{
  read = analogRead(A0);
  if(!state)
  {
    state = 0x01;
    old = (read * 150.0) / 1024.0;
  }
  else
  {
    neww = (read * 150.0) / 1024.0;
    if(neww != old)
      old = neww;
  }
}
void display(void)
{
  for(unsigned char i = 0; i < 3; ++i)
  {
    digitalWrite(pins[6], values[digits[i]] & 0x40);
    digitalWrite(pins[5], values[digits[i]] & 0x20);
    digitalWrite(pins[4], values[digits[i]] & 0x10);
    digitalWrite(pins[3], values[digits[i]] & 0x08);
    digitalWrite(pins[2], values[digits[i]] & 0x04);
    digitalWrite(pins[1], values[digits[i]] & 0x02);
    digitalWrite(pins[0], values[digits[i]] & 0x01);
    if(!i)
    {
      digitalWrite(pins[7], HIGH);
      digitalWrite(pins[8], LOW);
      digitalWrite(pins[9], LOW);
    }
    else if(i == 1)
    {
      digitalWrite(pins[7], LOW);
      digitalWrite(pins[8], HIGH);
      digitalWrite(pins[9], LOW);
    }
    else
    {
      digitalWrite(pins[7], LOW);
      digitalWrite(pins[8], LOW);
      digitalWrite(pins[9], HIGH);
    }
    delay(time);
  }
}
void extractDigits(void)
{
  unsigned char i = 0;
  digits[0] = 0;
  digits[1] = 0;
  digits[2] = 0;
  while(old != 0)
  {
    digits[i++] = old % 10;
    old /= 10;
  }
}