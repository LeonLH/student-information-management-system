#include<iostream>
#include"admin.h"
#include"student-list.h"
#include"manager.h"

void normalRun(){
	Admin admin;
	admin.Welcome();
	admin.Run();
	admin.Exit();
}

void TestStudent(){
	StudentList student;
	student.Test();
}

void TestManager(){

}

void TestAdmin(){

}

int main(){
	//normalRun();
	TestStudent();
	return 0;
}
