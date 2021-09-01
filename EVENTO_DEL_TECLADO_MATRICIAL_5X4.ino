#include <LiquidCrystal_I2C.h>
#include <Keypad.h>

#define I2C_ADDR 0X27
#define BACKLIGHT_PIN 3

LiquidCrystal_I2C lcd(I2C_ADDR, BACKLIGHT_PIN, POSITIVE);

const byte row = 5;
const byte column = 4;

char matrix[row][column] = {
    {'A', 'B', '#', '*'},
    {'1', '2', '3', 'U'},
    {'4', '5', '6', 'L'},
    {'7', '8', '9', 'E'},
    {'<', '0', '>', 'S'}};

byte arrayColumn[column] = {2, 3, 4, 5};
byte arrayRow[row] = {10, 9, 8, 7, 6};
Keypad keypad = Keypad(makeKeymap(matrix), arrayRow, arrayColumn, row, column);

void setup()
{
  Serial.begin(9600);

  lcd.begin(20, 4);
  lcd.setBacklight(HIGH);
}

void loop()
{
  char key = keypad.getKey();

  if (key)
  {
    Serial.println(key);
    if (key != 'S')
      lcd.print(key);
  }
  if (key == '*')
  {
    lcd.clear();
  }
  else if (key == 'S')
  {
    lcd.print(" ");
  }
}