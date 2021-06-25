// Workshop 5: Part 2
// Date: 2021/06/25
// Author: Wonkeun No
// Student #: 145095196
// Description:
// Book.cpp
///////////////////////////////////////////////////
// I have done all the coding by myself and only copied the code that my professor
// provided to complete my workshops and assignments.
///////////////////////////////////////////////////
#include <sstream>
#include <string>
#include "Book.h"
#define BOOK_ARR 6

namespace sdds
{
	
	const std::string& Book::title() const
	{
		return m_title;
	}
	
	const std::string& Book::country() const
	{
		return m_country;
	}
	
	const size_t& Book::year() const
	{
		return m_year;
	}
	
	double& Book::price(double& num)
	{
		m_price*= num;
		return m_price;
	}
	
	
	
	Book::Book(const std::string& strBook)
	{
		std::istringstream inputStream(strBook);
		std::string tmpArr[BOOK_ARR];

		int i = 0; 
		while (i<BOOK_ARR)
		{
			if (i < BOOK_ARR-1)
			{
				std::getline(inputStream, tmpArr[i], ',');
			}
			else
			{
				std::getline(inputStream, tmpArr[i]);
			}
			i++;
		}

		m_author = removeSpaces(tmpArr[0]);
		m_title = removeSpaces(tmpArr[1]);
		m_country = removeSpaces(tmpArr[2]);
		m_price = stod(tmpArr[3]);
		m_year = stoi(tmpArr[4]);
		m_desc = removeSpaces(tmpArr[5]);
	}
	
	std::ostream& operator<<(std::ostream& os, const Book& src) 
	{
		os.width(20);
		os << src.m_author << " | ";
		
		os.setf(std::ios::right);
		os.width(22);
		os << src.title() << " | ";
		os.width(5);
		os << src.country() << " | " << src.year() << " | ";
		os.width(6);

		os.setf(std::ios::fixed);
			os.precision(2);
		os << src.m_price;
		os << " | " << src.m_desc << std::endl;

		return os;
	}
	
}