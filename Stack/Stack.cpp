#include "Stack.h"
Stack::Stack(int size) {
	base = new SElemType[size];
}
Stack::Stack() {
	p = nullptr;
}
SElemType Stack::Pop() {
	top = top - 1;
	return p[top + 1];
	
}
void Stack::Push(SElemType t) {
	top = top + 1;
	p[top] = t;
}

Stack::~Stack() {
	delete[]p;
}
