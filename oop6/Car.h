// Name:Kim Phuong Tu
// Seneca Student ID: 148886179
// Seneca email:kptu@myseneca.ca
// Date of completion: Mar 4,2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#include <iostream>
#include "Vehicle.h"
#ifndef SDDS_CAR_H__
#define SDDS_CAR_H__
using namespace std;
namespace sdds
{
	class Car :public Vehicle {
		std::string c_maker = "";
		std::string c_condition = "";
		double c_topSpeed{ 0.0 };
	public:
		Car(std::istream&);
		Car();
		std::string condition() const { return c_condition; };
		double topSpeed() const { return c_topSpeed; };
		void display(std::ostream& os) const;
		void trim(string& str)const;
	};
}
#endif // !