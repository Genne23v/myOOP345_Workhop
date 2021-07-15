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
#ifndef SDDS_SONG_COLLECTION_H
#define SDDS_SONG_COLLECTION_H
#include <string>
#include <iostream>
#include <list>

namespace sdds
{
	struct Song
	{
		std::string m_artist;
		std::string m_title;
		std::string m_album;
		double m_price;
		std::string m_releaseYear;
		size_t m_length=0;

		void operator=(const char* str);
	};

	class SongCollection
	{
		std::list<Song> m_songs;
	public:
		SongCollection(char* filename);
		void display(std::ostream& out) const;
		void sort(const std::string& param);
		void cleanAlbum();
		bool inCollection(const std::string& artist) const;
		std::list<Song> getSongsForArtist(const std::string& artist) const;
	};
	std::ostream& operator<<(std::ostream& out, const Song& theSong);
}
#endif // !SDDS_SONG_COLLECTION_H


