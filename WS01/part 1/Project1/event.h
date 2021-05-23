#pragma once
#ifndef __EVENT_H__
#define __EVENT_H__

extern unsigned int g_sysClock;

namespace sdds
{
	class Event
	{
		char m_event[128];
		unsigned int m_time;
	public:
		Event();
		Event(Event& src);
		//~Event();
		void set();
		void set(char* buf);
		void display();
		//void copy(Event& src);
	};
}

#endif // !__EVENT_H__



