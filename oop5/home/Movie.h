// Name:Kim Phuong Tu
// Seneca Student ID: 148886179
// Seneca email:kptu@myseneca.ca
// Date of completion: Feb 23,2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#include <iostream>
#ifndef SDDS_MOVIE_H__
#define SDDS_MOVIE_H__
using namespace std;
namespace sdds
{
	class Movie {
		string m_title = "";
		size_t m_year{ 0 };
		string m_desc = "";
	public:
		Movie() {};
		const std::string& title() const { return m_title; };
		Movie(const std::string& strMovie);
		template<typename T>
		void fixSpelling(T spellChecker) {
			 spellChecker(m_desc);
			 spellChecker(m_title);
		}
		void trim(string&)const;
		friend std::ostream& operator<<(std::ostream& os, const Movie&);
	};
}
#endif // !