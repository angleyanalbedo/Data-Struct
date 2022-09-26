#include<iostream>

#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define MAXSIZE 100

typedef int SElemType;
typedef int Status;
typedef struct {
	SElemType* base;
	SElemType* top;
	int stacksize;
}Sqstack;

Status Init(Sqstack& S) {
	//S.base = (SElemType*)malloc(sizeof(SElemType) * MAXSIZE);
	S.base = new SElemType[MAXSIZE];
	if (!S.base) return OVERFLOW;
	S.top = S.base;
	S.stacksize = MAXSIZE;
	return OK;
}//��ʼ��

Status Push(Sqstack& S, const SElemType& e) {
	int i;
	if (S.top - S.base == S.stacksize) {
		return ERROR;
	}
	*S.top = e;
	S.top++;
	return OK;
} //��ջ

Status GetTop(Sqstack S, SElemType& e) {
	if (S.top == S.base) return ERROR;
	e = *(S.top - 1);
	return OK;
} //��ȡջ��Ԫ��

Status Pop(Sqstack& S, SElemType& e) {
	if (S.top == S.base) {
		std::cout<<"ջ�գ��޷���ջ\n";
		return ERROR;
	}
	--S.top;
	e = *S.top;
	return OK;
}//��ջ

bool StackEmpty(Sqstack S) {
	if (S.top == S.base) return 1;
	else return 0;
}//�п�

Status Clear(Sqstack& S) {
	if (S.base) S.base = S.top;
	return OK;
}//���

void conversion() {
	int N, base;
	SElemType e;//��ջ����
	Sqstack S;
	Init(S);//����ջS
	std::cout<<"������Ҫת��������:\n";
	std::cin>>N;
	while (N<0 || N>MAXSIZE) {
		std::cout<<"���뷶Χ��������������:";
		std::cin>>N;
	}
	std::cout<<"������Ҫת���ɼ����ƣ�\n";
	std::cin >> base;
	while (base<0 || base>MAXSIZE) {
		std::cout<<"���뷶Χ��������������:";
		std::cin >> base;
	}
	while (N) {
		Push(S, N % base);
		N = N / base;
	}
	std::cout<<"ת��������Ϊ��\n";
	while (!StackEmpty(S)) {
		Pop(S, e);
		std::cout<< e ;
	}
}//ʮ����תd����

int main() {
	Sqstack S1;
	
	if (Init(S1) == OK) {
		std::cout << "��ʼ���ɹ���\n";
		conversion();
	}
	else std::cout<<"��ʼ��ʧ�ܣ�";
	return 0;
}

