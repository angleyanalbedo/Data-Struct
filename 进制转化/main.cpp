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
}//初始化

Status Push(Sqstack& S, const SElemType& e) {
	int i;
	if (S.top - S.base == S.stacksize) {
		return ERROR;
	}
	*S.top = e;
	S.top++;
	return OK;
} //进栈

Status GetTop(Sqstack S, SElemType& e) {
	if (S.top == S.base) return ERROR;
	e = *(S.top - 1);
	return OK;
} //读取栈顶元素

Status Pop(Sqstack& S, SElemType& e) {
	if (S.top == S.base) {
		std::cout<<"栈空，无法出栈\n";
		return ERROR;
	}
	--S.top;
	e = *S.top;
	return OK;
}//出栈

bool StackEmpty(Sqstack S) {
	if (S.top == S.base) return 1;
	else return 0;
}//判空

Status Clear(Sqstack& S) {
	if (S.base) S.base = S.top;
	return OK;
}//清空

void conversion() {
	int N, base;
	SElemType e;//出栈的数
	Sqstack S;
	Init(S);//构造栈S
	std::cout<<"请输入要转换的数据:\n";
	std::cin>>N;
	while (N<0 || N>MAXSIZE) {
		std::cout<<"输入范围错误，请重新输入:";
		std::cin>>N;
	}
	std::cout<<"请输入要转换成几进制：\n";
	std::cin >> base;
	while (base<0 || base>MAXSIZE) {
		std::cout<<"输入范围错误，请重新输入:";
		std::cin >> base;
	}
	while (N) {
		Push(S, N % base);
		N = N / base;
	}
	std::cout<<"转换的数据为：\n";
	while (!StackEmpty(S)) {
		Pop(S, e);
		std::cout<< e ;
	}
}//十进制转d进制

int main() {
	Sqstack S1;
	
	if (Init(S1) == OK) {
		std::cout << "初始化成功！\n";
		conversion();
	}
	else std::cout<<"初始化失败！";
	return 0;
}

