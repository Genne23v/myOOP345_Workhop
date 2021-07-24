// Workshop 7: Part 2
// Date: 2021/07/15
// Author: Wonkeun No
// Student #: 145095196
// Description:
// SongCollection.h
///////////////////////////////////////////////////
// I have done all the coding by myself and only copied the code that my professor
// provided to complete my workshops and assignments.
///////////////////////////////////////////////////
#ifndef SDDS_UTILITIES_H
#define SDDS_UTILITIES_H
// Workshop 8 - Smart Pointers
// 2019/11 - Cornel


#include "List.h"
#include "Element.h"

namespace sdds {
	List<Product> mergeRaw(const List<Description>& desc, const List<Price>& price);
}

#endif