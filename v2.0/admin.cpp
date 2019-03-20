#include "admin.h"
#include<cstdlib>
#include<iostream>
using namespace std;

Admin::Admin(){

}

Admin::~Admin(){

}

void Admin::Welcome(){
	cout << "\033[2J\033[1;1H";
	cout << endl;
	cout << endl;
	puts("\t**************************************************************");
	puts("\t**************************************************************");
	puts("\t**************************************************************");
	puts("\t**************************************************************");
	puts("\t***********                                        ***********");
	puts("\t***********  Student Infomation Management System  ***********");
	puts("\t***********                                        ***********");
	puts("\t**************************************************************");
	puts("\t**************************************************************");
	puts("\t**********************************************  by LeonLH  ***");
	puts("\t**************************************************************");
	puts("\t**************************************************************");
	cout << endl;
	cout << "\tPress Enter key to continue..." << endl;
	fgetc(stdin);
}

int Admin::Login(){
	return 0;
}

int Admin::Menu(){
	cout << "\033[2J\033[1;1H";
	cout << endl;
	cout << endl;
	puts("\t*******************************************************");
	puts("\t*******************************************************");
	puts("\t*******************************************************");
	puts("\t**************  1. Add Students' Info     *************");
	puts("\t**************  2. Browse Students' Info  *************");
	puts("\t**************  3. Delete Students' Info  *************");
	puts("\t**************  4. Modify Students' Info  *************");
	puts("\t**************  5. Search Students' Info  *************");
	puts("\t**************  6. Modify Password        *************");
	puts("\t**************  7. Accounts Management    *************");
	puts("\t**************  0. Logout                 *************");
	puts("\t*******************************************************");
	puts("\t*******************************************************");
	puts("\t*******************************************************");
	cout << endl;
	cout << "\tPress Enter key to continue..." << endl;
	fgetc(stdin);

	int i;
	cout << "\tPlease input select the option(0-7)" << endl;
	cin >> i ;

	switch(i){
		case 1:
			student_list.Input();
			break;
		case 2:
			while(student_list.Browse())
				;
			break;
		case 3:
			student_list.Remove();
			break;
		case 4:
			student_list.Modify();
		case 5:
			while(student_list.Search())
				;
			break;
		case 6:
		//	while(mana_list.changePW())
				;
			break;
		case 7:
		//	while(mana_list.menu())
				;
			break;
		case 0:
			break;

	}
	return 0;
}

void Admin::Run(){
//	while(!student_list.login())
//		;
	while(Menu())
		;
}

void Admin::Exit(){
	student_list.Save();
}
