#include <fstream>
#include <sstream>
#include <algorithm>
#include <list>
#include "SongCollection.h"

namespace sdds
{
	std::string removeSpaces(std::string str)
	{
		int strBegin = str.find_first_not_of(' ');
		int strEnd = str.find_last_not_of(' ');
		std::string returnStr;

		if (strBegin != std::string::npos && strEnd != std::string::npos)
			returnStr = str.substr(strBegin, (strEnd - strBegin + 1));
		else returnStr = "";
		
		return returnStr;
	}

	constexpr size_t size = 26;
	constexpr size_t arr_size = 6;
	SongCollection::SongCollection(char* filename)
	{
		std::ifstream fIn(filename);
		char buffer[size];
		std::string tmpArr[arr_size];
	
		if (fIn.is_open())
		{
			while (fIn)
			{
				for (auto i = 0; i < 3; i++)
				{
					fIn.read(buffer, 25);
					buffer[25] = '\0';
					tmpArr[i] = buffer;
				}
				for (auto i = 3; i < 6; i++)
				{
					fIn.read(buffer, 5);
					buffer[5] = '\0';
					tmpArr[i] = buffer;
				}
				char c = '\0';
				fIn.get(c);

				Song song;
				song.m_title = removeSpaces(tmpArr[0]);
				song.m_artist = removeSpaces(tmpArr[1]);
				song.m_album = removeSpaces(tmpArr[2]);
				
				song.m_releaseYear = removeSpaces(tmpArr[3]);
				/*if (!tmpYear.empty())
				song.m_releaseYear = stoi(tmpYear);*/

				song.m_length = stoi(removeSpaces(tmpArr[4]));
				song.m_price = stod(removeSpaces(tmpArr[5]));

				m_songs.push_back(song);
			}
			
		}
		else
		{
			throw std::invalid_argument("");
		}
	}
	void SongCollection::display(std::ostream& out) const
	{
		
		for (auto it = m_songs.begin(); it != m_songs.end(); it++)
			out << *it;
	}
	std::string getTime(const size_t seconds)
	{
		size_t min = seconds / 60;
		size_t sec = seconds % 60;
		std::string time;

		if (sec < 10)
			time = std::to_string(min) + ":0" + std::to_string(sec);
		else 
			time = std::to_string(min) + ":" + std::to_string(sec);

		return time;
	}
	std::ostream& operator<<(std::ostream& out, const Song& theSong)
	{
		out << "| ";
		out.unsetf(std::ios::right);
		out.setf(std::ios::left);
		out.width(20);
		out << theSong.m_title << " | ";
		out.width(15);
		out << theSong.m_artist << " | ";
		out.width(20);
		out << theSong.m_album << " | ";
		out.width(6);
		out.unsetf(std::ios::left);
		out.setf(std::ios::right);
		out << theSong.m_releaseYear << " | ";
		out << getTime(theSong.m_length) << " | " << theSong.m_price << " |" << std::endl;

		return out;
	}
}