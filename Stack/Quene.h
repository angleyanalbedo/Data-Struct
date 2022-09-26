#pragma once
typedef char SElemType;
typedef struct QNode {
	SElemType data;
	struct QNode* next;
}*QuenePtr;
class Quene
{
private:
	QuenePtr front;
	QuenePtr rear;
public:
	Quene();
	QNode Outline();
	void Inline(QNode t);
};

