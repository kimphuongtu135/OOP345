// Name:Kim Phuong Tu
// Seneca Student ID: 148886179
// Seneca email:kptu@myseneca.ca
// Date of completion: Feb 05,2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include "Restaurant.h"

using namespace std;
namespace sdds
{
	Restaurant::Restaurant(const Restaurant& res) {
		*this = res;
	}
	Restaurant& Restaurant::operator=(const Restaurant& res) {
		//Check self-assignment
		if (this != &res) {
			numb = res.numb;
			delete[] reservation;
			if (res.reservation != nullptr) {
				reservation = new Reservation[numb];
				for (size_t i = 0; i < numb; i++) {
					reservation[i] = res.reservation[i];
				}
			}
			else {
				numb = 0;
				reservation = nullptr;
			}
		}
		return *this;
	}
	Restaurant::Restaurant(Restaurant&&res) {
		*this = std::move(res);
	}
	Restaurant& Restaurant::operator=(Restaurant&& res) {
		if (this != &res) {
			delete[] reservation;
			reservation = res.reservation;
			numb = res.numb;

			res.reservation = nullptr;
			res.numb = 0;
		}
		return* this;
	}

	Restaurant::Restaurant(Reservation* reservations[], size_t cnt) {
		if (cnt > 0 || reservations != nullptr) {
			reservation = new Reservation[cnt];

			numb = cnt;

			for (size_t i = 0; i < cnt; i++) {
				this->reservation[i] = *reservations[i];
			}
		}
	}

	size_t Restaurant::size() const {
		return numb;
	}

	
	ostream& operator<<(ostream& os, const Restaurant& res) {
		os << "--------------------------" << endl;
		os << "Fancy Restaurant" << endl;
		os << "--------------------------" << endl;
		if (res.size() == 0 && res.reservation == nullptr) {
			os << "The object is empty!" << endl;
			os << "--------------------------" << endl;
		}
		else {
			for (size_t i = 0; i < res.size(); i++) {
				os << res.reservation[i];
			}
			os << "--------------------------" << endl;
		}
		return os;
	}
	Restaurant::~Restaurant() {
		delete[] reservation;
		reservation = nullptr;
	}
};


