// Name:Kim Phuong Tu
// Seneca Student ID: 148886179
// Seneca email:kptu@myseneca.ca
// Date of completion: Mar 11,2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef SDDS_SONGCOLLECTION_H__
#define SDDS_SONGCOLLECTION_H__
#include <vector>
#include <list>
#include <iostream>
using namespace std;
namespace sdds
{
	struct Song {
		string s_artist = "";
		string s_title = "";
		string s_album = "";
		double m_price{ 0.0 };
		size_t s_year{ 0 };
		size_t s_length{ 0 };
	};
	class SongCollection {
		vector<Song*> s_songs;
	public:
		void trim(string& str)const;
		SongCollection(const string name);
		void display(std::ostream& os) const;
		~SongCollection();
		void sort(const string name);
		void cleanAlbum();
		bool inCollection(const string name) const;
		std::list<Song> getSongsForArtist(const string& name) const;
	};
	std::ostream& operator<<(std::ostream& out, const Song& theSong);
}
#endif // !