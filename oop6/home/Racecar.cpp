// Name:Kim Phuong Tu
// Seneca Student ID: 148886179
// Seneca email:kptu@myseneca.ca
// Date of completion: Mar 4,2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include "Racecar.h"

using namespace std;
namespace sdds
{
	
	Racecar::Racecar(std::istream& in) :Car(in) {
		std::string substr;
		getline(in, substr,'\n');
		trim(substr);
		m_booster = stod(substr);
		
	}

	void Racecar::display(std::ostream& os) const {
		Car::display(os);
		os << "*";
	}
	double Racecar::topSpeed() const{ 
		return Car::topSpeed()* (1 + m_booster); 
	}

}