#include <dht.h>

//variable to hold the humidity and temperature
dht DHT;

//connected the humidity and temprature to 7
int DHT11_PIN= 7;  

//gas detector is connected to A0
int GASA0 = A0;   

//Carbon monoxide detector is connected to A1
int CARBONA1=A1;  
         

void setup() {
  //to read from port 9600
  Serial.begin(9600);
}

void loop() {
  //store the gas amount and print it for user 
  int analogSensorGas = analogRead(GASA0);
  Serial.print(" gas amount: ");
  Serial.print(analogSensorGas);
  Serial.print("\n ");

  //store the carbon monoxide amount and print it for user 
  int analogSensorCarbon = analogRead(CARBONA1);
  Serial.print("carbon monoxide amount: ");
  Serial.print(analogSensorCarbon );
  Serial.print("\n ");

  //store the temprature and humidity and print it for user 
  DHT.read11(DHT11_PIN);
  //convert the temprature to farenheit
  int temp=(DHT.temperature/5)*9 +32;
  Serial.print("Temperature: ");
  Serial.print( temp);
  Serial.print("\n ");
  Serial.print("Humidity: ");
  Serial.print( DHT.humidity);
  Serial.print("\n \n");
  
  delay(1500);
}
