// kt540b.h

#ifndef _KT540B_h
#define _KT540B_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include <SoftwareSerial.h>

/*选曲播放*/
#define CMD_NEXT                     0x01
#define CMD_PREV                     0x02
#define CMD_PLAY_SONG                0x03
/*播放设置*/
#define CMD_VOLUME_INC               0x04
#define CMD_VOLUME_DEC               0x05
#define CMD_VOLUME                   0x06
#define CMD_SET_EQ                   0x07
#define CMD_LOOP                     0x08
#define CMD_MEDIA_SELECT             0x09
/*设备状态设置*/
#define CMD_ENTER_SLEEP_MODE         0x0A
#define CMD_EXIT_SLEEP_MODE          0x0B
#define CMD_RESET                    0x0C
#define CMD_PLAY                     0x0D
#define CMD_PAUSE                    0x0E
#define CMD_DIR_PLAY                 0x0F
#define CMD_DIR_PLAY1                0x14
#define CMD_STOP                     0x16
#define CMD_DIR_LOOP                 0x17
#define CMD_RADOM_PLAY               0x18
#define CMD_LOOP_ONE                 0x19
#define CMD_DAC_ON_OFF               0x1A
#define CMD_PLAY_WITH_VOLUME         0x22
/*获取设备状态*/
#define CMD_GET_STATE                0x42
#define PLAY_STATE                   0x01
#define STOP_STATE                   0x00

typedef enum {
	UDISK,
	TFCARD,
	FLASH,
} MEDIA;

class Kt540bClass
{
 protected:

 public:
	 Kt540bClass(int rxPin, int txPin);
	void begin();
	void play(void);     //播放（比如从暂停中恢复）
	void play(uint8_t songNum);   //播放指定序号歌曲 
	//void play(uint8_t songNum, uint8_t volume); //按给定音量播放指定序号歌曲 
	void playDir(uint8_t dir, uint8_t songNum); //播放指定文件夹指定歌曲
	void playNext(void);    //播下一首
	void playPrev(void);    //播上一首
	void setVolume(uint8_t volume);  //设置音量
	void volumeInc();       //音量+
	void volumeDec();       //音量-
	void setEQ(uint8_t eq);                  //设置EQ值
	void loop(uint8_t songNo);               //指定根文件夹下相关序号歌曲循环播放
	void loop(uint8_t dir, uint8_t songNo);  //指定目录相关序号歌曲循环播放
	void loopDir(uint8_t dir);               //指定目录循环播放
	void singleLoop(boolean onOff);         //单曲循环开关
	void radomPlay(void);  //随机播放（整个设备上的歌）
	void pause(void);   //暂停
	void stop(void);    //停止
	void setDac(bool onOff);  //DAC开关
	void enterSleep(void);    //进入睡眠__bool_true_false_are_defined
	void exitSleep(void);    //退出睡眠
	void resetDevice(void);  //设备复位
	void setPlayMedia(MEDIA playMedia);  //选择播入媒体
	uint8_t getPlayState(void); //获取播放状态
private:
	int pinRx;
	int pinTx;
	SoftwareSerial Sserial;

	void sendCmd(uint8_t cmd, uint8_t data1, uint8_t data2);
};

//extern Kt540bClass Kt540b;

#endif

