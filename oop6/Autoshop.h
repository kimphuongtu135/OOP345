// Name:Kim Phuong Tu
// Seneca Student ID: 148886179
// Seneca email:kptu@myseneca.ca
// Date of completion: Mar 4,2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#include <iostream>
#include <vector>
#include "Vehicle.h"
#ifndef SDDS_AUTOSHOP_H__
#define SDDS_AUTOSHOP_H__
using namespace std;
namespace sdds
{
	class Autoshop {
		std::vector<Vehicle*> m_vehicles;
	public:
		Autoshop& operator +=(Vehicle* theVehicle);
		void display(std::ostream& os) const;
		~Autoshop();

	};
}
#endif // !