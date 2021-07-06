// Workshop 6: Part 2
// Date: 2021/07/07
// Author: Wonkeun No
// Student #: 145095196
// Description:
// Car.h
///////////////////////////////////////////////////
// I have done all the coding by myself and only copied the code that my professor
// provided to complete my workshops and assignments.
///////////////////////////////////////////////////
#ifndef SDDS_CAR_H
#define SDDS_CAR_H
#include <string>
#include <iostream>
#include "Vehicle.h"

namespace sdds
{
	class Car : public Vehicle
	{
		std::string m_maker;
		std::string m_condition;
		double m_topSpeed;
	public:
		Car(std::istream& is);
		~Car() {};
		std::string condition() const;
		double topSpeed() const;
		void display(std::ostream& out) const;
	};

	std::string removeSpaces(std::string str);
}
#endif // !SDDS_CAR_H

