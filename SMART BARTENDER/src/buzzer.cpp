#include <Arduino.h>

const int piezoPin = 19;
unsigned long previousBeepTime = 0;

void piezoBeep()
{

    previousBeepTime = millis();

    do
    {
        int x = millis();
        if (x % 2 == 0)
        {
            digitalWrite(piezoPin, HIGH); //piezo fluctuates a tone based off of whether or not millis is even or odd
        }
        else
        {
            digitalWrite(piezoPin, LOW);
        }

    } while (millis() - previousBeepTime < 100);

    digitalWrite(piezoPin, LOW); //this ensures the speaker is silent afterwards
}

void buzzer_setup()
{
    pinMode(piezoPin, OUTPUT);

    piezoBeep(); //double beep to let me know the sketch has finished uploading
    delay(500);
    piezoBeep();
}

void buzzer_once()
{
    piezoBeep();
}

void buzzer_twice()
{
    piezoBeep();
    delay(150);
    piezoBeep();
}
