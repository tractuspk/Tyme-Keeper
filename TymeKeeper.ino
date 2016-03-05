/*
 * TYME-KEEPER
 * Utility for recording loops on Tyme Sefari MKii
 * Uses Arduino Uno
 *
 * Mason Malvinni
 * 3/4/2016
 */


const int recordButtonPin = 9;
const int playGatePin = 12;
const int recordGatePin = 10;
const int lengthVoltagePin = 11;

int triggered = 0;
int counter = 0;

void setup()
{
	pinMode(recordButtonPin,INPUT_PULLUP);
	
	pinMode(playGatePin,OUTPUT);
	pinMode(recordGatePin,OUTPUT);
	pinMode(lengthVoltagePin,OUTPUT);
	
	
	digitalWrite(recordGatePin,LOW);
	analogWrite(lengthVoltagePin,255);
	digitalWrite(playGatePin,HIGH);	
	

}

void loop()
{
	counter = 0;
	while(!digitalRead(recordButtonPin))
	{
		
		
		
		if(counter==0)
		{
			digitalWrite(playGatePin,LOW);
			analogWrite(lengthVoltagePin,255);
			digitalWrite(recordGatePin,HIGH);
			digitalWrite(playGatePin,HIGH);
		}
		counter++;
		delayMicroseconds(13500); //could probably use more tuning
		
		
	
	}
	if(counter!=0)
	{
		constrain(counter,0,255);
		digitalWrite(playGatePin,LOW);
		analogWrite(lengthVoltagePin,counter);
		digitalWrite(recordGatePin,LOW);
		digitalWrite(playGatePin,HIGH);
	}
	
	

}
