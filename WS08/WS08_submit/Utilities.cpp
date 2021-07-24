// Workshop 8 - Smart Pointers
// 2019/11 - Cornel
// Workshop 8: Part 2
// Date: 2021/07/24
// Author: Wonkeun No
// Student #: 145095196
// Description:
// Utilities.cpp
///////////////////////////////////////////////////
// I have done all the coding by myself and only copied the code that my professor
// provided to complete my workshops and assignments.
///////////////////////////////////////////////////
#include <memory>
#include "List.h"
#include "Element.h"
#include "Utilities.h"

using namespace std;

namespace sdds {
	List<Product> mergeRaw(const List<Description>& desc, const List<Price>& price) {
		List<Product> priceList;
		Product* tmpProduct = nullptr;

		for (size_t i = 0; i < desc.size(); i++)
		{
			for (size_t j = 0; j < price.size(); j++)
			{
				if (desc[i].code == price[j].code)
				{
					try
					{
						tmpProduct = new Product(desc[i].desc, price[j].price);
						tmpProduct->validate();
						priceList += *tmpProduct;
						delete tmpProduct;
					}
					catch (...)
					{
						throw std::string("*** Negative prices are invalid ***");
					}
				}
			}
		}
		return priceList;
	}

	List<Product> mergeSmart(const List<Description>& desc, const List<Price>& price) {
		List<Product> priceList;
		
		for (size_t i = 0; i < desc.size(); i++)
		{
			for (size_t j = 0; j < price.size(); j++)
			{
				if (desc[i].code == price[j].code)
				{
					try
					{
						std::unique_ptr<Product> tmpProduct(new Product(desc[i].desc, price[j].price));
						tmpProduct->validate();
						priceList += *tmpProduct;
					}
					catch (...)
					{
						throw std::string("*** Negative prices are invalid ***");
					}
				}
			}
		}
		return priceList;
	}
}