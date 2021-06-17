// Workshop 4: Part 2
// Date: 2021/06/19
// Author: Wonkeun No
// Student #: 145095196
// Description:
// Restaurant.cpp
///////////////////////////////////////////////////
// I have done all the coding by myself and only copied the code that my professor
// provided to complete my workshops and assignments.
///////////////////////////////////////////////////

#include "Restaurant.h"

namespace sdds
{
	Restaurant::Restaurant(const Reservation* reservation[], size_t cnt) 
	{
		m_arr = new const Reservation*[cnt];
		m_size = cnt;

		for (size_t i = 0; i < size(); i++)
		{
			m_arr[i] = new const Reservation(reservation[i]);
		}
	}

	size_t Restaurant::size() const
	{
		return m_size;
	}

	std::ostream& operator<<(std::ostream& os, const Restaurant& src)
	{
		static int count = 1;

		os << "--------------------------" << std::endl;
		os << "Fancy Restaurant (" << count++ << ")" << std::endl;
		os << "--------------------------" << std::endl;

		if (src.size() > 0)
		{
			for (size_t i = 0; i < src.size(); i++)
			{
				os << *src.m_arr[i];
			}
		}
		else
		{
			os << "This restaurant is empty!" << std::endl;
		}
		os << "--------------------------" << std::endl;

		return os;
	}

	Restaurant::Restaurant(const Restaurant& src)
	{
		*this = src;
	}
	Restaurant::Restaurant(Restaurant&& src) noexcept
	{
		*this = std::move(src);
	}
	Restaurant& Restaurant::operator=(Restaurant&& src) noexcept
	{
		if (this != &src)
		{
			delete[] m_arr;
			m_arr = src.m_arr;
			src.m_arr = nullptr;
			
			m_size = src.m_size;
			src.m_size = 0;
		}
		
		return *this;
	}
	Restaurant& Restaurant::operator=(const Restaurant& src)
	{
		if (this != &src)
		{
			delete[] m_arr;
			m_arr = new const Reservation * [src.m_size];
			m_size = src.m_size;

			for (size_t i = 0; i < size(); i++)
			{
				m_arr[i] = new const Reservation(src.m_arr[i]);
			}
		}
		
		return *this;
	}
}