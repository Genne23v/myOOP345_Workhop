// Workshop 6: Part 2
// Date: 2021/07/06
// Author: Wonkeun No
// Student #: 145095196
// Description:
// Racecar.h
///////////////////////////////////////////////////
// I have done all the coding by myself and only copied the code that my professor
// provided to complete my workshops and assignments.
///////////////////////////////////////////////////
#ifndef SDDS_RACECAR_H
#define SDDS_RACECAR_H
#include <iostream>
#include "Car.h"

namespace sdds
{
	class Racecar : public Car
	{
		double m_booster = 0.0;
	public:
		Racecar(std::istream& in);
		void display(std::ostream& out) const;
		double topSpeed() const;
	};
}
#endif // !SDDS_RACECAR_H

