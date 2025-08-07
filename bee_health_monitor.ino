#define BLYNK_TEMPLATE_ID "TMPL3OSqucMyR"
#define BLYNK_TEMPLATE_NAME "Bee Health"
#define BLYNK_AUTH_TOKEN "6qgSx0h36I0cGlSC0WqX2kog3DkYZaWZ"


#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#define DHTPIN D1
#define DHTTYPE DHT11
#define SOUND_SENSOR A0
#define RED_LED D2
#define GREEN_LED D3
#define BLUE_LED D4
#define BUZZER D5


char ssid[] = "Redmi K50i";          
char pass[] = "987654321";         

DHT dht(DHTPIN, DHTTYPE);


BlynkTimer timer;

void sendSensorData() {
  float temperature = dht.readTemperature();     
  float humidity = dht.readHumidity();           
  int soundFrequency = analogRead(SOUND_SENSOR); 

  
  Blynk.virtualWrite(V1, temperature); 
  Blynk.virtualWrite(V2, humidity);     
  Blynk.virtualWrite(V3, soundFrequency); 
  
 
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print(" °C, Humidity: ");
  Serial.print(humidity);
  Serial.print(" %, Sound Frequency: ");
  Serial.println(soundFrequency);
}

void setup() {
  Serial.begin(9600);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  dht.begin();
  pinMode(SOUND_SENSOR, INPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);
  pinMode(BUZZER, OUTPUT);



  digitalWrite(RED_LED, LOW);
  digitalWrite(GREEN_LED, LOW);
  digitalWrite(BLUE_LED, LOW);
  digitalWrite(BUZZER, LOW);


  
  timer.setInterval(2000, sendSensorData);
}

void loop() {
  Blynk.run();
  timer.run();
  

  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();
  int soundFrequency = analogRead(SOUND_SENSOR);
  
  bool tempThreshold = (temperature < 0 || temperature > 33);
  bool humidityThreshold = (humidity < 40 || humidity > 80);
  bool soundThreshold = (soundFrequency < 20 || soundFrequency > 90);
  
  int exceededThresholds = tempThreshold + humidityThreshold + soundThreshold;


  if (exceededThresholds == 1) {
    digitalWrite(RED_LED, LOW); 
    digitalWrite(BLUE_LED, LOW);
    digitalWrite(GREEN_LED, HIGH);

  } else if (exceededThresholds == 2) {
    digitalWrite(RED_LED, LOW);
    digitalWrite(GREEN_LED, LOW);    
    digitalWrite(BLUE_LED, HIGH);

  } else if (exceededThresholds >= 3) {    
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(BLUE_LED, LOW);
    digitalWrite(RED_LED, HIGH);  
    digitalWrite(BUZZER, HIGH);
    delay(2000);
    digitalWrite(BUZZER, LOW);
  }
      
}