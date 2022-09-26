/*
*注意在vs20119 2022 请将vs改为1
*或者将c++ 启用
*/
#define VS 1
#define C
#if VS
#define _CRT_SECURE_NO_WARNINGS
#endif // VS

#ifdef C
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#elif
#include<iostream>

#endif
#define MAXSIZE 100//顺序表的最大空间

typedef struct {
	char no[8];   //8位学号
	char name[20]; //姓名
	int score;     //成绩
}student;

typedef  struct {
	student* elem;     //指向数据元素的基地址
	int  length;       //线性表的当前长度
}sqlist;

int creat(sqlist* L)//顺序表的初始化
{
	L->elem = (student*)malloc(sizeof(student) * MAXSIZE);//分配空间
#ifdef C
	if (!L->elem)printf("分配失败");
#elif
	if (!l->elem)std::cout << "分配失败";
#endif
	L->length = 0;
	return 1;
}

student getelem(sqlist* L, int i)//取i位置元素值
{
	return L->elem[i];

}

int search(sqlist* L)//查找学生函数
{
	int t = 0;
	char s[20];
	printf("请输入要查找的学生姓名:");
	scanf("%s", s);
	int i;
	for (i = 1; i <= L->length; i++)
	{
		if (strcmp(L->elem[i].name, s) == 0)
			t = i;
	}
	return t;
}

int insert(sqlist* L, int i, student e)//插入函数
{
	int j;
	if ((i < 1) || (i > L->length + 1))  printf("error");
	if (L->length == MAXSIZE)      printf("error");
	for (j = L->length; j >= i; j--)
	{
		L->elem[j + 1] = L->elem[j];//将每个节点都后移一位
	}
	L->elem[i] = e;//插入节点
	++L->length;
	return 1;
}
int Delete(sqlist* L, int i)//删除函数
{
	int j;
	if ((i < 1) || (i > L->length + 1))  printf("error");
	for (j = i; j <= L->length; j++)
	{
		L->elem[j] = L->elem[j + 1];
	}
	--L->length;//长度减一
	return 1;
}
void input(student* e)//输入函数
{
	printf("学号:");	scanf("%s", e->no);
	printf("姓名:");	scanf("%s", e->name);
	printf("成绩:");	scanf("%d", &e->score);
	printf("输入完成\n\n");
}
void Output(student* e)//输出函数
{
	printf("学号:%s\n姓名:%s\n成绩:%d\n\n", e->no, e->name, e->score);
}
int main()
{
	sqlist L;
	student a, b, c;
	printf("\n********************************\n\n");
	printf("1. 顺序表初始化                 *\n");
	printf("2. 录入学生信息                 *\n");
	printf("3. 显示学生信息                 *\n");
	printf("4. 输入姓名，查找该学生         *\n");
	printf("5. 显示某位置该学生信息         *\n");
	printf("6. 在指定位置插入学生信息       *\n");
	printf("7. 在指定位置删除学生信息       *\n");
	printf("8. 统计学生个数                 *\n");
	printf("0. 退出                         *\n");
	printf("\n********************************\n\n");
	int x, choose, i, d = 0, id1, id2, id3;

	while (1)
	{
		printf("请选择");
		scanf("%d", &choose);
		if (choose == 0)break;
		switch (choose)
		{
		case 1:if (creat(&L))
			printf("成功建立顺序表\n\n");
			  else
			printf("顺序表建立失败\n\n");
			break;
		case 2:printf("请输入要录入学生的人数（小于100）:");
			scanf("%d", &x);
			for (i = 1; i <= x; i++)
			{
				printf("第%d个学生:\n", i);
				input(&L.elem[i]);
			}
			L.length = x;
			puts("");
			break;
		case 3:for (i = 1; i <= x; i++)
		{
			a = (student)(getelem(&L, i));
			Output(&a);
		}
			  break;
		case 4:

			d = search(&L);
			if (d > 0)
				Output(&L.elem[search(&L)]);
			else
				puts("对不起，查无此人\n");
			printf("");
			break;
		case 5:
			printf("请输入要查询的位置:");
			scanf("%d", &id1);
			b = getelem(&L, id1);
			Output(&b);
			break;
		case 6:
			printf("请输入要插入的位置:");
			scanf("%d", &id2);
			printf("请输入学生信息:\n");
			input(&c);
			if (insert(&L, id2, c))
			{
				x++;
				printf("插入成功\n");
				puts("");
			}
			else
			{
				printf("插入失败");
				puts("");
			}
			break;
		case 7:
			printf("请输入要删除的位置:");
			scanf("%d", &id3);
			if (Delete(&L, id3))
			{
				x--;
				printf("删除成功");
				puts("");
			}
			else
			{
				printf("删除失败");
				puts("");
			}
			break;
		case 8:
			printf("已录入的学生个数为:%d\n\n", L.length);
			break;
		}
	}
}


