#include"admin.h"
#include<iostream>
#include<sstream>
#include<fstream>
#include"mytools/normal_tools.h"

using namespace std;

extern NormalTools tools;
extern Person* current_person;
extern list<Teacher*> teacher_list;

static Teacher* current_teacher = nullptr;
static void ClearScreen(){
cout << "\033[2J\033[1;1H";
}
static void PrintTitle(){
	cout << "Number\tName\tGender\tPRI\tPasswd" << endl;
}
static void PrintCurrentManager(){
	if(current_teacher){
		PrintTitle();
		current_teacher->Print();
	}
	else{
		cout << "Status: Unlogged" << endl;
	}
	cout << endl;
}

void Admin::PrintTeacher(){
	list<Teacher*>::iterator it = teacher_list.begin();
	PrintTitle();
	while(it != teacher_list.end()){
		(*it)->Print();
		it++;
	}
	cout << "Press any key to continue: ";
	cin.ignore();
	cin.get();
}

void Admin::InputTeacher(){
	char c;
	do{
		Teacher* p = new Teacher;
		p->Input();
		if(IsTeacherExist(p->numb) == teacher_list.end()){	// doesn't exist
			teacher_list.push_back(p);
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

Admin::~Admin(){
	//SaveTeacher();
	//RemoveAllTeacherHelper();
}

bool Admin::LoadTeacher(){
	ifstream ifs;
	ifs.open("./data/teacher.dat");
	string line;
	int head = 0;
	while(getline(ifs, line)){
		if(head == 0){
			head++;
			continue;
		}
		Teacher* p = new Teacher;
		istringstream is;
		is.str(line);
		is >> p->numb >> p->name >> p->sex >> p->prio >> p->pw;
		teacher_list.push_back(p);
	}
	ifs.close();
	if(teacher_list.empty())
		return false;
	else
		return true;
}

bool Admin::SaveTeacher(){
	ofstream ofs;
	ofs.open("./data/teacher.dat");
	ofs << "Number" << '\t' << "Name" << '\t' << "Gender" << '\t'\
		<< "PRI" << '\t' << "Passwd" << '\n';
	list<Teacher*>::iterator it = teacher_list.begin();
	while(it != teacher_list.end()){
		ofs << (*it)->numb << '\t' << (*it)->name << '\t'\
			<< (*it)->sex  << '\t' << (*it)->prio << '\t'\
			<< (*it)->pw << '\n';
		it++;
	}
	ofs.close();
	if(it == teacher_list.end())
		return true;
	else
		return false;
}

list<Teacher*>::iterator Admin::IsTeacherExist(const int num){
	list<Teacher*>::iterator it = teacher_list.begin();
	while(it != teacher_list.end()){
		if((*it)->numb == num){
			return it;
		}
		it++;
	}
	return it;
}

// bool Admin::LoginHelper(){
// 	cout << "Please enter your number: " << endl;
// 	int num;
// 	string passwd;
// 	cin >> num;
// 	cin.clear();
// 	cin.ignore(10000, '\n');
// 	list<Teacher*>::iterator it = IsTeacherExist(num);
// 	Teacher* p = *it;
// 	if(it != teacher_list.end()){
// 		cout << "Please enter your password: " << endl;
// 		cin >> passwd;
// 		if(p->pw == passwd){
// 			cout << "Welcome! " << p->name << endl;
// 			current_teacher = p;
// 			return true;
// 		}
// 		else{
// 			cout << "Wrong password, ";
// 			return false;
// 		}
// 	}
// 	else{
// 		cout << "The number doesn't exist, ";
// 		return false;
// 	}
// }
// 
// bool Admin::Login(){
// 	char quit;
// 	bool success = false;
// 	while(!success){
// 		success = LoginHelper();
// 		if(success)
// 			break;
// 		cout << "[# to EXIT / otherwise TRY AGIAN]: ";
// 		cin >> quit;
// 		if(quit == '#')
// 			break;
// 	}
// 	cout << "Press any key to continue: " ;
// 	cin.ignore();
// 	cin.get();
// 	return success;
// }

bool Admin::Logout(){
	current_teacher = nullptr;
	return true;
}

bool Admin::RemoveAllTeacherHelper(){
	list<Teacher*>::iterator it = teacher_list.begin();
	while(it != teacher_list.end()){
		delete *it;
		it++;
	}
	teacher_list.clear();
	return true;
}

void Admin::RemoveAllTeacher(){
	PrintTeacher();
	cout << "Really remove all of the teachers data[Y/N]?" << endl;
	char confirm;
	bool success = false;
	cin >> confirm;
	if(confirm == 'y' || confirm == 'Y'){
		success = RemoveAllTeacherHelper();
	}
	if(success)
		cout << "Done! You have removed all the teachers data."<<endl;
	else
		cout << "Remove is fail!" << endl;

}
bool Admin::RemoveTeacherHelper(){
	cout << "Please enter the number of teacher you want to delete: ";
	int num;
	cin >> num;
	cin.clear();
	cin.ignore(10000, '\n');
	list<Teacher*>::iterator it = IsTeacherExist(num);
	Teacher* p = *it;
	if(it == teacher_list.end()){
		cout << "The number you have input in not exist! ";
		return false;
	}
	else{
		(*it)->Print();
		cout << "Please Confirm! Really Delete? [Y/N] ";
		char confirm;
		cin >> confirm;
		if(confirm == 'Y' || confirm == 'y'){
			teacher_list.erase(it);
			return true;
		}
	}
	return false;
}

void Admin::RemoveTeacher(){
	char confirm;
	do{
		RemoveTeacherHelper();
		cout << "Continue to remove? [Y/N]" ;
		cin >> confirm;
	}while(confirm == 'Y' || confirm == 'y');
}

bool Admin::ModifyTeacherHelper(){
	cout << "Please enter the number of teacher you want to modify: ";
	int num;
	cin >> num;
	cin.clear();
	cin.ignore(10000, '\n');
	list<Teacher*>::iterator it = IsTeacherExist(num);
	Teacher* p = *it;
	if(it == teacher_list.end()){
		cout << "The number you have input in not exist! ";
		return false;
	}
	else{
		Teacher *new_teacher = new Teacher;
		new_teacher->Input();
		cout << "Please Confirm! Really Modify From:" << endl;
		(*it)->Print();
		cout << "To:"<< endl;
		new_teacher->Print();
		cout << "[Y/N]? " << endl;
		char confirm;
		cin >> confirm;
		if(confirm == 'Y' || confirm == 'y'){
			teacher_list.erase(it);
			teacher_list.push_back(new_teacher);
			return true;
		}
	}
	return false;
}

void Admin::ModifyTeacher(){
	char confirm;
	PrintTeacher();
	do{
		ModifyTeacherHelper();
		cout << "Continue to modify? [Y/N]" ;
		cin >> confirm;
	}while(confirm == 'Y' || confirm == 'y');
}

void Admin::SortTeacherByName(){
	list<Teacher*>::iterator i = teacher_list.begin();
	list<Teacher*>::iterator j, pj;	// pj is previous of j
	if(teacher_list.size() <= 1) 
		return;
	i++;
	while(i != teacher_list.end()){
		// Insertion Sort
		j = i;
		pj = --i;
		++i;

		while(j != teacher_list.begin() && (*j)->numb < (*pj)->numb){
			*j = *pj;
			--j;
			--pj;
		}
		*j = *i;
		i++;
	}
}

void Admin::SortTeacher(){
	SortTeacherByName();
	PrintTeacher();
}

void Admin::Run(){
	current_teacher = (Teacher*)current_person;
	while(Menu())
		;
	//cout << "You are a good administrator!" << endl;
}

// normal admin can do: manipulate teacher_list, change own password
int Admin::Menu(){
	tools.ClearScreen();
	PrintCurrentManager();
	cout << "Print teacher, \t\ttype 1" << endl;			
	cout << "Add a teacher, \t\ttype 2" << endl;	
	cout << "Remove a teacher, \ttype 3" << endl;
	cout << "Modify teachers, \ttype 4" << endl;
	cout << "Sort teacher info, \ttype 5" << endl;			
	cout << "Remove all teachers, \ttype 6" << endl;	
	cout << "Change password, \ttype 7" << endl;
	cout << "Logout, \t\ttype 8" << endl;	
	cout << "QUIT, \t\t\ttype 0" << endl;
	
	int i;
	cin >> i;
	switch(i){
		case 1:
			PrintTeacher();
			break;
		case 2:
			Input();
			break;
		case 3:
			RemoveTeacher();
			break;
		case 4:
			ModifyTeacher();
			break;
		case 5:
			SortTeacher();
			break;
		case 6:
			RemoveAllTeacher();
			break;
		case 7:
			ChangePassword();
			break;
		case 8:
			Logout();
			break;
		case 0:
			break;
	}
	return i;

	// print current person
}

int Admin::TestAdminMenu(){
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
			PrintTeacher();
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
			RemoveTeacher();
			break;
		case 6:
			ModifyTeacher();
			break;
		case 7:
			SortTeacher();
			break;
		case 8:
			RemoveAllTeacher();
			break;
		case 9:
			LoadTeacher();
			break;
		case 10:
			SaveTeacher();
			break;
		case 11:
			Admin();
			//~Admin();
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

void Admin::TestAdmin(){
	while(TestAdminMenu())
		;
}
