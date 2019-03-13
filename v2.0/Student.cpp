#include"Student.h"
#include<list>
#include<iostream>
#include <sstream>
#include <fstream>
using namespace std;


void STUD::print(){
	cout << "Number\tName\tGender\tType\tMath\tChinese\tEnglish\t\
Geog\tHistory\tBiology\tPhysics\tChemics" << endl;

	string type, gender;
	if(this->bType == 0)
		type = "Scie";
	else
		type = "Arts";

	if(this->bSex == 0)
		gender = "Boy";
	else
		gender = "Girl";

	cout << this->nNumb << "\t" << this->sName << "\t" << gender << \
"\t" << type << "\t" << this->fMath << "\t" << this->fChin << \
"\t" << this->fEngl << "\t";

}
void SCIESTUD::print(){
	STUD::print();
	cout << " \t \t" << this->fBiol << "\t" << this->fPhys << \
"\t" << this->fChem << endl;
}
void ARTSSTUD::print(){
	STUD::print();
	cout << this->fGeog << "\t" << this->fHist << "\t \t \t" << endl;
}

Student::Student(){
	load();
}

Student::~Student(){
	save();
}

void Student::clearscreen(){
	cout << "\033[2J\033[1;1H";
}

void Student::test(){
	while(testMenu())
		;
}
int Student::testMenu(){
	cout << "Test print, \t\ttype 1" << endl;
	cout << "Test browse, \t\ttype 2" << endl;
	cout << "Test input, \t\ttype 3" << endl;
	cout << "Test remove, \t\ttype 4" << endl;
	cout << "Test modify, \t\ttype 5" << endl;
	cout << "Test searchByName, \ttype 6" << endl;
	cout << "Test search, \t\ttype 7" << endl;
	cout << "Test byNumb, \t\ttype 8" << endl;
	cout << "Test sort, \t\ttype 9" << endl;
	cout << "Test freeRAM, \t\ttype 10" << endl;
	cout << "Test removeAll, \ttype 11" << endl;
	cout << "Test load, \t\ttype 12" << endl;
	cout << "Test save, \t\ttype 13" << endl;
	cout << "Test constructor, \ttype 14" << endl;
	cout << "Test deconstructor, \ttype 15" << endl;
	cout << "Test isExist, \t\ttype 16" << endl;
	cout << "QUIT, \t\t\ttype 0" << endl;

	int i;
	cin >> i;
	switch(i){
		case 1:
			//print();
			break;
		case 2:
			while(browse())
				;
			break;
		case 3:
			input();
			break;
		case 4:
			remove();
			break;
		case 5:
			modify();
			break;
		case 6:
			//searchByName();
			break;
		case 7:
			search();
			break;
		case 8:
			//byNumb();
			break;
		case 9:
			//sort();
			break;
		case 10:
			//freeRAM();
			break;
		case 11:
			//removeAll();
			break;
		case 12:
			load();
			break;
		case 13:
			save();
			break;
		case 14:
			Student();
			break;
		case 15:
			//~Student();
			break;
		case 16:
			//isExist();
			break;
		case 0:
			break;
	}
	return i;

}

int Student::load(){
	int count = 0, head = 0;
	string line;
	float tmp = 0;
	ifstream ifs("student.dat");
	while(!ifs) return -2;
	while(getline(ifs, line)){
		istringstream is(line);
		if(head == 0){
			head++;
			continue;

		}
		int nNumb;
		string sName;
		bool sex, type;
		float fMath, fChin, fEngl, fGeog, fHist, fBiol, fPhys, fChem;
		is >> nNumb >> sName >> sex >> type >> fMath >> fChin >> \
			  fEngl >> fGeog >> fHist >> fBiol >> fPhys >> fChem;
		if(type == 0){
			SCIESTUD* psci = new SCIESTUD;
			psci->nNumb = nNumb;
			psci->sName = sName;
			psci->bSex = sex;
			psci->bType = type;
			psci->fMath = fMath;
			psci->fChin = fChin;
			psci->fEngl = fEngl;
			psci->fBiol = fBiol;
			psci->fPhys = fPhys;
			psci->fChem = fChem;
			stu_list.push_back(psci);
		}
		else{
			ARTSSTUD* part = new ARTSSTUD;
			part->nNumb = nNumb;
			part->sName = sName;
			part->bSex = sex;
			part->bType = type;
			part->fMath = fMath;
			part->fChin = fChin;
			part->fEngl = fEngl;
			part->fGeog = fGeog;
			part->fHist = fHist;
			stu_list.push_back(part);
		}
	}
	ifs.close();
	return 0;
}

int Student::save(){
	ofstream ofs("student.dat");
	if(!ofs) return -2;
	ofs << "Number\tName\tGender\tType\tMath\tChinese\tEnglish\t\
Geog\tHistory\tBiology\tPhysics\tChemics" << endl;
	list<STUD*>::iterator it = stu_list.begin();
	while(it != stu_list.end()){
		STUD* p1 = *it;
		if(p1->bType == 0){
			SCIESTUD* p = (SCIESTUD*)p1;
			ofs << p->nNumb << "\t" << p->sName << "\t" << p->bSex 
			   	<< "\t" << p->bType << "\t" << p->fMath << "\t" 
				<< p->fChin << "\t" << p->fEngl << "\t" << 0 << "\t" 
				<< 0 << "\t"<< p->fBiol << "\t" << p->fPhys << "\t" 
			   	<< p->fChem << endl;
		}
		else{
			ARTSSTUD* p = (ARTSSTUD*)p1;
			ofs << p->nNumb << "\t" << p->sName << "\t" << p->bSex  
				<< "\t" << p->bType << "\t" << p->fMath << "\t" 
				<< p->fChin << "\t" << p->fEngl << "\t" << p->fGeog 
				<< "\t" << p->fHist << "\t" << 0 << "\t" << 0 
				<< "\t"  << 0 << endl;
		}
		it++;
	}
	ofs.close();
	return 0;
}

void Student::input(){
	cout << "Please type your type(0 for science, 1 for arts)? ";
	bool btype;
	cin >> btype;
	if(btype == 0){
		SCIESTUD* p = new SCIESTUD;
		p->bType = 0;
		cout << "Please enter your Number, Name, Gender, Math, \
			Chinese, English, Biology, Physics and Chemics: "<< endl;
		cin >> p->nNumb >> p->sName >> p->bSex  >> p->fMath  \
			>> p->fChin >> p->fEngl >> p->fBiol >> p->fPhys  \
			>> p->fChem;
		stu_list.push_back(p);
	}
	else{
		ARTSSTUD* p = new ARTSSTUD;
		p->bType = 1;
		cout << "Please enter your Number, Name, Gender, Math, \
			Chinese, English, Geograph, History: "<< endl;
		cin >> p->nNumb >> p->sName >> p->bSex  >> p->fMath  \
			>> p->fChin >> p->fEngl >> p->fGeog >> p->fHist; 
		stu_list.push_back(p);
	}
}

int Student::browse(){
//	cout << "Number\tName\tGender\tType\tMath\tChinese\tEnglish\t\
//Geog\tHistory\tBiology\tPhysics\tChemics" << endl;
	clearscreen();
	std::list<STUD*>::iterator it = stu_list.begin();
	for(; it != stu_list.end(); it++){
		STUD* p = *it;
		if(p->bType == 0){
			SCIESTUD* p0 = (SCIESTUD*)p;
			p0->print();
		}
		else{
			ARTSSTUD* p1 = (ARTSSTUD*)p;
			p1->print();
		}

	}
	cout << "Press any key to continue:" ;
	getchar();
	return 0;
}

void Student::remove(){

}

void Student::modify(){

}

int Student::search(){
	return 0;
}
