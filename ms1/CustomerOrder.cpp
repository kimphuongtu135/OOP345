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
#include <algorithm>
#include "CustomerOrder.h"

using namespace std;

size_t CustomerOrder::m_widthField = 0;

CustomerOrder::CustomerOrder() {}


CustomerOrder::CustomerOrder(std::string& str) {
	try {
		Utilities ul;
		size_t pos = 0;
		bool check;
		m_name = ul.extractToken(str, pos, check);
		m_product = ul.extractToken(str, pos, check);
		m_cntItem = count(str.begin(), str.end(), ul.getDelimiter()) - 1;
		m_lstItem = new Item * [m_cntItem];
		for (size_t i = 0; i < m_cntItem; i++) {
			m_lstItem[i] = new Item(ul.extractToken(str, pos, check));
		}

		if (m_widthField < ul.getFieldWidth())
			m_widthField = ul.getFieldWidth();
		else
			m_widthField = m_widthField;
	}

	catch (string & err) {
		cout << err;
	}

}
CustomerOrder::CustomerOrder(const CustomerOrder& cust) {
	throw "No Copy";
}


CustomerOrder::CustomerOrder(CustomerOrder&& cust) noexcept {
	m_lstItem = nullptr;
	*this = std::move(cust);
}
CustomerOrder& CustomerOrder::operator=(CustomerOrder&& cust)noexcept {
	if (this != &cust) {

		for (size_t i = 0u; i < m_cntItem; i++)
			delete m_lstItem[i];
		delete[] m_lstItem;

		m_name = cust.m_name;
		m_product = cust.m_product;
		m_cntItem = cust.m_cntItem;
		m_lstItem = cust.m_lstItem;


		cust.m_name = "";
		cust.m_product = "";
		cust.m_cntItem = 0;
		cust.m_lstItem = nullptr;
	}
	return *this;
}

CustomerOrder::~CustomerOrder() {
	for (size_t i = 0; i < m_cntItem; i++)
		delete m_lstItem[i];
	delete[] m_lstItem;


}
bool CustomerOrder::isOrderFilled() const {
	for (size_t i = 0; i < m_cntItem; i++) {
		if (!m_lstItem[i]->m_isFilled) 
			return false;
	}
	return true;
}
bool CustomerOrder::isItemFilled(const std::string & itemName) const {
	for (size_t i = 0; i < m_cntItem; i++) {
		if (m_lstItem[i]->m_itemName == itemName)
			return m_lstItem[i]->m_isFilled;
	}
	return true;
}


void CustomerOrder::fillItem(Station & station, std::ostream & os) {
	for (size_t i = 0; i < m_cntItem; i++) {
		if (station.getItemName() == m_lstItem[i]->m_itemName) {
			if (station.getQuantity() > 0) {
				m_lstItem[i]->m_serialNumber = station.getNextSerialNumber();
				m_lstItem[i]->m_isFilled = true;
				station.updateQuantity();
				os << "    Filled " << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]" << endl;
			}
			else {
				os << "Unable to fill " << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]" << endl;
			}
		}
	}

}





void CustomerOrder::display(std::ostream & os) const {
	os << m_name << " - " << m_product << endl;
	for (size_t i = 0; i < m_cntItem; i++) {
		os << "[" << std::setw(6) <<right<< setfill('0') << m_lstItem[i]->m_serialNumber << "] ";
		os << std::setw(m_widthField) <<left<< setfill(' ') << m_lstItem[i]->m_itemName << " - ";
		if (m_lstItem[i]->m_isFilled == true)
			os << "FILLED" << endl;
		else
			os << "MISSING" << endl;
	}
}