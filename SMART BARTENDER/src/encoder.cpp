#include "Arduino.h"
#include "NewEncoder.h"

//==================Manually declaring button as it is not in NewEncoder lib===========================//
const int buttonPin = 5;
int buttonState;                    // the current reading from the input pin
int lastButtonState = HIGH;         // the previous reading from the input pin
unsigned long lastDebounceTime = 0; // the last time the output pin was toggled
unsigned long debounceDelay = 20;   // the debounce time

// Demonstrate how to include an encoder object inside of a class and how to use the
// callback feature to call an instance function of the class
class My_Encoder_Class
{
public:
    My_Encoder_Class(uint8_t aPin, uint8_t bPin, int16_t minValue, int16_t maxValue, int16_t initalValue, uint8_t type = FULL_PULSE) : encoder{aPin, bPin, minValue, maxValue, initalValue, type}
    {
    }

    bool begin()
    {
        NewEncoder::EncoderState state;
        if (!encoder.begin())
        {
            return false;
        }
        newValueAvailable = false;
        encoder.getState(state);
        encoderValue = state.currentValue;
        encoder.attachCallback(callBack, this);
        return true;
    }

    bool newDataAvailable()
    {
        noInterrupts();
        bool temp = newValueAvailable;
        newValueAvailable = false;
        interrupts();
        return temp;
    }

    int16_t getData()
    {
        int16_t temp;
        noInterrupts();
        temp = encoderValue;
        interrupts();
        return temp;
    }
    //===============================set encoder 0===========================//
    void set_encoder_at_zero()
    {
        encoderValue = 0;
    }

    //=======================================================================//

private:
    // embedded NewEncoder object
    NewEncoder encoder;

    volatile int16_t encoderValue = 0;
    volatile bool newValueAvailable = false;
    void handleEncoder(const volatile NewEncoder::EncoderState *state);
    static void callBack(NewEncoder *encPtr, const volatile NewEncoder::EncoderState *state, void *uPtr);
};

// Static class callback function. Common to all instances. Uses the uPtr parameter to select the proper
// instance. Then, calls the instance function.
// Be careful, the callback executes in interrupt contexts.
void ESP_ISR My_Encoder_Class::callBack(NewEncoder *encPtr, const volatile NewEncoder::EncoderState *state, void *uPtr)
{
    (void)encPtr;
    My_Encoder_Class *ptr = (My_Encoder_Class *)uPtr;
    ptr->handleEncoder(state);
}

// Instance function to handle encoder specific to each object. Called by static callback function.
// This is where instance-specific actions will be taken when the encoder is rotated.
// In this example, we just set a flag and make encoder value available to main code.
// Be careful, the callback executes in interrupt contexts.
void ESP_ISR My_Encoder_Class::handleEncoder(const volatile NewEncoder::EncoderState *state)
{
    if (state->currentValue != encoderValue)
    {
        encoderValue = state->currentValue;
        newValueAvailable = true;
    }
}

// Pins 2 and 4 should work for many processors, including Uno. See README for meaning of constructor arguments.
// Use FULL_PULSE for encoders that produce one complete quadrature pulse per detnet, such as: https://www.adafruit.com/product/377
// Use HALF_PULSE for endoders that produce one complete quadrature pulse for every two detents, such as: https://www.mouser.com/ProductDetail/alps/ec11e15244g1/?qs=YMSFtX0bdJDiV4LBO61anw==&countrycode=US&currencycode=USD
My_Encoder_Class Rotary_encoder{2, 4, 0, 10, 0, FULL_PULSE};

void encoder_setup()
{
    delay(1000);

    if (!Rotary_encoder.begin())
    {
        Serial.println("\nEncoder failed to start. Aborting");
        while (1)
        {
            delay(1);
        }
    }

    Serial.print("\nEncoder started at: ");
    Serial.println(Rotary_encoder.getData());
}

void encoder_value()
{
    if (Rotary_encoder.newDataAvailable())
    {
        Serial.print("Encoder: ");
        Serial.println(Rotary_encoder.getData());
    }
}

int current_encoder_value()
{
    return Rotary_encoder.getData();
}

int ButtonPressed()
{

    int reading = digitalRead(buttonPin);

    if (reading != lastButtonState)
    {
        lastDebounceTime = millis();
    }

    if ((millis() - lastDebounceTime) > debounceDelay)
    {

        if (reading != buttonState)
        {
            buttonState = reading;

            if (buttonState == HIGH)
            {
                // Serial.println("The button has been pressed");
                return (true);
            }
        }
    }
    lastButtonState = reading;
    return (false);
}

void set_value_zero()
{
    Rotary_encoder.set_encoder_at_zero();
}