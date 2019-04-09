#include"teacher.h"
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

StudentData* Teacher::InputStudent(){
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
	if(IsStudentExist(pres->numb, useless))
		cout << "The number is exist, Please try again: " << endl;
	else
		student_list.push_back(pres);
	return pres;
}

Teacher::Teacher(){
	LoadStudent();
}

Teacher::~Teacher(){
	SaveStudent();
	RemoveAllStudent();
}

void Teacher::PrintStudentTitle(){
	cout << "Number\tName\tGender\tType\tMath\tChinese\tEnglish\t\
Geog\tHistory\tBiology\tPhysics\tChemics" << endl;
}
void Teacher::PrintStudent(){
	ClearScreen();
	PrintStudentTitle();
	std::list<StudentData*>::iterator it = student_list.begin();
	for(; it != student_list.end(); it++){
		(*it)->Print();
	}
	cout << "Press any key to continue:" << endl;
	cin.ignore();
	cin.get();

}

void Teacher::Test(){
	while(TestMenu())
		;
}
int Teacher::TestMenu(){
	cout << "Test print, \t\ttype 1" << endl;		// done
	cout << "Test Browse, \t\ttype 2" << endl;		// done
	cout << "Test input, \t\ttype 3" << endl;		// done
	cout << "Test remove, \t\ttype 4" << endl;		// done
	cout << "Test modify, \t\ttype 5" << endl;		// done
	cout << "Test searchByName, \ttype 6" << endl;	// done
	cout << "Test search, \t\ttype 7" << endl;		// done
	cout << "Test byNumb, \t\ttype 8" << endl;		// done
	cout << "Test sort, \t\ttype 9" << endl;		// done
	cout << "Test freeRAM, \t\ttype 10" << endl;	// done
	cout << "Test removeAll, \ttype 11" << endl;	// done
	cout << "Test load, \t\ttype 12" << endl;		// done
	cout << "Test save, \t\ttype 13" << endl;		// done
	cout << "Test constructor, \ttype 14" << endl;	// done
	cout << "Test deconstructor, \ttype 15" << endl;// done
	cout << "Test isExist, \t\ttype 16" << endl;	// done
	cout << "QUIT, \t\t\ttype 0" << endl;

	int i;
	cin >> i;
	switch(i){
		case 1:
			PrintStudent();
			break;
		case 2:
			BrowseStudent();
			break;
		case 3:
			InputStudent();
			break;
		case 4:
			RemoveStudent();
			break;
		case 5:
			ModifyStudent();
			break;
		case 6:
			SearchStudentByName();
			break;
		case 7:
			SearchStudent();
			break;
		case 8:
			//ByNumb();
			break;
		case 9:
			SortStudent();
			break;
		case 10:
			//FreeRAM();
			break;
		case 11:
			//RemoveAll();
			break;
		case 12:
			LoadStudent();
			break;
		case 13:
			SaveStudent();
			break;
		case 14:
			Teacher();
			break;
		case 15:
			//~Teacher();
			break;
		case 16:
			//IsStudentExist();
			break;
		case 0:
			break;
	}
	return i;

}

int Teacher::LoadStudent(){
	int count = 0, head = 0;
	string line;
	float tmp = 0;
	ifstream ifs("./data/student.dat");
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

int Teacher::SaveStudent(){
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



int Teacher::BrowseStudentMenu(){
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
			SortStudent(ByName);
			PrintStudent();
			break;
		case 2:
			SortStudent(ByNumb);
			PrintStudent();
			break;
		case 3:
			SortStudent(ByGender);
			PrintStudent();
			break;
		case 4:
			SortStudent(ByType);
			PrintStudent();
			break;
		case 5:
			SortStudent(ByMath);
			PrintStudent();
			break;
		case 6:
			SortStudent(ByAverage);
			PrintStudent();
			break;
	}
	return i;
	
}
// BrowseStudent by name-order, number, gender, type, math, average score. 
int Teacher::BrowseStudent(){
	while(BrowseStudentMenu())
		;
	return 0;
}

bool Teacher::IsStudentExist(const int num){
	list<StudentData*>::iterator it = student_list.begin();
	while(it != student_list.end()){
		if(num == (*it)->numb){
			return true;
		}
		it++;
	}
	return false;
}

bool Teacher::IsStudentExist(const int num, StudentData* &p){
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

void Teacher::RemoveAllStudent(){
	list<StudentData*>::iterator it = student_list.begin();
	while(it != student_list.end()){
		delete *it;
		it++;
	}
	student_list.clear();
}

bool Teacher::RemoveStudent(int num){
	list<StudentData*>::iterator it = student_list.begin();
	while(it != student_list.end()){
		if(num == (*it)->numb){
			if((*it)->type == 1)
				*it = (ScienceData*)(*it);
			else
				*it = (ArtsData*)(*it);
			delete (*it);						// TBD
			student_list.erase(it);
			return true;
		}
		it++;
	}
	return false;

}

void Teacher::RemoveStudent(){
	PrintStudent();
	cout << "Please enter the number of student you want to remove: "\
	   	<< endl;
	int num;
	cin >> num;
	bool if_remove = RemoveStudent(num);
	if(!if_remove)
		cout << "The number " << num << " doesn't exist." << endl;
	PrintStudent();
}

void Teacher::ModifyStudent(){
	PrintStudent();
	cout << "Please enter the student number you want to modify:"\
	<< endl;
	int num;
	cin >> num;
	StudentData* pold = nullptr;
	while(!IsStudentExist(num, pold)){
		PrintStudent();
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
	if(IsStudentExist(pnew->numb)){
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
		RemoveStudent(pold->numb);
		student_list.push_back(pnew);
	}
	PrintStudent();
}

void Teacher::SearchStudentByName(){
	cout << "Please enter the name you want to search: ";
	string str;
	cin >> str;
	list<StudentData*>::iterator it = student_list.begin();
	PrintStudentTitle();
	while(it != student_list.end()){
		if((*it)->name == str){
			(*it)->Print();
			return;
		}
		it++;
	}
	cout << "Doesn't find the name " << str << "!" << endl;
}

void Teacher::SearchStudentByNumb(){
	cout << "Please enter the number you want to search: ";
	int num;
	cin >> num;
	list<StudentData*>::iterator it = student_list.begin();
	PrintStudentTitle();
	while(it != student_list.end()){
		if((*it)->numb == num){
			(*it)->Print();
			return;
		}
		it++;
	}
	cout << "Doesn't find the number " << num << "!" << endl;
}

void Teacher::SearchStudentByGend(){
	cout << "Please enter the Gender you want to search ";
	cout << "[0 for boy, 1 for girl]:";
	int count = 0;
	bool sex;
	cin >> sex;
	list<StudentData*>::iterator it = student_list.begin();
	PrintStudentTitle();
	while(it != student_list.end()){
		if((*it)->sex == sex){
			(*it)->Print();
			count++;
		}
		it++;
	}
	if(!count && sex)
		cout << "There is no Girl. " << endl;
	if(!count && !sex)
		cout << "There is no Boy." << endl;
}

void Teacher::SearchStudentByType(){
	cout << "Please enter the Type you want to search ";
	cout << "[0 for Science, 1 for Arts]:";
	int count = 0;
	bool type;
	cin >> type;
	list<StudentData*>::iterator it = student_list.begin();
	PrintStudentTitle();
	while(it != student_list.end()){
		if((*it)->type == type){
			(*it)->Print();
			count++;
		}
		it++;
	}
	if(!count && type)
		cout << "There is no Arts student. " << endl;
	if(!count && !type)
		cout << "There is no Science student." << endl;

}

void Teacher::SearchStudentByMath(){
	cout << "Please enter the range of math you want to search ";
	cout << "[Seperate with ' ']:";
	int count = 0;
	float min, max;
	cin >> min >> max;
	list<StudentData*>::iterator it = student_list.begin();
	PrintStudentTitle();
	while(it != student_list.end()){
		if((*it)->math >= min && (*it)->math <= max){
			(*it)->Print();
			count++;
		}
		it++;
	}
	if(!count)
		cout << "There is no student meet the requirment." << endl;
}

// search by name/number/gender/range_of_score
int Teacher::SearchStudentMenu(){
	ClearScreen();
	cout << "1. Search by Name: " << endl;
	cout << "2. Search by Number: " << endl;
	cout << "3. Search by Gender: " << endl;
	cout << "4. Search by Type: " << endl;
	cout << "5. Search by Math Score: " << endl;
	cout << "0. Quit!" << endl;

	int i;
	cin >> i;
	cout << endl;
	switch(i){
		case 1:
			SearchStudentByName();
			break;
		case 2:
			SearchStudentByNumb();
			break;
		case 3:
			SearchStudentByGend();
			break;
		case 4:
			SearchStudentByType();
			break;
		case 5:
			SearchStudentByMath();
			break;
		case 0:
			break;

	}
	cout << "Press any key to continue: " ;
	cin.ignore();
	cin.get();
	return i;
}

int Teacher::SearchStudent(){		//Search menu
	while(SearchStudentMenu())
		;
	return 0;
}

void Teacher::SortStudent(funcp fp){
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

// SortMenu is in BrowseStudentMenu
void Teacher::SortStudent(){
	SortStudent(ByNumb);
	PrintStudent();
}

// normal SortByNumber
// void Teacher::SortStudent(){
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
