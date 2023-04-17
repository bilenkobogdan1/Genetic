#include "Schedule.h"
ostream& operator<<(ostream& out, const Schedule& shed) {
	for (int i = 0; i < shed.weekStud.size(); i++) {
		out << "--------------------------" << endl;
		out <<"          " << shed.studs[i].name<<endl;
		out << shed.weekStud[i];
		
}
	return out;
}
