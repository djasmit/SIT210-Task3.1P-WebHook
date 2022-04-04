#include "Adafruit_DHT.h"

// Based on the DHT example project: https://build.particle.io/libs/Adafruit_DHT/0.0.4/tab/example/dht-test.ino

#define DHTPIN D6     // what pin we're connected to

// Uncomment whatever type you're using!
//#define DHTTYPE DHT11		// DHT 11 
#define DHTTYPE DHT11		// DHT 22 (AM2302)
//#define DHTTYPE DHT21		// DHT 21 (AM2301)

DHT dht(DHTPIN, DHTTYPE);

void setup() {
	dht.begin();
}

void loop() {
// Wait a few seconds between measurements.
	delay(1000);

// Reading temperature or humidity takes about 250 milliseconds!
// Sensor readings may also be up to 2 seconds 'old' (its a 
// very slow sensor)
	float h = dht.getHumidity();
	Particle.publish("hum", String(h), PRIVATE);
// Read temperature as Celsius
	float t = dht.getTempCelcius();
	Particle.publish("temp_c", String(t), PRIVATE);
// Read temperature as Farenheit
  
// Check if any reads failed and exit early (to try again).
	if (isnan(h) || isnan(t)) {
		Serial.println("Failed to read from DHT sensor!");
		return;
	}

}

