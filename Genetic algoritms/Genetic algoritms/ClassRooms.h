#pragma once
#include<iostream>
#include <string>
#include<vector>
#include "Professors.h"
#include"Students.h"
using namespace std;

class ClassRooms
{
public: string nomer;
public: int count;
public:  Professor &pf;
public: vector <Students> StudentsList;

};

