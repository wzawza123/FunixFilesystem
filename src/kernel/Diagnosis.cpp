#include "Diagnosis.h"

Diagnose::Diagnose()
{
	//全部都是static成员变量，所以没有什么需要在构造函数中初始化的。
}

Diagnose::~Diagnose()
{
	//this is an empty dtor
}

/*
	能够输出格式化后的字符串，目前只能识别一些%d %x  %s 和%n;
	没有检查错误功能，% 和 值匹配要自己注意。
*/
void Diagnose::Write(const std::string &content)
{
	std::cout << content;
}
