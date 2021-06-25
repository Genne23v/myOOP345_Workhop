// Workshop 5: Part 2
// Date: 2021/06/25
// Author: Wonkeun No
// Student #: 145095196
// Description:
// SpellChecker.cpp
///////////////////////////////////////////////////
// I have done all the coding by myself and only copied the code that my professor
// provided to complete my workshops and assignments.
///////////////////////////////////////////////////
#include <fstream>
//#include <string>

//#include <cerrno>
#include "SpellChecker.h"

namespace sdds
{
	SpellChecker::SpellChecker(const char* filename)
	{
		std::ifstream file(filename);
		std::string tmp[12];

			if (file)
			{
				for (auto i = 0; i < 12; i++)
					file >> tmp[i];

				int j = 0, k = 0;
				for (auto i = 0; i < 12; i++)
				{
					if (i % 2 == 0)
					{
						m_badWords[j++] = tmp[i];
					}
					else 
					{
						m_goodWords[k++] = tmp[i];
					}
					
				}
			}
			else
			{
				throw "Bad file name!";
			}
	}

	//unsigned int findCnt = 0;
	void SpellChecker::operator()(std::string& text)
	{
		
		for (auto i = 0; i < ARRAY_SIZE; i++)
		{
			bool found = false;
			do
			{
				found = false;
				if (text.find(m_badWords[i]) != std::string::npos)
				{
					text.replace(text.find(m_badWords[i]), m_badWords[i].length(), m_goodWords[i]);
					found = true;
					m_correction[i]++;
				}

			} while (found);
		}
	}
	void SpellChecker::showStatistics(std::ostream& out) const
	{
		out << "Spellchecker Statistics" << std::endl;
		for (auto i = 0; i < ARRAY_SIZE; i++)
		{
			out.width(15);
			out.setf(std::ios::right);
			out << m_badWords[i] << ": " << m_correction[i] << " replacements" << std::endl;
		}
	}
}