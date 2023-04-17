#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include "Professors.h"
#include <stdlib.h>
using namespace std;

class XML
{
private: string path;
public:void Open(string path) {
	this->path = path;
}
public: void OpenProfessors(vector <Professor>& professorlist) {
	ifstream f;
	f.open(path);
	string line = "";
	while (line != "#endprofessors") {
		getline(f, line);
		if (line == "#professors") {
			Professor prof;
			getline(f, prof.name);
			string n;
			getline(f, n);

			int nn = atoi(n.c_str());

			for (int i = 0; i < nn; i++) {
				string vec;
				getline(f, vec);
				prof.course.push_back(vec);
			}
			professorlist.push_back(prof);
			string endline;
			getline(f, endline);
		}
	}

}
public: void OpenStudent(vector <Students>& studentslist) {
	ifstream f;
	f.open(path);
	string line = "";
	while (line != "#endstudents") {
		getline(f, line);
		if (line == "#students") {
			Students student;
			getline(f, student.name);
			string n;
			getline(f, n);

			int nn = atoi(n.c_str());

			for (int i = 0; i < nn; i++) {
				string vec;
				string  m;
				getline(f, vec);
				getline(f, m);
				int mm = atoi(m.c_str());
				student.course[vec]=mm;
			}
			studentslist.push_back(student);
			string endline;
			getline(f, endline);
		}
	}



}
public: void WriteProfessors(vector <Professor> prof) {
	for (int i = 0; i < prof.size(); i++) {
		cout << prof[i].name << endl;
		for (int j = 0; j < prof[i].course.size(); j++) {
			cout << prof[i].course[j] << endl;
		}
	}
}
public: void WriteStudent(vector<Students> stud) {
	for (int i = 0; i < stud.size(); i++) {
		cout << stud[i].name << endl;
		for (auto& item : stud[i].course) {
			cout << item.first << endl;
			cout << item.second << endl;
		}
	}
}
};

 