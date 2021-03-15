#pragma once
#include <iostream>
#define CAutoIsHere

class CAuto
{
public:
	CAuto();
	~CAuto();
private:
	int maximum;
	int minimum;
	int currentNum;
public:
	int AutoSearch();
	void Reset();
	void Setmaximum(int max);
	void SetTIOC(bool TIOC); // targetIsOverCur
	

};

