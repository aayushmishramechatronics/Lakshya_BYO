int soilHumidity = 0;
const int sensorPin = A0;

void setup() {
  Serial.begin(9600);
  
  pinMode(3, OUTPUT); // Green LED
  pinMode(4, OUTPUT); // Red LED
  pinMode(5, OUTPUT); // Blue LED

}

void loop() {
  soilHumidity = analogRead(sensorPin);
  soilHumidity = map(soilHumidity, 0, 1023, 100, 0);

  Serial.print("Soil Humidity: ");
  Serial.print(soilHumidity);
  Serial.println(" %");

  // The Plant has Enough Water. No Watering Needed.
  if (soilHumidity >= 40 && soilHumidity <= 60 ) {
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);

  // The Plant is too Dry. Watering Needed.
  }else if (soilHumidity < 40) {
    digitalWrite(3, LOW);
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);

  // The Plant is Overwatered. Wait with Watering until the Red LED is Glowing. 
  }else if (soilHumidity > 60) {
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);
  }

  delay(1000);
}
