// Name:Kim Phuong Tu
// Seneca Student ID: 148886179
// Seneca email:kptu@myseneca.ca
// Date of completion: Mar 19,2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#ifndef SDDS_STATION_H__
#define SDDS_STATION_H__
#include <iostream>
#include "Utilities.h"
using namespace std;

class Station {
	int id{ 0 };
	string name = "";
	string des = "";
	size_t serial{ 0 };
	unsigned int currentItem{ 0 };
	static size_t m_widthField;
	static size_t id_generator;
public:
	Station(const std::string&);
	const std::string& getItemName() const;
	unsigned int getNextSerialNumber();
	unsigned int getQuantity() const;
	void updateQuantity();
	void display(std::ostream& os, bool full) const;
};

#endif // !