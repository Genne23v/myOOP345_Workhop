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
	};

}
#endif // !SDDS_RESERVATION_H
