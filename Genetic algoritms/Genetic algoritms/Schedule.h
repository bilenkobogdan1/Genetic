#pragma once
#include<iostream>
#include"Day.h"
#include"Professors.h"
#include"Students.h"
#include"Week.h"
using namespace std;

class Schedule
{
private: Students stud1;
private: vector <Professor> prof;
private: vector <Students> studs;
public:int raiting;
public: int sumlessons;
private: int mondayLessons;
private: int tuesdayLessons;
private: int wednesdayLessons;
private: int thursdayLessons;
private: int fridayLessons;
public: vector <Week> weekStud;
public: Schedule(vector <Professor> prof, vector <Students> studs) {
	this->prof = prof;
	this->studs = studs;
}
public: void testadd(Week wek, Week wek2) {
	Week weeksum = wek + wek2;
	cout << weeksum;
}
public: Schedule operator+(const Schedule other) {
	Schedule res(prof, studs);
	vector <Week> weeksum;
	for (int i = 0; i < this->weekStud.size()-1; i++) {
		weeksum.push_back(this->weekStud[i] + other.weekStud[i]);
		weeksum.push_back(this->weekStud[i+1] + other.weekStud[i + 1]);
	}
	res = *this;
	res.weekStud = weeksum;
	return res;
}
friend ostream& operator<<(ostream& out, const Schedule& shed);
private: void Genereterandom() {
	int weeklessonsrand;
	mondayLessons = rand() % sumlessons;
	tuesdayLessons = rand() % sumlessons;
	wednesdayLessons = rand() % sumlessons;
	thursdayLessons = rand() % sumlessons;
	fridayLessons = rand() % sumlessons;
	weeklessonsrand = mondayLessons + thursdayLessons + wednesdayLessons + tuesdayLessons + fridayLessons;

	mondayLessons = mondayLessons * sumlessons / weeklessonsrand;
	tuesdayLessons = tuesdayLessons * sumlessons / weeklessonsrand;
	wednesdayLessons = wednesdayLessons * sumlessons / weeklessonsrand;
	thursdayLessons = thursdayLessons * sumlessons / weeklessonsrand;
	fridayLessons = fridayLessons * sumlessons / weeklessonsrand;
	 int sumnormallessons = mondayLessons + thursdayLessons + wednesdayLessons + tuesdayLessons + fridayLessons;
	 if (sumlessons - sumnormallessons > 0) {
		 mondayLessons = mondayLessons  + sumlessons- sumnormallessons;
	 }
/*	 cout << mondayLessons << endl;
	 cout << tuesdayLessons << endl;
	 cout << wednesdayLessons << endl;
	 cout << thursdayLessons << endl;
	 cout << fridayLessons << endl;
	 cout << sumlessons << endl;*/
}
private: void GenereteDay(Day& day,Students st,int weekleessons, vector <Professor> prof) {

		for (int i = 0; i < weekleessons; i++) {
			Lessons les;
			int n=0;
		
			n = rand() % stud1.course.size();
			n = rand() % stud1.course.size();
			n = rand() % stud1.course.size();
			n = n + 1;
			int k = 0;
			for (auto& item : stud1.course) {
				k=k+1;
				if (k == n) {
					les.course = item.first;
					for (int i = 0; i < prof.size(); i++) {
						for (int j = 0; j < prof[i].course.size(); j++) {
							if (prof[i].course[j] == item.first) { les.professors = prof[i].name; }
						}
					}
					break;
				}
			}
			day.les.push_back(les);
		}
	
}
public: void GenerationStud( vector <Professor> prof,Students stud) {
	


		sumlessons = 0;

		for (auto j = stud.course.begin(); j != stud.course.end(); j++) {
			sumlessons = sumlessons + j->second;
		}

		Genereterandom();
		Day monday; monday.nameday = Monday;
		GenereteDay(monday, stud1, mondayLessons,prof);
		for (int i = 0; i < mondayLessons; i++) {
			//cout << monday.les[i].course<<" "<<monday.les[i].professors<<endl;
			
		}
		Day tuesday; monday.nameday = Tuesday;
		GenereteDay(tuesday, stud1, tuesdayLessons,prof);
		Day wednesday; wednesday.nameday = Wednesday;
		GenereteDay(wednesday, stud1, wednesdayLessons,prof);
		Day thursday; thursday.nameday = Thursday;
		GenereteDay(thursday, stud1, thursdayLessons,prof);
		Day friday; friday.nameday = Friday;
		GenereteDay(friday, stud1, fridayLessons,prof);
		Week week;
		week.week.push_back(monday);
		week.week.push_back(tuesday);
		week.week.push_back(wednesday);
		week.week.push_back(thursday);
		week.week.push_back(friday);
		//int sumnormallessons = mondayLessons + thursdayLessons + wednesdayLessons + tuesdayLessons + fridayLessons;
		weekStud.push_back(week);
	
}
public: void Generation() {
	for (int i = 0; i < studs.size(); i++) {
		stud1 = studs[i];
		GenerationStud(prof,studs[i]);
	}
}
public: void normaal() {
	
		for (int i = 0;i< weekStud.size()-1; i++) {
			for (int j = 0; j < weekStud[i].week.size(); j++) {
				int maxLesSize = 0;
				if (weekStud[i].week[j].les.size() < weekStud[i + 1].week[j].les.size()) {
					maxLesSize = weekStud[i].week[j].les.size();
				}
				else {
					maxLesSize = weekStud[i + 1].week[j].les.size();
				}
				for (int k = 0; k <maxLesSize; k++) {
					if (weekStud[i].week[j].les[k].professors == weekStud[i + 1].week[j].les[k].professors) { //cout << "*"; cout << j << " " << k << endl;
					int ranBin = rand() % 2;
					ranBin = rand() % 2;
					Lessons les;
					 ranBin = rand() % 2;
					les.course = weekStud[i + ranBin].week[j].les[k].course+"$";
					les.professors = weekStud[i + ranBin].week[j].les[k].professors;
					les.students= weekStud[i + ranBin].week[j].les[k].students;
					weekStud[i+ranBin].week[j].les[k].professors = "-";
					weekStud[i + ranBin].week[j].les[k].course = "*";					
					weekStud[i + ranBin].week[j].les.push_back(les);

					}
				}
			}
	   }
	  
}













	   
};

