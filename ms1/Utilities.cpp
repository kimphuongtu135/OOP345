// Name:Kim Phuong Tu
// Seneca Student ID: 148886179
// Seneca email:kptu@myseneca.ca
// Date of completion: Mar 19,2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#include <iostream>
#include <string>
#include <iomanip>
#include "Utilities.h"

using namespace std;
char Utilities::m_delimiter = ' ';

void Utilities::setFieldWidth(size_t newWidth) {
	m_widthField = newWidth;
}
size_t Utilities::getFieldWidth() const {
	return m_widthField;
}
std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more) {
	size_t end = str.find(m_delimiter, next_pos);
	string token = str.substr(next_pos, end - next_pos);
	
	if (token != "") {
		
		more = (end != string::npos) ? true : false;
		next_pos = end + 1;
		if (m_widthField < token.length())
			m_widthField = token.length();
		else
			m_widthField = m_widthField;

	}
	else {
		more = false;
		throw"Invalid";
	}
	return token;
}

void Utilities::setDelimiter(char newDelimiter) {
	m_delimiter = newDelimiter;
}

char Utilities::getDelimiter() {
	return m_delimiter;
}
