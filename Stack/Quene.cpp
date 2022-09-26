#include "Quene.h"
Quene::Quene() {
	front = nullptr;
	rear = nullptr;
}
Quene::~Quene() {
	QuenePtr t,p = front;
	t = p;
	while (p != nullptr) {
		t = p;
		p = p->next;
		delete t;
	}
}
void Quene::Inline(QNode t) {
	QuenePtr p = new QNode;
	p->data = t.data;
	rear->next->next = p;
	rear = p;
}
QNode Quene::Outline() {
	QNode t = *(front->next);
	QuenePtr p = front;
	front = front->next->next;
	delete p;
	return t;
}