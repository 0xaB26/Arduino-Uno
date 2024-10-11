unsigned int pin = 2, time = 500;

void setup(void)
{
  pinMode(pin, OUTPUT);
}

void loop(void)
{
  digitalWrite(pin, HIGH);
  delay(time);
  digitalWrite(pin ,LOW);
  delay(time);
}