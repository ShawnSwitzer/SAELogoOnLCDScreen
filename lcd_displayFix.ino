#include <Wire.h>
#include <LiquidCrystal_I2C.h>      

//Created new object that connected to the Arduino board.
LiquidCrystal_I2C lcd(0x27,20,4);     
//The byte arrays were created using the website https://maxpromer.github.io/LCD-Character-Creator/
byte fullBox[] = 
{
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111
};
byte halfBoxBottom[] =
{
  B00000,
  B00000,
  B00000,
  B00000,
  B11111,
  B11111,
  B11111,
  B11111  
};
byte halfBoxTop[] =
{
  B11111,
  B11111,
  B11111,
  B11111,
  B00000,
  B00000,
  B00000,
  B00000  
};

byte topLeftAChar[] = {
  B00001,
  B00011,
  B00111,
  B01111,
  B01111,
  B11111,
  B11111,
  B11111
};
byte sideLeftAChar[] = {
  B00001,
  B00011,
  B00111,
  B01111,
  B11111,
  B11111,
  B11111,
  B11111
};
byte sideLeftAInnerChar[] = {
  B11111,
  B11111,
  B11110,
  B11110,
  B11100,
  B11000,
  B10000,
  B10000
};
byte sideLeftInnerCharConnector[] = {
  B11111,
  B11111,
  B11110,
  B11100,
  B11111,
  B11111,
  B11111,
  B11111
};
byte topRightSCurve[] = {
  B10000,
  B11000,
  B11100,
  B11110,
  B11111,
  B11111,
  B11111,
  B11111
};
byte topLeftSCurve[] = {
  B00001,
  B00011,
  B00111,
  B01111,
  B11111,
  B11111,
  B11111,
  B11111
};
byte bottomLeftSCurve[] = {
  B00000,
  B00000,
  B11100,
  B11110,
  B11110,
  B01111,
  B01111,
  B00111
};

void setup()

{        
   //Initialized screen and backlight.
  lcd.init();
  lcd.backlight();

  //Characters used to create the logo
  lcd.begin(20, 4);
  lcd.createChar(0, fullBox);
  lcd.createChar(1, halfBoxBottom);
  lcd.createChar(2, halfBoxTop);
  lcd.createChar(3, topLeftAChar);
  lcd.createChar(4, sideLeftAChar);
  lcd.createChar(5, sideLeftAInnerChar);
  lcd.createChar(6, sideLeftInnerCharConnector);
  lcd.createChar(7, topRightSCurve);

  /**
   * First line of LCD Screen
   */
  lcd.setCursor(1,0);
  lcd.write(3);
  
  for(int i = 2; i <= 5; i++)
  {
    lcd.setCursor(i,0);
    lcd.write(0);
  }
  
  lcd.setCursor(6,0);
  lcd.write(7);

  lcd.setCursor(9,0);
  lcd.write(3);

  for(int i = 10; i <= 17; i++)
  {
    lcd.setCursor(i,0);
    lcd.write(0);  
  }

  /**
   * Second line of LCD Screen
   */
  lcd.setCursor(1,1);
  lcd.write(0);
  lcd.setCursor(6,1);
  lcd.write(2);
  lcd.setCursor(8,1);
  lcd.write(4);
  lcd.setCursor(9,1);
  lcd.write(5);
  lcd.setCursor(12,1);
  lcd.write(0);
  lcd.setCursor(13,1);
  lcd.write(0);

  for(int i = 14; i <= 17; i++)
  {
    lcd.setCursor(i,1);
    lcd.write(1);
  }

  /**
   * Third line of LCD Screen
   */
   for(int i = 1; i <= 5; i++)
   {
      lcd.setCursor(i,2);
      lcd.write(2);
   }
   
   lcd.setCursor(6,2);
   lcd.write(7);
   lcd.setCursor(7,2);
   lcd.write(4);

   for(int i = 8; i <= 13; i++)
   {
      lcd.setCursor(i,2);
      lcd.write(0); 
   }

   for(int i = 14; i <= 17; i++)
   {
      lcd.setCursor(i,2);
      lcd.write(2);
   }

   /**
    * Fourth line of LCD Screen
    */
    lcd.setCursor(1,3);
    lcd.write(6);

    for(int i = 2; i <= 5; i++)
    {
       lcd.setCursor(i,3);
       lcd.write(1);
    }

    lcd.setCursor(6,3);
    lcd.write(0);
    lcd.setCursor(7,3);
    lcd.write(5);

    for(int i = 12; i <= 17; i++)
    {
        lcd.setCursor(i,3);
        lcd.write(0);  
    }
}

//Optional code to make logo blink on the lcd screen.
void loop()
{
  /**lcd.noDisplay();
  delay(1000);
  lcd.display();
  delay(1000);
  **/
}
