/**
 * @ Author: wzawza123
 * @ Create Time: 2023-03-25 21:06:15
 * @ Modified by: wzawza123
 * @ Modified time: 2023-03-25 21:35:16
 * @ Description: ���ļ�����ʵ�ֿ��豸�����������
 */

#include "BlockDevice.h"
#include "Kernel.h"
#include "ATADriver.h"

/*==============================class Devtab===================================*/
/* ������豸��devtab��ʵ����Ϊϵͳ��ATAӲ������һ�����豸��*/
Devtab g_Atab;

//���豸���Ǽ�����Ĺ�����״
Devtab::Devtab()
{
	this->d_active = 0;	//��������ִ��IO����ʱ��d_active��1
	this->d_errcnt = 0;	//��ǰ����IO��������������ִ���ʱ���ñ���������10ʱϵͳ�Ż����
	this->b_forw = NULL;	//�豸������еĶ���
	this->b_back = NULL;	//�豸������еĶ�β
	this->d_actf = NULL;	//IO ������еĶ���
	this->d_actl = NULL;	//IO ������еĶ�β
}

Devtab::~Devtab()
{
	//nothing to do here
}

/*==============================class BlockDevice===============================*/
BlockDevice::BlockDevice()
{
	//nothing to do here
}

BlockDevice::BlockDevice(Devtab* pDevtab)
{	
	this->d_tab = pDevtab;	//��pDevtab���г�ʼ��
	if(this->d_tab != NULL)
	{
		//��ʼ��ʱָ���豸������е�ָ�룬��ָ����Ŀ��豸��
		this->d_tab->b_forw = (Buf *)this->d_tab;
		this->d_tab->b_back = (Buf *)this->d_tab;
	}
}

BlockDevice::~BlockDevice()
{
	//nothing to do here
}

//��Ӧ�ñ�����
int BlockDevice::Open(short dev, int mode)
{
	Utility::Panic("ERROR! Base Class: BlockDevice::Open()!");
	return 0;	/* GCC likes it ! */
}

//��Ӧ�ñ�����
int BlockDevice::Close(short dev, int mode)
{
	Utility::Panic("ERROR! Base Class: BlockDevice::Close()!");
	return 0;	/* GCC likes it ! */
}

//��Ӧ�ñ�����
int BlockDevice::Strategy(Buf *bp)
{
	Utility::Panic("ERROR! Base Class: BlockDevice::Strategy()!");
	return 0;	/* GCC likes it ! */
}

//��Ӧ�ñ�����
void BlockDevice::Start()
{
	Utility::Panic("ERROR! Base Class: BlockDevice::Start()!");
}

/*=============================class ATABlockDevice=============================*/
/* ����������ATABlockDevice��ʵ����
 * ��ʵ��������override���豸����BlockDevice��Open(), Close(), Strategy()�麯����
 */
ATABlockDevice g_ATADevice(&g_Atab);

/* 
 * !hard code!������bochs�´���ӳ���ļ�c.img����������С��Ӧ����ϵͳ����ʱ��ȡ��
 * 20 Cylinders; 16 Heads; 63 Sectors/Track��20 * 16 * 63 = 20160 Sectors��
 * c.img: 10,321,920 bytes = 10,008KB 
 */
int ATABlockDevice::NSECTOR = 0x7FFFFFFF;	/* Max Possible Sector Numbers */

//���캯����ֱ�Ӽ̳�
ATABlockDevice::ATABlockDevice(Devtab* pDevtab)
	:BlockDevice(pDevtab)
{
}

//��������
ATABlockDevice::~ATABlockDevice()
{
	//nothing to do here
}

//Ϊ�գ�����Բ����ת��Ӳ�̲���Ҫ�򿪹ر�
int ATABlockDevice::Open(short dev, int mode)
{
	return 0;	/* GCC likes it ! */
}
//Ϊ�գ�����Բ����ת��Ӳ�̲���Ҫ�򿪹ر�
int ATABlockDevice::Close(short dev, int mode)
{
	return 0;	/* GCC likes it ! */
}

//ά�� FIFS ��������С�������Ŷ�β���������أ�����Ϊ�գ�����Start ������������
int ATABlockDevice::Strategy(Buf* bp)
{
	/* ���I/O�������Ƿ񳬳��˸�Ӳ�̵����������� */
	if(bp->b_blkno >= ATABlockDevice::NSECTOR)
	{
		/* ���ó����־ */
		bp->b_flags |= Buf::B_ERROR;

		BufferManager& bm = Kernel::Instance().GetBufferManager();
		/* 
		 * ��������²�����ִ��I/O�����������൱��ģ������ж�
		 * ��������е���IODone()���ѵȴ�I/O���������Ľ��̡�
		 */
		return 0;	/* GCC likes it ! */
	}

	/* ��bp����I/O������еĶ�β����ʱI/O�����Ѿ��˻�����������ʽ����bp->av_forw��־�������β */
	bp->av_forw = NULL;

	/* ���²����������ٽ����������ٽ���ԴΪ���豸��g_Atab��
	 * ��Ϊ���������Կ��豸��g_Atab��I/O������н��в�����
	 * �����жϴ������Ҳ���I/O�����������в����������ǲ��еġ�
	 * ʵ��������ֻ��ر�Ӳ�̵��жϾͿ����ˡ�
	 */
	if(this->d_tab->d_actf == NULL)	//���IO�������Ϊ�գ�ֱ�Ӳ��ڶ���
	{
		this->d_tab->d_actf = bp;
	}
	else	//���IO������в�Ϊ��
	{
		this->d_tab->d_actl->av_forw = bp;	//�������ڵ�IO������ж�β�ĺ���
	}
	this->d_tab->d_actl = bp;	//�²����bp��Ϊ�µĶ�β

	/* ���Ӳ�̲�æ����������Ӳ�̲��������򽫵�ǰI/O��������
	 * ���豸��I/O�������֮��ֱ�ӷ��أ���ǰ���̵�I/O������ɺ�
	 * ����CPU���������жϣ�ϵͳ���ڴ����жϴ��������ִ�п��豸
	 * ��I/O��������е���һ��I/O����
	 */
	if(this->d_tab->d_active == 0)		/* ���̿��� */
	{
		this->Start();
	}

	return 0;	/* GCC likes it ! */
}

void ATABlockDevice::Start()
{
	Buf* bp;

	if( (bp = this->d_tab->d_actf) == 0 )
		return;		/* ���I/O�������Ϊ�գ����������� */

	this->d_tab->d_active++;	/* I/O������в��գ����ÿ�����æ��־ */

	/* ���ô��̼Ĵ���������I/O���� */
	ATADriver::DevStart(bp);
}
