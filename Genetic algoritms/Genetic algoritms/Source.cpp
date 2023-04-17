#include<iostream>
#include "Professors.h"
#include "XML.h";
#include "Schedule.h"
#include<map>
#include<algorithm>
using namespace std;
void GeneretionPopulation(vector<Schedule>& shvector, vector <Students> stud, vector<Professor> prof,int count) {
	for (int i = 0; i < count; i++) {
		Schedule sh(prof, stud);
		sh.Generation();
		sh.normaal();
		shvector.push_back(sh);
	}

}
int Rating(Schedule sh) {
	int rating = 0;
    
	for (int i = 0; i < sh.weekStud.size(); i++) {
		for (int j = 0; j < sh.weekStud[i].week.size(); j++) {
			int sum = 1;
			for (int k = 0; k < sh.weekStud[i].week[j].les.size(); k++) {
				sum = sum * 2;
				if (sh.weekStud[i].week[j].les[k].course == "*") { rating=rating+100; }
			}
			rating = rating + sum;
		}
	}
	return rating;
}
bool comp(Schedule sh, Schedule sh2) {
	return sh.raiting < sh2.raiting;
}
void SelectPopulation(vector<Schedule> &shvector) {
	for (int i = 0; i < shvector.size(); i++) {
		shvector[i].raiting = Rating(shvector[i]);
	}
	sort(shvector.begin(), shvector.end(), comp);
	for (int i = 0; i < shvector.size(); i++) {
		//cout << Rating(shvector[i]) << "+";

	}
	vector<Schedule> shvectorErese;
	for (int i = 0; i < shvector.size() / 2; i++) {
		shvectorErese.push_back(shvector[i]);
	}
	shvector = shvectorErese;
}
void Crossing(vector<Schedule> &shvector){
	vector<Schedule> shvectorSum;
	for (int i = 0; i < shvector.size(); i=i+2) {
		Schedule sheduleSum = shvector[i] + shvector[i + 1];
		shvectorSum.push_back(sheduleSum);
	}
	shvector = shvectorSum;
}
void Mutation(vector<Schedule> &shvector){
	for (int i = 0; i < shvector.size(); i++) {		
		Lessons les1,les2;
		int rani = rand() % shvector[i].weekStud.size();
		int ranj = rand() % shvector[i].weekStud[rani].week.size();
		int randk = rand() % shvector[i].weekStud[rani].week[ranj].les.size();
		les1 = shvector[i].weekStud[rani].week[ranj].les[randk];
		int rani2 = rand() % shvector[i].weekStud.size();
		int ranj2 = rand() % shvector[i].weekStud[rani2].week.size();
		int randk2 = rand() % shvector[i].weekStud[rani2].week[ranj2].les.size();
		les2 = shvector[i].weekStud[rani2].week[ranj2].les[randk2];
		shvector[i].weekStud[rani].week[ranj].les[randk] = les2;
		shvector[i].weekStud[rani2].week[ranj2].les[randk2] = les1;

	 }
		
			

}
void satisfactionProblem(vector<Schedule> shvector, vector <Students> stud, vector<Professor> prof){
	while (true)
	{


		GeneretionPopulation(shvector, stud, prof, 16);
		SelectPopulation(shvector);
		Crossing(shvector);
		Mutation(shvector);

		for (int i = 0; i < shvector.size(); i++) {
			shvector[i].normaal();
		}
		for (int i = 0; i < shvector.size(); i++) {
			for (int j = 0; j < shvector[i].weekStud.size(); j++) {
				for (int k = 0; k < shvector[i].weekStud[j].week.size(); k++)
					if (shvector[i].weekStud[j].week[k].day.size() == 0) {
						cout << shvector[i]; break; break;
					}
				break;
			}
			break;
		}
		break;
	}
}



int main() {
	vector <Schedule> sheduls;
	XML xm;
	xm.Open("genetic.txt");
	vector <Students> stud;
	vector<Professor> prof;
	xm.OpenProfessors(prof);
	//xm.WriteProfessors(prof);
	xm.OpenStudent(stud);
	//xm.WriteStudent(stud);
	/*Schedule sh(prof, stud);
	sh.Generation();
	sh.normaal();
	Schedule sh1(prof, stud);
	sh1.Generation();
	sh1.normaal();
	cout << sh;
	cout << sh1;
	cout << sh + sh1;*/
	vector<Schedule> shvector;

GeneretionPopulation(shvector, stud, prof, 16);

	SelectPopulation(shvector);
	Crossing(shvector);
	Mutation(shvector);
	for (int i = 0; i < shvector.size(); i++) {
		shvector[i].normaal();
	}
	SelectPopulation(shvector);
	Crossing(shvector);
	Mutation(shvector);
	for (int i = 0; i < shvector.size(); i++) {
		shvector[i].normaal();
	}
	cout << shvector[0];
	//satisfactionProblem(shvector, stud, prof);
	int n;
	cin >> n;
	return 0; 
}