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
#include "Car.h"

using namespace std;
namespace sdds
{
	void Car::trim(string& str)const {
		size_t i = 0;
		for (i = 0; i < str.length() && str[i] == ' '; i++);

		str = str.substr(i);



		for (i = str.length(); i > 0 && str[i - 1] == ' '; i--);
		str = str.substr(0, i);

	}


	Car::Car(std::istream& is) {
		std::string substr = "";
		getline(is, substr);


		size_t start = 0;
		size_t pos = substr.find(',', start);


		c_maker = substr.substr(start, pos);
		trim(c_maker);


		start = pos;
		pos = substr.find(',', start + 1);

		c_condition = substr.substr(start + 1, pos - start - 1);
		trim(c_condition);
		if (c_condition == "n" || c_condition == "N") {
			c_condition = "new";
		}
		else if (c_condition == "u" || c_condition == "U") {
			c_condition = "used";
		}
		else if (c_condition == "b" || c_condition == "B") {
			c_condition = "broken";
		}
		else {
			c_condition= "Invalid";
		}

		start = pos;
		pos = substr.find(',', start + 1);
		c_topSpeed = std::stod(substr.substr(start + 1, pos - start - 1));

	}
	void Car::display(std::ostream& os) const {
		os << "| ";
		os << setw(10);
		os <<std::right<< c_maker;
		os << " | ";
		os << setw(6);
		os <<std::left<< c_condition;
		os << " | ";
		os << setw(6);
		os << fixed << setprecision(2) << c_topSpeed;
		os << " |";
	}

}