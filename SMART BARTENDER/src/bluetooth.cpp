#include <Arduino.h>
#include "BluetoothSerial.h"
#include "Relay.h"
#include "Oled_Display.h"

BluetoothSerial SerialBT;
char receivedChar; // received value will be stored as CHAR in this variable
const char Drink1 = 'A';
const char Drink2 = 'B';
const char Drink3 = 'C';
const char Drink4 = 'D';
const char Drink5 = 'E';
const char Drink6 = 'F';

void bluetooth_setup()
{
    SerialBT.begin("SMART BARTENDER"); //Bluetooth device name
    Serial.println("The device started, now you can pair it with bluetooth!");
    Serial.println("Send A,B,C,D,E,F, for different drinks"); //print on serial monitor
}

void Check_bluetooth()
{
    if (Serial.available())
    {
        SerialBT.write(Serial.read());
    }
    if (SerialBT.available())
    {

        receivedChar = (char)SerialBT.read();
        SerialBT.print("Received:");    // write on BT app
        SerialBT.println(receivedChar); // write on BT app
        Serial.print("Received:");      //print on serial monitor
        Serial.println(receivedChar);   //print on serial monitor
        delay(100);

        print_bluetooth_message();

        if (receivedChar == Drink1)
        {
            SerialBT.println("Making Drink1"); // write on BT app
            Serial.println("Making Drink1");   //write on serial monitor
            Mix(2000, 0, 1000, 0, 0, 1000, 0, 0);
            delay(100);
        }
        if (receivedChar == Drink2)
        {
            SerialBT.println("Making Drink2"); // write on BT app
            Serial.println("Making Drink2");   //write on serial monitor
            Mix(2000, 1000, 0, 0, 0, 1000, 0, 0);
            delay(100);
        }

        if (receivedChar == Drink3)
        {
            SerialBT.println("Making Drink3"); // write on BT app
            Serial.println("Making Drink3");   //write on serial monitor
            Mix(2000, 0, 1000, 3000, 0, 0, 0, 0);
            delay(100);
        }
        if (receivedChar == Drink4)
        {
            SerialBT.println("Making Drink4"); // write on BT app
            Serial.println("Making Drink4");   //write on serial monitor
            Mix(2000, 0, 1000, 0, 0, 1000, 0, 0);
            delay(100);
        }

        if (receivedChar == Drink5)
        {
            SerialBT.println("Making Drink5"); // write on BT app
            Serial.println("Making Drink5");   //write on serial monitor
            Mix(1000, 0, 0, 1000, 0, 0, 2000, 0);
            delay(100);
        }
        if (receivedChar == Drink6)
        {
            SerialBT.println("Making Drink6"); // write on BT app
            Serial.println("Making Drink6");   //write on serial monitor
            Mix(2000, 1000, 1000, 0, 0, 1000, 0, 0);
            delay(100);
        }
    }
}