#include <sstream>
#include "Utilities.h"
#include "Car.h"

namespace sdds
{
	Vehicle* createInstance(std::istream& in)
	{
		Vehicle* vehicle;

		char c = ' ';
		in.get(c);

		if (c == 'c' || c == 'C')
		{
			vehicle = new Car(in);
		}
		else
		{
			vehicle = nullptr;
		}
		return vehicle;
	}
}

