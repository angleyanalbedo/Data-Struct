#include <iostream>
#define MAXSIZE 100
int i = 0;
char str[] = "abc###dc#f##g##";
/*
����������Ҫ��ν��ͷ���֮���
ʹ������ǽ��ṹ���뷽��һ���װ����

*/

using namespace std;
typedef struct BiTNode { //�������Ĵ洢�ṹ 
	char data;
	struct BiTNode* lchild, * rchild;
}BiTNode, * BiTree;
/*
typedef struct //ջ�Ĵ洢�ṹ 
{
	BiTree* base;
	BiTree* top;
	int stacksize;
} SqStack;
*/
/*
void InitStack(SqStack& S) //����һ����ջ 
{
	S.base = new BiTree[MAXSIZE];
	if (!S.base) exit(-2);
	S.top = S.base;
	S.stacksize = MAXSIZE;
}

typedef struct { //���еĴ洢�ṹ 
	BiTree* base; //�洢�ռ�Ļ�ָ��
	int front; //ͷָ�루αָ�룩
	int rear; //βָ�루αָ�룩
}SqQueue;
//ѭ�����г�ʼ��
int InitQueue(SqQueue& Q)
{ //����һ���ն���Q
	Q.base = new BiTree[MAXSIZE]; //Ϊ���з���һ���������ΪMAXSIZE������ռ�
	if (!Q.base) exit(-2); //�洢����ʧ��
	Q.front = Q.rear = 0; //ͷָ���βָ����Ϊ0������Ϊ��
	return 1;
}
//ѭ�������п�
bool QueueEmpty(SqQueue Q)
{
	if (Q.front == Q.rear) return true;
	else return false;
}
// ѭ���������
int EnQueue(SqQueue& Q, BiTree e)
{
	if ((Q.rear + 1) % MAXSIZE == Q.front)
		return 0;
	Q.base[Q.rear] = e;
	Q.rear = (Q.rear + 1) % MAXSIZE;
	return 1;
}
//ѭ�����еĳ���
int DeQueue(SqQueue& Q, BiTree& e)
{
	if (Q.front == Q.rear) return 0;
	e = Q.base[Q.front];
	Q.front = (Q.front + 1) % MAXSIZE;
	return 1;
}
//ȡ��ͷԪ��
BiTree GetHead(SqQueue Q)
{
	if (Q.front != Q.rear)
		return Q.base[Q.front];
}

bool StackEmpty(SqStack S)//�ж�ջ�Ƿ�Ϊ�� 
{
	if (S.top == S.base) return true;
	else return false;
}

int Push(SqStack& S, BiTree e) //��ջ 
{
	if (S.top - S.base == S.stacksize)return -1;
	*(S.top++) = e;
	return 1;
}

int Pop(SqStack& S, BiTree& e) //��ջ 
{
	if (S.top == S.base) return 0;
	e = *(--S.top);
	return 1;
}
*/

void createBiTree(BiTree& T) {  //����������������� �ݹ�ʵ�� 
	char ch;
	//cin >> ch;
	ch = str[i];
	i++;
	if (ch == '#')T = NULL;   //�ݹ���� 
	else {
		T = new BiTNode;
		T->data = ch;
		createBiTree(T->lchild); //���������� 
		createBiTree(T->rchild);  //���������� 
	}
}

void FirstOrderTraverse(BiTree T) { //����������������ݹ�ʵ�� 
	if (T) {
		cout << T->data;
		FirstOrderTraverse(T->lchild);
		FirstOrderTraverse(T->rchild);
	}
}
/*
�����������
*/
void InOrderTraverse(BiTree T) {  //����������������ݹ�ʵ�� 

	if (T) {
		InOrderTraverse(T->lchild);
		cout << T->data;
		InOrderTraverse(T->rchild);
	}
}

void LastOrderTraverse(BiTree T) {  //����������������ݹ�ʵ�� 
	if (T) {
		LastOrderTraverse(T->lchild);
		LastOrderTraverse(T->rchild);
		cout << T->data;
	}
}
/*
���������еĲ�����������ݹ�ķ�ʽ��ʵ��
��ʹ�ǿ���������
*/
void Copy(BiTree T, BiTree& NewT) { //���ƶ�����
	if (T == NULL) {
		NewT = NULL;
		return;
	}

	else {
		NewT = new BiTNode;
		NewT->data = T->data;
		Copy(T->lchild, NewT->lchild);
		Copy(T->rchild, NewT->rchild);
	}
}
int Depth(BiTree T) {  //��������������
	int m, n;
	if (T == NULL) return 0;
	else {
		m = Depth(T->lchild);
		n = Depth(T->rchild);
		if (m > n) return(m + 1);
		else return(n + 1);
	}
}

int NodeCount(BiTree T) { //ͳ�ƽ�����
	if (T == NULL) return 0;
	else {
		return NodeCount(T->lchild) + NodeCount(T->rchild) + 1;
	}
}

void menu() {  //�˵�����
	cout << "��ѡ�������" << endl;
	cout << "      1.����������" << endl;
	cout << "      2.�������������" << endl;
	cout << "      3.�������������" << endl;
	cout << "      4.�������������" << endl;
	//cout << "      5.���ƶ�����" << endl;
	cout << "      5.������������" << endl;
	cout << "      6.ͳ�ƽ�����" << endl;
	cout << "      11.�˳�" << endl;
}
int main()
{
	BiTree T = nullptr;
	createBiTree(T);
	InOrderTraverse(T);
	cout << Depth(T)<< endl;
	//int choose;
	//menu();
	//while (cin >> choose && choose != 11) {
	//	switch (choose) {
	//	case 1: {
	//		cout << "�밴�����������˳������һ����������������#��ǣ�:";
	//		createBiTree(T);
	//		cout << "�����������ɹ���" << endl;
	//		break;
	//	}
	//	case 2: {
	//		cout << "��������Ľ��Ϊ:" << endl;
	//		FirstOrderTraverse(T);
	//		cout << endl;
	//		break;
	//	}
	//	case 3: {
	//		cout << "��������Ľ��Ϊ:" << endl;
	//		InOrderTraverse(T);
	//		cout << endl;
	//		break;
	//	}
	//	case 4: {
	//		cout << "��������Ľ��Ϊ:" << endl;
	//		LastOrderTraverse(T);
	//		cout << endl;
	//		break;
	//	}
	//	/*case 5: {
	//		BiTree NewT;
	//		Copy(T, NewT);
	//		cout << "������ϣ�" << endl;
	//		cout << "���ƺ�Ķ������������Ϊ:" << endl;
	//		FirstOrderTraverse(NewT);
	//		cout << endl;
	//		break;
	//	}*/
	//	case 5: {
	//		cout << "�����������Ϊ:";
	//		cout << Depth(T);
	//		cout << endl;
	//		break;
	//	}
	//	case 6: {
	//		cout << "�������н�����Ϊ:";
	//		cout << NodeCount(T);
	//		cout << endl;
	//		break;
	//	}
	//	default: {
	//		cout << "������������������" << endl;
	//		break;
	//		}
	//	}
	//	menu();
	//}
}