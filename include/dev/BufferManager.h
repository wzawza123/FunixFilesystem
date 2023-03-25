#ifndef BUFFER_MANAGER_H
#define BUFFER_MANAGER_H

#include "Buf.h"
#include "DeviceManager.h"

class BufferManager
{
public:
	/* static const member */
	static const int NBUF = 15;			/* ������ƿ顢������������ */
	static const int BUFFER_SIZE = 512;	/* ��������С�� ���ֽ�Ϊ��λ */

public:
	BufferManager();	//���캯��
	~BufferManager();	//��������
	
	void Initialize();					/* ������ƿ���еĳ�ʼ������������ƿ���b_addrָ����Ӧ�������׵�ַ��*/
	
	Buf* GetBlk(short dev, int blkno);	/* ����һ�黺�棬���ڶ�д�豸dev�ϵ��ַ���blkno��*/
	void Brelse(Buf* bp);				/* �ͷŻ�����ƿ�buf */

	Buf* Bread(short dev, int blkno);	/* ��һ�����̿顣devΪ�������豸�ţ�blknoΪĿ����̿��߼���š� */
	Buf* Breada(short adev, int blkno, int rablkno);	/* ��һ�����̿飬����Ԥ����ʽ��
														 * adevΪ�������豸�š�blknoΪĿ����̿��߼���ţ�ͬ����ʽ��blkno��
														 * rablknoΪԤ�����̿��߼���ţ��첽��ʽ��rablkno�� */
	void Bwrite(Buf* bp);				/* дһ�����̿� */
	void Bdwrite(Buf* bp);				/* �ӳ�д���̿� */
	void Bawrite(Buf* bp);				/* �첽д���̿� */

	void ClrBuf(Buf* bp);				/* ��ջ��������� */
	void Bflush(short dev);				/* ��devָ���豸�������ӳ�д�Ļ���ȫ����������� */
	Buf& GetBFreeList();				/* ��ȡ���ɻ�����п��ƿ�Buf�������� */

private:
	void DetachNode(Buf* bp);				/* �����ɶ�����ժ��ָ���Ļ�����ƿ�buf */
	Buf* InCore(short adev, int blkno);	/* ���ָ���ַ����Ƿ����ڻ����� */
	
private:
	Buf bFreeList;						/* ���ɻ�����п��ƿ� */
	Buf m_Buf[NBUF];					/* ������ƿ����� */
	unsigned char Buffer[NBUF][BUFFER_SIZE];	/* ���������� */
	
	DeviceManager* m_DeviceManager;		/* ָ���豸����ģ��ȫ�ֶ��� */
};

#endif