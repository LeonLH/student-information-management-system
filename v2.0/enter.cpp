#include<iostream>
#include"admin.h"
#include"student-list.h"
#include"manager-list.h"

void normalRun(){
	Admin admin;
	admin.Welcome();
	admin.Run();
	admin.Exit();
}

void TestForStudent(){
	StudentList student;
	student.Test();

}

void TestForManager(){
	ManagerList manager;
	manager.Test();
}

void TestManager(){

}

void TestAdmin(){

}

int main(){
	//normalRun();
	//TestForStudent();
	TestForManager();
	return 0;
}
