// Name:Kim Phuong Tu
// Seneca Student ID: 148886179
// Seneca email:kptu@myseneca.ca
// Date of completion: Feb 05,2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#include <iostream>
#ifndef SDDS_RESERVATION_H__
#define SDDS_RESERVATION_H__
using namespace std;
namespace sdds
{
	class Reservation {
		string id="";
		string name="";
		string email="";
		size_t numb{ 0 };
		size_t day{ 0 };
		size_t hour{ 0 };
	public:
		Reservation() {};
		Reservation(const std::string& res);
		friend ostream& operator<<(ostream& os, const Reservation&);


	};
	



}
#endif // !