// Workshop 3: Part 2
// Date: 2021/06/11
// Author: Wonkeun No
// Student #: 145095196
// Description:
// PairSummable.h
///////////////////////////////////////////////////
// I have done all the coding by myself and only copied the code that my professor
// provided to complete my workshops and assignments.
///////////////////////////////////////////////////
#ifndef PAIR_SUMMABLE_H
#define PAIR_SUMMABLE_H
#include <iostream>
#include <string>
#include <typeinfo>
#include "Pair.h"

namespace sdds
{
	template <typename V, typename K>
	class PairSummable : public Pair<V, K>
	{
		static V m_initial;
		static size_t m_minField;
	public:
		PairSummable() {};
		PairSummable(const K& key, const V& value = m_initial);
		bool isCompatibleWith(const PairSummable<V, K>& b) const;
		PairSummable& operator+=(const PairSummable& src);
		void display(std::ostream& os) const;
	};

	template <typename V, typename K>
	V PairSummable<V, K>::m_initial;
	template <typename V, typename K>
	size_t PairSummable<V, K>::m_minField;

	template <typename V, typename K>
	PairSummable<V, K>::PairSummable(const K& key, const V& value) : Pair<V, K>(key, value)
	{

		if (m_minField < key.size())
		{
			m_minField = key.size();
		}
	}

	template <typename V, typename K>
	bool PairSummable<V, K>::isCompatibleWith(const PairSummable<V, K>& b) const
	{
		bool same = false;

		if (Pair<V, K>::key() == b.key())
		{
			same = true;
		}
		return same;
	}

	template <typename V, typename K>
	PairSummable<V, K>& PairSummable<V, K>::operator+=(const PairSummable<V, K>& src)
	{
		Pair<V, K>::updateValue(src.value());
		return *this;
	}
	template <>
	PairSummable<std::string, std::string>& PairSummable<std::string, std::string>::operator+=(const PairSummable<std::string, std::string>& src)
	{
		Pair<std::string, std::string>::updateValue(src.value());
		return *this;
	}

	template <typename V, typename K>
	void PairSummable<V, K>::display(std::ostream& os) const
	{
		os.setf(std::ios::left);
		os.width(m_minField);
		Pair<V, K>::display(os);
	}
}
#endif // !PAIR_SUMMABLE_H

