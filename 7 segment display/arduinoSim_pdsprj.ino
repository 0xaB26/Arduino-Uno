unsigned char pins[] = {13, 12, 8, 7}, counter = 0x00;
unsigned int time = 1000;

void setup(void)
{
  for(unsigned char i = 0; i < 4; ++i)
    pinMode(pins[i], OUTPUT);
}

void loop(void)
{
  if(counter != 0x0A)
  {
    digitalWrite(pins[0], (counter & 0x01));
    digitalWrite(pins[1], (counter & 0x02));
    digitalWrite(pins[2], (counter & 0x04));
    digitalWrite(pins[3], (counter & 0x08));
    delay(time);
    ++counter;
  }
  else
    counter = 0x00;
}