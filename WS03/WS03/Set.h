// Workshop 3: Part 2
// Date: 2021/06/10
// Author: Wonkeun No
// Student #: 145095196
// Description:
// Set.h
///////////////////////////////////////////////////
// I have done all the coding by myself and only copied the code that my professor
// provided to complete my workshops and assignments.
///////////////////////////////////////////////////
#ifndef SET_H
#define SET_H

namespace sdds
{
	template <unsigned int N, typename T>
	class Set
	{
		size_t m_numElement = 0;
		T m_arr[N];
	public:
		Set<N, T>() {};
		size_t size() const;
		const T& get(size_t idx) const;
		void operator+=(const T& item);
	};


	template <unsigned int N, typename T>
	size_t Set<N, T>::size() const
	{
		return m_numElement;
	}

	template <unsigned int N, typename T>
	const T& Set<N, T>::get(size_t idx) const
	{
		if (idx >= 0 && idx < N)
		return m_arr[idx];
	}

	template <unsigned int N, typename T>
	void Set<N, T>::operator+=(const T& item)
	{
		if (m_numElement < N)
		{
			m_arr[m_numElement] = item;
			m_numElement++;
		}
	}
}

#endif // !SET_H
