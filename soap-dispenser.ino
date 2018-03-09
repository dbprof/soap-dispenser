#define SENSOR_PIN 10 // Optical Sensor
#define SWITCH_PIN 11 // Pump
#define DO_PIN 12     // Red LED
#define WAIT_PIN 13   // Green LED

void switch_led(){
  if (digitalRead(DO_PIN) == LOW) {
    digitalWrite(DO_PIN, HIGH);
    digitalWrite(WAIT_PIN, LOW);
  }
  else {
    digitalWrite(DO_PIN, LOW);
    digitalWrite(WAIT_PIN, HIGH);
  }
}

void setup() {

  Serial.begin(9600);

  pinMode(SWITCH_PIN, OUTPUT);
  digitalWrite(SWITCH_PIN, LOW);
  
  pinMode(DO_PIN, OUTPUT);
  digitalWrite(DO_PIN, LOW);
  
  pinMode(WAIT_PIN, OUTPUT);
  digitalWrite(WAIT_PIN, HIGH);

}

void loop() {

  // Проверка сенсора
  if (!digitalRead(SENSOR_PIN)) 
  {
    Serial.println("No motion");
    delay(500);
    return;
  }

  // Работа диспенсера
  Serial.println("Motion detected");
  switch_led();
  digitalWrite(SWITCH_PIN, HIGH);
  delay(1000);
  digitalWrite(SWITCH_PIN, LOW);
  delay(500);
  switch_led();

}
