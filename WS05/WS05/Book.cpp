#include <sstream>
#include <string>
#include "Book.h"


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

	/*const std::string& Book::author() const
	{
		return m_author;
	}
	const std::string& Book::description() const
	{
		return m_desc;
	}*/
	std::string removeSpaces(std::string str)
	{
		int strBegin = str.find_first_not_of(' ');
		int strEnd = str.find_last_not_of(' ');

		return str.substr(strBegin, (strEnd - strBegin + 1));
	}
	Book::Book(const std::string& strBook)
	{
		std::istringstream inputStream(strBook);
		std::string tmpArr[6];

		int i = 0; 
		while (i<6)
		{
			if (i < 5)
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

		if (src.m_price >= 100)
		{
			os.precision(5);
		}
		else
		{
			os.precision(4);
		}
		os << src.m_price;
		os << " | " << src.m_desc << std::endl;

		return os;
	}
	
}