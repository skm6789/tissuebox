int a;
int b;
int i;
int c;
int num;
#include <Wire.h>
#include "TM1650.h"
#include <Arduino.h>
TM1650 d;
char line[] = {"1234"};
void setup() {
  Serial.begin(9600);
  pinMode(A1,INPUT);
  Wire.begin();        
  d.init();  //数码管初始化
  d.displayOff(); //关闭显示
  //d.displayString(line);  //输入显示字符
  d.setBrightness(2);  //设定显示亮度
  for(int i=0; i<4; i++) d.setDot(i, true);  //显示小数点
}

void loop() {
  //d.displayOn();  //显示信息
  //delay(500);
  //d.displayOff(); //关闭显示  
  //delay(500);

  for(i=1; i<=100; i++){
    a = digitalRead(A0);
    b = b + a;
  }
  if (b > 10 and b<90){
    num = num +1;
    Serial.println(num);
    if (num == 999){
      num = 0;
    }
    itoa(num, line,10);
    Serial.println(line);
    d.displayString(line);
    d.displayOn();
    delay(500);
  }
  b = 0;
}
