#ifndef TIMER_H
#define TIMER_H

#include <string>

class Timer
{
private:
	float seconds;
	float minutes;
	float hours;
public:
	Timer();
	~Timer();

	void update(float elapsedTime);
	std::string getString();
private:
	int removeExcess(float &timeVar);
};

#endif //TIMER_H