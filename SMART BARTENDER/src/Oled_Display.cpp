#include <Arduino.h>
#include <U8g2lib.h>
#include "encoder.h"

#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif
#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif

U8G2_SH1106_128X64_NONAME_1_HW_I2C u8g2(U8G2_R0, /* reset=*/U8X8_PIN_NONE);

int p;

void Introduction()
{
    u8g2.setFont(u8g2_font_pxplustandynewtv_8u);
    u8g2.drawStr(3, 10, "SMART BARTENDER");

    u8g2.setFont(u8g2_font_u8glib_4_hr);
    u8g2.drawStr(0, 30, "Press Button for students info");
    u8g2.drawStr(0, 40, "Rotate Encoder for next and back");

    u8g2.setFont(u8g2_font_p01type_tf);
    u8g2.drawStr(0, 60, "         | START |          -->");
}

void Drink1()
{
    // u8g2.setFont(u8g2_font_pxplustandynewtv_8u);
    u8g2.setFont(u8g2_font_nokiafc22_tf);
    u8g2.drawStr(0, 10, "DRINK 1 NAME");

    u8g2.drawHLine(0, 15, 128);

    u8g2.drawVLine(53, 15, 39);

    u8g2.setFont(u8g2_font_profont10_mr);
    u8g2.drawStr(0, 28, "Ingredient");
    u8g2.drawStr(58, 28, "Milk, Coffee,");
    u8g2.drawStr(58, 38, "Sugar, Ice,");
    u8g2.drawStr(58, 48, "Milk, Coffee,");

    u8g2.drawHLine(0, 53, 128);

    u8g2.setFont(u8g2_font_p01type_tf);
    u8g2.drawStr(0, 60, "<--        | PAGE 1 |        -->");
}

void Drink2()
{
    u8g2.setFont(u8g2_font_nokiafc22_tf);
    u8g2.drawStr(0, 10, "DRINK 2 NAME");

    u8g2.drawHLine(0, 15, 128);

    u8g2.drawVLine(53, 15, 39);

    u8g2.setFont(u8g2_font_profont10_mr);
    u8g2.drawStr(0, 28, "Ingredient");
    u8g2.drawStr(58, 28, "Names here");
    u8g2.drawStr(58, 38, "");
    u8g2.drawStr(58, 48, "");

    u8g2.drawHLine(0, 53, 128);

    u8g2.setFont(u8g2_font_p01type_tf);
    u8g2.drawStr(0, 60, "<--        | PAGE 2 |        -->");
}

void Drink3()
{
    u8g2.setFont(u8g2_font_nokiafc22_tf);
    u8g2.drawStr(0, 10, "DRINK 3 NAME");

    u8g2.drawHLine(0, 15, 128);

    u8g2.drawVLine(53, 15, 39);

    u8g2.setFont(u8g2_font_profont10_mr);
    u8g2.drawStr(0, 28, "Ingredient");
    u8g2.drawStr(58, 28, "Names here");
    u8g2.drawStr(58, 38, "");
    u8g2.drawStr(58, 48, "");

    u8g2.drawHLine(0, 53, 128);

    u8g2.setFont(u8g2_font_p01type_tf);
    u8g2.drawStr(0, 60, "<--        | PAGE 3 |        -->");
}

void Drink4()
{
    u8g2.setFont(u8g2_font_nokiafc22_tf);
    u8g2.drawStr(0, 10, "DRINK 4 NAME");

    u8g2.drawHLine(0, 15, 128);

    u8g2.drawVLine(53, 15, 39);

    u8g2.setFont(u8g2_font_profont10_mr);
    u8g2.drawStr(0, 28, "Ingredient");
    u8g2.drawStr(58, 28, "Names here");
    u8g2.drawStr(58, 38, "");
    u8g2.drawStr(58, 48, "");

    u8g2.drawHLine(0, 53, 128);

    u8g2.setFont(u8g2_font_p01type_tf);
    u8g2.drawStr(0, 60, "<--        | PAGE 4 |        -->");
}

void Drink5()
{
    u8g2.setFont(u8g2_font_nokiafc22_tf);
    u8g2.drawStr(0, 10, "DRINK 5 NAME");

    u8g2.drawHLine(0, 15, 128);

    u8g2.drawVLine(53, 15, 39);

    u8g2.setFont(u8g2_font_profont10_mr);
    u8g2.drawStr(0, 28, "Ingredient");
    u8g2.drawStr(58, 28, "Names here");
    u8g2.drawStr(58, 38, "");
    u8g2.drawStr(58, 48, "");

    u8g2.drawHLine(0, 53, 128);

    u8g2.setFont(u8g2_font_p01type_tf);
    u8g2.drawStr(0, 60, "<--        | PAGE 5 |        -->");
}

void Drink6()
{
    u8g2.setFont(u8g2_font_nokiafc22_tf);
    u8g2.drawStr(0, 10, "DRINK 6 NAME");

    u8g2.drawHLine(0, 15, 128);

    u8g2.drawVLine(53, 15, 39);

    u8g2.setFont(u8g2_font_profont10_mr);
    u8g2.drawStr(0, 28, "Ingredient");
    u8g2.drawStr(58, 28, "Names here");
    u8g2.drawStr(58, 38, "");
    u8g2.drawStr(58, 48, "");

    u8g2.drawHLine(0, 53, 128);

    u8g2.setFont(u8g2_font_p01type_tf);
    u8g2.drawStr(0, 60, "<--        | PAGE 6 |        -->");
}

void Drink7()
{
    u8g2.setFont(u8g2_font_nokiafc22_tf);
    u8g2.drawStr(0, 10, "DRINK 7 NAME");

    u8g2.drawHLine(0, 15, 128);

    u8g2.drawVLine(53, 15, 39);

    u8g2.setFont(u8g2_font_profont10_mr);
    u8g2.drawStr(0, 28, "Ingredient");
    u8g2.drawStr(58, 28, "Names here");
    u8g2.drawStr(58, 38, "");
    u8g2.drawStr(58, 48, "");

    u8g2.drawHLine(0, 53, 128);

    u8g2.setFont(u8g2_font_p01type_tf);
    u8g2.drawStr(0, 60, "<--        | PAGE 7 |        -->");
}

void Drink8()
{
    u8g2.setFont(u8g2_font_nokiafc22_tf);
    u8g2.drawStr(0, 10, "DRINK 8 NAME");

    u8g2.drawHLine(0, 15, 128);

    u8g2.drawVLine(53, 15, 39);

    u8g2.setFont(u8g2_font_profont10_mr);
    u8g2.drawStr(0, 28, "Ingredient");
    u8g2.drawStr(58, 28, "Names here");
    u8g2.drawStr(58, 38, "");
    u8g2.drawStr(58, 48, "");

    u8g2.drawHLine(0, 53, 128);

    u8g2.setFont(u8g2_font_p01type_tf);
    u8g2.drawStr(0, 60, "<--        | PAGE 8 |        -->");
}

void Drink9()
{
    u8g2.setFont(u8g2_font_nokiafc22_tf);
    u8g2.drawStr(0, 10, "DRINK 9 NAME");

    u8g2.drawHLine(0, 15, 128);

    u8g2.drawVLine(53, 15, 39);

    u8g2.setFont(u8g2_font_profont10_mr);
    u8g2.drawStr(0, 28, "Ingredient");
    u8g2.drawStr(58, 28, "Names here");
    u8g2.drawStr(58, 38, "");
    u8g2.drawStr(58, 48, "");

    u8g2.drawHLine(0, 53, 128);

    u8g2.setFont(u8g2_font_p01type_tf);
    u8g2.drawStr(0, 60, "<--        | PAGE 9 |        -->");
}

void Drink10()
{
    u8g2.setFont(u8g2_font_nokiafc22_tf);
    u8g2.drawStr(0, 10, "DRINK 10 NAME");

    u8g2.drawHLine(0, 15, 128);

    u8g2.drawVLine(53, 15, 39);

    u8g2.setFont(u8g2_font_profont10_mr);
    u8g2.drawStr(0, 28, "Ingredient");
    u8g2.drawStr(58, 28, "Names here");
    u8g2.drawStr(58, 38, "");
    u8g2.drawStr(58, 48, "");

    u8g2.drawHLine(0, 53, 128);

    u8g2.setFont(u8g2_font_p01type_tf);
    u8g2.drawStr(0, 60, "<--        | Last |             ");
}

void (*pages[])() = {Introduction, Drink1, Drink2, Drink3, Drink4, Drink5, Drink6, Drink7, Drink8, Drink9, Drink10};

void oled_setup()
{
    u8g2.setColorIndex(2);
    u8g2.begin();
}

void pages_display()
{
    u8g2.firstPage();
    do
    {
        // u8g2.setFont(u8g2_font_pxplustandynewtv_8u );
        // u8g2.drawStr(0, 24, "Hello World!");
        (*pages[p])();
    } while (u8g2.nextPage());
    p = current_encoder_value();
}

//===========================Waste time at start for fun :]=============================//
uint8_t draw_state = 0;
void progress_bar_value(uint8_t a)
{
    u8g2.drawFrame(0, 35, 128, 20);
    u8g2.drawBox(5, 40, 0 + a, 10);
}

void progress_bar()
{
    progress_bar_value(draw_state);
}

void setup_load_display()
{
    while (draw_state != 100)
    {
        u8g2.firstPage();
        do
        {

            if (draw_state < 50)
            {
                u8g2.setFont(u8g2_font_pcsenior_8f);
                u8g2.drawStr(20, 10, "Welcome To");
                u8g2.drawStr(0, 20, "Smart Bartender");
            }
            else
            {
                u8g2.setFont(u8g2_font_pxplustandynewtv_8u);
                u8g2.drawStr(40, 30, "LOADING ");
            }
            progress_bar();

        } while (u8g2.nextPage());
        draw_state += 2;
        delay(100);
    }
}

//========================================SUB PAGES AFTER BUTTON IS PRESSED================================================//

void students_info()
{
    u8g2.firstPage();
    do
    {
        // u8g2.setFont(u8g2_font_profont11_mf);
        u8g2.setFont(u8g2_font_pxplustandynewtv_8u); // font for main drink names
        u8g2.drawStr(3, 10, "SMART BARTENDER");
        u8g2.setFont(u8g2_font_courB08_tf);
        u8g2.drawStr(0, 30, "No. Name");
        u8g2.setFont(u8g2_font_tinytim_tf);
        u8g2.drawStr(0, 40, "138  Prem Oswal");
        u8g2.drawStr(0, 50, "133  Aishwarya Narvankar");
        u8g2.drawStr(0, 60, "139  Swapnil Panchmind");

    } while (u8g2.nextPage());
}

//====================================Making Message Function=========================================================//

void sub_page_making_message()
{
    u8g2.setFont(u8g2_font_pressstart2p_8f);
    u8g2.drawStr(20, 20, "MAKING...");
}

//=============================================All Making Message Subpages=============================================//

void print_making_drink1()
{

    u8g2.firstPage();
    do
    {
        sub_page_making_message();
        u8g2.setFont(u8g2_font_tinytim_tf);
        u8g2.drawStr(20, 30, "Drink 1");

    } while (u8g2.nextPage());
}

void print_making_drink2()
{

    u8g2.firstPage();
    do
    {
        sub_page_making_message();
        u8g2.setFont(u8g2_font_tinytim_tf);
        u8g2.drawStr(20, 30, "Drink 2");

    } while (u8g2.nextPage());
}

void print_making_drink3()
{

    u8g2.firstPage();
    do
    {
        sub_page_making_message();
        u8g2.setFont(u8g2_font_tinytim_tf);
        u8g2.drawStr(20, 30, "Drink 3");

    } while (u8g2.nextPage());
}

void print_making_drink4()
{

    u8g2.firstPage();
    do
    {
        sub_page_making_message();
        u8g2.setFont(u8g2_font_tinytim_tf);
        u8g2.drawStr(20, 30, "Drink 4");

    } while (u8g2.nextPage());
}

void print_making_drink5()
{

    u8g2.firstPage();
    do
    {
        sub_page_making_message();
        u8g2.setFont(u8g2_font_tinytim_tf);
        u8g2.drawStr(20, 30, "Drink 5");

    } while (u8g2.nextPage());
}

void print_making_drink6()
{

    u8g2.firstPage();
    do
    {
        sub_page_making_message();
        u8g2.setFont(u8g2_font_tinytim_tf);
        u8g2.drawStr(20, 30, "Drink 6");

    } while (u8g2.nextPage());
}

void print_making_drink7()
{

    u8g2.firstPage();
    do
    {
        sub_page_making_message();
        u8g2.setFont(u8g2_font_tinytim_tf);
        u8g2.drawStr(20, 30, "Drink 7");

    } while (u8g2.nextPage());
}

void print_making_drink8()
{

    u8g2.firstPage();
    do
    {
        sub_page_making_message();
        u8g2.setFont(u8g2_font_tinytim_tf);
        u8g2.drawStr(20, 30, "Drink 8");

    } while (u8g2.nextPage());
}

void print_making_drink9()
{

    u8g2.firstPage();
    do
    {
        sub_page_making_message();
        u8g2.setFont(u8g2_font_tinytim_tf);
        u8g2.drawStr(20, 30, "Drink 9");

    } while (u8g2.nextPage());
}

void print_making_drink10()
{

    u8g2.firstPage();
    do
    {
        sub_page_making_message();
        u8g2.setFont(u8g2_font_tinytim_tf);
        u8g2.drawStr(20, 30, "Drink 10");

    } while (u8g2.nextPage());
}

//=========================================Enjoy your Drink Message========================================//

void print_enjoy_your_drink()
{

    u8g2.firstPage();
    do
    {
        u8g2.setFont(u8g2_font_pressstart2p_8f);
        u8g2.drawStr(40, 30, "ENJOY");
        u8g2.drawStr(20, 40, "YOUR DRINK!");
    } while (u8g2.nextPage());
}

//===========================================Bluetooth page===============================================//
void print_bluetooth_message()
{
    u8g2.firstPage();
    do
    {
        u8g2.setFont(u8g2_font_pressstart2p_8f);
        u8g2.drawStr(40, 30, "MAKING");
        u8g2.drawStr(10, 40, "USING BLUETOOTH!");
    } while (u8g2.nextPage());
}