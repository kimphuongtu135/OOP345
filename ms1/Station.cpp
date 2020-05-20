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
#include "Station.h"

using namespace std;

size_t Station::m_widthField = 0;
size_t Station::id_generator = 0;

Station::Station(const std::string& str) {
	try {
		Utilities ul;
		size_t pos = 0;
		bool check;
		id_generator++;
		id = id_generator;
		name = ul.extractToken(str, pos, check);
		serial = std::stoi(ul.extractToken(str, pos, check));
		currentItem = std::stoi(ul.extractToken(str, pos, check));
		des = ul.extractToken(str, pos, check);
		if (m_widthField < name.size())
			m_widthField = name.size();
		else
			m_widthField = m_widthField;
	}
	catch (string & err) {
		cout << err;
	}

}
const std::string& Station::getItemName() const {
	return name;
}
unsigned int Station::getNextSerialNumber() {
	return serial++;
}
unsigned int Station::getQuantity() const {
	return currentItem;
}
void Station::updateQuantity() {
	currentItem--;
	if (currentItem < 0)
	{
		throw "Quantity cannot go under 0";
	}
}
void Station::display(std::ostream& os, bool full) const {
	if (!full) {
		os << "[" << setw(3) << right << setfill('0') << id << "] Item: " << setw(m_widthField) << setfill(' ') << left << name << " [" << setw(6) << setfill('0') << right << serial << "]" << endl;
	}
	else {
		os << "[" << setw(3) << right << setfill('0') << id << "] Item: " << setw(m_widthField) << setfill(' ') << left << name << " [" << setw(6) << setfill('0') << right << serial << "]";
		os << " Quantity: " << setw(m_widthField) << setfill(' ') << left << currentItem << " Description: " << des << endl;
	}
}

