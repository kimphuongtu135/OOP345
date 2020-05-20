// Name:Kim Phuong Tu
// Seneca Student ID:148886179
// Seneca email: kptu@myseneca.ca
// Date of completion:Jan 22,2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#ifndef SDDS_TIMEDEVENTS_H__
#define SDDS_TIMEDEVENTS_H__

#include <iostream>
#include <chrono>

#define MAX_RECORD 7

using namespace std;
namespace sdds
{
	class TimedEvents {
		int numrecord;
		chrono::steady_clock::time_point start;
		chrono::steady_clock::time_point end;
		struct {
			string name;
			string unit;
			chrono::steady_clock::duration timedura;
		}record[MAX_RECORD];
	public:
		TimedEvents();
		void startClock();
		void stopClock();
		void recordEvent(const char*);
		friend ostream& operator<<( ostream& , const TimedEvents& );

	};

}
#endif // !
