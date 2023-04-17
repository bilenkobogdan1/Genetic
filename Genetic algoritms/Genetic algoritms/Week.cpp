#include "Week.h"
ostream& operator<<(std::ostream& out, const Week& weekop) {
	for (int i = 0; i < weekop.week.size(); i++) {
		out << "Day " << i << endl;
		for (int j = 0; j < weekop.week[i].les.size(); j++) {
			out << weekop.week[i].les[j].course << " " << weekop.week[i].les[j].professors << weekop.week[i].les[j].students << endl;
		}

	}
	return out;
}
