#include<fstream>
#include<list>
#include<iostream>
#include<sstream>


#include"mytools/normal_tools.h"
#include"enter.h"

using namespace std;

list<Student*> student_list;
list<Teacher*> teacher_list;
NormalTools tools;
Person* current_person;
int an_external_integer;

void Enter::Welcome(){

	tools.ClearScreen();
	cout << "This software is writen by Leon. Enjoy it!\n"\
		<< "Please do not hesitate to contact me if you have any "\
		<< "questions. My email is XXX@126.com."<< endl;
	tools.PressAnyKeyToContinue();
}

bool Enter::LoadStudent(){
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
		string name, pw;
		bool sex, type;
		float math, chin, engl, geog, hist, biol, phys, chem;
		is >> numb >> name >> sex >> type >> math >> chin >> \
			  engl >> geog >> hist >> biol >> phys >> chem >> pw;
		if(type == 0){
			ScienceStudent* psci = new ScienceStudent;
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
			psci->pw = pw;
			student_list.push_back(psci);
		}
		else{
			ArtsStudent* part = new ArtsStudent;
			part->numb = numb;
			part->name = name;
			part->sex = sex;
			part->type = type;
			part->math = math;
			part->chin = chin;
			part->engl = engl;
			part->geog = geog;
			part->hist = hist;
			part->pw = pw;
			student_list.push_back(part);
		}
	}
	ifs.close();
	return true;
}

bool Enter::LoadTeacher(){
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

Person* Enter::IsPersonExist(const int num){
	list<Teacher*>::iterator it = teacher_list.begin();
	while(it != teacher_list.end()){
		if((*it)->numb == num){
			return *it;
		}
		it++;
	}
	list<Student*>::iterator it_student = student_list.begin();
	while(it_student != student_list.end()){
		if((*it_student)->numb == num){
			return *it_student;
		}
		it_student++;
	}
	return nullptr;
}

// 1. clear screen
// 2. get into a loop, this loop can login for many times, until 
// 		entered a '#'
// 3. 
bool Enter::LoginHelper(){
	cout << "Please enter your number: " << endl;
	int num;
	string passwd;
	cin >> num;
	if(cin.fail()){
		cout << "Please enter a number rather than a string." << endl;
		cin.clear();
		cin.ignore(10000, '\n');
		return false;
	}
	Person* p = IsPersonExist(num);
	if(p){
		cout << "Please enter your password: " << endl;
		cin >> passwd;
		if((*p).pw == passwd){
			cout << "Welcome! " << p->name << endl;
			current_person = p;
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

bool Enter::Login(){
	tools.ClearScreen();
	char quit;
	bool success = false;
	while(!success){
		cout << "This is Login page." << endl;
		success = LoginHelper();
		if(success)
			break;
		else{
			cout << "[# to EXIT / anyother key to continue trying]: ";
			cin.ignore(99999, '\n');
			quit = cin.get(); // >> quit;
		}
		if(quit == '#')
			break;
	}
	if(success){
		cout << "Login successful!" << endl;
	}
	else{
		cout << "Login fail!" << endl;
	}
	cout << "Press any key to continue: " ;
	cin.ignore();
	cin.get();
	return success;
}

bool Enter::Logout(){
	cout << "Thanks for using, see you!" <<endl;
	return true;

}
void Enter::Run(){
	LoadStudent();
	LoadTeacher();
	Login();
	if(current_person->prio == 0 || current_person->prio == 1){
		Admin* admin = (Admin*)current_person;
		admin->Run();
	}
	else if(current_person->prio == 2){
		Teacher* teacher = (Teacher*)current_person;
		teacher->Run();
	}
	else if(current_person->prio == 3){
		Student* student = (Student*)current_person;
		student->Run();
	}
	SaveStudent();
	SaveTeacher();

}



bool Enter::SaveTeacher(){
	ofstream ofs;
	ofs.open("data/teacher.dat");
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

bool Enter::SaveStudent(){
	ofstream ofs("data/student.dat");
	if(!ofs) return -2;
	ofs << "Number\tName\tGender\tType\tMath\tChinese\tEnglish\t\
Geog\tHistory\tBiology\tPhysics\tChemics\tPw" << endl;
	list<Student*>::iterator it = student_list.begin();
	while(it != student_list.end()){
		Student* p1 = *it;
		if(p1->type == 0){
			ScienceStudent* p = (ScienceStudent*)p1;
			ofs << p->numb << "\t" << p->name << "\t" << p->sex 
			   	<< "\t" << p->type << "\t" << p->math << "\t" 
				<< p->chin << "\t" << p->engl << "\t" << 0 << "\t" 
				<< 0 << "\t"<< p->biol << "\t" << p->phys << "\t" 
			   	<< p->chem << "\t" << p->pw << endl;
		}
		else{
			ArtsStudent* p = (ArtsStudent*)p1;
			ofs << p->numb << "\t" << p->name << "\t" << p->sex  
				<< "\t" << p->type << "\t" << p->math << "\t" 
				<< p->chin << "\t" << p->engl << "\t" << p->geog 
				<< "\t" << p->hist << "\t" << 0 << "\t" << 0 
				<< "\t"  << 0 << "\t" << p->pw << endl;
		}
		it++;
	}
	ofs.close();
	return true;
}


int main(){
	Enter enter;
	enter.Welcome();
	enter.Run();
	enter.Logout();
	return 0;
}
