#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "event.h"

namespace sdds 
{
	Event::Event()
	{
		m_event[0] = '\0';
		m_time = 0;
	}
	Event::Event(Event& src)
	{
		m_time = src.m_time;
		strcpy(m_event, src.m_event);
	}
	void Event::set()
	{
		m_event[0] = '\0';
		m_time = 0;
	}
	void Event::set(char* buf)
	{
		if (buf != nullptr)
		{
			strcpy(m_event, buf);
		} 
		else
		{
			m_event[0] = '\0';
			m_time = 0;
		}
	}
	void Event::display()
	{
		//a field of size 2, that holds the number of times that this function has been called
		static int counter;

		std::cout.width(2);
		if (this->m_event[0] != '\0')
		{
			std::cout << counter << ". HH:MM:SS" << "=>" << m_event << std::endl;
		}
		else
		{
			std::cout << counter << ". | No Event |" << std::endl;
		}
	}
	/*void Event::copy(Event& src)
	{

	}*/
}
