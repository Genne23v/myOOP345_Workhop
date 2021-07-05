#ifndef SDDS_AUTOSHOP_H
#define SDDS_AUTOSHOP_H
#include <vector>
#include <iostream>
#include "Vehicle.h"

namespace sdds
{
	class Autoshop
	{
		std::vector<Vehicle*>m_vehicles;
	public:
		Autoshop& operator+=(Vehicle* theVehicle);
		void display(std::ostream& out) const;
		~Autoshop();
	};
}
#endif // !SDDS_AUTOSHOP_H

