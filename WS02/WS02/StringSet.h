#pragma once
#ifndef STRING_SET_H
#define STRING_SET_H
#include <string>

namespace sdds
{
	class StringSet
	{
		std::string *m_content = nullptr;
		size_t numOfStrings = 0;
	public:
		StringSet();
		StringSet(const StringSet& src);
		StringSet(char* nameOfFile);
		~StringSet();
		StringSet& operator=(const StringSet& src);
		size_t size() const;
		std::string operator[](size_t idx) const;
	};
}

#endif // !__STRING_SET_H__
