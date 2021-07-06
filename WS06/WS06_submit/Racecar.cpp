// Workshop 6: Part 2
// Date: 2021/07/07
// Author: Wonkeun No
// Student #: 145095196
// Description:
// Racecar.cpp
///////////////////////////////////////////////////
// I have done all the coding by myself and only copied the code that my professor
// provided to complete my workshops and assignments.
///////////////////////////////////////////////////
#include "Racecar.h"

namespace sdds
{
	Racecar::Racecar(std::istream& in) : Car(in)
	{
		std::string tmp;
		std::getline(in, tmp);

		m_booster = stod(tmp);
	}
	void Racecar::display(std::ostream& out) const
	{
		Car::display(out);
		out << "*";
	}
	double Racecar::topSpeed() const
	{
		return Car::topSpeed() * (1 + m_booster);
	}
}