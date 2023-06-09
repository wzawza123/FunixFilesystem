/*
 * @Description: this file contains some utility functions and constants
 * @Date: 2022-09-05 14:30:17
 * @LastEditTime: 2023-03-22 21:00:41
 */
#ifndef UITILITY_H
#define UITILITY_H

#include<iostream>

/*
 *@comment 定义一些工具常量
 * 由于使用了编译选项-fno-builtin，
 * 编译器不提供这些常量的定义。
 */
#define NULL	0

/* 保存系统时间信息的结构体 */
struct SystemTime
{
	int Second;		/* Seconds: 0 ~ 59 */
	int Minute;		/* Minutes: 0 ~ 59 */
	int Hour;		/* Hours of Day: 0 ~ 23 */
	int DayOfMonth;	/* Day of Month: 1 ~ 31 */
	int Month;		/* Months since January: 1 ~ 12 */
	int Year;		/* Years since 1900 */
	int DayOfWeek;	/* Days since Sunday: 1 ~ 7 */
};

/* 记录进程使用的内核态和用户态下CPU时间的结构体 */
struct tms
{
	int utime;		/* 进程用户态CPU时间 */
	int stime;		/* 进程核心态CPU时间 */
	int cutime;		/* 子进程用户态时间总和 */
	int cstime;		/* 子进程核心态时间总和 */
};

/*
 *@comment 一些经常被使用到的工具函数
 *
 *
 */
class Utility
{
public:
	//从src拷贝count个byte到des
	static void MemCopy(unsigned long src, unsigned long des, unsigned int count);
	//计算在pagesize大小下，内存大小为memoryneed需要多少page来存贮
	static int CaluPageNeed(unsigned int memoryneed, unsigned int pagesize);
	//从src到dst复制字符串
	static void StringCopy(char* src, char* dst);
	//求pString字符串的长度
	static int StringLength(char* pString);
	/* 提取参数dev中的主设备号major，高8比特 */
	static short GetMajor(const short dev);
	/* 提取参数dev中的次设备号minor，低8比特 */
	static short GetMinor(const short dev);
	/* 设置参数dev中的主设备号部分，高8比特 */
	static short SetMajor(short dev, const short value);
	/* 设置参数dev中的次设备号部分，低8比特 */
	static short SetMinor(short dev, const short vlaue);
	/* 输出错误信息，然后死循环 */
	static void Panic(const std::string& str);

	/* 以src为源地址，dst为目的地址，复制count个双字 */
	static void DWordCopy(int* src, int* dst, int count);

	//求最小值
	static int Min(int a, int b);
	//求最大值
	static int Max(int a, int b);

	/* Convert BCD to Binary */
	static int BCDToBinary(int value);

	/* 用于在读、写文件时，高速缓存与用户指定目标内存区域之间数据传送 */
	static void IOMove(unsigned char* from, unsigned char* to, int count);

	/* 根据SystemTime结构体中的值计算出内核格式的时间值：从1970年1月1日0时至当前的秒数 */
	static unsigned int MakeKernelTime(struct SystemTime* pTime);
	//计算是否是闰年
	static bool IsLeapYear(int year);
	//计算这一年有多少天
	static unsigned int DaysInYear(int year);

	static const unsigned int borrowedPTE = 256;
	static const unsigned int SECONDS_IN_MINUTE = 60;	/* 一分钟60秒 */
	static const unsigned int SECONDS_IN_HOUR = 3600;	/* 一小时3600秒 */
	static const unsigned int SECONDS_IN_DAY = 86400;	/* 一天86400秒 */

	/* 某个月份前经过的天数 */
	static const unsigned int DaysBeforeMonth[13];
};

#endif
