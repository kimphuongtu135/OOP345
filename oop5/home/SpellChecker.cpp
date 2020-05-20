// Name:Kim Phuong Tu
// Seneca Student ID: 148886179
// Seneca email:kptu@myseneca.ca
// Date of completion: Feb 23,2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#include <iostream>
#include <fstream>
#include <string>
#include "SpellChecker.h"

using namespace std;
namespace sdds
{
	SpellChecker::SpellChecker(const char* filename) {
		if (filename == nullptr || filename[0] == '\0') {
			throw "Bad file name!";
		}
		else {

			ifstream file(filename);

			if (!file) {
				throw "Bad file name!";
				cout << filename;
			}
			else {
				string sub = "";
				size_t count = 0;
				do {
					getline(file, sub, '\n');
					size_t idx = sub.find(' ');
					if (idx < sub.length()) {
						m_badWords[count] = sub.substr(0, idx);
						size_t pos = sub.find("\n", idx + 1);
						m_goodWords[count] = sub.substr(idx + 1, pos - idx - 1);
						trim(m_goodWords[count]);
						count++;
					}
				} while (file && count < 5);
				file.close();
			}
		}
	}

	void SpellChecker::operator()(std::string& text) const {
		for (size_t i = 0; i < 5; i++) {
			size_t start = text.find(m_badWords[i]);
			while (start != std::string::npos) {
				text.replace(start, m_badWords[i].size(), m_goodWords[i]);
				start = text.find(m_badWords[i]);
			}
		}
	}
	void SpellChecker::trim(string& str)const {
		size_t i = 0;
		for (i = 0; i < str.length() && str[i] == ' '; i++);
		str = str.substr(i);

		for (i = str.length(); i > 0 && str[i - 1] == ' '; i--);
		str = str.substr(0, i);
	}
}