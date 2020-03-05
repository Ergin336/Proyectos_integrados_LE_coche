#include <ros.h>
#include <std_msgs/Float64.h>

ros::NodeHandle nh;
std_msgs::Float64 Distancia;
ros::Publisher chatter("chatter",&Distancia);

const int Echo = 16;
const int Trigger = 17;

// Motor A
int ENA = 13;
int IN1 = 12;
int IN2 = 11;

// Motor B
int ENB = 10;
int IN3 = 9;
int IN4 = 8;

// Motor C
int ENC = 7;
int IN5 = 6;
int IN6 = 5;

// Motor D
int END = 4;
int IN7 = 3;
int IN8 = 2;

long t;
float d;

void setup() {
  pinMode (ENA, OUTPUT);
  pinMode (ENB, OUTPUT);
  pinMode (ENC, OUTPUT);
  pinMode (END, OUTPUT);
  pinMode (IN1, OUTPUT);
  pinMode (IN2, OUTPUT);
  pinMode (IN3, OUTPUT);
  pinMode (IN4, OUTPUT);
  pinMode (IN5, OUTPUT);
  pinMode (IN6, OUTPUT);
  pinMode (IN7, OUTPUT);
  pinMode (IN8, OUTPUT);

  nh.initNode();
  nh.advertise(chatter);
  pinMode(Trigger, OUTPUT); 
  pinMode(Echo, INPUT); 
  Serial.begin(57600); 
}

void Adelante ()
{
 //Direccion motor A
 digitalWrite (IN1, HIGH);
 digitalWrite (IN2, LOW);
 analogWrite (ENA, 64); //Velocidad motor A
 //Direccion motor B
 digitalWrite (IN3, LOW);
 digitalWrite (IN4, HIGH);
 analogWrite (ENB, 64); //Velocidad motor B
 //Direccion motor C
 digitalWrite (IN5, HIGH);
 digitalWrite (IN6, LOW);
 analogWrite (ENC, 64); //Velocidad motor C
 //Direccion motor D
 digitalWrite (IN7, LOW);
 digitalWrite (IN8, HIGH);
 analogWrite (END, 64); //Velocidad motor D
 
}

void Atras ()
{
 //Direccion motor A
 digitalWrite (IN1, LOW);
 digitalWrite (IN2, HIGH);
 analogWrite (ENA, 128); //Velocidad motor A
 //Direccion motor B
 digitalWrite (IN3, LOW);
 digitalWrite (IN4, HIGH);
 analogWrite (ENB, 180); //Velocidad motor B
 //Direccion motor C
 digitalWrite (IN5, LOW);
 digitalWrite (IN6, HIGH);
 analogWrite (ENC, 128); //Velocidad motor C
 //Direccion motor D
 digitalWrite (IN7, LOW);
 digitalWrite (IN8, HIGH);
 analogWrite (END, 180); //Velocidad motor D
}

void Izquierda ()
{
 //Direccion motor A
 digitalWrite (IN1, HIGH);
 digitalWrite (IN2, LOW);
 analogWrite (ENA, 200); //Velocidad motor A
 //Direccion motor B
 digitalWrite (IN3, LOW);
 digitalWrite (IN4, LOW);
 analogWrite (ENB, 100); //Velocidad motor B
 //Direccion motor C
 digitalWrite (IN5, HIGH);
 digitalWrite (IN6, LOW);
 analogWrite (ENC, 200); //Velocidad motor C
 //Direccion motor D
 digitalWrite (IN7, LOW);
 digitalWrite (IN8, LOW);
 analogWrite (END, 100); //Velocidad motor D
}

void Derecha ()
{
 //Direccion motor A
 digitalWrite (IN1, LOW);
 digitalWrite (IN2, HIGH);
 analogWrite (ENA, 50); //Velocidad motor A
 //Direccion motor B
 digitalWrite (IN3, HIGH);
 digitalWrite (IN4, LOW);
 analogWrite (ENB, 150); //Velocidad motor B
 //Direccion motor C
 digitalWrite (IN5, LOW);
 digitalWrite (IN6, HIGH);
 analogWrite (ENC, 50); //Velocidad motor C
 //Direccion motor D
 digitalWrite (IN7, HIGH);
 digitalWrite (IN8, LOW);
 analogWrite (END, 150); //Velocidad motor D
}


void Parar ()
{
 //Direccion motor A
 digitalWrite (IN1, LOW);
 digitalWrite (IN2, LOW);
 analogWrite (ENA, 0); //Velocidad motor A
 //Direccion motor B
 digitalWrite (IN3, LOW);
 digitalWrite (IN4, LOW);
 analogWrite (ENB, 0); //Velocidad motor A
 //Direccion motor C
 digitalWrite (IN5, LOW);
 digitalWrite (IN6, LOW);
 analogWrite (ENC, 0); //Velocidad motor C
 //Direccion motor D
 digitalWrite (IN7, LOW);
 digitalWrite (IN8, LOW);
 analogWrite (END, 0); //Velocidad motor D
}

void loop() {

  digitalWrite(Trigger, LOW);
  delayMicroseconds(2);
  
  
  digitalWrite(Trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trigger, LOW);
  
  t = pulseIn(Echo, HIGH);
  d = t / 59;
  
  if(d <= 50.00){
   
   Parar ();
   delay (500);
   Atras ();
  }
  
  else{
    
    Adelante ();
  }
  
  Distancia.data = d;
  chatter.publish(&Distancia);
  nh.spinOnce();
  
  Serial.print(d);
  delay(100);
}


//void loop ()
//{
 //Adelante ();
 //delay (5000);
 //Atras ();
 //delay (3000);
 //Derecha ();
 //delay (2000);
 //Izquierda ();
 //delay (2000);
 //Parar ();
 //delay (4000);
//}
