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
		//m_time = src.m_time;
		m_time = g_sysClock;
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
			m_time = g_sysClock;
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
		static int counter = 1;

		int secs = m_time % 60;
		int mins = ((m_time - secs) / 60) %60;
		int hour = ((m_time - secs) - (mins*60)) / 3600;


		std::cout.width(2);
		std::cout.fill(' ');
		if (this->m_event[0] != '\0')
		{
			std::cout << counter << ". ";
			std::cout.width(2);
			std::cout.fill('0');
			std::cout << hour << ":";
			std::cout.width(2);
			std::cout.fill('0');
			std::cout << mins << ":";
			std::cout.width(2);
			std::cout.fill('0'); 
			std::cout << secs;
			std::cout << " => " << m_event << std::endl;
			//std::cout.unsetf();
		}
		else
		{
			std::cout << counter << ". | No Event |" << std::endl;
		}
		counter++;
	}
	/*void Event::copy(Event& src)
	{

	}*/
}
