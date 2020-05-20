// !// Name:Kim Phuong Tu
// Seneca Student ID: 148886179
// Seneca email:kptu@myseneca.ca
// Date of completion: Feb 02,2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#define _CRT_SECURE_NO_WARNINGS
#ifndef SDDS_PAIRSUMMABLE_H__
#define SDDS_PAIRSUMMABLE_H__
#include <iostream>
#include "Pair.h"

using namespace std;
namespace sdds
{
	template <typename K, typename V>
	class PairSummable : public Pair<K, V> {
		static V s_value;
		static size_t field;
	public:
		static const V& getInitialValue() { return s_value; };

		PairSummable() : Pair<K, V>() {};

		PairSummable(const K& key, const V& value) :Pair<K, V>(key, value) {
			if (field < key.size()) {
				field = key.size();
			}
		};
		V sum(const K& key, const V& val) const {
			if (this->key() == key) {
				return (this->value() + val);
			}
			else
				return val;
		};

		virtual void display(std::ostream & os) const {
			os << std::left <<std::setw(field);
			Pair<K, V> ::display(os);
			os << std::right;
		};

	};

	template <typename K, typename V>
	size_t PairSummable < K,V> ::field = 0;

	template <>
	std::string PairSummable < std::string, std::string> ::s_value = "";

	template <>
	int PairSummable < std::string, int> ::s_value = 0;

	template <>
	std::string PairSummable < std::string, std::string> ::sum(const string& key, const string& val) const {
		std::string result="" ;
		if (PairSummable<std::string, std::string>::key() == key) {
			if (val == "") {
				result = this->value();
			}
			else {
				result = val + ", " + this->value();
			}
			return result;
		}
		else 
			return result = val;

		
	};



}
#endif // !