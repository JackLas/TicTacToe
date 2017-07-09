#include "Timer.hpp"
#include <to_string.hpp>

Timer::Timer()
{
	seconds = 0.f;
	minutes = 0.f;
	seconds = 0.f;
}

Timer::~Timer()
{

}

int Timer::removeExcess(float &timeVar)
{
	int num = 0;

	timeVar -= 60;
	num++;

	if((int)timeVar > 60)
		removeExcess(timeVar);
	return num;
}

void Timer::update(float elapsedTime)
{
	seconds += elapsedTime;

	if(seconds > 60.f)
	{
		minutes += removeExcess(seconds);

		if(minutes > 60.f)
			hours += removeExcess(minutes);
	}
}

std::string Timer::getString()
{
	std::string secStr;
	if(seconds < 10)
		secStr = "0" + to_string((int)seconds);
	else secStr = to_string((int)seconds);

	std::string minStr;
	if(minutes < 10)
		minStr = "0" + to_string((int)minutes);
	else minStr = to_string((int)minutes);

	std::string hourStr;
	if(hours < 10)
		hourStr = "0" + to_string((int)hours);
	else hourStr = to_string((int)hours);

	return hourStr + "|" + minStr + "|" + secStr;
}