#include <functional>
#include <thread>
#include <chrono>

/*
  Weston McNamara

  The idea here is basically dump a function onto a new thread that waits the specified seconds, and then call the funciton.

  https://www.codewars.com/kata/607c60d84dcfb40056991042
*/

void SeperateThreadSleep(int seconds, std::function<void()> func)
{
	std::this_thread::sleep_for(std::chrono::seconds(seconds));
	func();
}

class Timer 
{
public:
	explicit Timer(int seconds, std::function<void()> func) : mSeconds(seconds), mFunc(func) {}
	void Start();

private:

	int mSeconds;
	std::function<void()> mFunc;
};

void Timer::Start() 
{
	std::thread thr(SeperateThreadSleep, mSeconds, mFunc);
	thr.detach();
}