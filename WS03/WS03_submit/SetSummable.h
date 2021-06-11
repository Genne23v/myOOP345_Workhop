// Workshop 3: Part 2
// Date: 2021/06/11
// Author: Wonkeun No
// Student #: 145095196
// Description:
// SetSummable.h
///////////////////////////////////////////////////
// I have done all the coding by myself and only copied the code that my professor
// provided to complete my workshops and assignments.
///////////////////////////////////////////////////
#ifndef SET_SUMMABLE_H
#define SET_SUMMABLE_H
#include <string>
#include "Set.h"

namespace sdds
{
	template<unsigned int N, typename T>
	class SetSummable : public Set<N, T>
	{
	public:
		SetSummable() {};
		T accumulate(const std::string& filter) const;
	};

	template<unsigned int N, typename T>
	T SetSummable<N, T>::accumulate(const std::string& filter) const
	{
		T tmp(filter);

		for (size_t i = 0; i< Set<N, T>::size(); i++)
		{
			if (this->get(i).isCompatibleWith(tmp))
			{
				tmp+= Set<N, T>::get(i);
			}
		}
		return tmp;
	}
}
#endif // !SET_SUMMABLE_H

