int pin_button = 13;
int pin_return = 7;
int pin_relay1 = 12;
int pin_relay2 = 11;
int lastValue = 0;

void setup()
{
	Serial.begin(9600);
	pinMode(pin_button, INPUT);
	pinMode(pin_return, INPUT);
	pinMode(pin_relay1, OUTPUT);
	pinMode(pin_relay2, OUTPUT);
	digitalWrite(pin_relay1, LOW);
	digitalWrite(pin_relay2, LOW);
}

void loop()
{
	if(digitalRead(pin_button) == HIGH && lastValue == 0)
	{
		Serial.println("OPEN");
		lastValue = 1;
		digitalWrite(pin_relay1, HIGH);
		digitalWrite(pin_relay2, LOW);
		delay(300);
	}
	else if(digitalRead(pin_return) == HIGH)
	{
		Serial.println("CLOSE");
		lastValue = 0;
		digitalWrite(pin_relay1, LOW);
		digitalWrite(pin_relay2, HIGH);
	}
	else{
		Serial.println("NOTHING");
		lastValue = 0;
		digitalWrite(pin_relay1, LOW);
		digitalWrite(pin_relay2, LOW);
	}
}