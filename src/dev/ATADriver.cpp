/**
 * @ Author: wzawza123
 * @ Create Time: 2023-03-25 20:15:24
 * @ Modified by: wzawza123
 * @ Modified time: 2023-03-25 21:40:07
 * @ Description: 本文件用于实现ATA磁盘设备类的驱动程序

 */

#include "ATADriver.h"
#include "BufferManager.h"
#include "Utility.h"
#include "Kernel.h"

void ATADriver::DevStart(struct Buf* bp)
{
	//传入的缓存控制块指针为空，出错
	if(bp == NULL)
	{
		Utility::Panic("Invalid Buf in DevStart()!");
	}
	//打开文件
	FILE* m_File = fopen("hd.img", "rb+");
	//判断是读操作还是写操作
	if( (bp->b_flags & Buf::B_READ) == Buf::B_READ )
	{
		/* 读取磁盘数据 */
		fseek(m_File, bp->b_blkno * 512, SEEK_SET);
		fread(bp->b_addr, 512, 1, m_File);
	}else{
		/* 写入磁盘数据 */
		fseek(m_File, bp->b_blkno * 512, SEEK_SET);
		fwrite(bp->b_addr, 512, 1,m_File);
	}
	//关闭文件
	fclose(m_File);
	return;
}
