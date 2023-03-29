#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE
#include <Arduino.h>
#include <DabbleESP32.h>
#include "esp32_eoss3_spi.h"

#define MISC_BASE_ADDR 0x40005000
#define SW_MB_1  MISC_BASE_ADDR+0x110
#define SW_MB_2  MISC_BASE_ADDR+0x114

#define SW_MB_1_DEF_VAL 0
#define SW_MB_2_DEF_VAL 0

uint32_t dest_address = SW_MB_1_DEF_VAL;
void sevenseg(int a,int b,int c,int d,int e,int f,int g)
{
  digitalWrite(32, a); 
  digitalWrite(33, b); 
  digitalWrite(25, c); 
  digitalWrite(26, d); 
  digitalWrite(27, e); 
  digitalWrite(14, f);     
  digitalWrite(12, g); 
}
            
void _setup() 
{

Dabble.begin("Esp32");
pinMode(32, OUTPUT);  
pinMode(33, OUTPUT);
pinMode(25, OUTPUT);
pinMode(26, OUTPUT);
pinMode(27, OUTPUT);
pinMode(14, OUTPUT);
pinMode(12, OUTPUT); 

}

void _loop() {
  Dabble.processInput(); //Continously process input from the dabble app over bluetooth
}

#define MAP_FROM_HIGH 7.0f
#define MAP_FROM_LOW -7.0f
#define MAP_TO_HIGH 255.0f
#define MAP_TO_LOW -255.0f

int16_t joystick_pwm_map(float axis_value){
 int16_t pwm_val = (int16_t) (axis_value*(MAP_TO_HIGH-MAP_TO_LOW)/(MAP_FROM_HIGH-MAP_FROM_LOW));
 return pwm_val;
}

void setup()
{
 _setup();

 uint8_t* read_buff = (uint8_t*)&dest_address;

 Serial.begin(115200);

 pinMode(LED_BUILTIN, OUTPUT);
 digitalWrite(LED_BUILTIN, 1);

 esp32_eoss3_spi_init(); 
 do{
  esp32_eoss3_spi_ahb_read(SW_MB_1, read_buff, 4);
  delay(10);
 }while(dest_address == SW_MB_1_DEF_VAL);

 digitalWrite(LED_BUILTIN, 0);
}

void loop()

{

 static uint32_t shape_button_status = 0, previous_status = 0;
 static int16_t pwm_val[2] = {0,0}, previous_val[2] = {0,0};
 uint8_t* write_buff = NULL;
 
 _loop();
 write_buff = (uint8_t*)&shape_button_status;
 write_buff[0] = (uint8_t)GamePad.isCrossPressed();
 Serial.write(write_buff[0]); 
 write_buff[1] = (uint8_t)GamePad.isSquarePressed(); 
 //Serial.write(write_buff[1]); 
 write_buff[2] = (uint8_t)GamePad.isTrianglePressed(); 
 write_buff[3] = (uint8_t)GamePad.isCirclePressed(); 
 pwm_val[0] = joystick_pwm_map(GamePad.getXaxisData());
 pwm_val[1] = joystick_pwm_map(GamePad.getYaxisData());
 if(shape_button_status != previous_status||pwm_val[0] != previous_val[0]||pwm_val[1] != previous_val[1])
 {
  previous_status = shape_button_status;
  previous_val[0] = pwm_val[0];
  previous_val[1] = pwm_val[1];

  Serial.println(pwm_val[0]);
  Serial.println(pwm_val[1]);


if(((pwm_val[1]>=0)&&(pwm_val[1]<=255))&&write_buff[1])
{
sevenseg(1,0,0,1,1,1,1); //1
Serial.println("1");
}
else if(((pwm_val[1]>=-255)&&(pwm_val[1]<=0))&&write_buff[1])
{
sevenseg(0,0,1,0,0,1,0);//2
Serial.println("2");
}
if((pwm_val[0]>=0)&&(pwm_val[0]<=255)&&write_buff[0])
{
sevenseg(0,0,0,0,1,1,0); //3
Serial.println("3");
}
else if((pwm_val[0]>=-255)&&(pwm_val[0]<=0)&&write_buff[0])
{
sevenseg(1,0,0,1,1,0,0); //4
Serial.println("4");
}



/*if((pwm_val[1]>=-50)||(pwm_val[1]<=255)&&(pwm_val[0]>=-120)||(pwm_val[0]<=120))
{
        //sevenseg(0,0,1,0,0,1,0);
 sevenseg(1,0,0,1,1,1,1);
 Serial.println("1");
 }

else if((pwm_val[1]<=50)||(pwm_val[1]>=-255)&&(pwm_val[0]>=-120)||(pwm_val[0]<=120))
{
 sevenseg(0,0,1,0,0,1,0);
 Serial.println("2");
}*/


 /* if((pwm_val[0]>=-128  pwm_val[0]<= 128)&&(pwm_val[1]>=128  pwm_val[1]<=255))
  {
   sevenseg(1,0,0,1,1,1,1); //1
   Serial.println("1");
  }
   else if((pwm_val[0]>=-128  pwm_val[0]<=128)&&(pwm_val[1]>=-128  pwm_val[1]<=-255))
   {
   sevenseg(0,0,1,0,0,1,0);  //2
   Serial.println("2");

  }*/
       /* else if((pwm_val[0]>=-255  pwm_val[0]<= -128) && (pwm_val[1]>=-128  pwm_val[1]<=128))
  {
   sevenseg(0,0,0,0,1,1,0); //3
   Serial.println("3");
  }
  else
  {
   sevenseg(1,0,0,1,1,0,0); //4
   Serial.println("4");
  }*/
  write_buff = (uint8_t*)&shape_button_status;
  esp32_eoss3_spi_ahb_write(dest_address, write_buff, 4);

  write_buff = (uint8_t*)&pwm_val[0];
  esp32_eoss3_spi_ahb_write(dest_address+4, write_buff, 4);
 }

}
