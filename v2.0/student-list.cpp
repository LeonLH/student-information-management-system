#include"student-list.h"
#include<list>
#include <stdio.h>
#include<iostream>
#include <sstream>
#include <fstream>
using namespace std;

static void ClearScreen(){
	cout << "\033[2J\033[1;1H";
}

static int ByNumb(const StudentData *p1, const StudentData *p2){
	return p1->numb < p2->numb;
}
static int ByName(const StudentData *p1, const StudentData *p2){
	return p1->name < p2->name;
}
static int ByGender(const StudentData *p1, const StudentData *p2){
	return p1->sex < p2->sex;
}
static int ByType(const StudentData *p1, const StudentData *p2){
	return p1->type < p2->type;
}
static int ByMath(const StudentData *p1, const StudentData *p2){
	return p1->math < p2->math;
}
// need virtual function support, otherwise it will be complex
static int ByAverage(const StudentData *p1, const StudentData *p2){
	return p1->AverageScore() < p2->AverageScore();
}

//ArtsData::~ArtsData(){
//
//}
//
//ScienceData::~ScienceData(){
//
//}

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

StudentData* StudentList::Input(){
	cout << "Please type your type(0 for science, 1 for arts)?";
	bool btype;
	cin >> btype;
	StudentData* pres = nullptr;
	if(btype == 0){
		ScienceData* p = new ScienceData;
		pres = p->Input();
	}
	else{
		ArtsData* p = new ArtsData;
		pres = p->Input();
	}
	StudentData* useless;
	if(IsExist(pres->numb, useless))
		cout << "The number is exist, Please try again: " << endl;
	else
		student_list.push_back(pres);
	return pres;
}

StudentList::StudentList(){
	Load();
}

StudentList::~StudentList(){
	Save();
}

void StudentList::Print(){
	ClearScreen();
	cout << "Number\tName\tGender\tType\tMath\tChinese\tEnglish\t\
Geog\tHistory\tBiology\tPhysics\tChemics" << endl;
	std::list<StudentData*>::iterator it = student_list.begin();
	for(; it != student_list.end(); it++){
		(*it)->Print();
	}
	cout << "Press any key to continue:" << endl;
	cin.ignore();
	cin.get();

}

void StudentList::Test(){
	while(TestMenu())
		;
}
int StudentList::TestMenu(){
	cout << "Test print, \t\ttype 1" << endl;	// done
	cout << "Test browse, \t\ttype 2" << endl;	// done
	cout << "Test input, \t\ttype 3" << endl;	// done
	cout << "Test remove, \t\ttype 4" << endl;	// done
	cout << "Test modify, \t\ttype 5" << endl;	// done
	cout << "Test searchByName, \ttype 6" << endl;
	cout << "Test search, \t\ttype 7" << endl;
	cout << "Test byNumb, \t\ttype 8" << endl;
	cout << "Test sort, \t\ttype 9" << endl;	// done
	cout << "Test freeRAM, \t\ttype 10" << endl;
	cout << "Test removeAll, \ttype 11" << endl;
	cout << "Test load, \t\ttype 12" << endl;	// done
	cout << "Test save, \t\ttype 13" << endl;	// done
	cout << "Test constructor, \ttype 14" << endl;
	cout << "Test deconstructor, \ttype 15" << endl;
	cout << "Test isExist, \t\ttype 16" << endl;	// done
	cout << "QUIT, \t\t\ttype 0" << endl;

	int i;
	cin >> i;
	switch(i){
		case 1:
			Print();
			break;
		case 2:
			Browse();
			break;
		case 3:
			Input();
			break;
		case 4:
			Remove();
			break;
		case 5:
			Modify();
			break;
		case 6:
			SearchByName();
			break;
		case 7:
			Search();
			break;
		case 8:
			//ByNumb();
			break;
		case 9:
			Sort();
			break;
		case 10:
			//FreeRAM();
			break;
		case 11:
			//RemoveAll();
			break;
		case 12:
			Load();
			break;
		case 13:
			Save();
			break;
		case 14:
			StudentList();
			break;
		case 15:
			//~StudentList();
			break;
		case 16:
			//IsExist();
			break;
		case 0:
			break;
	}
	return i;

}

int StudentList::Load(){
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
		int numb;
		string name;
		bool sex, type;
		float math, chin, engl, geog, hist, biol, phys, chem;
		is >> numb >> name >> sex >> type >> math >> chin >> \
			  engl >> geog >> hist >> biol >> phys >> chem;
		if(type == 0){
			ScienceData* psci = new ScienceData;
			psci->numb = numb;
			psci->name = name;
			psci->sex = sex;
			psci->type = type;
			psci->math = math;
			psci->chin = chin;
			psci->engl = engl;
			psci->biol = biol;
			psci->phys = phys;
			psci->chem = chem;
			student_list.push_back(psci);
		}
		else{
			ArtsData* part = new ArtsData;
			part->numb = numb;
			part->name = name;
			part->sex = sex;
			part->type = type;
			part->math = math;
			part->chin = chin;
			part->engl = engl;
			part->geog = geog;
			part->hist = hist;
			student_list.push_back(part);
		}
	}
	ifs.close();
	return 0;
}

int StudentList::Save(){
	ofstream ofs("student.dat");
	if(!ofs) return -2;
	ofs << "Number\tName\tGender\tType\tMath\tChinese\tEnglish\t\
Geog\tHistory\tBiology\tPhysics\tChemics" << endl;
	list<StudentData*>::iterator it = student_list.begin();
	while(it != student_list.end()){
		StudentData* p1 = *it;
		if(p1->type == 0){
			ScienceData* p = (ScienceData*)p1;
			ofs << p->numb << "\t" << p->name << "\t" << p->sex 
			   	<< "\t" << p->type << "\t" << p->math << "\t" 
				<< p->chin << "\t" << p->engl << "\t" << 0 << "\t" 
				<< 0 << "\t"<< p->biol << "\t" << p->phys << "\t" 
			   	<< p->chem << endl;
		}
		else{
			ArtsData* p = (ArtsData*)p1;
			ofs << p->numb << "\t" << p->name << "\t" << p->sex  
				<< "\t" << p->type << "\t" << p->math << "\t" 
				<< p->chin << "\t" << p->engl << "\t" << p->geog 
				<< "\t" << p->hist << "\t" << 0 << "\t" << 0 
				<< "\t"  << 0 << endl;
		}
		it++;
	}
	ofs.close();
	return 0;
}



int StudentList::BrowseMenu(){
	cout << "1. Browse by name:" << endl;
	cout << "2. Browse by number:" << endl;
	cout << "3. Browse by gender:" << endl;
	cout << "4. Browse by type:" << endl;
	cout << "5. Browse by math:" << endl;
	cout << "6. Browse by average:" << endl;
	cout << "0. Quit!" << endl;

	int i;
	cin >> i;
	switch(i){
		case 1:
			Sort(ByName);
			Print();
			break;
		case 2:
			Sort(ByNumb);
			Print();
			break;
		case 3:
			Sort(ByGender);
			Print();
			break;
		case 4:
			Sort(ByType);
			Print();
			break;
		case 5:
			Sort(ByMath);
			Print();
			break;
		case 6:
			Sort(ByAverage);
			Print();
			break;
	}
	return i;
	
}
// Browse by name-order, number, gender, type, math, average score. 
int StudentList::Browse(){
	while(BrowseMenu())
		;
	return 0;
}

bool StudentList::IsExist(const int num){
	list<StudentData*>::iterator it = student_list.begin();
	while(it != student_list.end()){
		if(num == (*it)->numb){
			return true;
		}
		it++;
	}
	return false;
}

bool StudentList::IsExist(const int num, StudentData* &p){
	list<StudentData*>::iterator it = student_list.begin();
	while(it != student_list.end()){
		if(num == (*it)->numb){
			p = *it;
			return true;
		}
		it++;
	}
	p = nullptr;
	return false;
}
bool StudentList::Remove(int num){
	list<StudentData*>::iterator it = student_list.begin();
	while(it != student_list.end()){
		if(num == (*it)->numb){
			if((*it)->type == 1)
				*it = (ScienceData*)(*it);
			else
				*it = (ArtsData*)(*it);

//			delete *it;						// TBD
			student_list.erase(it);

			return true;
		}
		it++;
	}
	return false;

}

void StudentList::Remove(){
	Print();
	cout << "Please enter the number of student you want to remove: "\
	   	<< endl;
	int num;
	cin >> num;
	bool if_remove = Remove(num);
	if(!if_remove)
		cout << "The number " << num << " doesn't exist." << endl;
	Print();
}

void StudentList::Modify(){
	Print();
	cout << "Please enter the student number you want to modify:"\
	<< endl;
	int num;
	cin >> num;
	StudentData* pold = nullptr;
	while(!IsExist(num, pold)){
		Print();
		cout << "Doesn't exists, Please enter another number";
		cout << "[0 to exit]: "<< endl;
		cin >> num;
		if(!num)
			return;
	}
	
	cout << "Please enter the new type of student: " << endl;
	int type;
	cin >> type;
	StudentData* pnew = nullptr;
	if(type){
		ArtsData* p = new ArtsData;
		pnew = p->Input();
	}
	else{
		ScienceData* p = new ScienceData;
		pnew = p->Input();
	}
	if(IsExist(pnew->numb)){
		cout << "The new number is already exist, please ";
		cout << "try another number" << endl;
		return ;
	}

	cout << "Modify:" << endl;
	pold->Print();
	cout << "To:" << endl;
	pnew->Print();
	cout << "Y/N?" << endl;

	char confirm;
	cin >> confirm;
	if(confirm == 'y' | confirm == 'Y'){
		Remove(pold->numb);
		student_list.push_back(pnew);
	}
	Print();
}

void StudentList::SearchByName(){
	cout << ""
}

void StudentList::SearchByNumb(){

}

void StudentList::SearchByGend(){

}

void StudentList::SearchByType(){

}

void StudentList::SearchByMath(){


}

// search by name/number/gender/range_of_score
int StudentList::SearchMenu(){
	ClearScreen();
	cout << "1. Search by Name:" << endl;
	cout << "2. Search by Number:" << endl;
	cout << "3. Search by Gender:" << endl;
	cout << "4. Search by Type:" << endl;
	cout << "5. Search by Math Score:" << endl;
	cout << "0. Quit!" << endl;

	int i;
	cin >> i;
	switch(i){
		case 1:
			SearchByName();
		case 2:
			SearchByNumb();
		case 3:
			SearchByGend();
		case 4:
			SearchByType();
		case 5:
			SearchByMath();
		case 0:
			break;
	}
	return i;
}

int StudentList::Search(){		//Search menu
	SearchMenu();
	return 0;
}

void StudentList::Sort(funcp fp){
	list<StudentData*>::iterator i = student_list.begin();
	while(i != student_list.end()){
		list<StudentData*>::iterator j = i;
		// pj is alway previous than j by 1.
		list<StudentData*>::iterator pj = --j;
		++j;
		while(j != student_list.begin()){
			if(fp(*j, *pj))
				swap(*j, *pj);
			--j;
			--pj;
		}
		i++;
	}
}

// SortMenu is in BrowseMenu
void StudentList::Sort(){
	Sort(ByNumb);
	Print();
}

// normal SortByNumber
// void StudentList::Sort(){
// 	list<StudentData*>::iterator i = student_list.begin();
// 	while(i != student_list.end()){
// 		list<StudentData*>::iterator j = i;
// 		list<StudentData*>::iterator pj = --j;
// 		++j;
// 		while(j != student_list.begin()){
// 			if((*j)->numb < (*pj)->numb)
// 				swap(*j, *pj);
// 			--j;
// 			--pj;
// 		}
// 		i++;
// 	}
// 	Print();
// }
