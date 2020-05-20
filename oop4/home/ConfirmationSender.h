// Name:Kim Phuong Tu
// Seneca Student ID: 148886179
// Seneca email:kptu@myseneca.ca
// Date of completion: Feb 05,2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#include <iostream>
#include "Reservation.h"
#ifndef SDDS_CONFIRM_H__
#define SDDS_CONFIRM_H__
using namespace std;
namespace sdds
{
	class ConfirmationSender {
		const Reservation** resser=nullptr;
		size_t size{0};

	public:
		ConfirmationSender() {};
		~ConfirmationSender();
		ConfirmationSender(const ConfirmationSender&);
		ConfirmationSender& operator=(const ConfirmationSender&);
		ConfirmationSender(ConfirmationSender&&);
		ConfirmationSender& operator=(ConfirmationSender&&);
		ConfirmationSender& operator+=(const Reservation& res);
		ConfirmationSender& operator-=(const Reservation& res);
		friend ostream& operator<<(ostream& os, const ConfirmationSender&);
	};




}
#endif // !