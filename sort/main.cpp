/*
���� :adminangleyan
ʱ��: 2022 6 9
����:
��ɲ������� ���ֲ��Ҳ������� ϣ������
*/
#include"type.h"
SqList L;
int dk[] = { 50, 25, 12, 6, 3, 1 };
void rondom() {
	srand((unsigned)time(NULL));
	for (int i = 1; i < MAXSIZE; ++i) {
		L.r[i].key = rand() % 100;
		//std::cout << L.r[i].key << std::endl;
	}
	L.length = MAXSIZE;
}
void Print() {
	for (int i = 1; i < MAXSIZE; ++i) {
		std::cout << L.r[i].key << std::endl;
	}
}
int main() {
	rondom();
	InsertSort(L);
	Print();
	return 0;
}