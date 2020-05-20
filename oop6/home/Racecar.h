// Name:Kim Phuong Tu
// Seneca Student ID: 148886179
// Seneca email:kptu@myseneca.ca
// Date of completion: Mar 4,2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#include <iostream>
#include "Car.h"
#ifndef SDDS_RACECAR_H__
#define SDDS_RACECAR_H__
using namespace std;
namespace sdds
{
	class Racecar :public Car {
		double m_booster{ 0.0 };
	public:
		Racecar(std::istream& in);
		void display(std::ostream& os) const;
		double topSpeed() const;
	};
}
#endif // !