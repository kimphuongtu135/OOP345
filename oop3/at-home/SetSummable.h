// Name:Kim Phuong Tu
// Seneca Student ID: 148886179
// Seneca email:kptu@myseneca.ca
// Date of completion: Feb 02,2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#ifndef SDDS_SETSUMMABLE_H__
#define SDDS_SETSUMMABLE_H__
#include <iostream>
#include "Set.h"


using namespace std;
namespace sdds
{
	template <typename T, int N, typename K, typename V>
	class SetSummable : public Set<T,N> {
		T capacity[N];
		K t_key;
		V t_value;
	public:
		V accumulate(const K& key) const {
			V local= this->operator[](0).getInitialValue();
			for (size_t i = 0; i < this->size(); i++) {
				local = (this->operator[](i)).sum(key, local);
			}
			return local;
		}
	};
}
#endif // !