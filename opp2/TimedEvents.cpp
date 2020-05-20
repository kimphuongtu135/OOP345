// Name:Kim Phuong Tu
// Seneca Student ID:148886179
// Seneca email: kptu@myseneca.ca
// Date of completion:Jan 22,2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include "TimedEvents.h"

using namespace std;
namespace sdds
{
	TimedEvents::TimedEvents() {
		numrecord = 0;
	}
	void TimedEvents::startClock() {
		start = chrono::steady_clock::now();
	}
	void TimedEvents::stopClock() {
		end = chrono::steady_clock::now();
	}
	void TimedEvents::recordEvent(const char* nameevent) {
			string substr = "nanoseconds";
			record[numrecord].name = nameevent;
			record[numrecord].unit = substr;
			record[numrecord].timedura = chrono::duration_cast<std::chrono::nanoseconds>(end - start);
			numrecord++;
		
	}
		ostream& operator<<( ostream & os, const TimedEvents & arr) {
			os << "--------------------------" << endl;
			os << "Execution Times:" << endl;
			os << "--------------------------"<<endl;
			for(int i =0 ; i<arr.numrecord; i++){
				os << setw(20) << left
					<< arr.record[i].name << " "
					<< setw(12) << right
					<< arr.record[i].timedura.count() << " "
					<< arr.record[i].unit << endl;
					
		}
			os << "--------------------------" << endl;
			return os;
	}
}