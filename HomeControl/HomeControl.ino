int relays[] = {37, 36, 35, 34, 33, 32, 31, 30, 29, 28, 27, 26, 25, 24, 23, 22 };
int switches[] = {38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53 }; 
bool stateRelays[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1\ };
 
void setup()
{
  for (byte i = 0; i < 16; i = i + 1) {
    pinMode(switches[i], INPUT_PULLUP);
    pinMode(relays[i], OUTPUT);
    digitalWrite(relays[i], stateRelays[i]);
  }
}
 
void loop()
{
  for (byte i = 0; i < 16; i = i + 1) {
    if(digitalRead(switches[i]) == LOW)
    {
      stateRelays[i] = !stateRelays[i];
      digitalWrite(relays[i], stateRelays[i]);
      while(digitalRead(switches[i]) == LOW);
      delay(100);       
    }    
  }
}
