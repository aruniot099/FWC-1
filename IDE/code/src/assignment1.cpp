#include<Arduino.h>
int X,Y,Z;
int F;
void assign(int F)
{
	digitalWrite(8, F);
}

void setup()
{
	pinMode(2,INPUT);
	pinMode(3,INPUT);
	pinMode(4,INPUT);
	pinMode(8,OUTPUT);
}

void loop()
{
	X = digitalRead(2);  
	Y = digitalRead(3);  
	Z = digitalRead(4);
	F=Y||(X&&!Z);
assign(F);
}

