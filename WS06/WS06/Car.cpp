#include "Car.h"

namespace sdds
{
	constexpr size_t size = 4;

	std::string removeSpaces(std::string str)
	{
		int strBegin = str.find_first_not_of(' ');
		int strEnd = str.find_last_not_of(' ');

		return str.substr(strBegin, (strEnd - strBegin + 1));
	}

	Car::Car(std::istream& is)
	{
		std::string tmp[size];

		int i = 0; 
		while (i < size)
		{
			if (i < size - 1)
			{
				std::getline(is, tmp[i], ',');
			}
			else
			{
				std::getline(is, tmp[i]);
			}
			i++;
		}

		m_maker = removeSpaces(tmp[1]);
		
		std::string conditionCheck = removeSpaces(tmp[2]);

		if (conditionCheck == "n")
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
			m_condition = "";
		}
		
		m_topSpeed = stod(removeSpaces(tmp[3]));
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
		out.setf(std::ios::right);
		out.width(10);
		out << m_maker << " | ";
		out.width(6);
		out.unsetf(std::ios::right);
		out.setf(std::ios::left);
		out << condition() << " | ";
		out.precision(2);
		out.setf(std::ios::fixed);
		out << topSpeed() << " | " << std::endl;
	}
}