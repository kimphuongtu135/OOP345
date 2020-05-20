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
#include "Reservation.h"

using namespace std;
namespace sdds
{

	Reservation::Reservation(const std::string& res)
	{

		size_t start = 0;
		size_t pos = res.find(':', start);


		id = res.substr(start, pos);
		id.erase(remove(id.begin(), id.end(), ' '), id.end());



		//name
		start = pos;
		pos = res.find(',', start);
		name = res.substr(start + 1, pos - start - 1);
		name.erase(remove(name.begin(), name.end(), ' '), name.end());



		//email 

		start = pos;
		pos = res.find(',', start + 1);
		email = res.substr(start + 1, pos - start - 1);
		email.erase(remove(email.begin(), email.end(), ' '), email.end());


		//numb
		start = pos;
		pos = res.find(',', start + 1);
		numb = std::stoi(res.substr(start + 1, pos - start - 1));


		//day
		start = pos;
		pos = res.find(',', start + 1);
		day = std::stoi(res.substr(start + 1, pos - start - 1));

		//hour
		start = pos;
		pos = res.find(',', start + 1);
		hour = std::stoi(res.substr(start + 1, pos - start - 1));



	}

	std::ostream & operator<<(std::ostream & os, const Reservation & res) {
		std::string emailDisplay = "<" + res.email + ">";
		os << "Reservation " << res.id << ": ";
		os << setw(10);
		os << std::right;
		os << res.name;
		os << "  ";
		os << setw(20);
		os << std::left;
		os << emailDisplay;
		os << "   ";
		if (res.hour >= 6 && res.hour <= 9)
			os << " Breakfast";
		else if (res.hour >= 11 && res.hour <= 15)
			os << " Lunch";
		else if (res.hour >= 17 && res.hour <= 21)
			os << " Dinner";
		else
			os << " Drinks";

		os << " on day " << res.day << " @ " << res.hour << ":00 for " << res.numb << " people." << endl;

		return os;
	}

};


