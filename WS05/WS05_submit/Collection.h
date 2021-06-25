// Workshop 5: Part 2
// Date: 2021/06/25
// Author: Wonkeun No
// Student #: 145095196
// Description:
// Collection.h
///////////////////////////////////////////////////
// I have done all the coding by myself and only copied the code that my professor
// provided to complete my workshops and assignments.
///////////////////////////////////////////////////
#ifndef SDDS_COLLECTION_H
#define SDDS_COLLECTION_H
#include <string>
#include <iostream>
#include <stdexcept>

namespace sdds
{
	template <class T>
	class Collection
	{
		std::string m_name;
		T* m_arr{ nullptr };
		size_t m_size = 0;
		void (*observerFunc)(const Collection<T>&, const T&) { nullptr };
	public:
		Collection(const std::string& name);
		~Collection();
		const std::string& name() const;
		size_t size() const;
		void setObserver(void (*observer)(const Collection<T>&, const T&));
		Collection<T>& operator+=(const T& item);
		T& operator[](size_t idx) const;
		T* operator[](const std::string& title) const;
	};

	template <class T>
	Collection<T>::Collection(const std::string& name)
	{
		m_name = name;
	}
	template <class T>
	Collection<T>::~Collection()
	{
		delete[] m_arr;
	}
	template <class T>
	const std::string& Collection<T>::name() const
	{
		return m_name;
	}
	template <class T>
	size_t Collection<T>::size() const
	{
		return m_size;
	}
	template <class T>
	void Collection<T>::setObserver(void(*observer)(const Collection<T>&, const T&))
	{
		observerFunc = observer;
	}
	template <class T>
	Collection<T>& Collection<T>::operator+=(const T& item)
	{
		bool exist = false;

		for (size_t i = 0; i < size(); i++)
		{
			if (m_arr[i].title() == item.title())
			{
				exist = true;
			}
		}
		if (!exist)
		{
			if (m_arr != nullptr)
			{
				T* tmpArr = nullptr;
				tmpArr = new T[m_size];

				for (size_t i = 0; i < size(); i++)
				{
					tmpArr[i] = m_arr[i];
				}
				
				if (m_size == 1)
					delete m_arr;
				else
					delete[]m_arr;
				m_size++;
				m_arr = new T[m_size];

				for (size_t i = 0; i < size() - 1; i++)
				{
					m_arr[i] = tmpArr[i];
				}
				m_arr[size() - 1] = item;
				delete[] tmpArr;
			}
			else
			{
				m_arr = new T;
				m_arr[0] = item;
				m_size++;
			}
			
			if (observerFunc != nullptr)
				observerFunc(*this, item);
		}
			return *this;
	}
	template <class T>
	T& Collection<T>::operator[](size_t idx) const
	{
		if (idx >= size() || idx < 0)
		{
			throw std::out_of_range("Bad index [" + std::to_string(idx) + "]. Collection has [" + std::to_string(m_size) + "] items.");
		}

		return m_arr[idx];
	}
	template <class T>
	T* Collection<T>::operator[](const std::string& title) const
	{
		T* tmp = nullptr;

		for (size_t i = 0; i < size(); i++)
		{
			if (m_arr[i].title() == title)
			{
				tmp = &m_arr[i];
			}
		}
		return tmp;
	}
	template <class T>
	std::ostream& operator<<(std::ostream& os, const Collection<T>& src)
	{
		for (size_t i = 0; i < src.size(); i++)
		{
			os << src[i];
		}
		return os;
	}
}
#endif // !SDDS_COLLECTION_H
