// Name:Kim Phuong Tu
// Seneca Student ID: 148886179
// Seneca email:kptu@myseneca.ca
// Date of completion: Feb 10,2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include "Book.h"

using namespace std;
namespace sdds
{
	void Book::trim(string& str)const {
		size_t i = 0;
		for (i = 0; i < str.length() && str[i] == ' '; i++);

		str = str.substr(i);



		for (i = str.length(); i > 0 && str[i - 1] == ' '; i--);
		str = str.substr(0, i);



	}

	Book::Book(const std::string & strBook) {

		size_t start = 0;
		size_t pos = strBook.find(',', start);


		b_author = strBook.substr(start, pos);
		trim(b_author);


		start = pos;
		pos = strBook.find(',', start + 1);

		b_title = strBook.substr(start + 1, pos - start - 1);
		trim(b_title);


		start = pos;
		pos = strBook.find(',', start + 1);
		b_country = strBook.substr(start + 1, pos - start - 1);
		b_country.erase(remove(b_country.begin(), b_country.end(), ' '), b_country.end());


		start = pos;
		pos = strBook.find(',', start + 1);
		b_price = std::stod(strBook.substr(start + 1, pos - start - 1));


		start = pos;
		pos = strBook.find(',', start + 1);
		b_year = std::stoi(strBook.substr(start + 1, pos - start - 1));


		start = pos;
		pos = strBook.find('.', start + 1);
		b_des = strBook.substr(start + 1, pos - start);
		trim(b_des);
	}

	std::ostream & operator<<(std::ostream & os, const Book & bk) {
		os << setw(20);
		os << bk.b_author;
		os << " | ";
		os << setw(22);
		os << bk.title();
		os << " | ";
		os << setw(5);
		os << bk.country();
		os << " | ";
		os << setw(4);
		os << bk.b_year;
		os << " | ";
		os << setw(6);
		os << fixed << setprecision(2) << bk.b_price;
		os << " | ";
		os << bk.b_des << endl;

		return os;
	}
}