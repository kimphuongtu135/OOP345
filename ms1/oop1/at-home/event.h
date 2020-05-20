// Name:Kim Phuong Tu
// Seneca Student ID:148886179
// Seneca email: kptu@myseneca.ca
// Date of completion:
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.


#ifndef SDDS_EVENT_H__
#define SDDS_EVENT_H__

extern unsigned int g_sysClock;

using namespace std;
namespace sdds
{

	class Event {
		char* des;
		int time;
	public:
		Event();
		Event(const Event& eve);
		Event& operator=(const Event&);
		~Event();
		void display();
		void setDescription(const char arr[]);
	};

}
#endif // !