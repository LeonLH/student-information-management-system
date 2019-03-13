#include<iostream>
#include"Admin.h"
#include"Student.h"
#include"Manager.h"

void normalRun(){
	Admin admin;
	admin.welcome();
	admin.run();
	admin.exit();
}

void testStudent(){
	Student stu;
	stu.test();
}

void testManager(){

}

void testAdmin(){

}

int main(){
	//normalRun();
	testStudent();
	return 0;
}
