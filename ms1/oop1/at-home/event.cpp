// Name:Kim Phuong Tu
// Seneca Student ID:148886179
// Seneca email: kptu@myseneca.ca
// Date of completion:
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include<cstring>
#include "event.h"


unsigned int g_sysClock;
using namespace std;
namespace sdds
{
	Event::Event() {
		des = nullptr;
		time = 0;
	}
	Event::Event(const Event& eve) {
		//shallow copy static memory
		time = eve.time;

		//allocate dynamic memory
		if (eve.des != nullptr) {
			des = new char[strlen(eve.des) + 1];
			int len = strlen(eve.des);
			for (int i = 0; i < len; i++) {
				des[i] = eve.des[i];
			}
			des[strlen(eve.des)] = '\0';
		}
		else {
			des = nullptr;
			time = 0;
		}
	}

	Event& Event::operator=(const Event& eve) {
		// check self-assigment
		if (this != &eve) {
			//shallow copy static memory
			time = eve.time;
			//deallocate previously allocated memory
			delete[] des;
			//allocate new dynamic memory
			if (eve.des != nullptr) {
				des = new char[strlen(eve.des) + 1];
				int len = strlen(eve.des);
				for (int i = 0; i < len; i++) {
					des[i] = eve.des[i];
				}
				des[strlen(eve.des)] = '\0';

			}
			else {
				des = nullptr;
				time = 0;
			}
		}

		return *this;
	}

	Event::~Event() {
		delete[] des;
	}

	void Event::display() {
		int h = 0;
		int m = 0;
		int s = 0;
		int t = time;
		h = t / 3600;
		t = t % 3600;
		m = t / 60;
		t = t % 60;
		s = t;


		static int counter = 1;


		if (des != nullptr && des[0] != '\0')
			cout << std::setfill(' ') << std::setw(3) << counter << ". " << std::setfill('0') << std::setw(2) << h << ":" << std::setfill('0') << std::setw(2) << m << ":" << std::setfill('0') << std::setw(2) << s << " -> " << des << endl;
		else
			cout << std::setfill(' ') << std::setw(3) << counter << ". [ No Event ]" << endl;

		counter++;
	}

	void Event::setDescription(const char arr[]) {
		time = g_sysClock;
		if (arr != nullptr && arr[0] != '\0') {
			if (des != nullptr && des[0] != '\0') {
				delete[] des;
			}
			des = new char[strlen(arr) + 1];
			strcpy(des, arr);

		}
		else {
			des = nullptr;
			time = 0;
		}
	}
}
