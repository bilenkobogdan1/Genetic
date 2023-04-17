#pragma once
#include<iostream>
#include<vector>
#include"Lessons.h"
using namespace std;
enum Nameday {
	Monday,
	Tuesday,
	Wednesday,
	Thursday,
	Friday,
};
class Day
{
public:Lessons mixLessons(Lessons les, Lessons les2) {
	int a = rand() % 1;
	if (a == 0) { return les; }
	if (a == 1) { return les2; }
}
public:	Nameday nameday;
public: string day;
vector<Lessons> les;
};

