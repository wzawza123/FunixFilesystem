#include "Kernel.h"
#include "Diagnosis.h"
// #include "Machine.h"
// #include "New.h"
// #include "Video.h"

Kernel Kernel::instance;

/* 
 * 内存管理相关的全局manager
 */
// UserPageManager g_UserPageManager(&(Allocator::GetInstance()));
// KernelPageManager g_KernelPageManager(&(Allocator::GetInstance()));
// KernelAllocator g_KernelAllocator(&(Allocator::GetInstance()));

/*
 * 交换区相关全局manager
 */
// SwapperManager g_SwapperManager(&(Allocator::GetInstance()));

/* 
 * 进程相关全局manager
 */
// ProcessManager g_ProcessManager;

/*
 * 设备管理、高速缓存管理全局manager
 */
BufferManager g_BufferManager;
DeviceManager g_DeviceManager;

/*
 * 文件系统相关全局manager
 */
// FileSystem g_FileSystem;
// FileManager g_FileManager;

Kernel::Kernel()
{
}

Kernel::~Kernel()
{
}

Kernel& Kernel::Instance()
{
	return Kernel::instance;
}

void Kernel::InitBuffer()
{
	this->m_BufferManager = &g_BufferManager;
	this->m_DeviceManager = &g_DeviceManager;

	Diagnose::Write("Initialize Buffer...");
	this->GetBufferManager().Initialize();
	Diagnose::Write("OK.\n");

	Diagnose::Write("Initialize Device Manager...");
	this->GetDeviceManager().Initialize();
	Diagnose::Write("OK.\n");
}

void Kernel::InitFileSystem()
{
	// this->m_FileSystem = &g_FileSystem;
	// this->m_FileManager = &g_FileManager;

	// Diagnose::Write("Initialize File System...");
	// this->GetFileSystem().Initialize();
	// Diagnose::Write("OK.\n");

	// Diagnose::Write("Initialize File Manager...");
	// this->GetFileManager().Initialize();
	// Diagnose::Write("OK.\n");
}

void Kernel::Initialize()
{
	InitBuffer();
	InitFileSystem();
}


BufferManager& Kernel::GetBufferManager()
{
	return *(this->m_BufferManager);
}

DeviceManager& Kernel::GetDeviceManager()
{
	return *(this->m_DeviceManager);
}

// FileSystem& Kernel::GetFileSystem()
// {
// 	return *(this->m_FileSystem);
// }

// FileManager& Kernel::GetFileManager()
// {
// 	return *(this->m_FileManager);
// }

// User& Kernel::GetUser()
// {
// 	return *(User*)USER_ADDRESS;
// }
