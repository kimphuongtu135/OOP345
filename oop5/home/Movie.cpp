// Name:Kim Phuong Tu
// Seneca Student ID: 148886179
// Seneca email:kptu@myseneca.ca
// Date of completion: Feb 23,2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include "Movie.h"

using namespace std;
namespace sdds
{
	void Movie::trim(string& str)const {

		size_t i = 0;
		for (i = 0; i < str.length() && str[i] == ' '; i++);

		str = str.substr(i);

		for (i = str.length(); i > 0 && str[i - 1] == ' '; i--);
		str = str.substr(0, i);
	}

	Movie::Movie(const std::string & strBook) {

		size_t start = 0;
		size_t pos = strBook.find(',', start);

		m_title = strBook.substr(start, pos - start );
		trim(m_title);

		start = pos;
		pos = strBook.find(',', start + 1);
		m_year = std::stoi(strBook.substr(start + 1, pos - start - 1));

		start = pos;
		pos = strBook.find('.', start + 1);
		m_desc = strBook.substr(start + 1, pos - start);
		trim(m_desc);
	}

	std::ostream & operator<<(std::ostream & os, const Movie & bk) {
		os << setw(40);
		os << bk.title();
		os << " | ";
		os << setw(4);
		os << bk.m_year;
		os << " | ";
		os << bk.m_desc << endl;

		return os;
	}
}