// C++ code
//
void setup()
{
  pinMode(2, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(7, OUTPUT);
}

void loop()
{
  digitalWrite(2, HIGH);
  delay(6000); // Wait for 6000 millisecond(s) vermeho
  digitalWrite(2, LOW);

  digitalWrite(7, HIGH);
  delay(4000); // Wait for 4000 millisecond(s) verde
  digitalWrite(7, LOW);

  digitalWrite(4, HIGH);
  delay(2000); // Wait for 2000 millisecond(s) amarelo
  digitalWrite(4, LOW);
}