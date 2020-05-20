// Name:Kim Phuong Tu
// Seneca Student ID:148886179
// Seneca email: kptu@myseneca.ca
// Date of completion: Jan 22,2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "RecordSet.h"

using namespace std;
namespace sdds
{
	RecordSet::RecordSet() {
		str = nullptr;
		numstr = 0;
	}
	RecordSet::RecordSet(const char* name) {
		ifstream myfile(name); // open file "name"

		std::string substr; // create a substring 

		if (myfile) {
			while (!myfile.eof()) {
				getline(myfile, substr, ' '); // read file from beginning till substr and remove the ' '
				numstr++;
			}
		}

		str = new std::string[numstr]; // dynamic allocation the str with new number of index
		myfile.seekg(0); // load file back to begining without re-opening


		if (myfile) {
			int count = 0;
			while (!myfile.eof()) {
				
				getline(myfile, substr, ' '); // read file from beginning till substr and remove the ' '
				str[count] = substr;
				count++;
			}
		}

		/*for (int i = 0; i < numstr; i++) {
			getline(myfile, substr, ' '); // read the file until str[i] and remove the ' '
			str[i] = substr;
		}*/
		myfile.close();// close file 

	}

	RecordSet::RecordSet(const RecordSet& record) {
		//shallow copy static memory
		numstr = record.numstr;

		//allocate dynamic memory
		if (record.str != nullptr) {
			str = new std::string[numstr];

			for (int i = 0; i < numstr; i++) {
				str[i] = record.str[i];
			}

		}
		else {
			str = nullptr;
			numstr = 0;
		}
	}


	RecordSet& RecordSet::operator=(const RecordSet& record) {
		// check self-assigment
		if (this != &record) {
			//shallow copy static memory
			numstr = record.numstr;
			//deallocate previously allocated memory
			delete[] str;
			//allocate new dynamic memory
			if (record.str != nullptr) {
				str = new std::string[numstr];

				for (int i = 0; i < numstr; i++) {
					str[i] = record.str[i];
				}
			}
			else {
				str = nullptr;
				numstr = 0;
			}
		}

		return *this;
	}



	std::size_t RecordSet::size()const {
		return numstr;
	}

	std::string RecordSet::getRecord(size_t num)const {
		if (num < size() && num >= 0) {
			return str[num];
		}
		else {
			return "";
		}
	}

	RecordSet::~RecordSet() {
		delete[] str;
	}
	//Move constructor
	RecordSet::RecordSet(RecordSet&& record) {
		str = nullptr;
		*this = std::move(record);
	}
	//Move Assignment operator
	RecordSet& RecordSet::operator =(RecordSet&& record) {
		if (this != &record) {
			delete[] str;
			str = record.str;
			numstr = record.numstr;
			record.str = nullptr;
			record.numstr = 0;
		}
		return *this;
	}
}