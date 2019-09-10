#include"student.h"
#include<iostream>
#include<string>
#include"mytools/normal_tools.h"
using namespace std;

extern Person* current_person;
extern NormalTools tools;
static Student* current_student;
void Student::Print(){
	string type, gender;
	if(this->type == 0)
		type = "Scie";
	else
		type = "Arts";

	if(this->sex == 0)
		gender = "Boy";
	else
		gender = "Girl";

	cout << this->numb << "\t" << this->name << "\t" << gender << \
"\t" << type << "\t" << this->math << "\t" << this->chin << \
"\t" << this->engl << "\t";

}
void ScienceStudent::Print(){
	Student::Print();
	cout << " \t \t" << this->biol << "\t" << this->phys << \
"\t" << this->chem << endl;
}
void ArtsStudent::Print(){
	Student::Print();
	cout << this->geog << "\t" << this->hist << "\t \t \t" << endl;
}

float Student::AverageScore() const{
	return 0;
}

float ArtsStudent::AverageScore() const{
	float res = 0;
	res = chin + engl + math + hist + geog;
	return res/5;
}

float ScienceStudent::AverageScore() const{
	float res = 0;
	res = chin + engl + math;
	res += biol + chem + phys;
	return res/6;
}

void Student::Run(){
	current_student = (Student*) current_person;
	while(Menu())
		;
}
int Student::Menu(){
	tools.ClearScreen();
	// print current student.

	cout << "ChangePassword, \ttype 1" << endl;
	cout << "Logout, \t\ttype 2" << endl;	
	cout << "QUIT, \t\t\ttype 0" << endl;
	
	int i;
	cin >> i;
	switch(i){
		case 1:
			ChangePassword();
			break;
		case 2:
			Logout();
			break;
		case 0:
			break;
	}
	return i;
}

Student* Student::Input(){
	return nullptr;
}

Student* ArtsStudent::Input(){
	this->type = 1;
	cout << "Please enter your Number, Name, Gender, Math, "\
		<< "Chinese, English, Geograph, History: "<< endl;
	cin >> this->numb >> this->name >> this->sex  >> this->math  \
		>> this->chin >> this->engl >> this->geog >> this->hist; 
	return this;
}

Student* ScienceStudent::Input(){
	this->type = 0;
	cout << "Please enter your Number, Name, Gender, Math, "\
		<< "Chinese, English, Biology, Physics and Chemics: "\
		<< endl;
	cin >> this->numb >> this->name >> this->sex  >> this->math  \
		>> this->chin >> this->engl >> this->biol >> this->phys  \
		>> this->chem;
	return this;
}
