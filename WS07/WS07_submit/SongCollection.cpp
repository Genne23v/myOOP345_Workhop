#include <fstream>
#include <sstream>
#include <algorithm>
#include <list>
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
	void SongCollection::display(std::ostream& out) const
	{
		size_t totalLength = 0;
		for (auto it = m_songs.begin(); it != m_songs.end(); it++)
		{
			out << *it << std::endl;
			totalLength += it->m_length;
		}

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
	void SongCollection::cleanAlbum()
	{
		for (Song& song : m_songs)
		{
			if (song.m_album == "[None]")
			{
				song.m_album = "";
			}
		}
	}
	bool SongCollection::inCollection(const std::string& artist) const
	{
		bool inCollection = false;
		for (auto it = m_songs.begin(); it != m_songs.end(); it++)
		{
			if (it->m_artist == artist)
				inCollection = true;
		}
		return inCollection;
	}
	std::list<Song> SongCollection::getSongsForArtist(const std::string& artist) const
	{
		std::list<Song> songsByArtist;
		for (auto it = m_songs.begin(); it != m_songs.end(); it++)
		{
			if (it->m_artist == artist)
				songsByArtist.push_back(*it);
		}
		return songsByArtist;
	}
}