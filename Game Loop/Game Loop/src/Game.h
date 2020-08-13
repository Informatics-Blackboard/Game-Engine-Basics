#pragma once

#include <chrono>

#define CLOCK std::chrono::steady_clock
#define TIME_UNIT std::chrono::duration<double, std::ratio<1>>		// Time in seconds, represented as double (milliseconds would be std::milli = std::ratio<1, 1000>)
#define TIME_POINT std::chrono::time_point<CLOCK, TIME_UNIT>
#define DURATION std::chrono::duration<CLOCK, TIME_UNIT>
#define NOW std::chrono::time_point_cast<TIME_UNIT>(CLOCK::now())

class Game
{
public:
	void Init();
	void Run();
	void Cleanup();

	void UpdateGame(TIME_UNIT timestep);
	void DisplayGame();

	void Sleep(TIME_UNIT time);

	bool IsRunning();
	TIME_POINT GetGameTime();
	void SetGameTime(TIME_POINT time);

	static const int updateRate = 30;

private:
	bool mRunning;
	TIME_POINT mGameTime;

};