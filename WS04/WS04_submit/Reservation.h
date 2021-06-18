// Workshop 4: Part 2
// Date: 2021/06/19
// Author: Wonkeun No
// Student #: 145095196
// Description:
// Reservation.h
///////////////////////////////////////////////////
// I have done all the coding by myself and only copied the code that my professor
// provided to complete my workshops and assignments.
///////////////////////////////////////////////////
#ifndef SDDS_RESERVATION_H
#define SDDS_RESERVATION_H
#include <string>
#include <iostream>

namespace sdds
{
	class Reservation
	{
		std::string m_reserveId;
		std::string m_name;
		std::string m_email;
		int m_numPeople =0;
		int m_day = 0;
		int m_hour = 0;
	public:
		Reservation() {};
		Reservation(const std::string& res);
		friend std::ostream& operator<<(std::ostream& os, const Reservation src);
		
		Reservation(const Reservation* src);
	};
}
#endif // !SDDS_RESERVATION_H
