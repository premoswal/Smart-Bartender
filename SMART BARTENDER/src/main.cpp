#include <Arduino.h>
#include "encoder.h"
#include "Oled_Display.h"
#include "buzzer.h"
#include "Relay.h"
#include "bluetooth.h"

void setup()
{
  Serial.begin(115200);
  encoder_setup();
  oled_setup();

  setup_load_display();
  delay(500);
  buzzer_setup();
  relay_setup();
  bluetooth_setup();
}

void loop()
{
  encoder_value();
  pages_display();

  int loopEncoderValue = current_encoder_value();

  switch (loopEncoderValue)
  {

  case 0:
    if (ButtonPressed())
    {
      Serial.println("case 0 : Print welcome message and maker details");
      students_info();
      delay(5000);
    }
    break;

  case 1:
    if (ButtonPressed())
    {
      buzzer_once();
      Serial.println("Making Drink 1");
      print_making_drink1();
      // delay(5000); // when you add relay pump delay that time remove this statement
      Mix(2000, 0, 1000, 0, 0, 1000, 0, 0);
      print_enjoy_your_drink();
      buzzer_twice();
      delay(3000);
    }
    break;

  case 2:
    if (ButtonPressed())
    {
      buzzer_once();
      Serial.println("case 2 : Drink2 process");
      print_making_drink2();
      // delay(5000); // when you add relay pump delay that time remove this statement
      Mix(2000, 0, 3000, 0, 0, 0, 0, 0);
      print_enjoy_your_drink();
      buzzer_twice();
      delay(3000);
    }
    break;

  case 3:
    if (ButtonPressed())
    {
      buzzer_once();
      Serial.println("case 3 : Drink3 process");
      print_making_drink3();
      // delay(5000); // when you add relay pump delay that time remove this statement
      Mix(2000, 0, 1000, 0, 2000, 1000, 0, 500);
      print_enjoy_your_drink();
      buzzer_twice();
      delay(3000);
    }
    break;

  case 4:
    if (ButtonPressed())
    {
      buzzer_once();
      Serial.println("case 4 : Drink4 process");
      print_making_drink4();
      // delay(5000); // when you add relay pump delay that time remove this statement
      Mix(2000, 0, 0, 2000, 0, 0, 0, 500);
      print_enjoy_your_drink();
      buzzer_twice();
      delay(3000);
    }
    break;

  case 5:
    if (ButtonPressed())
    {
      buzzer_once();
      Serial.println("case 5 : Drink5 process");
      print_making_drink5();
      delay(5000); // when you add relay pump delay that time remove this statement
      print_enjoy_your_drink();
      buzzer_twice();
      delay(3000);
    }
    break;

  case 6:
    if (ButtonPressed())
    {
      buzzer_once();
      Serial.println("case 6 : Drink6 process");
      print_making_drink6();
      delay(5000); // when you add relay pump delay that time remove this statement
      print_enjoy_your_drink();
      buzzer_twice();
      delay(3000);
    }
    break;

  case 7:
    if (ButtonPressed())
    {
      buzzer_once();
      Serial.println("case 7 : Drink7 process");
      print_making_drink7();
      delay(5000); // when you add relay pump delay that time remove this statement
      print_enjoy_your_drink();
      buzzer_twice();
      delay(3000);
    }
    break;

  case 8:
    if (ButtonPressed())
    {
      buzzer_once();
      Serial.println("case 8 : Drink8 process");
      print_making_drink8();
      delay(5000); // when you add relay pump delay that time remove this statement
      print_enjoy_your_drink();
      buzzer_twice();
      delay(3000);
    }
    break;

  case 9:
    if (ButtonPressed())
    {
      buzzer_once();
      Serial.println("case 9 : Drink9 process");
      print_making_drink9();
      delay(5000); // when you add relay pump delay that time remove this statement
      print_enjoy_your_drink();
      buzzer_twice();
      delay(3000);
    }
    break;

  case 10:
    if (ButtonPressed())
    {
      buzzer_once();
      Serial.println("case 10 : Drink10 process");
      print_making_drink10();
      delay(5000); // when you add relay pump delay that time remove this statement
      print_enjoy_your_drink();
      buzzer_twice();
      delay(3000);
      // set_value_zero();
    }
    break;
  }

  Check_bluetooth();
}
