// Workshop 5: Part 2
// Date: 2021/06/25
// Author: Wonkeun No
// Student #: 145095196
// Description:
// w5_p2.cpp
///////////////////////////////////////////////////
// I have done all the coding by myself and only copied the code that my professor
// provided to complete my workshops and assignments.
///////////////////////////////////////////////////

#include <iostream>
#include <iomanip>
#include <fstream>
#include "Collection.h"
#include "Collection.h"
#include "Book.h"
#include "Book.h"
#include "Movie.h"
#include "Movie.h"
#include "SpellChecker.h"
#include "SpellChecker.h"

using namespace sdds;

enum AppErrors
{
	CannotOpenFile = 1, 
	BadArgumentCount = 2, 
};

void bookAddedObserver(const Collection<Book>& theCollection,
	const Book& theBook)	
{
	std::cout << "Book \"" << theBook.title() << "\" added!\n";
}

void movieAddedObserver(const Collection<Movie>& theCollection,
	const Movie& theMovie)
{
	std::cout << "Movie \"" << theMovie.title()
		<< "\" added to collection \"" << theCollection.name()
		<< "\" (" << theCollection.size() << " items).\n";
}

int main(int argc, char** argv)
{
	std::cout << "Command Line:\n";
	std::cout << "--------------------------\n";
	for (int i = 0; i < argc; i++)
		std::cout << std::setw(3) << i + 1 << ": " << argv[i] << '\n';
	std::cout << "--------------------------\n\n";

	sdds::Collection<sdds::Book> library("Bestsellers");
	if (argc == 5) {
		
		std::ifstream file(argv[1]);
		if (!file)
		{
			std::cerr << "ERROR: Couldn't open the file - " << argv[1] << std::endl;
			exit(AppErrors::CannotOpenFile);
			return 1;
		}
		std::string tmpStr;

		int i = 0;
		while(i<4)
		{
			std::getline(file, tmpStr);

			if (file)
			{
				if (tmpStr[0] != '#')
				{
					library += Book(tmpStr);
					i++;
				}
			}
		}
		
		library.setObserver(bookAddedObserver);

		do
		{
			std::getline(file, tmpStr);

			if (file)
			{
				library += Book(tmpStr);
			}
		} while (file);

		file.close();
	}
	else
	{
		std::cerr << "ERROR: Incorrect number of arguments.\n";
		exit(AppErrors::BadArgumentCount);
	}

	double usdToCadRate = 1.3;
	double gbpToCadRate = 1.5;

	auto updatePrice = [&usdToCadRate, &gbpToCadRate](Book& book)
	{
		if (book.country() == "US")
		{
			book.price(usdToCadRate);
		}
		else if (book.country() == "UK" && (book.year() >= 1990 && book.year() <= 1999))
		{
			book.price(gbpToCadRate);
		}
	};

	std::cout << "-----------------------------------------\n";
	std::cout << "The library content\n";
	std::cout << "-----------------------------------------\n";
	std::cout << library;
	std::cout << "-----------------------------------------\n\n";

	for (auto i = 0u; i < 7; i++)
	{
		updatePrice(library[i]);
	}


	std::cout << "-----------------------------------------\n";
	std::cout << "The library content (updated prices)\n";
	std::cout << "-----------------------------------------\n";
	std::cout << library;
	std::cout << "-----------------------------------------\n\n";

	Collection<Movie> theCollection("Action Movies");

	Movie movies[5];
	if (argc > 2) {
		
		std::ifstream file(argv[2]);
		if (!file)
		{
			std::cerr << "ERROR: Couldn't open the file - " << argv[2] << std::endl;
			exit(AppErrors::CannotOpenFile);
			return 1;
		}
		std::string tmpStr;

		int i = 0;
		while (i < 5)
		{
			std::getline(file, tmpStr);

			if (file)
			{
				if (tmpStr[0] != '#')
				{
					movies[i] = Movie(tmpStr);
					i++;
				}
			}
		}
	}

	std::cout << "-----------------------------------------\n";
	std::cout << "Testing addition and callback function\n";
	std::cout << "-----------------------------------------\n";
	if (argc > 2) {
		((theCollection += movies[0]) += movies[1]) += movies[2];
		theCollection += movies[1];
		theCollection.setObserver(movieAddedObserver);
		theCollection += movies[3];
		theCollection += movies[3];
		theCollection += movies[4];
	}
	else {
		std::cout << "** No movies in the Collection\n";
	}
	std::cout << "-----------------------------------------\n\n";
	
	std::cout << "-----------------------------------------\n";
	std::cout << "Testing exceptions and operator[]\n";
	std::cout << "-----------------------------------------\n";

	try {

		for (auto i = 0u; i < 10; ++i)
			std::cout << theCollection[i];
	}
	catch (std::out_of_range& err) {
		std::cerr << "** EXCEPTION: " << err.what() << std::endl;
	}

	std::cout << "-----------------------------------------\n\n";


	std::cout << "-----------------------------------------\n";
	std::cout << "Testing the functor\n";
	std::cout << "-----------------------------------------\n";
	
		for (auto i = 3; i < argc; ++i)
		{
			try {

				SpellChecker sp(argv[i]);
				for (auto j = 0u; j < library.size(); ++j)
					library[j].fixSpelling(sp);
				sp.showStatistics(std::cout);

				for (auto j = 0u; j < theCollection.size(); ++j)
					theCollection[j].fixSpelling(sp);
				sp.showStatistics(std::cout);
			}
			catch (const char* err) {
				std::cerr << "** EXCEPTION: " << err << std::endl;
			}
		}

	if (argc < 3) {
		std::cout << "** Spellchecker is empty\n";
		std::cout << "-----------------------------------------\n";
	}
	std::cout << "\n";

	std::cout << "=========================================\n";
	std::cout << "Wrapping up this workshop\n";
	std::cout << "--------------- Movies ------------------\n";
	std::cout << theCollection;
	std::cout << "--------------- Books -------------------\n";
	std::cout << library;
	std::cout << "-----------------------------------------\n";
	std::cout << "Testing operator[] (the other overload)\n";
	std::cout << "-----------------------------------------\n";
	const Movie* aMovie = theCollection["Terminator 2"];
	if (aMovie == nullptr)
		std::cout << "** Movie Terminator 2 not in collection.\n";
	aMovie = theCollection["Dark Phoenix"];
	if (aMovie != nullptr)
		std::cout << "In this collection:\n" << *aMovie;
	std::cout << "-----------------------------------------\n\n";

	return 0;
}
