#pragma once
#ifndef TIMED_EVENTS
#define TIMED_EVENTS
#include <chrono>
#include <iostream>

namespace sdds
{
	struct Event
	{
		char* m_eventName = nullptr;
		char* m_unitsOfTime = nullptr;
		std::chrono::steady_clock::duration m_duration;
		~Event();
	};

	class TimedEvents
	{
		Event m_event[10];
		int numOfRecords=0;
		std::chrono::steady_clock::time_point m_startTime;
		std::chrono::steady_clock::time_point m_endTime;
	public:
		TimedEvents() {};
		~TimedEvents() {};
		void startClock();
		void stopClock();
		void addEvent(const char* event);
		int getNumOfRecords() const;
		friend std::ostream& operator<<(std::ostream& os, const TimedEvents& src);
	};
}

#endif // !TIMED_EVENTS



