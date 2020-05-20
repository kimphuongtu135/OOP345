// Name:Kim Phuong Tu
// Seneca Student ID: 148886179
// Seneca email:kptu@myseneca.ca
// Date of completion: Mar 19,2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#include <iostream>
#include <string>
#include <iomanip>
#include "Workstation.h"

using namespace std;

Workstation::Workstation(const std::string& str) :Station(str) {
	m_pNextStation = nullptr;
}
void Workstation::runProcess(std::ostream& os) {
	if (!m_orders.empty()) {
		if (!m_orders.front().isOrderFilled())
			m_orders.front().fillItem(*this, os);
	}
}

bool Workstation::moveOrder() {
	if (!m_orders.empty()) {
		// if true means doesn't require service
		if (m_orders.front().isItemFilled(getItemName()))
		{
			if (m_pNextStation != nullptr) {
				*m_pNextStation += std::move(m_orders.front());
				m_orders.pop_front(); // remove the first order
				return true;
			}
		}
	}
	return false;
}


void Workstation::setNextStation(Workstation& station) {
	m_pNextStation = &station;
}
const Workstation* Workstation::getNextStation() const {
	return m_pNextStation;
}
void Workstation::display(std::ostream& os) {
	if (m_pNextStation != nullptr)
		os << getItemName() << " --> " << m_pNextStation->getItemName() << endl;
	else
		os << getItemName() << " --> " << "END OF LINE" << endl;
}
Workstation& Workstation::operator+=(CustomerOrder && cust) {
	m_orders.push_back(std::move(cust));
	return *this;
}
bool Workstation::getIfCompleted(CustomerOrder & cust) {
	if (!m_orders.empty()) {
		if (m_orders.front().isOrderFilled())
		{
			cust = move(m_orders.front());
			m_orders.pop_front();
			return true;
		}
	}
	return false;
}