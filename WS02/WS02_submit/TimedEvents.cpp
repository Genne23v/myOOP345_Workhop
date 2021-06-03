#define _CRT_SECURE_NO_WARNINGS
#include "TimedEvents.h"
#include <cstring>
#include <iostream>


namespace sdds
{
	Event::~Event()
	{
		delete[] m_eventName;
		delete[] m_unitsOfTime;
	}
	void TimedEvents::startClock()
	{
		m_startTime = std::chrono::steady_clock::now();
	}
	void TimedEvents::stopClock()
	{
		m_endTime = std::chrono::steady_clock::now();
	}
	void TimedEvents::addEvent(const char* event)
	{ 
		if (event != nullptr)
		{
			m_event[numOfRecords].m_eventName = new char[strlen(event) + 1];
			strcpy(m_event[numOfRecords].m_eventName, event);
		}
		
		m_event[numOfRecords].m_unitsOfTime = new char[strlen("nanoseconds") + 1];
		strcpy(m_event[numOfRecords].m_unitsOfTime, "nanoseconds");
		m_event[numOfRecords].m_duration = std::chrono::duration_cast<std::chrono::nanoseconds>(m_endTime - m_startTime);
		numOfRecords++;

	}
	int TimedEvents::getNumOfRecords() const
	{
		return numOfRecords;
	}
	std::ostream& operator<<(std::ostream& os, const TimedEvents& src)
	{
		std::cout << "--------------------------" << std::endl;
		std::cout << "Execution Times:" << std::endl;
		std::cout << "--------------------------" << std::endl;
		
		for (int i = 0; i < src.getNumOfRecords(); i++)
		{
			std::cout.width(21);
			std::cout << src.m_event[i].m_eventName;
			std::cout.width(13);
			std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(src.m_event[i].m_duration).count();
			std::cout << " " << src.m_event[i].m_unitsOfTime << std::endl;	
		}
		std::cout << "--------------------------" << std::endl;

		return os;
	}
}