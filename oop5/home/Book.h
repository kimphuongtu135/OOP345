// Name:Kim Phuong Tu
// Seneca Student ID: 148886179
// Seneca email:kptu@myseneca.ca
// Date of completion: Feb 23,2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#include <iostream>
#ifndef SDDS_BOOK_H__
#define SDDS_BOOK_H__
using namespace std;
namespace sdds
{
	class Book {
		string b_author = "";
		string b_title = "";
		string b_country = "";
		size_t b_year{ 0 };
		double b_price{ 0.0 };
		string b_des = "";
	public:
		Book() {};
		const std::string& title() const { return b_title; }
		const std::string& country() const { return b_country; }
		const size_t& year() { return b_year; }
		double& price() { return b_price; }
		Book(const std::string& strBook);
		void trim(string&)const;
		template<typename T>
		void fixSpelling(T spellChecker) {
			return spellChecker(b_des);
		}
		friend std::ostream& operator<<(std::ostream& os, const Book&);
	};



}
#endif // !