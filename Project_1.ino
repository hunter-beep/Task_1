int sensorpin=2;  //PIR Sensor connection
int relay=3;	// Relayconnection
int asensorpin=A0; // Ambient light sensor connection
float light;       
int lightvalue;
void setup() 
{
  Serial.begin(112500); 
  pinMode(asensorpin,INPUT);   
  pinMode(relay,OUTPUT);
  pinMode(sensorpin,INPUT);
}

void loop() 
{
  int lightvalue=analogRead(asensorpin);// Readng ambient light present
  light=lightvalue*0.0976; // Calculation
  Serial.println(light);   
  int sensorvalue=digitalRead(sensorpin);
  if(sensorvalue==HIGH && light<90) // If PIR is active and ambient light below threshold
  {
    digitalWrite(relay,HIGH); //
  }
  else
  {
    digitalWrite(relay,LOW);
  }
  //delay(2000);
  //digitalWrite(relay,HIGH);
}