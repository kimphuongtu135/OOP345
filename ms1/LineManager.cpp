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
#include <fstream>
#include "LineManager.h"


using namespace std;

LineManager::LineManager(const std::string& str, std::vector<Workstation*>& wk, std::vector<CustomerOrder>& cust) {
	fstream file(str);
	if (!file)
		throw"Error";
	else {
		while (!file.eof()) {
			Utilities ul;
			size_t pos = 0;
			bool check = true;
			ul.setDelimiter('|');

			std::string local = "";
			std::string station = "";
			std::string nextStation = "";

			getline(file, local);

			station = ul.extractToken(local, pos, check);
			if (check) 
				nextStation = ul.extractToken(local, pos, check);
			else
				nextStation = "";

			for (auto i : wk) {
				if (station == i->getItemName()) {
					for (auto item : wk) {
						if (item->getItemName() == nextStation)
							i->setNextStation(*item);
					}
				}
			}
		}
	}
	for (auto& i : cust)
		ToBeFilled.push_back(std::move(i));

	AssemblyLine = wk;
	m_cntCustomerOrder = cust.size();

}
std::deque<Workstation*> LineManager::sort(const std::vector<Workstation*> & wk) const {
	Workstation* last{};
	std::deque<Workstation*>station;
	while (station.size() != wk.size()) {
		for (size_t i = 0; i < wk.size(); i++) {
			if (wk[i]->getNextStation() == last) {
				station.push_front(wk[i]);
				last = wk[i];
			}
		}
	}
	return station;
}

bool LineManager::run(std::ostream & os) {
	static size_t count = 1;
	std::deque<Workstation*>station = sort(AssemblyLine);
	os << "Line Manager Iteration: " << count << endl;

	if (!ToBeFilled.empty()) {
		*station.front() += std::move(ToBeFilled.front());
		ToBeFilled.pop_front();
	}

	for (auto i : AssemblyLine)
		i->runProcess(os);

	CustomerOrder cust;
	for (auto i : AssemblyLine) {
		i->moveOrder();
		if (i->getIfCompleted(cust)) {
			Completed.push_back(std::move(cust));
		}
	}

	count++;
	return Completed.size() == m_cntCustomerOrder;
}
void LineManager::displayCompletedOrders(std::ostream & os) const {
	for (auto& i : Completed)
		i.display(os);
}
void LineManager::displayStations() const {
	for (auto& i : AssemblyLine)
		i->display(std::cout);
}
void LineManager::displayStationsSorted() const {
	std::deque<Workstation*>station = sort(AssemblyLine);
	for (auto& i : station)
		i->display(std::cout);
}