/**
 * @ Author: wzawza123
 * @ Create Time: 2023-03-25 20:15:49
 * @ Modified by: wzawza123
 * @ Modified time: 2023-03-25 21:40:19
 * @ Description: ���ļ����ڶ���ATA�����豸�����������
 */

#ifndef ATA_DRIVE_H
#define ATA_DRIVE_H

#include<iostream>

const std::string DISK_NAME = "disk.img";

class ATADriver
{
public:
	/* ���ô��̼Ĵ������������̽���I/O���� */
	static void DevStart(struct Buf* bp);
};

#endif
