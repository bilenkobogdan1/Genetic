#pragma once
#include "Day.h"
using namespace std;
class Week
{
public: Day mixDay(Day day,Day day2,vector <Lessons>& modDayVector) {
	int lesmin;
	Day dayles;
	if (day.les.size() < day2.les.size()) {   lesmin = day.les.size(); }
	else {
		lesmin = day2.les.size();
	}
		for (int i = 0; i<lesmin; i++) {
				dayles.les.push_back(dayles.mixLessons(day.les[i], day2.les[i]));
		}
		vector <Lessons> lesmodd;
		lesmodd = modDay(day, day2);
		for (int i = 0; i < lesmodd.size(); i++) {
			modDayVector.push_back(lesmodd[i]);
		}
		return dayles;

	
}
friend ostream& operator<<(ostream& out, const Week& weekop);
public:vector <Lessons> modDay(Day day,Day day2) {
	Day dayles;
	int lesmin;
	if (day2.les.size() < day.les.size()) { lesmin = day2.les.size(); }
	else { lesmin = day.les.max_size();  }
		if (day.les.size() == lesmin) {
		for (int i = lesmin; i < day2.les.size(); i++) {
			dayles.les.push_back(day2.les[i]);
		}
	}
	if (day2.les.size() == lesmin) {
		for (int i = lesmin; i < day.les.size(); i++) {
			dayles.les.push_back(day.les[i]);
		}
	}
	return dayles.les;
}
public: Week operator+(const Week other) {
		Week weeknew;
		vector <Lessons> modDay;
		vector <Day> resDay;

		for (int i = 0; i < this->week.size(); i++) {
			weeknew.week.push_back(mixDay(this->week[i], other.week[i],modDay));
	   }
		for (int i = 0; i < modDay.size(); i++) {
			int ran;
			ran = rand() % 5; 
			weeknew.week[ran].les.push_back(modDay[i]);
		}

		return weeknew;
}
public: vector<Day> week;
private: vector<Lessons> modLesWeek;
};


