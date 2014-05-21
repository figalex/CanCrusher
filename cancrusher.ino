int pin_button_open = 13;
int pin_button_close = 12;
int pin_relay1 = 11;
int pin_relay2 = 10;
int foto = 0;
int lastValue = 0;

void setup()
{
	Serial.begin(9600);
	pinMode(pin_button_open, INPUT);
	pinMode(pin_button_close, INPUT);
	pinMode(pin_relay1, OUTPUT);
	pinMode(pin_relay2, OUTPUT);
	digitalWrite(pin_relay1, LOW);
	digitalWrite(pin_relay2, LOW);
}

void loop()
{

	Serial.println(analogRead(foto));

	if(digitalRead(pin_button_open) == LOW && lastValue == 0)
	{
		Serial.println("OPEN");
		lastValue = 1;
		digitalWrite(pin_relay1, LOW);
		digitalWrite(pin_relay2, HIGH);
		delay(300);
	}
	else if(digitalRead(pin_button_close) == LOW)
	{
		Serial.println("CLOSE");
		lastValue = 0;
		digitalWrite(pin_relay1, HIGH);
		digitalWrite(pin_relay2, LOW);
		delay(300);
	}
	else{
		Serial.println("NOTHING");
		lastValue = 0;
		digitalWrite(pin_relay1, LOW);
		digitalWrite(pin_relay2, LOW);
	}
}