#include"manager.h"
#include<iostream>
#include<sstream>
#include<fstream>
using namespace std;

static ManagerData* current_manager = nullptr;

static void ClearScreen(){
	cout << "\033[2J\033[1;1H";
}
static void PrintTitle(){
	cout << "Number\tName\tGender\tPRI\tPasswd" << endl;
}
static void PrintCurrentManager(){
	if(current_manager){
		PrintTitle();
		current_manager->Print();
	}
	else{
		cout << "Status: Unlogged" << endl;
	}
	cout << endl;
}

void ManagerData::Print(){
	string pri;
	string gender;
	if(this->sex)
		gender = "Women";
	else
		gender = "Men";

	if(this->prio == 0)
		pri = "Super";
	else if(this->prio == 1)
		pri = "Admin";
	else if(this->prio == 2)
		pri = "Teacher";
	else if(this->prio == 3)
		pri = "Student";

	cout << this->numb << '\t' << this->name << '\t' \
		<< gender << '\t' << pri << '\t' \
		<< this->passwd << endl;
}

void ManagerList::Print(){
	list<ManagerData*>::iterator it = manager_list.begin();
	PrintTitle();
	while(it != manager_list.end()){
		(*it)->Print();
		it++;
	}
	cout << "Press any key to continue: ";
	cin.ignore();
	cin.get();
}

ManagerData* ManagerData::Input(){
	cout << "Please input the manager Number, Name, Gender, Password \
and Priority[Seperate with ' ']" << endl;
	cin >> this->numb >> this->name >> this->sex >> this->passwd\
		>> this->prio;
	return this;
}

void ManagerList::Input(){
	char c;
	do{
		ManagerData* p = new ManagerData;
		p->Input();
		if(IsExist(p->numb) == manager_list.end()){	// doesn't exist
			manager_list.push_back(p);
			cout << "Continue to input? [Y/N] " ;
			cin.ignore();
			cin >> c; 
		} 
		else{
			cout << "Number exists, please try another number" << endl;
			cin.clear();
			cin.ignore(10000, '\n');
			delete p;
			c = 'y';
			continue;
		}
	}while(c == 'Y' || c == 'y');
}
ManagerList::ManagerList(){
	Load();
}

ManagerList::~ManagerList(){
	Save();
	RemoveAllHelper();
}

void ManagerList::Load(){
	ifstream ifs;
	ifs.open("manager.dat");
	string line;
	int head = 0;
	while(getline(ifs, line)){
		if(head == 0){
			head++;
			continue;
		}
		ManagerData* p = new ManagerData;
		istringstream is;
		is.str(line);
		is >> p->numb >> p->name >> p->sex >> p->prio >> p->passwd;
		manager_list.push_back(p);
	}
	ifs.close();
}

void ManagerList::Save(){
	ofstream ofs;
	ofs.open("manager.dat");
	ofs << "Number" << '\t' << "Name" << '\t' << "Gender" << '\t'\
		<< "PRI" << '\t' << "Passwd" << '\n';
	list<ManagerData*>::iterator it = manager_list.begin();
	while(it != manager_list.end()){
		ofs << (*it)->numb << '\t' << (*it)->name << '\t'\
			<< (*it)->sex  << '\t' << (*it)->prio << '\t'\
			<< (*it)->passwd << '\n';
		it++;
	}
	ofs.close();
}

list<ManagerData*>::iterator ManagerList::IsExist(const int num){
	list<ManagerData*>::iterator it = manager_list.begin();
	while(it != manager_list.end()){
		if((*it)->numb == num){
			return it;
		}
		it++;
	}
	return it;
}

// ManagerData* ManagerList::IsExist(const int num){
// 	list<ManagerData*>::iterator it = manager_list.begin();
// 	while(it != manager_list.end()){
// 		if((*it)->numb == num){
// 			return *it;
// 		}
// 		it++;
// 	}
// 	return nullptr;
// }
// 
bool ManagerList::LoginHelper(){
	cout << "Please enter your number: " << endl;
	int num;
	string passwd;
	cin >> num;
	cin.clear();
	cin.ignore(10000, '\n');
	list<ManagerData*>::iterator it = IsExist(num);
	ManagerData* p = *it;
	if(it != manager_list.end()){
		cout << "Please enter your password: " << endl;
		cin >> passwd;
		if(p->passwd == passwd){
			cout << "Welcome! " << p->name << endl;
			current_manager = p;
			return true;
		}
		else{
			cout << "Wrong password, ";
			return false;
		}
	}
	else{
		cout << "The number doesn't exist, ";
		return false;
	}
}

bool ManagerList::Login(){
	char quit;
	bool success = false;
	while(!success){
		success = LoginHelper();
		if(success)
			break;
		cout << "[# to EXIT / otherwise TRY AGIAN]: ";
		cin >> quit;
		if(quit == '#')
			break;
	}
	cout << "Press any key to continue: " ;
	cin.ignore();
	cin.get();
	return success;
}

void ManagerList::Logout(){
	current_manager = nullptr;
}

bool ManagerList::RemoveAllHelper(){
	list<ManagerData*>::iterator it = manager_list.begin();
	while(it != manager_list.end()){
		delete *it;
		it++;
	}
	manager_list.clear();
	return true;
}

void ManagerList::RemoveAll(){
	Print();
	cout << "Really remove all of the managers data[Y/N]?" << endl;
	char confirm;
	bool success = false;
	cin >> confirm;
	if(confirm == 'y' || confirm == 'Y'){
		success = RemoveAllHelper();
	}
	if(success)
		cout << "Done! You have removed all the managers data."<<endl;
	else
		cout << "Remove is fail!" << endl;

}
bool ManagerList::RemoveHelper(){
	cout << "Please enter the number of manager you want to delete: ";
	int num;
	cin >> num;
	cin.clear();
	cin.ignore(10000, '\n');
	list<ManagerData*>::iterator it = IsExist(num);
	ManagerData* p = *it;
	if(it == manager_list.end()){
		cout << "The number you have input in not exist! ";
		return false;
	}
	else{
		(*it)->Print();
		cout << "Please Confirm! Really Delete? [Y/N] ";
		char confirm;
		cin >> confirm;
		if(confirm == 'Y' || confirm == 'y'){
			manager_list.erase(it);
			return true;
		}
	}
	return false;
}

void ManagerList::Remove(){
	char confirm;
	do{
		RemoveHelper();
		cout << "Continue to remove? [Y/N]" ;
		cin >> confirm;
	}while(confirm == 'Y' || confirm == 'y');
}

bool ManagerList::ModifyHelper(){
	cout << "Please enter the number of manager you want to modify: ";
	int num;
	cin >> num;
	cin.clear();
	cin.ignore(10000, '\n');
	list<ManagerData*>::iterator it = IsExist(num);
	ManagerData* p = *it;
	if(it == manager_list.end()){
		cout << "The number you have input in not exist! ";
		return false;
	}
	else{
		ManagerData *new_manager = new ManagerData;
		new_manager->Input();
		cout << "Please Confirm! Really Modify From:" << endl;
		(*it)->Print();
		cout << "To:"<< endl;
		new_manager->Print();
		cout << "[Y/N]? " << endl;
		char confirm;
		cin >> confirm;
		if(confirm == 'Y' || confirm == 'y'){
			manager_list.erase(it);
			manager_list.push_back(new_manager);
			return true;
		}
	}
	return false;
}

void ManagerList::Modify(){
	char confirm;
	Print();
	do{
		ModifyHelper();
		cout << "Continue to modify? [Y/N]" ;
		cin >> confirm;
	}while(confirm == 'Y' || confirm == 'y');
}

void ManagerList::SortByName(){
	list<ManagerData*>::iterator i = manager_list.begin();
	list<ManagerData*>::iterator j, pj;	// pj is previous of j
	if(manager_list.size() <= 1) 
		return;
	i++;
	while(i != manager_list.end()){
		// Insertion Sort
		j = i;
		pj = --i;
		++i;

		while(j != manager_list.begin() && (*j)->numb < (*pj)->numb){
			*j = *pj;
			--j;
			--pj;
		}
		*j = *i;
		i++;
	}
}

void ManagerList::Sort(){
	SortByName();
	Print();
}

int ManagerList::TestMenu(){
	ClearScreen();
	PrintCurrentManager();
// print 					done
// login and logout			done
// input by superuser 		done
// change password			
// remove by super			done
// modify by super 			done
	cout << "Test print, \t\ttype 1" << endl;			// done 
	cout << "Test login, \t\ttype 2" << endl;			// done
	cout << "Test input by super, \ttype 3" << endl;	// done 
	cout << "Test logout, \t\ttype 4" << endl;			// done
	cout << "Test remove by super, \ttype 5" << endl;	// done 
	cout << "Test modify, \t\ttype 6" << endl;			// done 
	cout << "Test sort, \t\ttype 7" << endl;			// done
	cout << "Test removeAll, \ttype 8" << endl;			// done

	cout << "Test load, \t\ttype 9" << endl;			// done
	cout << "Test save, \t\ttype 10" << endl;			// done

	cout << "Test constructor, \ttype 11" << endl;		// done
	cout << "Test deconstructor, \ttype 11" << endl;	// done
	cout << "Test isExist, \t\ttype 12" << endl;		// done
	cout << "Test change password, \ttype 12" << endl;	// 
	cout << "QUIT, \t\t\ttype 0" << endl;

	int i;
	cin >> i;
	switch(i){
		case 1:
			Print();
			break;
		case 2:
			Login();
			break;
		case 3:
			Input();
			break;
		case 4:
			Logout();
			break;
		case 5:
			Remove();
			break;
		case 6:
			Modify();
			break;
		case 7:
			Sort();
			break;
		case 8:
			RemoveAll();
			break;
		case 9:
			Load();
			break;
		case 10:
			Save();
			break;
		case 11:
			ManagerList();
			//~ManagerList();
			break;
		case 12:
			//IsExist();
			//ChangePassword();
			break;
		case 0:
			break;
	}
	return i;

}

void ManagerList::Test(){
	while(TestMenu())
		;
}
