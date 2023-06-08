#include <LiquidCrystal_I2C.h>
#define AOUT_PIN A0 // Arduino pin that connects to AOUT pin of moisture sensor
LiquidCrystal_I2C lcd(0x27,16,2);

int Htime;              //integer for storing high time

int Ltime;                //integer for storing low time

int Ttime;            // integer for storing total time of a cycle

float frequency;        //storing frequency

void setup() {
  Serial.begin(9600);
  pinMode(8,INPUT);
  lcd.init(); //display initialization
  lcd.backlight(); // activate the backlight
}

void loop() {
    Htime=pulseIn(8,HIGH);      //read high time

    Ltime=pulseIn(8,LOW);        //read low time

    Ttime = Htime+Ltime;

    frequency=1000000/Ttime;

  lcd.setCursor(2,0); 
  lcd.print("Frequency : ");
  lcd.setCursor(2,1);  
  lcd.print(frequency);
  lcd.print(" Hz");
  delay(500);
  lcd.clear();
}
