#include <LiquidCrystal.h>

int RS = 2;
int E = 3;
int d4 = 4;
int d5 = 5;
int d6 = 6;
int d7 = 7;

int i = 7;
int score = 0;
int speed = 300;
bool isPlaying = true;

char ball = '.';

LiquidCrystal lcd(RS,E,d4,d5,d6,d7);
void setup() {
  Serial.begin(9600);
  lcd.begin(16,2);
  lcd.clear();
  pinMode(8, INPUT_PULLUP); //button
}

void screen(int i){
  lcd.setCursor(i,0);
  lcd.write(ball);
  delay(speed);
  lcd.clear();
}
void loop() {
  bool button = !digitalRead(8);
  Serial.println(button);
  if(i<16){
    while(i<15){
      ++i;
      if(button && isPlaying){
        isPlaying = true;
        screen(i);
      }else{
        isPlaying = false;
        lcd.setCursor(0,1);
        lcd.print("lose");
        lcd.setCursor(6,1);
        lcd.print("score : ");
        lcd.print(score);
        break;

        score = 0;
        speed = 300;
      }
    }
  } 
  if(i>0) {
    while(i>0){
      --i;
      screen(i);
    }
  }
  if (isPlaying){
    speed-=25;
    score++;
  }
  if(button){
    isPlaying = true;
  }


}
