// Name:Kim Phuong Tu
// Seneca Student ID: 148886179
// Seneca email:kptu@myseneca.ca
// Date of completion: Feb 02,2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#include <iostream>
#ifndef SDDS_SET_H__
#define SDDS_SET_H__


namespace sdds
{
	template <typename T, int N>
	class Set {
		T capacity[N];
		int numb{ 0 };
	public:
		size_t size() const {
			return numb;
		}

		const T& operator[](size_t index) const {
			return capacity[index];
		}
		void operator+=(const T& item) {
			if (numb < N) {
				capacity[numb]=item;
				numb++;
			}
		}

	};
}
#endif // !