// Workshop 5: Part 2
// Date: 2021/06/25
// Author: Wonkeun No
// Student #: 145095196
// Description:
// Movie.cpp
///////////////////////////////////////////////////
// I have done all the coding by myself and only copied the code that my professor
// provided to complete my workshops and assignments.
///////////////////////////////////////////////////
#include <sstream>
#include "Movie.h"
#define MOVIE_ARR 3

namespace sdds
{
	const std::string& Movie::title() const
	{
		return m_title;
	}

	std::string removeSpaces(std::string str)
	{
		int strBegin = str.find_first_not_of(' ');
		int strEnd = str.find_last_not_of(' ');

		return str.substr(strBegin, (strEnd - strBegin + 1));
	}
	
	Movie::Movie(const std::string& strMovie)
	{
		std::istringstream inputStream(strMovie);
		std::string tmpArr[MOVIE_ARR];

		int i = 0;
		while (i < MOVIE_ARR)
		{
			if (i < MOVIE_ARR -1)
			{
				std::getline(inputStream, tmpArr[i], ',');
			}
			else
			{
				std::getline(inputStream, tmpArr[i]);
			}
			i++;
		}

		m_title = removeSpaces(tmpArr[0]);
		m_year = stoi(tmpArr[1]);
		m_desc = removeSpaces(tmpArr[2]);
	}
	
	std::ostream& operator<<(std::ostream& os, const Movie& src)
	{
		os.width(40);
		os << src.title() << " | ";
		os.width(4);
		os << src.m_year << " | " << src.m_desc << std::endl;

		return os;
	}
}