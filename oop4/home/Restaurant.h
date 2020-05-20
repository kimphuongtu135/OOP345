// Name:Kim Phuong Tu
// Seneca Student ID: 148886179
// Seneca email:kptu@myseneca.ca
// Date of completion: Feb 05,2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#include <iostream>
#include "Reservation.h"
#ifndef SDDS_RESTAURANT_H__
#define SDDS_RESTAURANT_H__

using namespace std;
namespace sdds
{
	class Restaurant {
		Reservation* reservation = nullptr;
		size_t numb{ 0 };
	public:
		Restaurant() {};
		Restaurant(const Restaurant&);
		Restaurant& operator=(const Restaurant&);
		Restaurant(Restaurant&&);
		Restaurant& operator=(Restaurant&&);
		Restaurant(Reservation* reservations[], size_t cnt);
		size_t size() const;
		~Restaurant();
		friend ostream& operator<<(ostream& os, const Restaurant& res);

	};

}
#endif // !