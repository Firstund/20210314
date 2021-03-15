#include "CAuto.h"

CAuto::CAuto()
{
	maximum = 0;
	minimum = 0;
	currentNum = 0;
}
CAuto::~CAuto()
{
	
}
int CAuto::AutoSearch()
{
	currentNum = (minimum + ((maximum - minimum) / 2));
	return currentNum;
}
void CAuto::Reset()
{
	maximum = 0;
	minimum = 0;
	currentNum = 0;
}
void CAuto::SetTIOC(bool TIOC)
{
	if (TIOC)
	{
		minimum = currentNum;
	}
	else
	{
		maximum = currentNum;
	}

}
void CAuto::Setmaximum(int max)
{
	maximum = max;
}
