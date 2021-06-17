// Workshop 4: Part 2
// Date: 2021/06/19
// Author: Wonkeun No
// Student #: 145095196
// Description:
// Restaurant.h
///////////////////////////////////////////////////
// I have done all the coding by myself and only copied the code that my professor
// provided to complete my workshops and assignments.
///////////////////////////////////////////////////
#ifndef SDDS_RESTAURANT_H
#define SDDS_RESTAURANT_H
#include <iostream>
#include "Reservation.h"

namespace sdds
{
	class Restaurant
	{
		const Reservation** m_arr{ nullptr };
		size_t m_size=0;
	public:
		Restaurant(const Reservation* reservation[], size_t cnt);
		size_t size() const;
		friend std::ostream& operator<<(std::ostream& os, const Restaurant& src);
		
		~Restaurant();
		Restaurant(const Restaurant& src);
		Restaurant(Restaurant&& src) noexcept;
		Restaurant& operator=(const Restaurant& src); 
		Restaurant& operator=(Restaurant&& src) noexcept; 
	};
}

#endif // !SDDS_RESTAURANT_H
