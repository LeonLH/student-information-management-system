#include"student.h"
#include<iostream>
#include<string>
using namespace std;

void StudentData::Print(){
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
void ScienceData::Print(){
	StudentData::Print();
	cout << " \t \t" << this->biol << "\t" << this->phys << \
"\t" << this->chem << endl;
}
void ArtsData::Print(){
	StudentData::Print();
	cout << this->geog << "\t" << this->hist << "\t \t \t" << endl;
}



float StudentData::AverageScore() const{
	return 0;
}

float ArtsData::AverageScore() const{
	float res = 0;
	res = chin + engl + math + hist + geog;
	return res/5;
}

float ScienceData::AverageScore() const{
	float res = 0;
	res = chin + engl + math;
	res += biol + chem + phys;
	return res/6;
}

StudentData* StudentData::Input(){
	return nullptr;
}

StudentData* ArtsData::Input(){
	this->type = 1;
	cout << "Please enter your Number, Name, Gender, Math, "\
		<< "Chinese, English, Geograph, History: "<< endl;
	cin >> this->numb >> this->name >> this->sex  >> this->math  \
		>> this->chin >> this->engl >> this->geog >> this->hist; 
	return this;
}

StudentData* ScienceData::Input(){
	this->type = 0;
	cout << "Please enter your Number, Name, Gender, Math, "\
		<< "Chinese, English, Biology, Physics and Chemics: "\
		<< endl;
	cin >> this->numb >> this->name >> this->sex  >> this->math  \
		>> this->chin >> this->engl >> this->biol >> this->phys  \
		>> this->chem;
	return this;
}

