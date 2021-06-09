// Workshop 3: Part 2
// Date: 2021/06/10
// Author: Wonkeun No
// Student #: 145095196
// Description:
// Pair.h
///////////////////////////////////////////////////
// I have done all the coding by myself and only copied the code that my professor
// provided to complete my workshops and assignments.
///////////////////////////////////////////////////
#ifndef PAIR_H
#define PAIR_H
#include <iostream>

namespace sdds
{
	template <typename V, typename K>
	class Pair
	{
		V m_value;
		K m_key;
	public:
		Pair<V, K>() {};
		Pair<V, K>(const K& key, const V& value);
		const V& value() const;
		const K& key() const;
		void display(std::ostream& os) const;
	};

	template <typename V, typename K>
	std::ostream& operator<<(std::ostream& os, const Pair<V, K>& pair) 
	{
		pair.display(os);
		return os;
	}

	template <typename V, typename K>
	Pair<V, K>::Pair(const K& key, const V& value)
	{
		m_key = key;
		m_value = value;
	}

	template <typename V, typename K>
	const V& Pair<V, K>::value() const
	{
		return m_value;
	}

	template <typename V, typename K>
	const K& Pair<V, K>::key() const
	{
		return m_key;
	}

	template <typename V, typename K>
	void Pair<V, K>::display(std::ostream& os) const
	{
		os << m_key << " : " << m_value << std::endl;
	}
}




#endif // !PAIR_H
