/*
Copyright (C), 2014- ,  盛思科教
File name:     kt540b.cpp
Author: jiangzhaohui      Version: v1.0      Date: 2016.12.15
Description: 基于kt540b的mp3驱动
驱动使用：
1、声明一个对象实例，并指定串口rx tx引脚
2、调用begin()初始化
3、调用各功能函数数完成各设置及播放。

Others:
Function List:
1.
2.
History:

1. Date: 2014.10.8       Author:
Modification: 代码创建
2. ...
*/

#include "kt540b.h"

Kt540bClass::Kt540bClass(int rxPin, int txPin) : Sserial(rxPin, txPin)
{
	pinRx = rxPin;
	pinTx = txPin;
}

void Kt540bClass::begin()
{
	Sserial.begin(9600);
	delay(1500);   //上电延时
}

/***************************************************************************
Function:       play()
Description:    恢复播放
Calls:
Called By:
Input:
Output:
Return:
Others:
***************************************************************************/
void Kt540bClass::play(void)     //播放（比如从暂停中恢复）
{
	sendCmd(CMD_PLAY, 0, 0);
}

/***************************************************************************
Function:       play()
Description:    播放指定序号歌曲
Calls:
Called By:
Input:
1、uint8_t songNum：歌曲序号
Output:
Return:
Others:
***************************************************************************/
void Kt540bClass::play(uint8_t songNum)   //播放指定序号歌曲 
{
	sendCmd(CMD_PLAY_SONG, 0x00, songNum);
}

/***************************************************************************
Function:       play()
Description:    按指定音量播放指定序列号歌曲
Calls:
Called By:
Input:
1、uint8_t songNum：歌曲序号
2、uint8_t volume：音量
Output:
Return:
Others:
***************************************************************************/
//void Kt540bClass::play(uint8_t songNum, uint8_t volume) 
//{
//	sendCmd(CMD_PLAY_WITH_VOLUME, volume, songNum);
//}

/***************************************************************************
Function:       playDir()
Description:    播放指定文件夹指定歌曲
Calls:
Called By:
Input:
1、uint8_t songNum：歌曲序号
2、uint8_t volume：音量
Output:
Return:
Others:
***************************************************************************/
void Kt540bClass::playDir(uint8_t dir, uint8_t songNum)
{
	sendCmd(CMD_DIR_PLAY, dir, songNum);
}

/***************************************************************************
Function:       play()
Description:    播放指定序号歌曲
Calls:
Called By:
Input:
1、uint8_t songNum：歌曲序号
Output:
Return:
Others:
***************************************************************************/
void Kt540bClass::playNext(void)    //播下一首
{
	sendCmd(CMD_NEXT, 0, 0);
}

/***************************************************************************
Function:       play()
Description:    播放指定序号歌曲
Calls:
Called By:
Input:
1、uint8_t songNum：歌曲序号
Output:
Return:
Others:
***************************************************************************/
void Kt540bClass::playPrev(void)    //播上一首
{
	sendCmd(CMD_PREV, 0, 0);
}

/***************************************************************************
Function:       setVolume()
Description:    设置音量
Calls:
Called By:
Input:
	1、uint8_t volume：音量值 范围 0-30
Output:
Return:  
Others:
***************************************************************************/
void Kt540bClass::setVolume(uint8_t volume)  //设置音量
{
	sendCmd(CMD_VOLUME, 0x00, volume);
}

/***************************************************************************
Function:       volumeInc()
Description:    音量+
Calls:
Called By:
Input:
Output:
Return:
Others:
***************************************************************************/
void Kt540bClass::volumeInc()       //音量—
{
	sendCmd(CMD_VOLUME_INC, 0, 0);
}

/***************************************************************************
Function:       volumeDec()
Description:    音量-
Calls:
Called By:
Input:
Output:
Return:
Others:
***************************************************************************/
void Kt540bClass::volumeDec()       //音量+
{
	sendCmd(CMD_VOLUME_DEC, 0, 0);
}

/***************************************************************************
Function:       setEQ()
Description:    设置EQ
Calls:
Called By:
Input:
1、uint8_t eq ：eq值
Output:
Return:
Others:
***************************************************************************/
void Kt540bClass::setEQ(uint8_t eq)                  //设置EQ值
{
	sendCmd(CMD_SET_EQ, 0, eq);
}

/***************************************************************************
Function:       loop()
Description:    指定曲目循环播放
Calls:
Called By:
Input:
1、uint8_t songNo ：要循环的曲目编号
Output:
Return:
Others:
***************************************************************************/
void Kt540bClass::loop(uint8_t songNo)               
{
	sendCmd(CMD_LOOP, 0, songNo);
}

/***************************************************************************
Function:       loop()
Description:    指定目录内指定序号歌曲循环播放
Calls:
Called By:
Input:
1、uint8_t dir：目录号（目录名须为01、02、03这样的格式）
2、uint8_t songNo ：要循环的曲目编号
Output:
Return:
Others:
***************************************************************************/
void Kt540bClass::loop(uint8_t dir, uint8_t songNo)  
{
	sendCmd(CMD_LOOP, dir, songNo);
}

/***************************************************************************
Function:       loopDir()
Description:    指定目录循环播放
Calls:
Called By:
Input:
1、uint8_t dir：目录号（目录名须为01、02、03这样的格式）
Output:
Return:
Others:
***************************************************************************/
void Kt540bClass::loopDir(uint8_t dir)              
{
	sendCmd(CMD_DIR_LOOP, 0, dir);
}

/***************************************************************************
Function:       singleLoop()
Description:    单曲循环开关，通常在发一条指令播放一首歌后，发本指令指定是否循环
     示例（循环放第3首歌）：
	        ... 
	      	mp3Play.play(3);
	        mp3Play.singleLoop(0);
			... 
Calls:
Called By:
Input:
1、boolean onOff: 0:循环  1：不循环
Output:
Return:
Others:
	test state: pass
***************************************************************************/
void Kt540bClass::singleLoop(boolean onOff)         
{
	sendCmd(CMD_LOOP_ONE, 0, onOff);
}

/***************************************************************************
Function:       radomPlay()
Description:    随机播放,对卡上所有文件随机播放，包括文件夹中的歌
Calls:
Called By:
Input:
Output:
Return:
Others:
	test state: pass
***************************************************************************/
void Kt540bClass::radomPlay(void)  //随机播放
{
	sendCmd(CMD_RADOM_PLAY, 0, 0);
}

/***************************************************************************
Function:       pause()
Description:    暂停
Calls:
Called By:
Input:
Output:
Return:
Others:
***************************************************************************/
void Kt540bClass::pause(void)   //暂停
{
	sendCmd(CMD_PAUSE, 0, 0);
}

/***************************************************************************
Function:       stop()
Description:    停止播放
Calls:
Called By:
Input:
Output:
Return:
Others:
***************************************************************************/
void Kt540bClass::stop(void)    //停止
{
	sendCmd(CMD_STOP, 0, 0);
}

/***************************************************************************
Function:       setDac()
Description:    启用或停止DAC
Calls:
Called By:
Input:
bool onOff：0：停止 1：启用
Output:
Return:
Others:
***************************************************************************/
void Kt540bClass::setDac(bool onOff)  //DAC开关
{
	sendCmd(CMD_DAC_ON_OFF, 0, 0);
}

/***************************************************************************
Function:       enterSleep()
Description:    进入睡眠模式
Calls:
Called By:
Input:
Output:
Return:
Others:
***************************************************************************/
void Kt540bClass::enterSleep(void)    
{
	sendCmd(CMD_ENTER_SLEEP_MODE, 0, 0);
}

/***************************************************************************
Function:       exitSleep()
Description:    退出睡眠模式
Calls:
Called By:
Input:
Output:
Return:
Others:
***************************************************************************/
void Kt540bClass::exitSleep(void)    
{
	sendCmd(CMD_EXIT_SLEEP_MODE, 0, 0);
}

/***************************************************************************
Function:       resetDevice()
Description:    设备复位
Calls:
Called By:
Input:
Output:
Return:
Others:
***************************************************************************/
void Kt540bClass::resetDevice(void)
{
	sendCmd(CMD_RESET, 0, 0);
}

/***************************************************************************
Function:       setPlayMedia()
Description:    选择播放媒体
Calls:
Called By:
Input:
MEDIA playMedia： 	UDISK：U盘  TFCARD：TF卡 FLASH：FLASH芯片
Output:
Return:
Others:
***************************************************************************/
void Kt540bClass::setPlayMedia(MEDIA playMedia)
{
	sendCmd(CMD_MEDIA_SELECT, 0, 0);
}

/***************************************************************************
Function:       getPlayState()
Description:    获取设备当前状态
Calls:
Called By:
Input:
Output: 设备状态 0:播放停止 1：播放 2：暂停
Return:
Others:
***************************************************************************/
uint8_t Kt540bClass::getPlayState(void)
{
	uint8_t sendBuff[10];
	uint8_t i;

	sendBuff[0] = 0x7e;    //起始位
	sendBuff[1] = 0xff;    //版本
	sendBuff[2] = 0x06;    //长度
	sendBuff[3] = 0x42;     //命令
	sendBuff[4] = 0x00;    //是否反馈，0：不反馈
	sendBuff[5] = 0x00;   //数据字节1
	sendBuff[6] = 0x00;   //数据字节2
	sendBuff[7] = 0xfe;    //校验高字节
	sendBuff[8] = 0xb9;    //校验低字节
	sendBuff[9] = 0xef;     //结束

	for (i = 0; i < 10; i++)
		Sserial.write(sendBuff[i]);
	while (!Sserial.available());
	for (i = 0; i < 10; i++)
		sendBuff[i] = Sserial.read();
	return sendBuff[6];
}

/***************************************************************************
Function:       sendCmd()
Description:    向模块发送指令
Calls:
Called By:
Input:
1、uint8_t cmd： 指令
2、uint8_t data1： 数据字节1
3、uint8_t data2： 数据字节2
Output:
Return:
Others:
***************************************************************************/
void Kt540bClass::sendCmd(uint8_t cmd, uint8_t data1, uint8_t data2)
{
	uint8_t sendBuff[10];
	uint8_t i;
	uint16_t temp;
	uint8_t tempH, tempL;

	sendBuff[0] = 0x7e;    //起始位
	sendBuff[1] = 0xff;    //版本
	sendBuff[2] = 0x06;    //长度
	sendBuff[3] = cmd;     //命令
	sendBuff[4] = 0x00;    //是否反馈，0：不反馈
	sendBuff[5] = data1;   //数据字节1
	sendBuff[6] = data2;   //数据字节2

	temp = 0xff + 0x06 + cmd + 0x00 + data1 + data2;
	temp = (0xFFFF - temp) + 1;
	tempH = (uint8_t)(temp >> 8);
	tempL = (uint8_t)(temp & 0xff);
	sendBuff[7] = tempH;    //校验高字节
	sendBuff[8] = tempL;    //校验低字节
	sendBuff[9] = 0xef;     //结束

	for (i = 0; i < 10; i++)
		Sserial.write(sendBuff[i]);  
	delay(20);    //datasheet要求两条指令发送音隔不少于20ms，这里放宽一点
}



//Kt540bClass Kt540b;

