#include<iostream>
#include"normal_tools.h"

using namespace std;

void NormalTools::ClearScreen(){
	cout << "\033[2J\033[1;1H";
}
void NormalTools::PressAnyKeyToContinue(){
	cout << "Press any key to continue:" << endl;
	cin.ignore(99999, '\n');
	cin.get();
}

