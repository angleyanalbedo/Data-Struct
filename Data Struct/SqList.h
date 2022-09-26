#pragma once
typedef struct {
	char no[8];
	char name[20];
	int score;
}Student;
class SqList
{
private:
	Student* base;
	int length;
public:
	SqList();
	SqList(int n);
	~SqList();
	int Insert(Student& s);
	int FindByName(const char* name);
	int Init(int n);
	int Delete(int n);
};

