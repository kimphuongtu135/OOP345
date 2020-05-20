// Name:Kim Phuong Tu
// Seneca Student ID: 148886179
// Seneca email:kptu@myseneca.ca
// Date of completion: Mar 11,2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include"SongCollection.h"

using namespace std;
namespace sdds
{
	void SongCollection::trim(string& str)const {
		size_t i = 0;
		for (i = 0; i < str.length() && str[i] == ' '; i++);

		str = str.substr(i);

		for (i = str.length(); i > 0 && str[i - 1] == ' '; i--);
		str = str.substr(0, i);

	}


	SongCollection::SongCollection(const string name) {
		ifstream myfile(name); // open file "name"
		if (!myfile.is_open()) {
			throw "filename is incorrect";
		}
		else {
			while (!myfile.eof()) {
				Song* songs=new Song;
				string substr = "";
				getline(myfile, substr);

				songs->s_title = substr.substr(0, 25);
				trim(songs->s_title);
				//cout << songs->s_title << endl;


				songs->s_artist = substr.substr(25, 25);
				trim(songs->s_artist);


				songs->s_album = substr.substr(50, 25);
				trim(songs->s_album);

				string temp;
				temp = substr.substr(75, 5);
				trim(temp);
				if (temp == "")
					songs->s_year = 0;
				else
					songs->s_year = stoi(temp);

				songs->s_length = std::stoi(substr.substr(80, 5));

				songs->s_price = std::stod(substr.substr(85, 5));

				s_songs.push_back(songs);

			}
			
		}
	}
	void SongCollection::display(std::ostream& os) const {
		for_each(s_songs.begin(), s_songs.end(), [&os](const Song* s){ os << *s << endl; });
	}
	 std::ostream& operator<<(std::ostream& os, const Song& songs) {
		 size_t min = songs.s_length / 60;
		 size_t sec = songs.s_length % 60;
		 
		 os << "| ";
		 os << setw(20)<<setfill(' ');
		 os << std::left << songs.s_title;
		 os << " | ";
		 os << setw(15);
		 os << std::left << songs.s_artist;
		 os << " | ";
		 os << setw(20);
		 os << std::left << songs.s_album;
		 os << " | ";
		 os << setw(6);
		 os << std::left << setfill(' ');
		 if (songs.s_year == 0)
			 os << "";
		 else
			 os << std::right << songs.s_year;
		 os << " | ";
		 os << std::right << min<<":"<<setw(2)<<setfill('0')<<sec;
		 os << " | ";
		 os << fixed << setprecision(2) << songs.s_price;
		 os << " |";
		return os;
	}

	 SongCollection::~SongCollection() {
		 for (auto i = s_songs.begin(); i != s_songs.end(); i++)
		 {
			 delete* i;
		 }
	 }
}