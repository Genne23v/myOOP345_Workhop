#include <iostream>
#include <fstream>
#include "StringSet.h"

namespace sdds
{
	StringSet::StringSet()
	{

	}
	StringSet::StringSet(const StringSet& src)
	{
		if (src.m_content != nullptr)
		{
			numOfStrings = src.numOfStrings;

			m_content = new std::string[numOfStrings];
			
			for (size_t i = 0; i < numOfStrings; i++)
			{
				m_content[i] = src.m_content[i];
			}
			
		}
	}
	StringSet::~StringSet()
	{
		delete[] m_content;
		m_content = nullptr;
	}
	StringSet::StringSet(char* nameOfFile)
	{
		std::ifstream file(nameOfFile);
		while (file)
		{
			numOfStrings += (file.get() == ' ');
		}
		numOfStrings++;
		
		m_content = new std::string[numOfStrings];

		file.clear();
		file.seekg(0);
		
		for (size_t i = 0; i < numOfStrings; i++)
		{
			std::getline(file, m_content[i], ' ');
		}
	}
	StringSet& StringSet::operator=(const StringSet& src)
	{
		if (this != &src)
		{
			numOfStrings = src.numOfStrings;

			if (m_content != nullptr)
			{
				delete[] m_content;
			}
				m_content = new std::string[numOfStrings];
				
				for (size_t i = 0; i < numOfStrings; i++)
				{
					m_content[i] = src.m_content[i];
				}
		}
		return *this;
	}
	size_t StringSet::size() const
	{
		return numOfStrings;
	}
	std::string StringSet::operator[](size_t idx) const
	{
		std::string tmp; 
		
		if (m_content != nullptr && idx < numOfStrings)
		{
			tmp = m_content[idx];
		}
		else 
		{
			tmp = "";
		}

		return tmp;
	}
}