/* TODO
 * const potPin = ?;
 */
int incomingByte = 0;
unsigned long msSLB = 0;
int ledState = LOW;

bool getState() {
  // Would normally get the data from the pot
  if(random(1024) > 512) {
    return true;
  }
  return false;
}

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
  Serial.println("Reporting in...");
}

void loop() {
  if (Serial.available() > 0) {
    incomingByte = Serial.read();

    Serial.println(getState());
  }

  if(millis() > msSLB + 1000) {
    ledState = ledState == LOW ? HIGH : LOW;
    msSLB = millis();
    digitalWrite(LED_BUILTIN, ledState);
  }
  
}
