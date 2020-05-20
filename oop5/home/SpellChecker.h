// Name:Kim Phuong Tu
// Seneca Student ID: 148886179
// Seneca email:kptu@myseneca.ca
// Date of completion: Feb 23,2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#include <iostream>
#ifndef SDDS_SPELLCHECK_H__
#define SDDS_SPELLCHECK_H__
using namespace std;
namespace sdds
{
	class SpellChecker {
		string m_badWords[5];
		string m_goodWords[5];
	public:
		SpellChecker(const char* filename);
		void operator()(std::string& text) const;
		void trim(string&)const;
	};
}
#endif // !