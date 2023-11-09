int a;
int b;
int i;
int c;
int f;
int num;
#include <Wire.h>
#include "TM1650.h"
#include <Arduino.h>
#include "kt540b.h"
TM1650 d;
char line[] = { "1" };
Kt540bClass mp3Play(1, 0);  //实例化对象，定义pin0为RX，pin1为TX
void setup() {
  //mp3Play.play(1);       //播放第1首歌曲
  //mp3Play.pause();
  //delay(100000);            //等待，让其播放10秒
  //Serial.begin(9600);
  pinMode(A0, INPUT);
  Wire.begin();
  d.init();                                       //数码管初始化
  d.displayOff();                                 //关闭显示
  d.displayString(line);                          //输入显示字符
  d.setBrightness(2);                             //设定显示亮度
  for (int i = 0; i < 4; i++) d.setDot(i, true);  //显示小数点
  mp3Play.begin();                                //mp3初始化开始
  mp3Play.setVolume(100);                         //音量设置
}

void loop() {
  //mp3Play.play(1);
  //delay(10000);
  //mp3Play.stop();
  //d.displayOn();  //显示信息
  //delay(500);
  //d.displayOff(); //关闭显示
  //delay(500);

  for (i = 1; i <= 100; i++) {
    a = digitalRead(A0);
    c = digitalRead(A1);
    b = b + a;
    f = f + c;
  }
  if (b > 10 and b < 90) {
    num = num + 1;
    itoa(num, line, 10);
    Serial.println(num);
    Serial.println(line);
    d.displayString(line);
    d.displayOn();
    if (num == 20) {
      mp3Play.play(2);
      delay(4000);
      mp3Play.stop();  //停止播放歌曲
    }
    if (num == 50) {
      mp3Play.play(1);
      delay(4000);
      mp3Play.stop();  //停止播放歌曲
    }
    if (num == 999) {
      num = 0;
    }
    delay(500);
  }
  if (f > 10 and f < 90) {
    num = num + 1;
    itoa(num, line, 10);
    Serial.println(num);
    Serial.println(line);
    d.displayString(line);
    d.displayOn();
    if (num == 999) { num = 0; }
    delay(500);
  }
  b = 0;
  f = 0;
}
void test(){

}
void notice(int i){
  mp3Play.play(i);
  delay(4000);
  mp3Play.stop();  //停止播放歌曲
}