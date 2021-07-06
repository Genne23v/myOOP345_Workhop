// Workshop 6: Part 2
// Date: 2021/07/07
// Author: Wonkeun No
// Student #: 145095196
// Description:
// Autoshop.cpp
///////////////////////////////////////////////////
// I have done all the coding by myself and only copied the code that my professor
// provided to complete my workshops and assignments.
///////////////////////////////////////////////////
#include "Autoshop.h"

namespace sdds
{
	Autoshop& Autoshop::operator+=(Vehicle* theVehicle)
	{
		m_vehicles.push_back(theVehicle);
		return *this;
	}
	void Autoshop::display(std::ostream& out) const
	{

		out << "--------------------------------" << std::endl;
		out << "| Cars in the autoshop!        |" << std::endl;
		out << "--------------------------------" << std::endl;

		std::vector<Vehicle*>::iterator i;

		for (auto i = m_vehicles.begin(); i != m_vehicles.end(); i++)
		{
			auto tmp = (*i);
			tmp->display(out);
			out << std::endl;
		}
		
		out << "--------------------------------" << std::endl;
	}
	Autoshop::~Autoshop()
	{
		std::vector<Vehicle*>::iterator it;
		for (auto it = m_vehicles.begin(); it != m_vehicles.end(); it++)
			delete *it;
	}
}