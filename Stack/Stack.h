#pragma once
typedef char SElemType;
class Stack
{private:
	SElemType* base;
	SElemType* top;
	int size;
public:
	Stack();
	Stack(int size);
	void Push(SElemType t);
	SElemType Pop();
	void InitStack(int size);
	void DestoryStack();
	SElemType GetTop();
	int StackLength();
	void ClearStack();
	void StackTrverse();
	~Stack();
};


