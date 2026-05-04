#pragma once

#include <chrono>

class Clock {
	public:
		Clock();
		~Clock() = default;

		float getElapsedSeconds();
		float getElapsedMiliseconds();

		float restart();
	private:
		std::chrono::steady_clock::time_point startTime;
};