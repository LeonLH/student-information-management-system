#include "Admin.h"
#include<cstdlib>
#include<iostream>
using namespace std;

Admin::Admin(){

}

Admin::~Admin(){

}

void Admin::welcome(){
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

int Admin::login(){
	return 0;
}

int Admin::menu(){
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
			stu_list.input();
			break;
		case 2:
			while(stu_list.browse())
				;
			break;
		case 3:
			stu_list.remove();
			break;
		case 4:
			stu_list.modify();
		case 5:
			while(stu_list.search())
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

void Admin::run(){
//	while(!stu_list.login())
//		;
	while(menu())
		;
}

void Admin::exit(){
	stu_list.save();
}
