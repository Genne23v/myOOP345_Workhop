// Workshop 4: Part 2
// Date: 2021/06/19
// Author: Wonkeun No
// Student #: 145095196
// Description:
// ConfirmationSender.cpp
///////////////////////////////////////////////////
// I have done all the coding by myself and only copied the code that my professor
// provided to complete my workshops and assignments.
///////////////////////////////////////////////////

#include "ConfirmationSender.h"

namespace sdds
{
	ConfirmationSender& ConfirmationSender::operator+=(const Reservation& res)
	{
		bool exist = false;
		const Reservation** tmpPtr = nullptr;

		for (size_t i = 0; i < m_size; i++)
		{
			if (m_reservation[i] == &res)
			{
				exist = true;
			}
		}
				
		if (!exist)
		{
			tmpPtr = new const Reservation*[m_size];

			for (size_t i=0; i < m_size; i++)
				tmpPtr[i] = m_reservation[i];

			delete[] m_reservation;
			m_size++;
			m_reservation = new const Reservation * [m_size];

			for (size_t i = 0; i < m_size-1; i++)
				m_reservation[i] = tmpPtr[i];

			m_reservation[m_size-1] = &res;
		}

		delete[] tmpPtr;
		tmpPtr = nullptr;

		return *this;
	}

	ConfirmationSender& ConfirmationSender::operator-=(const Reservation& res)
	{
		bool exist = false;
		const Reservation** tmpPtr = nullptr;
		size_t index = -999999;
		
		for (size_t i = 0; i < m_size; i++)
		{
			if (m_reservation[i] == &res)
			{
				exist = true;
				index = i;
			}
		}

		if (exist)
		{
			tmpPtr = new const Reservation*[m_size - 1];
			int j = 0;

			for (size_t i = 0; i < m_size; i++)
			{
				if (i != index)
				{
					tmpPtr[j] = m_reservation[i];
					j++;
				}
			}
			
			delete[] m_reservation;
			m_size--;
			m_reservation = new const Reservation * [m_size];

			for (size_t i = 0; i < m_size; i++)
				m_reservation[i] = tmpPtr[i];
		}

		delete[] tmpPtr;
		tmpPtr = nullptr;

		return *this;
	}

	std::ostream& operator<<(std::ostream& os, const ConfirmationSender& src)
	{

		os << "--------------------------" << std::endl;
		os << "Confirmations to Send" << std::endl;
		os << "--------------------------" << std::endl;

		if (src.m_size > 0)
		{
			for (size_t i = 0; i < src.m_size; i++)
			{
				os << *src.m_reservation[i];
			}
		}
		else
		{
			os << "There are no confirmations to send!" << std::endl;
		}
		
		os << "--------------------------" << std::endl;

		return os;
	}

	ConfirmationSender::ConfirmationSender(const ConfirmationSender& src)
	{
		*this = src;
	}
	ConfirmationSender::ConfirmationSender(ConfirmationSender&& src) noexcept
	{
		*this = std::move(src);
	}
	ConfirmationSender& ConfirmationSender::operator=(const ConfirmationSender& src)
	{
		if (this != &src)
		{
			m_size = src.m_size;
			m_reservation = new const Reservation * [m_size];

			for (size_t i = 0; i < m_size; i++)
			{
				m_reservation[i] = src.m_reservation[i];
			}
		}
		return *this;
	}
	ConfirmationSender& ConfirmationSender::operator=(ConfirmationSender&& src) noexcept
	{
		if (this != &src)
		{
			m_size = src.m_size;
			src.m_size = 0;
			m_reservation = new const Reservation * [m_size];

			for (size_t i = 0; i < m_size; i++)
			{
				m_reservation[i] = src.m_reservation[i];
			}
			
			delete[] src.m_reservation;
		}
		return *this;
	}
}