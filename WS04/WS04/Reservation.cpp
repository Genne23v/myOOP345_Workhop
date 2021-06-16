#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>
#include "Reservation.h"

namespace sdds
{
	std::string removeSpaces(std::string str)
	{
		//str.erase(std::remove(str.begin(), str.end(), ' '), str.end());
		int strBegin = str.find_first_not_of(' ');
		int strEnd = str.find_last_not_of(' ');

		return str.substr(strBegin, (strEnd - strBegin +1));
	}
	Reservation::Reservation(const std::string& res)
	{
		
		std::istringstream inputStream(res);
		std::string tmpArr[6];
		
		int i = 1;

		while (std::getline(inputStream, tmpArr[i], ','))
		{
			i++;
		}

		int pos = tmpArr[1].find(":");
		tmpArr[0] = tmpArr[1].substr(0, pos);
		tmpArr[1].erase(0, pos + 1);		

		m_reserveId = removeSpaces(tmpArr[0]);
		m_name = removeSpaces(tmpArr[1]);
		m_email = removeSpaces(tmpArr[2]);
		m_numPeople = stoi(tmpArr[3]);
		m_day = stoi(tmpArr[4]);
		m_hour = stoi(tmpArr[5]);
	}

	std::ostream& operator<<(std::ostream& os, const Reservation src)
	{
		os << "Reservation ";
		os.width(10);
		os.setf(std::ios::right);
		os << src.m_reserveId << ": ";

		os.width(20);
		os << src.m_name << "  ";
		os.unsetf(std::ios::right);

		std::string tmp_email = "<" + src.m_email + ">";
		os.setf(std::ios::left); 
		os.width(20);
		os << tmp_email << "    ";

		if (src.m_hour >= 6 && src.m_hour <= 9)
		{
			os << "Breakfast";
		}
		else if (src.m_hour >= 11 && src.m_hour <= 15)
		{
			os << "Lunch";
		}
		else if (src.m_hour >= 17 && src.m_hour <= 21)
		{
			os << "Dinner";
		}
		else 
		{
			os << "Drinks";
		}
		os << " on day " << src.m_day << " @ " << src.m_hour << ":00 for ";

		if (src.m_numPeople == 1)
		{
			os << src.m_numPeople << " person.";
		}
		else if (src.m_numPeople > 1)
		{
			os << src.m_numPeople << " people.";
		}

		return os << std::endl;
	}
}