// Workshop 5: Part 2
// Date: 2021/06/25
// Author: Wonkeun No
// Student #: 145095196
// Description:
// Book.h
///////////////////////////////////////////////////
// I have done all the coding by myself and only copied the code that my professor
// provided to complete my workshops and assignments.
///////////////////////////////////////////////////
#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H
#include <iostream>
#include <string>

namespace sdds
{
	//template <class S>
	class Book
	{
		std::string m_author;
		std::string m_title;
		std::string m_country;
		size_t m_year = 0;
		double m_price = 0;
		std::string m_desc;
	public:
		Book() {};
		const std::string& title() const;
		const std::string& country() const;
		const size_t& year() const;
		double& price(double& num);	//CAN I CHANGE THIS?
		Book(const std::string& strBook);

		template <class T>
		void fixSpelling(T& spellChecker);

		friend std::ostream& operator<<(std::ostream& os, const Book& src);
	};

	template <class T>
	void Book::fixSpelling(T& spellChecker)
	{
		//spellChecker(m_title);
		spellChecker(m_desc);
	}

	std::string removeSpaces(std::string str);
}
#endif // !SDDS_BOOK_H

