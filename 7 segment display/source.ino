unsigned char pins[] = {2, 3, 4, 5, 6, 7, 8}, state = 0,
value[] = {0x01, 0x4F, 0x12, 0x06, 0x4C, 0x24, 0x20, 0x0F, 0x00, 0x04};   // 7 SEGMENT ANODE COMMON VALUES

float result = 0;
unsigned int read = 0, newValue = 0, oldValue = 0;

void setup(void)
{
  for(unsigned int i = 0; i < 7; ++i)
    pinMode(pins[i], OUTPUT);
}
void function(void)
{
  digitalWrite(pins[0], (value[oldValue] & 0x40));
  digitalWrite(pins[1], (value[oldValue] & 0x20));
  digitalWrite(pins[2], (value[oldValue] & 0x10));
  digitalWrite(pins[3], (value[oldValue] & 0x08));
  digitalWrite(pins[4], (value[oldValue] & 0x04));
  digitalWrite(pins[5], (value[oldValue] & 0x02));
  digitalWrite(pins[6], (value[oldValue] & 0x01));
}
void loop(void)
{
  read = analogRead(A2);            // READ ANALOG SIGNAL FROM PIN A2
  result = ceil((read * 5) / 1023); // MAP THE VALUES (0-1023) TO (0-5) IN ORDER TO BE DISPLAYED ON 7 SEGMENT
  if(state == 0)                    
  { 
    oldValue = (unsigned int)result;
    function();
    state = 0x01;
  }
  else                            // THIS IS USED ONLY TO DISPLAY WHEN THE VALUE CHANGES 
  {
    newValue = (unsigned int)result;
    if(newValue != oldValue)
    {
      oldValue = newValue;
      function();           // DISPLAY THE VALUE
    }
  }
}