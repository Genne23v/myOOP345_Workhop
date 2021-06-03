#include <fstream>
#include <utility>
#include "StringSet.h"

namespace sdds
{
	StringSet::StringSet(const StringSet& src)
	{
		if (src.m_content != nullptr)
		{
			*this = src;
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
	StringSet::StringSet(StringSet&& src)
	{
		if (src.m_content != nullptr)
		{
			*this = std::move(src);
		}
	}
	StringSet& StringSet::operator=(StringSet&& src)
	{
		if (this != &src)
		{
			numOfStrings = src.numOfStrings;
			m_content = std::move(src.m_content);
			src.m_content = nullptr;
		}
		return *this;
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