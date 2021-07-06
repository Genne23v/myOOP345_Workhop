// Workshop 6: Part 2
// Date: 2021/07/06
// Author: Wonkeun No
// Student #: 145095196
// Description:
// Utilities.cpp
///////////////////////////////////////////////////
// I have done all the coding by myself and only copied the code that my professor
// provided to complete my workshops and assignments.
///////////////////////////////////////////////////
#include <sstream>
#include "Utilities.h"
#include "Car.h"
#include "Racecar.h"

namespace sdds
{
	Vehicle* createInstance(std::istream& in)
	{
		Vehicle* vehicle = nullptr;
		std::string line, firstElem;
		
		std::getline(in, firstElem, ',');
		std::string tag = removeSpaces(firstElem);

		std::getline(in, line);
		std::istringstream iStrStream(line);
		
		if (tag == "c" || tag == "C")
		{
			vehicle = new Car(iStrStream);
		}
		else if (tag == "r" || tag == "R")
		{
			vehicle = new Racecar(iStrStream);
		}
		else
		{
			throw std::invalid_argument("Unrecognized record type: [" + tag + "]");
		}
		return vehicle;
	}
}

