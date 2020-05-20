// Name:Kim Phuong Tu
// Seneca Student ID: 148886179
// Seneca email:kptu@myseneca.ca
// Date of completion: Feb 02,2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#include <iostream>
#ifndef SDDS_PAIR_H__
#define SDDS_PAIR_H__
using namespace std;
namespace sdds
{
	template <typename K, typename V>
	class Pair {
		K p_key;
		V p_value;
	public:
		Pair() :p_key{ 0 }, p_value{ 0 } {};

		Pair(const K& key, const V& value) {
			p_key = key;
			p_value = value;
		};
		const K& key() const {
			return p_key;
		};
		const V& value() const {
			return p_value;
		};
		virtual void display(std::ostream& os) const {
			os << p_key << " : " << p_value << endl;
		};

	};
	template <typename K, typename V>
	std::ostream& operator<<(std::ostream& os, const Pair<K, V>& pair) {
		pair.display(os);
		return os;
	};
}
#endif // !