// Name:Kim Phuong Tu
// Seneca Student ID: 148886179
// Seneca email:kptu@myseneca.ca
// Date of completion: Mar 4,2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#include <iostream>
#include <sstream>
#include "Utilities.h"
#include "Car.h"
#include "Vehicle.h"
#include "Racecar.h"

using namespace std;
namespace sdds
{
	Vehicle* createInstance(std::istream& in) {
		char ch = '\0';
		char ch2 = '\0';

		std::string substr = "";
		getline(in, substr);
		std::stringstream ss(substr);
		ss >> ch >> ch2;
		if (ss) {
			if (ch == 'c' || ch == 'C') {
				return new Car(ss);
			}
			else if (ch == 'r' || ch == 'R') {
				return new Racecar(ss);
			}
			else
				throw ch;
		}
		else
			return nullptr;
	};
}