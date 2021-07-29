// Workshop 9: Part 2
// Date: 2021/07/29
// Author: Wonkeun No
// Student #: 145095196
// Description:
// SecureData.cpp
///////////////////////////////////////////////////
// I have done all the coding by myself and only copied the code that my professor
// provided to complete my workshops and assignments.
///////////////////////////////////////////////////
#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include <functional>
#include <algorithm>
#include <vector>
#include "SecureData.h"

using namespace std;

namespace w9 {

	void converter(char* t, char key, int n, const Cryptor& c) {
		for (int i = 0; i < n; i++)
			t[i] = c(t[i], key);
	}

	SecureData::SecureData(const char* file, char key, ostream* pOfs)
	{
		ofs = pOfs;

		fstream input(file, std::ios::in);
		if (!input)
			throw string("\n***Failed to open file ") +
			string(file) + string(" ***\n");

		input.seekg(0, std::ios::end);
		nbytes = (int)input.tellg() + 1;

		text = new char[nbytes];

		input.seekg(ios::beg);
		int i = 0;
		input >> noskipws;
		while (input.good())
			input >> text[i++];
		text[nbytes - 1] = '\0';
		*ofs << "\n" << nbytes - 1 << " bytes copied from file "
			<< file << " into memory (null byte added)\n";
		encoded = false;

		code(key);
		*ofs << "Data encrypted in memory\n";
	}

	SecureData::~SecureData() {
		delete[] text;
	}

	void SecureData::display(std::ostream& os) const {
		if (text && !encoded)
			os << text << std::endl;
		else if (encoded)
			throw std::string("\n***Data is encoded***\n");
		else
			throw std::string("\n***No data stored***\n");
	}

	void SecureData::code(char key)
	{
		function<void(char*, char, int, const Cryptor&)> convertFtr = converter;

		vector<char> textContainer(nbytes);
		/*size_t i = 0;
		while (i < nbytes)
		{
			textContainer.push_back(text[i]);
			i++;
		}*/

		size_t qtrPos = nbytes / 4;
		size_t i = 0, j = 0;
		char* text1 = new char[qtrPos];
		while (i < qtrPos)
		{
			text1[j] = text[i];
			i++, j++;
		}
		char* text2 = new char[qtrPos];
		j = 0;
		while (j < qtrPos)
		{
			text2[j] = text[i];
			i++, j++;
		}
		char* text3 = new char[qtrPos];
		j = 0;
		while (j < qtrPos)
		{
			text3[j] = text[i];
			i++, j++;
		}
		char* text4 = new char[qtrPos];
		j = 0;
		while (j < qtrPos)
		{
			text4[j] = text[i];
			i++, j++;
		}
		/*vector<char>::iterator bound1, bound2, bound3, bound4;
		bound1 = partition(textContainer.begin(), textContainer.begin() + qtrPos, [](char& ch) {return ch; });*/

		//vector<char> bound1(qtrPos), bound2(qtrPos), bound3(qtrPos), bound4(qtrPos);
		using namespace placeholders;
		auto cvtBind = bind(convertFtr, _1, key, qtrPos, Cryptor());

		thread t1(cvtBind, text1);
		thread t2(cvtBind, text2);
		thread t3(cvtBind, text3);
		thread t4(cvtBind, text4);

		/*thread t1(convertFtr, text, key, halfPos-1, Cryptor());
		thread t2(convertFtr, text+(halfPos), key, halfPos+(nbytes%2), Cryptor());*/

		t1.join();
		t2.join();
		t3.join();
		t4.join();

		encoded = !encoded;
	}

	void SecureData::backup(const char* file) {
		if (!text)
			throw std::string("\n***No data stored***\n");
		else if (!encoded)
			throw std::string("\n***Data is not encoded***\n");
		else
		{
			fstream fout;
			fout.open(file, ios::out | ios::binary);
			fout.write(text, nbytes);
			fout.close();
		}
	}

	void SecureData::restore(const char* file, char key) {
		fstream fin;
		fin.open(file, ios::in | ios::binary);

		// TODO: - allocate memory here for the file content
		fin.seekg(0, ios::end);
		nbytes = (int)fin.tellg();

		delete[] text;
		text = nullptr;
		text = new char[nbytes];

		// TODO: - read the content of the binary file
		fin.seekg(ios::beg);
		fin >> noskipws;
		while (fin)
		{
			fin.read(text, nbytes);
		}

		*ofs << "\n" << nbytes << " bytes copied from binary file "
			<< file << " into memory.\n";

		encoded = true;

		code(key);

		*ofs << "Data decrypted in memory\n\n";
	}

	std::ostream& operator<<(std::ostream& os, const SecureData& sd) {
		sd.display(os);
		return os;
	}
}
