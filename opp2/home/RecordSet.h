// Name:Kim Phuong Tu
// Seneca Student ID:148886179
// Seneca email: kptu@myseneca.ca
// Date of completion:Jan 26,2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#ifndef SDDS_RECORDSET_H__
#define SDDS_RECORDSET_H__

#include <iostream>
#include <chrono>


using namespace std;
namespace sdds
{
	class RecordSet {
		string* str = nullptr;
		int numstr;
	public:
		RecordSet();
		RecordSet(const char*);
		RecordSet(const RecordSet& record);
		RecordSet& operator = (const RecordSet&);
		~RecordSet();
		std::size_t size()const;
		std::string getRecord(size_t)const;

		RecordSet(RecordSet&&);
		RecordSet& operator =(RecordSet&&);
	};

}
#endif // !