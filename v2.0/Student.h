#pragma once
#include<vector>
#include<list>
#include<string>

struct STUD{
	int  nNumb;
	std::string sName;
	bool  bSex; 		// 0 is for Man, 1 for Woman. 
	bool  bType;		// 0 is for Science, 1 for liberal arts.

	void input();
	void print();

	float fMath;
	float fChin;
	float fEngl;
};

struct ARTSSTUD:STUD{
	float fGeog;
	float fHist;
	void input();
	void print();
};

struct SCIESTUD:STUD{
	float fBiol;
	float fPhys;
	float fChem;
	void input();
	void print();
};

typedef int (*funcp)(const STUD *pstud1, const STUD *pstud2);
class Student{
	std::list<STUD*> stu_list;
private:
	void clearscreen();

public:
	Student(void);
	~Student(void);
	bool isExist(int n);
	void print();
	void print(STUD* p);
	void print(STUD** p);
	int  browse();
	void input();
	void removeAll();
	void remove();
	void modify();

	void test();
	int testMenu();

	void welcome();
	int  search ();
	void searchByName();
	void searchByGend();
	void searchByType();
	void searchByNumb();
	void searchByEngl();
	void searchByGeog();
	void searchByPhys();



	void sort(funcp fp);
	static int byNumb(const STUD *pstud1, const STUD *pstud2){
		return pstud1->nNumb < pstud2->nNumb;
	}

	int load();
	int save();
};



