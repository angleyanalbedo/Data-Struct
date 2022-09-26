#include <iostream>
#define MAXSIZE 100
int i = 0;
char str[] = "abc###dc#f##g##";
/*
二叉树不需要所谓的头结点之类的
使用类就是将结构体与方法一起封装起来

*/

using namespace std;
typedef struct BiTNode { //二叉树的存储结构 
	char data;
	struct BiTNode* lchild, * rchild;
}BiTNode, * BiTree;
/*
typedef struct //栈的存储结构 
{
	BiTree* base;
	BiTree* top;
	int stacksize;
} SqStack;
*/
/*
void InitStack(SqStack& S) //构造一个空栈 
{
	S.base = new BiTree[MAXSIZE];
	if (!S.base) exit(-2);
	S.top = S.base;
	S.stacksize = MAXSIZE;
}

typedef struct { //队列的存储结构 
	BiTree* base; //存储空间的基指针
	int front; //头指针（伪指针）
	int rear; //尾指针（伪指针）
}SqQueue;
//循环队列初始化
int InitQueue(SqQueue& Q)
{ //构造一个空队列Q
	Q.base = new BiTree[MAXSIZE]; //为队列分配一个最大容量为MAXSIZE的数组空间
	if (!Q.base) exit(-2); //存储分配失败
	Q.front = Q.rear = 0; //头指针和尾指针置为0，队列为空
	return 1;
}
//循环队列判空
bool QueueEmpty(SqQueue Q)
{
	if (Q.front == Q.rear) return true;
	else return false;
}
// 循环队列入队
int EnQueue(SqQueue& Q, BiTree e)
{
	if ((Q.rear + 1) % MAXSIZE == Q.front)
		return 0;
	Q.base[Q.rear] = e;
	Q.rear = (Q.rear + 1) % MAXSIZE;
	return 1;
}
//循环队列的出队
int DeQueue(SqQueue& Q, BiTree& e)
{
	if (Q.front == Q.rear) return 0;
	e = Q.base[Q.front];
	Q.front = (Q.front + 1) % MAXSIZE;
	return 1;
}
//取队头元素
BiTree GetHead(SqQueue Q)
{
	if (Q.front != Q.rear)
		return Q.base[Q.front];
}

bool StackEmpty(SqStack S)//判断栈是否为空 
{
	if (S.top == S.base) return true;
	else return false;
}

int Push(SqStack& S, BiTree e) //入栈 
{
	if (S.top - S.base == S.stacksize)return -1;
	*(S.top++) = e;
	return 1;
}

int Pop(SqStack& S, BiTree& e) //出栈 
{
	if (S.top == S.base) return 0;
	e = *(--S.top);
	return 1;
}
*/

void createBiTree(BiTree& T) {  //先序遍历创建二叉树 递归实现 
	char ch;
	//cin >> ch;
	ch = str[i];
	i++;
	if (ch == '#')T = NULL;   //递归出口 
	else {
		T = new BiTNode;
		T->data = ch;
		createBiTree(T->lchild); //创建左子树 
		createBiTree(T->rchild);  //创建右子树 
	}
}

void FirstOrderTraverse(BiTree T) { //先序遍历二叉树，递归实现 
	if (T) {
		cout << T->data;
		FirstOrderTraverse(T->lchild);
		FirstOrderTraverse(T->rchild);
	}
}
/*
进行中序遍历
*/
void InOrderTraverse(BiTree T) {  //中序遍历二叉树，递归实现 

	if (T) {
		InOrderTraverse(T->lchild);
		cout << T->data;
		InOrderTraverse(T->rchild);
	}
}

void LastOrderTraverse(BiTree T) {  //后序遍历二叉树，递归实现 
	if (T) {
		LastOrderTraverse(T->lchild);
		LastOrderTraverse(T->rchild);
		cout << T->data;
	}
}
/*
二叉树所有的操作都可以义递归的方式来实现
即使是拷贝二叉树
*/
void Copy(BiTree T, BiTree& NewT) { //复制二叉树
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
int Depth(BiTree T) {  //计算二叉树的深度
	int m, n;
	if (T == NULL) return 0;
	else {
		m = Depth(T->lchild);
		n = Depth(T->rchild);
		if (m > n) return(m + 1);
		else return(n + 1);
	}
}

int NodeCount(BiTree T) { //统计结点个数
	if (T == NULL) return 0;
	else {
		return NodeCount(T->lchild) + NodeCount(T->rchild) + 1;
	}
}

void menu() {  //菜单界面
	cout << "请选择操作：" << endl;
	cout << "      1.创建二叉树" << endl;
	cout << "      2.先序遍历二叉树" << endl;
	cout << "      3.中序遍历二叉树" << endl;
	cout << "      4.后序遍历二叉树" << endl;
	//cout << "      5.复制二叉树" << endl;
	cout << "      5.计算二叉树深度" << endl;
	cout << "      6.统计结点个数" << endl;
	cout << "      11.退出" << endl;
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
	//		cout << "请按照先序遍历的顺序输入一个二叉树（空树以#标记）:";
	//		createBiTree(T);
	//		cout << "二叉树创建成功！" << endl;
	//		break;
	//	}
	//	case 2: {
	//		cout << "先序遍历的结果为:" << endl;
	//		FirstOrderTraverse(T);
	//		cout << endl;
	//		break;
	//	}
	//	case 3: {
	//		cout << "中序遍历的结果为:" << endl;
	//		InOrderTraverse(T);
	//		cout << endl;
	//		break;
	//	}
	//	case 4: {
	//		cout << "后序遍历的结果为:" << endl;
	//		LastOrderTraverse(T);
	//		cout << endl;
	//		break;
	//	}
	//	/*case 5: {
	//		BiTree NewT;
	//		Copy(T, NewT);
	//		cout << "复制完毕！" << endl;
	//		cout << "复制后的二叉树先序遍历为:" << endl;
	//		FirstOrderTraverse(NewT);
	//		cout << endl;
	//		break;
	//	}*/
	//	case 5: {
	//		cout << "二叉树的深度为:";
	//		cout << Depth(T);
	//		cout << endl;
	//		break;
	//	}
	//	case 6: {
	//		cout << "二叉树中结点个数为:";
	//		cout << NodeCount(T);
	//		cout << endl;
	//		break;
	//	}
	//	default: {
	//		cout << "输入有误，请重新输入" << endl;
	//		break;
	//		}
	//	}
	//	menu();
	//}
}