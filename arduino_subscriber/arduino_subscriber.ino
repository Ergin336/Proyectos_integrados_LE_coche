#include <ros.h>
#include <std_msgs/Float64.h>
#include <LiquidCrystal.h>
 
ros::NodeHandle nh;
 
float var;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
const int switchPin = 6;
int switchState = 0;
int prevSwitchState = 0;
int reply;

void Distancia(const std_msgs::Float64 &data)
{
  var = data.data;
  lcd.print(var);
  lcd.setCursor(0, 1);
  lcd.print("calculando...");
 
}
 
ros::Subscriber<std_msgs::Float64> sub("chatter", &Distancia);
 
void setup()
{
  nh.initNode();
  nh.subscribe(sub);
  Serial.begin(9600);
  lcd.begin(16, 2);
  pinMode(switchPin, INPUT);
  lcd.print("Bienvenido,ponme");
  lcd.setCursor(0, 1);
  lcd.print("en el suelo :)");
  lcd.setCursor(0, 1);
}
 
void loop()
{
  switchState = digitalRead(switchPin);

  if(switchState != prevSwitchState) {
    if(switchState == LOW) {
      reply = random(8);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.setCursor(0, 1);
    }
   
  Serial.print(var);
  
  nh.spinOnce();
  delay(100);
  }
}
