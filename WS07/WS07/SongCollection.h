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
	};

	class SongCollection
	{
		std::list<Song> m_songs;
	public:
		SongCollection(char* filename);
		void display(std::ostream& out) const;
	};
	std::ostream& operator<<(std::ostream& out, const Song& theSong);
}
#endif // !SDDS_SONG_COLLECTION_H


