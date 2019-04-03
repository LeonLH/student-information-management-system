#include"manager-list.h"
#include<iostream>
#include<sstream>
#include<fstream>
using namespace std;


static void PrintTitle(){
	cout << "Name\tNumber\tGender\tPriority" << endl;
}

ManagerList::ManagerList(){
	Load();
}

ManagerList::~ManagerList(){
	Save();
	RemoveAll();
}

void ManagerData::Print(){
	cout << this->numb << this->name << this->sex \
		<< this->prio << endl;
}


void ManagerData::Input(){
	cout << "Please input the manager Number, Name, Gender and "\
	   	<< "Priority[Seperate with ' ']" << endl;
	cin >> this->numb >> this->name >> this->sex >> this->prio;
}

void ManagerList::Print(){
	list<ManagerData*>::iterator it = manager_list.begin();
	PrintTitle();
	while(it != manager_list.end()){
		(*it)->Print();
		it++;
	}
}

void ManagerList::Load(){
	ifstream ifs;
	ifs.open("manager.dat");
	string line;
	int head = 0;
	while(getline(ifs, line)){
		if(head == 0)
			continue;
		ManagerData* p = new ManagerData;
		istringstream is;
		is.str(line);
		is >> p->numb >> p->name >> p->sex >> p->prio;
		manager_list.push_back(p);
	}
	ifs.close();
}

void ManagerList::Save(){
	ofstream ofs;
	ofs.open("manager.dat");
	ofs << "Name" << '\t' << "Number" << '\t' << "Gender" << '\t'\
		<< "Priority" << '\n';
	list<ManagerData*>::iterator it = manager_list.begin();
	while(it != manager_list.end()){
		ofs << (*it)->name << '\t' << (*it)->numb << '\t'\
			<< (*it)->sex  << '\t' << (*it)->prio << '\n';
		it++;
	}
	ofs.close();
}

int ManagerList::Test(){
	cout << "Test print, \t\ttype 1" << endl;		// 
	cout << "Test browse, \t\ttype 2" << endl;		// 
	cout << "Test input, \t\ttype 3" << endl;		// 
	cout << "Test remove, \t\ttype 4" << endl;		// 
	cout << "Test modify, \t\ttype 5" << endl;		// 
	cout << "Test sort, \t\ttype 6" << endl;		// 
	cout << "Test removeAll, \ttype 7" << endl;	// 
	cout << "Test load, \t\ttype 8" << endl;		// 
	cout << "Test save, \t\ttype 9" << endl;		// 
	cout << "Test constructor, \ttype 10" << endl;	// 
	cout << "Test deconstructor, \ttype 11" << endl;// 
	cout << "Test isExist, \t\ttype 12" << endl;	// 
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
			Insert();
			break;
		case 4:
			Remove();
			break;
		case 5:
			Modify();
			break;
		case 6:
			Sort();
			break;
		case 7:
			//RemoveAll();
			break;
		case 8:
			Load();
			break;
		case 9:
			Save();
			break;
		case 10:
			ManagerList();
			break;
		case 11:
	//		~ManagerList();
			break;
		case 12:
			//IsExist();
			break;
		case 0:
			break;
	}
	return i;

}

