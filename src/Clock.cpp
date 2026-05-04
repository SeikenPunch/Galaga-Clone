#include "Clock.hpp"

Clock::Clock(){
	startTime = std::chrono::steady_clock::now();
}

float Clock::getElapsedSeconds(){
	std::chrono::steady_clock::time_point now = std::chrono::steady_clock::now();
	std::chrono::duration<float> elapsed = now - startTime;

	return elapsed.count();
}

float Clock::getElapsedMiliseconds(){
	std::chrono::steady_clock::time_point now = std::chrono::steady_clock::now();
	std::chrono::duration<float, std::milli> elapsed = now - startTime;

	return elapsed.count();
}

float Clock::restart(){
	std::chrono::steady_clock::time_point now = std::chrono::steady_clock::now();
	std::chrono::duration<float> elapsed = now - startTime;

	startTime = now;

	return elapsed.count();
}