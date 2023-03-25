#include "DeviceManager.h"

extern ATABlockDevice g_ATADevice;	//ATA磁盘设备

//构造函数
DeviceManager::DeviceManager()
{
}
//析构函数
DeviceManager::~DeviceManager()
{
}
//初始化
void DeviceManager::Initialize()
{
	this->bdevsw[0] = &g_ATADevice;	//第一个块设备是上面定义的ATA磁盘设备
	this->nblkdev = 1;	//目前块设备数量为1
}

//获取块设备数量数
int DeviceManager::GetNBlkDev()
{
	return this->nblkdev;
}

//根据主设备号获取指向该块设备的指针
BlockDevice& DeviceManager::GetBlockDevice(short major)
{
	//保证主设备号合法
	if(major >= this->nblkdev || major < 0)
	{
		Utility::Panic("Block Device Doesn't Exist!");	//主设备号不合法直接报错
	}
	return *(this->bdevsw[major]);	//返回major对应的块设备
}