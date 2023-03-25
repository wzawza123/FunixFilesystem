//Video.h
#ifndef DIAGNOSE_H
#define DIAGNOSE_H

#include<iostream>



class Diagnose
{
public:
	static unsigned int ROWS;

	/* static const member */
	static const unsigned int COLUMNS = 80;
	static const unsigned short COLOR = 0x0B00;	/* char in bright CYAN */
	static const unsigned int SCREEN_ROWS = 25;	/* full screen rows */

public:
	Diagnose();
	~Diagnose();

	static void Write(const std::string& content);
	static void ClearScreen();
};
#endif
