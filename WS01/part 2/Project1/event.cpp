#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "event.h"

namespace sdds 
{
	Event::Event()
	{
		m_event = nullptr;
		m_time = 0;
	}
	Event::Event(Event& src)
	{
		m_time = src.m_time;
		if (src.m_event != nullptr)
		{
			m_event = new char[strlen(src.m_event) + 1];
			strcpy(m_event, src.m_event);
		}
		else
		{
			m_event = nullptr;
		}
	}
	Event::~Event()
	{
		if (m_event != nullptr)
			delete[] m_event;
	}
	void Event::operator=(Event& src)
	{
		if (this != &src && src.m_event != nullptr)
		{
			m_time = src.m_time;
			m_event = new char[strlen(src.m_event) + 1];
			strcpy(m_event, src.m_event);
		}
	}
	void Event::set()
	{
		delete[] m_event;
		m_event = nullptr;
		m_time = 0;
	}
	void Event::set(char* buf)
	{
		if (buf != nullptr)
		{
			delete[] m_event;
			m_event = new char[strlen(buf) + 1];
			strcpy(m_event, buf);
			m_time = g_sysClock;
		} 
		else
		{
			m_event = nullptr;
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
		if (this->m_event != nullptr)
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
		}
		else
		{
			std::cout << counter << ". | No Event |" << std::endl;
		}
		counter++;
	}

}
