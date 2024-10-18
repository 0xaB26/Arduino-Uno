unsigned int read = 0;
float neww = 0, old = 0;
unsigned char state = 0;

void setup(void)
{
  Serial.begin(9600);
  pinMode(A0, INPUT);
  analogReference(EXTERNAL);
}

void loop(void)
{
  read = analogRead(A0);
  if(!state)
  {
    state = 0x01;
    old = (read * 150.0) / 1024.0;
    Serial.print("Temperature : ");
    Serial.println(old);
  }
  else
  {
    neww = (read * 150.0) / 1024.0;
    if(neww != old)
    {
      old = neww;
      Serial.print("Temperature : ");
      Serial.println(old);
    }
  }
}