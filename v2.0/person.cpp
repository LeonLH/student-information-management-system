#include"person.h"
#include<iostream>
#include<list>
using namespace std;

static Person* current_person = 0;

Person* Person::IsPersonExist(int num){
	return nullptr;
}

Person* Person::IsNumberAndPwMatch(int num, string pw){
	return nullptr;
}

bool Person::LoginHelper(){
	cout << "Please enter your number:\t";
	int num;
	cin >> num;
	cin.clear();
	cin.ignore(10000, '\n');
	cout << "Please enter your password:\t";
	string password;
	cin >> password;
	cin.clear();
	cin.ignore(10000, '\n');
	current_person = IsNumberAndPwMatch(num, password);
	return current_person;
}

bool Person::Login(){
	bool success = false;
	char quit;
	while(!success && !current_person){
		LoginHelper();
		if(current_person){
			cout << "Welcome, " << current_person->name << "!" << endl;
			success = true;
			break;
		}
		else{
			cout << "Sorry, the number or password is wrong" ;
		}
		cout << "[# to EXIT / otherwise TRY AGIAN]: ";
		cin >> quit;
		if(quit == '#')
			break;
	}
 	return success;
}

bool Person::Logout(){
	//current_manager = nullptr;
	return true;
}

bool Person::ChangePassword(){
	cout << "Please enter your name: " << endl;
	string name;


	return true;
}


