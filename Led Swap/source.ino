unsigned int pins[] = {2, 4, 7, 8, 12, 13}, position = 0, time = 500;

void setup(void)
{
  for(unsigned int i = 0; i < 6; ++i)
    pinMode(pins[i], OUTPUT);     // OUTPUT MODE
}

void loop(void)
{
  for(unsigned int i = 0; i < 6; ++i)
  {
    if(i != position)                  
      digitalWrite(pins[i], LOW);
    else
      digitalWrite(pins[i], HIGH);
  }
  delay(time);
  if(position != 5)              
    ++position;
  else
    position = 0;
}