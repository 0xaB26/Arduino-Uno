void setup(void)
{
  pinMode(2, OUTPUT);
  pinMode(4, INPUT);
}
void loop(void)
{
  if(digitalRead(4))        // CHECK IF PIN 4 IS HIGH
    digitalWrite(2, HIGH);  // SET PIN 2 HIGH
  else
    digitalWrite(2, LOW);  // SET PIN 2 LOW
}