
#define READ_SW A0
#define BUZZ_PIN 13

void setup() 
{
  Serial.begin(9600);

  pinMode(BUZZ_PIN, OUTPUT);
  digitalWrite(BUZZ_PIN, LOW);

  pinMode(READ_SW, INPUT_PULLUP);   // IMPORTANT

  Serial.println("System Started...");
}

void loop() 
{
  int SW_State = digitalRead(READ_SW);

  Serial.print("Switch State: ");
  Serial.println(SW_State);   // 0 = pressed, 1 = released

  if(SW_State == HIGH)
  {
    Serial.println("Switch PRESSED → Buzzer ON");

    digitalWrite(BUZZ_PIN, HIGH);
    delay(500);

    digitalWrite(BUZZ_PIN, LOW);
    delay(500);
  }
  else
  {
    Serial.println("Switch RELEASED → Buzzer OFF");

    digitalWrite(BUZZ_PIN, LOW);
    delay(100);
  }

  delay(200);
}
//////////////////////////////////////////////////////////////
//#define READ_SW A0
//#define BUZZ_PIN 13
//
//void setup() 
//{
//  pinMode(BUZZ_PIN, OUTPUT);
//  digitalWrite(BUZZ_PIN,LOW);
//
//  pinMode(READ_SW, INPUT);
//}
//
//void loop() 
//{
//  int SW_State = digitalRead(READ_SW);
//
//  if(SW_State == LOW)
//  {
//    digitalWrite(BUZZ_PIN,HIGH);   // ON (active LOW)
//    delay(500);
//    digitalWrite(BUZZ_PIN, LOW);  // OFF
//    delay(500);
//  }
//  else
//  {
//    digitalWrite(BUZZ_PIN, LOW);  // OFF
//    delay(10);
//  }
//
//  delay(5);
//}
