#include<vector>
#include<list>

struct STUD{
	int  nNumb;
	char sName;
	int  nSex; 		// 0 is for Man, 1 for Woman. 
	int  nType;		// 0 is for Science, 1 for liberal arts.

	void Input();
	void Print();

	float fMath;
	float fChin;
	float fEngl;
};

struct ARTSSTUD:STUD{
	float fGeog;
	float fHist;
	void Input();
	void Print();
};

struct SCIESTUD:STUD{
	float fBiol;
	float fPhys;
	float fChem;
	void Input();
	void Pirnt();
};

typedef int (*funcp)(const STUD *pstud1, const STUD *pstud2);
class CStudent{
	std::list<STUD*> m_list;

public:
	CStudent(void);
	~CStudent(void);
	void removeAll();

	void welcome();
	int find();
	void findbyName();
	void findbyGend();
	void findbyType();
	void findbyNumb();
	void findbyEngl();
	void findbyGeog();
	void findbyPhys();

	void modify();
	void remove();
	void input();

	void print();
	void print(STUD* p);
	void print(STUD** p);

	void sort(funcp fp);
	static int byNumb(const STUD *pstud1, const STUD *pstud2){
		return pstud1->nNumb < pstud2->nNumb;
	}

	int  browse();
	bool isExist();
	void load();
	void save();
};



