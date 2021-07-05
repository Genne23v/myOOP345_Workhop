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
		}

	}
}