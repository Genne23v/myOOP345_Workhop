// Workshop 5: Part 2
// Date: 2021/06/25
// Author: Wonkeun No
// Student #: 145095196
// Description:
// Movie.h
///////////////////////////////////////////////////
// I have done all the coding by myself and only copied the code that my professor
// provided to complete my workshops and assignments.
///////////////////////////////////////////////////
#ifndef SDDS_MOVIE_H
#define SDDS_MOVIE_H
#include <string>

namespace sdds
{
	//template <class T>
	class Movie
	{
		std::string m_title;
		size_t m_year=0;
		std::string m_desc;
	public:
		Movie() {};
		const std::string& title() const;
		Movie(const std::string& strMovie);
		friend std::ostream& operator<<(std::ostream& os, const Movie& src);
		
		template <class T>
		void fixSpelling(T& spellChecker);
	};

	template <class T>
	void Movie::fixSpelling(T& spellChecker)
	{
		spellChecker(m_title);
		spellChecker(m_desc);
	}

	std::string removeSpaces(std::string str);
}
#endif // !SDDS_MOVIE_H

