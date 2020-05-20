// Name:Kim Phuong Tu
// Seneca Student ID: 148886179
// Seneca email:kptu@myseneca.ca
// Date of completion: Mar 4,2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#include <iostream>
#include <string>
#include <iomanip>
#include "Autoshop.h"
#include "Vehicle.h"

using namespace std;
namespace sdds
{
	Autoshop& Autoshop::operator +=(Vehicle* theVehicle) {
		if (theVehicle != nullptr) {
			m_vehicles.push_back(theVehicle);
		}
		return *this;
	}
	void Autoshop::display(std::ostream & os) const {
		os << "--------------------------------" << endl;;
		os << "| Cars in the autoshop!        |" << endl;
		os << "--------------------------------"<<endl;
		for (auto i = m_vehicles.begin(); i != m_vehicles.end(); i++)
		{
			(*i)->display(os);
			os << endl;
		}
		os << "--------------------------------" << endl;;
	}
	Autoshop::~Autoshop() {
		for (auto i = m_vehicles.begin(); i != m_vehicles.end(); i++)
		{
			delete *i;
		}
	}
}