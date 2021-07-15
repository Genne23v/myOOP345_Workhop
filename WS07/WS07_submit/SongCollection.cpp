// Workshop 7: Part 2
// Date: 2021/07/15
// Author: Wonkeun No
// Student #: 145095196
// Description:
// SongCollection.cpp
///////////////////////////////////////////////////
// I have done all the coding by myself and only copied the code that my professor
// provided to complete my workshops and assignments.
///////////////////////////////////////////////////
#include <fstream>
#include <sstream>
#include <algorithm>
#include <list>
#include <numeric>
#include "SongCollection.h"

namespace sdds
{
	std::string removeSpaces(std::string str)
	{
		size_t strBegin = str.find_first_not_of(' ');
		size_t strEnd = str.find_last_not_of(' ');
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
				song.m_length = stoi(removeSpaces(tmpArr[4]));
				song.m_price = stod(removeSpaces(tmpArr[5]));

				m_songs.push_back(song);
			}			
		}
		else
		{
			throw std::invalid_argument("Invalid file name.");
		}
	}

	std::string getTime(const size_t seconds)
	{
		size_t hour = seconds / 3600;
		size_t min = (seconds - (hour * 3600)) / 60;
		size_t sec = seconds % 60;

		std::string time;
		std::string min_str;
		std::string sec_str;
		if (min < 10 && hour >0) min_str = "0" + std::to_string(min);
		else min_str = std::to_string(min);
		if (sec < 10) sec_str = "0" + std::to_string(sec);
		else sec_str = std::to_string(sec);

		if (hour > 0)
		time = std::to_string(hour) + ":" + min_str + ":" + sec_str;
		else
		time = min_str + ":" + sec_str;

		return time;
	}
	
	size_t getSum(size_t sum, const Song& song)
	{
		return sum += song.m_length;
	}
	void SongCollection::display(std::ostream& out) const
	{
		size_t totalLength = 0;
		std::for_each(m_songs.begin(), m_songs.end(), 
			[&out](const Song& song){ out << song << std::endl; });
			
		totalLength = std::accumulate(m_songs.begin(), m_songs.end(), totalLength, getSum);

		std::string str("Total Listening Time: ");
		out.width(88);
		out.fill('-');
		out << "" << std::endl;
		out << "|";
		out.fill(' ');
		out.width(78);
		out << str;
		out.width(7);
		out << getTime(totalLength) << " |" << std::endl;
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
		out << getTime(theSong.m_length) << " | " << theSong.m_price << " |";

		return out;
	}
	void SongCollection::sort(const std::string& param)
	{
		if (param == "title")
		{
			m_songs.sort([](const Song& song1, const Song& song2) {return song1.m_title < song2.m_title; });
		}
		else if (param == "album")
		{
			m_songs.sort([](const Song& song1, const Song& song2) {return song1.m_album < song2.m_album; });
		}
		else if (param == "length")
		{
			m_songs.sort([](const Song& song1, const Song& song2) {return song1.m_length < song2.m_length; });
		}
	}

	bool invalidAlbum(Song& song)
	{
		return song.m_album == "[None]";
	}
	void Song::operator=(const char* c)
	{
		m_album = c;
	}
	void SongCollection::cleanAlbum()
	{
		std::replace_if(m_songs.begin(), m_songs.end(), invalidAlbum, "");	
	}
	bool SongCollection::inCollection(const std::string& artist) const
	{
		bool inCollection = std::any_of(m_songs.begin(), m_songs.end(), 
			[&artist](const Song& song)->bool {return song.m_artist == artist; });

		return inCollection;
	}
	std::list<Song> SongCollection::getSongsForArtist(const std::string& artist) const
	{
		std::list<Song> songsByArtist(m_songs.size());

		auto it = std::copy_if(m_songs.begin(), m_songs.end(), songsByArtist.begin(),
			[&artist](const Song& song)->bool { return song.m_artist == artist; });
		
		songsByArtist.resize(std::distance(songsByArtist.begin(), it));

		return songsByArtist;
	}
}