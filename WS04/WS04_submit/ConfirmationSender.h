// Workshop 4: Part 2
// Date: 2021/06/19
// Author: Wonkeun No
// Student #: 145095196
// Description:
// ConfirmationSender.h
///////////////////////////////////////////////////
// I have done all the coding by myself and only copied the code that my professor
// provided to complete my workshops and assignments.
///////////////////////////////////////////////////
#ifndef SDDS_CONFIRMATION_SENDER_H
#define SDDS_CONFIRMATION_SENDER_H
#include <iostream>
#include "Reservation.h"

namespace sdds
{
	class ConfirmationSender
	{
		const Reservation** m_reservation{ nullptr };
		size_t m_size=0;
	public:
		ConfirmationSender() {};
		~ConfirmationSender();
		ConfirmationSender(const ConfirmationSender& src);
		ConfirmationSender(ConfirmationSender&& src) noexcept;
		ConfirmationSender& operator=(const ConfirmationSender& src);
		ConfirmationSender& operator=(ConfirmationSender&& src) noexcept;
		ConfirmationSender& operator+=(const Reservation& res);
		ConfirmationSender& operator-=(const Reservation& res);
		friend std::ostream& operator<<(std::ostream& os, const ConfirmationSender& src);
	};
}

#endif // !SDDS_CONFIRMATION_SENDER_H
