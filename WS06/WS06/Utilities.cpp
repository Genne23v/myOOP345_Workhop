#include <sstream>
#include "Utilities.h"
#include "Car.h"

namespace sdds
{
	Vehicle* createInstance(std::istream& in)
	{
		std::string tmpStr;
		Vehicle* vehicle = nullptr;

		char c;
		in.get(c);

		if (c == 'c' || c == 'C')
		{
			vehicle = new Car(in);
		}
				
		return vehicle;
	}
}

