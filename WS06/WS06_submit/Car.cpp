// Workshop 6: Part 2
// Date: 2021/07/07
// Author: Wonkeun No
// Student #: 145095196
// Description:
// Car.cpp
///////////////////////////////////////////////////
// I have done all the coding by myself and only copied the code that my professor
// provided to complete my workshops and assignments.
///////////////////////////////////////////////////
#include <sstream>
#include "Car.h"

namespace sdds
{
	constexpr size_t size = 3;

	std::string removeSpaces(std::string str)
	{
		int strBegin = str.find_first_not_of(' ');
		int strEnd = str.find_last_not_of(' ');

		return str.substr(strBegin, (strEnd - strBegin + 1));
	}

	Car::Car(std::istream& is)
	{
		std::string tmp[size];
		std::string tag;
		size_t i = 0; 
		
		while (i < size)
		{
			std::getline(is, tmp[i], ',');
			i++;
		}

		m_maker = removeSpaces(tmp[0]);
		
		std::string conditionCheck;

		if (tmp[1].find_first_not_of(' ') != std::string::npos)
			conditionCheck = removeSpaces(tmp[1]);

		if (conditionCheck == "n" || conditionCheck == "")
		{
			m_condition = "new";
		}
		else if (conditionCheck == "u")
		{
			m_condition = "used";
		}
		else if (conditionCheck == "b")
		{
			m_condition = "broken";
		}
		else
		{
			throw std::invalid_argument("Invalid record!");
		}
		
		std::istringstream iss(tmp[2]);
		double test = 0.0;
		if (iss >> test)
			m_topSpeed = stod(tmp[2]);
		else
			throw std::invalid_argument("Invalid record!");
	}
	std::string Car::condition() const
	{
		return m_condition;
	}
	double Car::topSpeed() const
	{
		return m_topSpeed;
	}
	void Car::display(std::ostream& out) const
	{
		out << "| ";
		out.setf(std::ios::right);
		out.width(10);
		out << m_maker << " | ";
		out.width(6);
		out.unsetf(std::ios::right);
		out.setf(std::ios::left);
		out << condition() << " | ";
		out.precision(2);
		out.setf(std::ios::fixed);
		out << topSpeed() << " |";
	}
}