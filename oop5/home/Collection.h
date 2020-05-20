// Name:Kim Phuong Tu
// Seneca Student ID: 148886179
// Seneca email:kptu@myseneca.ca
// Date of completion: Feb 23,2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#include <iostream>
#ifndef SDDS_COLLECTION_H__
#define SDDS_COLLECTION_H__
using namespace std;
namespace sdds
{
	template <typename T>
	class Collection {
		string c_name = "";
		T* c_item = nullptr;
		size_t sizearr{ 0 };
		void(*ptFunc) (const Collection<T>&, const T&) = nullptr;
	public:
		Collection(std::string name)
		{
			c_name = name;
		};
		Collection(const Collection&) = delete;
		Collection& operator= (const Collection&) = delete;
		~Collection()
		{
			delete[] c_item;
		}
		const std::string& name() const { return c_name; }
		size_t size() const { return sizearr; }
		void setObserver(void (*observer)(const Collection<T>&, const T&)) {
			this->ptFunc = observer;
		}
		Collection<T>& operator+=(const T& item) {
			bool check = false;
			for (size_t i = 0; i < sizearr && c_item != nullptr; i++) {
				if (c_item[i].title() == item.title()) {
					check = true;
				}
			}
			if (!check) {
				T* subt = new T[sizearr + 1];
				for (size_t i = 0; i < sizearr; i++) {
					subt[i] = c_item[i];
				}
				subt[sizearr] = item;

				delete[] c_item;
				c_item = subt;
				sizearr++;

				if (ptFunc)
					ptFunc(*this, item);
			}
			return *this;
		};
		T& operator[](size_t idx) const {
			if (idx >= sizearr) {
				string index = to_string(idx);
				string size = to_string(sizearr);
				string message = "Bad index [" + index + "]. Collection has [" + size + "] items.";
				throw std::out_of_range(message);
			}
			else
				return c_item[idx];
		};
		T* operator[](std::string title) const {
			for (size_t i = 0; i < sizearr; i++) {
				if (c_item[i].title() == title) {
					return &(c_item[i]);
				}
			}
			return nullptr;

		}
	};
	template <typename T>
	std::ostream& operator<<(std::ostream& os, const Collection<T>& col) {
		for (size_t i = 0; i < col.size(); i++) {
			os << col[i];
		}
		return os;
	}

}
#endif // !