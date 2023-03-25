/**
 * @ Author: wzawza123
 * @ Create Time: 2023-03-25 20:15:49
 * @ Modified by: wzawza123
 * @ Modified time: 2023-03-25 21:40:19
 * @ Description: 本文件用于定义ATA磁盘设备类的驱动程序
 */

#ifndef ATA_DRIVE_H
#define ATA_DRIVE_H

#include<iostream>

const std::string DISK_NAME = "disk.img";

class ATADriver
{
public:
	/* 设置磁盘寄存器，启动磁盘进行I/O操作 */
	static void DevStart(struct Buf* bp);
};

#endif
