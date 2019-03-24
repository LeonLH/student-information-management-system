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
	return p1->math < p2->math;
}


StudentList::StudentList(){
	Load();
}

StudentList::~StudentList(){
	Save();
}

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

void StudentList::Print(){
	ClearScreen();
	cout << "Number\tName\tGender\tType\tMath\tChinese\tEnglish\t\
Geog\tHistory\tBiology\tPhysics\tChemics" << endl;
	std::list<StudentData*>::iterator it = student_list.begin();
	for(; it != student_list.end(); it++){
		StudentData* p = *it;
		if(p->type == 0){
			ScienceData* p0 = (ScienceData*)p;
			p0->Print();
		}
		else{
			ArtsData* p1 = (ArtsData*)p;
			p1->Print();
		}
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
			//SearchByName();
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

ArtsData* ArtsData::Input(){
	ArtsData* p = new ArtsData;
	p->type = 1;
	cout << "Please enter your Number, Name, Gender, Math, "\
		<< "Chinese, English, Geograph, History: "<< endl;
	cin >> p->numb >> p->name >> p->sex  >> p->math  \
		>> p->chin >> p->engl >> p->geog >> p->hist; 
	return p;
}

ScienceData* ScienceData::Input(){
	ScienceData* p = new ScienceData;
	p->type = 0;
	cout << "Please enter your Number, Name, Gender, Math, "\
		<< "Chinese, English, Biology, Physics and Chemics: "\
		<< endl;
	cin >> p->numb >> p->name >> p->sex  >> p->math  \
		>> p->chin >> p->engl >> p->biol >> p->phys  \
		>> p->chem;
	return p;
}

StudentData* StudentList::Input(){
	cout << "Please type your type(0 for science, 1 for arts)? ";
	bool btype;
	cin >> btype;
	StudentData* pres = nullptr;
	if(btype == 0){
		ScienceData* p = new ScienceData;
		p->type = 0;
		cout << "Please enter your Number, Name, Gender, Math, "\
			<< "Chinese, English, Biology, Physics and Chemics: "\
			<< endl;
		cin >> p->numb >> p->name >> p->sex  >> p->math  \
			>> p->chin >> p->engl >> p->biol >> p->phys  \
			>> p->chem;
		student_list.push_back(p);
		pres = p;
	}
	else{
		ArtsData* p = new ArtsData;
		p->type = 1;
		cout << "Please enter your Number, Name, Gender, Math, "\
			<< "Chinese, English, Geograph, History: "<< endl;
		cin >> p->numb >> p->name >> p->sex  >> p->math  \
			>> p->chin >> p->engl >> p->geog >> p->hist; 
		student_list.push_back(p);
		pres = p;
	}
	return pres;
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
void StudentList::Remove(){
	Print();
	cout << "Please enter the number of student you want to remove: "\
	   	<< endl;
	int num;
	cin >> num;

	list<StudentData*>::iterator it = student_list.begin();
	while(it != student_list.end()){
		if(num == (*it)->numb){
			if((*it)->type == 1)
				*it = (ScienceData*)(*it);
			else
				*it = (ArtsData*)(*it);

			delete *it;
			student_list.erase(it);
			break;
		}
		it++;
	}
	Print();
	if(it == student_list.end())
		cout << "The number " << num << " doesn't exist." << endl;
}

// to be done with implementation of polymorphism in next version.
void StudentList::Modify(){
	cout << "Please enter the student number you want to modify:"\
	<< endl;
	int num;
	cin >> num;
	StudentData* pold = nullptr;
	while(!IsExist(num, pold)){
		cout << "Doesn't exists, Please enter another number: "<<endl;
		cin >> num;
	}
	
	cout << "Please enter the new type of student: " << endl;
	int type;
	cin >> type;
	StudentData* pnew = nullptr;
	if(type)
		pnew = ((ArtsData*)pnew)->Input();
	else
		pnew = ((ScienceData*)pnew)->Input();

	cout << "Are you sure? Replace:" << endl;
	if(pold->type)
		((ArtsData*)pold)->Print();
	else
		((ScienceData*)pold)->Print();
	
	cout << "To: " << endl;
	if(pnew->type)
		((ArtsData*)pnew)->Print();
	else
		((ScienceData*)pnew)->Print();
	bool confirm;
	cin >> confirm;
	
	if(confirm){
		list<StudentData*>::iterator it = student_list.begin();
		while(it != student_list.end()){
			if((*it)->numb == num)
				*it = pnew;
			++it;
		}
	}

	if(pold->type)
		delete ((ArtsData*)pold);
	else
		delete ((ScienceData*)pold);

}

// search by name/number/gender
int StudentList::Search(){
	
	return 0;
}

// sort by name/number/average-score by using function pointer
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
