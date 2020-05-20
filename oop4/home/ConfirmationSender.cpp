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
#include "ConfirmationSender.h"

using namespace std;
namespace sdds
{
	ConfirmationSender::ConfirmationSender(const ConfirmationSender& con) {
		*this = con;
	}
	ConfirmationSender& ConfirmationSender::operator=(const ConfirmationSender& con) {
		if (this != &con) {
			size = con.size;
			delete[] resser;
			if (con.resser != nullptr) {
				resser = new const Reservation * [size];
				for (size_t i = 0; i < size; i++) {
					resser[i] = con.resser[i];
				}
			}
			else {
				size = 0;
				resser = nullptr;
			}
		}
		return *this;
	}
	ConfirmationSender::ConfirmationSender(ConfirmationSender&& con) {
		*this = std::move(con);
	}
	ConfirmationSender& ConfirmationSender::operator=(ConfirmationSender&& con) {
		if (this != &con) {
			delete[] resser;
			resser = con.resser;
			size = con.size;

			con.resser = nullptr;
			con.size = 0;
		}
		return*this;
	}


	ConfirmationSender& ConfirmationSender::operator+=(const Reservation& res) {
		bool match = false;

		for (size_t i = 0; i < size; i++)
		{
			if (resser[i] == &res)
				match = true;

		}
		if (!match)
		{
			const Reservation** temp = new const Reservation * [size + 1];
			for (size_t i = 0; i < size; i++) {
				temp[i] = resser[i]; // copy each element
			}
			temp[size] = &res; //Assign it to the last index
			size++;		//After assign the value to the end, increase element

			delete[] resser; //free this part to avoid memory leak
			resser = temp;
		}
		return *this;
	}
	ConfirmationSender& ConfirmationSender::operator-=(const Reservation & res) {
		bool match = false;

		for (size_t i = 0; i < size; i++) {
			if (resser[i] != &res)
				match = true;
		}

		if (match) {
			for (size_t i = 0; i < size; i++) {
				if (resser[i] == &res)
					resser[i] = nullptr;
			}
		}
		return *this;
	}

	ostream& operator<<(ostream & os, const ConfirmationSender & confirm) {
		os << "--------------------------" << endl;
		os << "Confirmations to Send" << endl;
		os << "--------------------------" << endl;
		if (confirm.size == 0 && confirm.resser == nullptr) {
			os << "The object is empty!" << endl;
			os << "--------------------------" << endl;
		}
		else {
			for (size_t i = 0; i < confirm.size; i++) {
				if (confirm.resser[i] != nullptr)
					os << *(confirm.resser[i]);

			}
			os << "--------------------------" << endl;
		}
		return os;
	}
	ConfirmationSender::~ConfirmationSender() {
		delete[] resser;

	}
};


