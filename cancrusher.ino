int pin_button_open = 13;
int pin_button_close = 12;
int pin_relay1 = 11;
int pin_relay2 = 10;
int pin_led_verde = 9;
int pin_led_rojo = 8;
int largo = 0;
int alto = 1;
int lastValue = 0;
int habilitado = 0;
int crushing = 0;


void setup()
{
    Serial.begin(9600);
    pinMode(pin_button_open, INPUT);
    pinMode(pin_button_close, INPUT);
    pinMode(pin_relay1, OUTPUT);
    pinMode(pin_relay2, OUTPUT);
    pinMode(pin_led_verde, OUTPUT);
    pinMode(pin_led_rojo, OUTPUT);
    digitalWrite(pin_relay1, LOW);
    digitalWrite(pin_relay2, LOW);
}

void loop()
{

    if(digitalRead(pin_button_open) == HIGH && lastValue == 0 && habilitado == 1)
    {
        Serial.println("OPEN");
        lastValue = 1;
        habilitado = 1;
        crushing = 1;
        digitalWrite(pin_relay1, HIGH);
        digitalWrite(pin_relay2, LOW);
        delay(300);
    }
    else if(digitalRead(pin_button_close) == HIGH)
    {
        Serial.println("CLOSE");
        lastValue = 0;
        habilitado = 1;
        crushing = 0;
        digitalWrite(pin_relay1, LOW);
        digitalWrite(pin_relay2, HIGH);
        delay(300);
    }else{

        if(digitalRead(pin_button_open) == LOW){
            crushing = 0;
        }
    }

    if(crushing == 0){
        Serial.println("NOTHING");
        lastValue = 0;
        digitalWrite(pin_relay1, LOW);
        digitalWrite(pin_relay2, LOW);

        Serial.println("LARGO:");
        Serial.println(analogRead(largo));

        Serial.println("ALTO:");
        Serial.println(analogRead(alto));

        if(analogRead(largo) < 200 && analogRead(alto) < 170)
        {
            habilitado = 1;
            digitalWrite(pin_led_verde, HIGH);
            digitalWrite(pin_led_rojo, LOW);
        }
        else{
            habilitado = 0;
            digitalWrite(pin_led_rojo, HIGH);
            digitalWrite(pin_led_verde, LOW);
        }
    }
}
