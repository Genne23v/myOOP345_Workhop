// Workshop 5: Part 2
// Date: 2021/06/25
// Author: Wonkeun No
// Student #: 145095196
// Description:
// SpellChecker.h
///////////////////////////////////////////////////
// I have done all the coding by myself and only copied the code that my professor
// provided to complete my workshops and assignments.
///////////////////////////////////////////////////
#ifndef SDDS_SPELL_CHECKER_H
#define SDDS_SPELL_CHECKER_H

#include <string>
#include <iostream>
#define ARRAY_SIZE 6

namespace sdds
{
	class SpellChecker
	{
		std::string m_badWords[ARRAY_SIZE];
		std::string m_goodWords[ARRAY_SIZE];
		unsigned int m_correction[ARRAY_SIZE]{0,};
	public:
		SpellChecker(const char* filename);
		void operator()(std::string& text);
		void showStatistics(std::ostream& out) const;
	};
}
#endif // !SDDS_SPELL_CHECKER_H

