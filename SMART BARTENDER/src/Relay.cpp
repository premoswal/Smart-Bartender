#include <Arduino.h>

// note you want to make  .h file for relay to operate it

//defining the pins used for each drink, you can changes this depending how you connect the pumps and the drinks.

int Vodka = 13;
int Cointreau = 12;
int CranberryJuice = 14;
int Sprite = 27;
int LemonJuice = 26;
int SugarWater = 25;
int BlueCur = 33;
int Gin = 32;

int state = 0;
// how much time there is between switching to the next pump.
int TimeBetweenPours = 500;

void relay_setup()
{

    // Serial.println("The bluetooth gates are open.\n Connect to HC-05 from any other bluetooth device with 1234 as pairing key!");

    // Setting corresponding pins to output pins to drive the relay board as they are consecutive pins on my ESP32 board.
    pinMode(13, OUTPUT);
    pinMode(12, OUTPUT);
    pinMode(14, OUTPUT);
    pinMode(27, OUTPUT);
    pinMode(26, OUTPUT);
    pinMode(25, OUTPUT);
    pinMode(33, OUTPUT);
    pinMode(32, OUTPUT);

    // My relayboard is a "low true" board. So setting the output to low energize the relay's. "If we don't do high then all Pumps will get ON while powering on the cocktailmaker..."

    digitalWrite(13, HIGH);
    digitalWrite(12, HIGH);
    digitalWrite(14, HIGH);
    digitalWrite(27, HIGH);
    digitalWrite(26, HIGH);
    digitalWrite(25, HIGH);
    digitalWrite(33, HIGH);
    digitalWrite(32, HIGH);
}

// creating Mix function for Cocktails Making:

void Mix(int Delay_Time_Pump1, int Delay_Time_Pump2, int Delay_Time_Pump3, int Delay_Time_Pump4, int Delay_Time_Pump5, int Delay_Time_Pump6, int Delay_Time_Pump7, int Delay_Time_Pump8)
{

    // state = 0; Use when you modifies for bluetooth connectivity
    delay(800);
    digitalWrite(Vodka, LOW);
    delay(Delay_Time_Pump1); //Pump 1 ingrediets "ON" Time
    digitalWrite(Vodka, HIGH);
    delay(TimeBetweenPours);

    digitalWrite(Cointreau, LOW);
    delay(Delay_Time_Pump2);
    digitalWrite(Cointreau, HIGH);
    delay(TimeBetweenPours);

    digitalWrite(CranberryJuice, LOW);
    delay(Delay_Time_Pump3);
    digitalWrite(CranberryJuice, HIGH);
    delay(TimeBetweenPours);

    digitalWrite(Sprite, LOW);
    delay(Delay_Time_Pump4);
    digitalWrite(Sprite, HIGH);
    delay(TimeBetweenPours);

    digitalWrite(LemonJuice, LOW);
    delay(Delay_Time_Pump5);
    digitalWrite(LemonJuice, HIGH);
    delay(TimeBetweenPours);

    digitalWrite(SugarWater, LOW);
    delay(Delay_Time_Pump6);
    digitalWrite(SugarWater, HIGH);
    delay(TimeBetweenPours);

    digitalWrite(BlueCur, LOW);
    delay(Delay_Time_Pump7);
    digitalWrite(BlueCur, HIGH);
    delay(TimeBetweenPours);

    digitalWrite(Gin, LOW);
    delay(Delay_Time_Pump8);
    digitalWrite(Gin, HIGH);
    delay(TimeBetweenPours);

    Serial.println("Drink is done!");
    // state = 0; Use when you modifies for bluetooth connectivity
}



// void loop()

// {
//     if (Serial.available() > 0)
//     {                          // Checks whether data is comming from the serial port
//         state = Serial.read(); // Reads the data from the serial port
//         Serial.println(state);
//     }

//     //Vodka sprite
//     if (state == 'a')
//     {
//         Serial.println("Vodka Sprite in the making");
//         Mix(3000, 0, 0, 0, 5000, 0, 0, 0); // Vodka, Triple Sec, Cranberry juice, Sprite, Lime juice, Sugar water, Blue Curacao, Gin
//     }

//     // Blue Lagoon
//     if (state == 'b')
//     {
//         Serial.println("Blue Lagoon in the making");
//         Mix(2000, 0, 0, 5000, 1800, 1000, 1800, 0); // Vodka, Triple Sec, Cranberry juice, Sprite, Lime juice, Sugar water, Blue Curacao, Gin
//     }

//     // Cosmo
//     if (state == 'c')
//     {
//         Serial.println("Cosmo in the making");
//         Mix(2500, 1500, 3800, 0, 1200, 1200, 0, 0); // Vodka, Triple Sec, Cranberry juice, Sprite, Lime juice, Sugar water, Blue Curacao, Gin
//     }

//     // Lemon drop
//     if (state == 'd')
//     {
//         Serial.println("Lemon drop in the making");
//         Mix(1500, 1500, 0, 0, 1800, 1200, 0, 0); // Vodka, Triple Sec, Cranberry juice, Sprite, Lime juice, Sugar water, Blue Curacao, Gin
//     }

//     // Blue Moon
//     if (state == 'e')
//     {
//         Serial.println("Blue Moon in the making");
//         Mix(2000, 0, 3000, 0, 1800, 1200, 1200, 0); // Vodka, Triple Sec, Cranberry juice, Sprite, Lime juice, Sugar water, Blue Curacao, Gin
//     }

//     // Blue Gin Moon
//     if (state == 'f')
//     {
//         Serial.println("Blue Gin Moon in the making");
//         Mix(0, 0, 3000, 0, 1800, 1200, 1200, 2000); // Vodka, Triple Sec, Cranberry juice, Sprite, Lime juice, Sugar water, Blue Curacao, Gin
//     }

//     // Double Strike
//     if (state == 'i')
//     {
//         Serial.println("Double Strike in the making");
//         Mix(2000, 0, 3000, 0, 1800, 0, 1200, 0); // Vodka, Triple Sec, Cranberry juice, Sprite, Lime juice, Sugar water, Blue Curacao, Gin
//     }

//     // Tom Collins
//     if (state == 'h')
//     {
//         Serial.println("Tom Collins in the making");
//         Mix(0, 0, 0, 4000, 1800, 1800, 0, 2200); // Vodka, Triple Sec, Cranberry juice, Sprite, Lime juice, Sugar water, Blue Curacao, Gin
//     }

//     // Flying Dutchman
//     if (state == 'g')
//     {
//         Serial.println("Flying Dutchman in the making");
//         Mix(0, 2000, 0, 0, 1200, 1000, 0, 2000); // Vodka, Triple Sec, Cranberry juice, Sprite, Lime juice, Sugar water, Blue Curacao, Gin
//     }

//     // London Cosmo
//     if (state == 'j')
//     {
//         Serial.println("London Cosmo in the making");
//         Mix(0, 2000, 5000, 1800, 0, 0, 0, 2000); // Vodka, Triple Sec, Cranberry juice, Sprite, Lime juice, Sugar water, Blue Curacao, Gin
//     }

//     // Vodka Cranberry
//     if (state == 'k')
//     {
//         Serial.println("Vodka Cranberry in the making");
//         Mix(2000, 0, 5000, 0, 0, 1200, 0, 0); // Vodka, Triple Sec, Cranberry juice, Sprite, Lime juice, Sugar water, Blue Curacao, Gin
//     }

//     // Cranberry Gin
//     if (state == 'l')
//     {
//         Serial.println("Cranberry Gin in the making");
//         Mix(0, 0, 5000, 0, 2000, 0, 0, 2200); // Vodka, Triple Sec, Cranberry juice, Sprite, Lime juice, Sugar water, Blue Curacao, Gin
//     }

//     // Testin and maintenance options

//     // Set-up Vodka
//     if (state == 'm')
//     {
//         Serial.println("Set-up Vodka");
//         Mix(1100, 0, 0, 0, 0, 0, 0, 0); // Vodka, Triple Sec, Cranberry juice, Sprite, Lime juice, Sugar water, Blue Curacao, Gin
//     }

//     // Set-up Tripple Sec
//     if (state == 'n')
//     {
//         Serial.println("Set-up Tripple Sec");
//         Mix(0, 1100, 0, 0, 0, 0, 0, 0); // Vodka, Triple Sec, Cranberry juice, Sprite, Lime juice, Sugar water, Blue Curacao, Gin
//     }

//     // Set-up Cranberry juice
//     if (state == 'o')
//     {
//         Serial.println("Set-up Cranberry juice");
//         Mix(0, 0, 1000, 0, 0, 0, 0, 0); // Vodka, Triple Sec, Cranberry juice, Sprite, Lime juice, Sugar water, Blue Curacao, Gin
//     }

//     // Set-up Sprite
//     if (state == 'p')
//     {
//         Serial.println("Set-up Sprite");
//         Mix(0, 0, 0, 1000, 0, 0, 0, 0); // Vodka, Triple Sec, Cranberry juice, Sprite, Lime juice, Sugar water, Blue Curacao, Gin
//     }

//     // Set-up Lime juice
//     if (state == 'q')
//     {
//         Serial.println("Set-up Lime juice");
//         Mix(0, 0, 0, 0, 1100, 0, 0, 0); // Vodka, Triple Sec, Cranberry juice, Sprite, Lime juice, Sugar water, Blue Curacao, Gin
//     }

//     // Set-up Sugar water
//     if (state == 'v')
//     {
//         Serial.println("Set-up Sugar water");
//         Mix(0, 0, 0, 0, 0, 1200, 0, 0); // Vodka, Triple Sec, Cranberry juice, Sprite, Lime juice, Sugar water, Blue Curacao, Gin
//     }

//     // Set-up Blue curacao
//     if (state == 'r')
//     {
//         Serial.println("Set-up Blue curacao");
//         Mix(0, 0, 0, 0, 0, 0, 800, 0); // Vodka, Triple Sec, Cranberry juice, Sprite, Lime juice, Sugar water, Blue Curacao, Gin
//     }

//     // Set-up Gin
//     if (state == 's')
//     {
//         Serial.println("Set-up Gin");
//         Mix(0, 0, 0, 0, 0, 0, 0, 1000); // Vodka, Triple Sec, Cranberry juice, Sprite, Lime juice, Sugar water, Blue Curacao, Gin
//     }

//     // Cleaning
//     if (state == 't')
//     {
//         Serial.println("Set-up Gin");
//         Mix(4000, 4000, 4000, 4000, 4000, 4000, 4000, 4000); // Vodka, Triple Sec, Cranberry juice, Sprite, Lime juice, Sugar water, Blue Curacao, Gin
//     }

//     // Set-up all (intial first time after cleaning)
//     if (state == 'u')
//     {
//         Serial.println("Set-up All");
//         Mix(800, 800, 800, 800, 1000, 1600, 800, 800); // Vodka, Triple Sec, Cranberry juice, Sprite, Lime juice, Sugar water, Blue Curacao, Gin
//     }
// }
