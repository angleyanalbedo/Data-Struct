/*
*ע����vs20119 2022 �뽫vs��Ϊ1
*���߽�c++ ����
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
#define MAXSIZE 100//˳�������ռ�

typedef struct {
	char no[8];   //8λѧ��
	char name[20]; //����
	int score;     //�ɼ�
}student;

typedef  struct {
	student* elem;     //ָ������Ԫ�صĻ���ַ
	int  length;       //���Ա�ĵ�ǰ����
}sqlist;

int creat(sqlist* L)//˳���ĳ�ʼ��
{
	L->elem = (student*)malloc(sizeof(student) * MAXSIZE);//����ռ�
#ifdef C
	if (!L->elem)printf("����ʧ��");
#elif
	if (!l->elem)std::cout << "����ʧ��";
#endif
	L->length = 0;
	return 1;
}

student getelem(sqlist* L, int i)//ȡiλ��Ԫ��ֵ
{
	return L->elem[i];

}

int search(sqlist* L)//����ѧ������
{
	int t = 0;
	char s[20];
	printf("������Ҫ���ҵ�ѧ������:");
	scanf("%s", s);
	int i;
	for (i = 1; i <= L->length; i++)
	{
		if (strcmp(L->elem[i].name, s) == 0)
			t = i;
	}
	return t;
}

int insert(sqlist* L, int i, student e)//���뺯��
{
	int j;
	if ((i < 1) || (i > L->length + 1))  printf("error");
	if (L->length == MAXSIZE)      printf("error");
	for (j = L->length; j >= i; j--)
	{
		L->elem[j + 1] = L->elem[j];//��ÿ���ڵ㶼����һλ
	}
	L->elem[i] = e;//����ڵ�
	++L->length;
	return 1;
}
int Delete(sqlist* L, int i)//ɾ������
{
	int j;
	if ((i < 1) || (i > L->length + 1))  printf("error");
	for (j = i; j <= L->length; j++)
	{
		L->elem[j] = L->elem[j + 1];
	}
	--L->length;//���ȼ�һ
	return 1;
}
void input(student* e)//���뺯��
{
	printf("ѧ��:");	scanf("%s", e->no);
	printf("����:");	scanf("%s", e->name);
	printf("�ɼ�:");	scanf("%d", &e->score);
	printf("�������\n\n");
}
void Output(student* e)//�������
{
	printf("ѧ��:%s\n����:%s\n�ɼ�:%d\n\n", e->no, e->name, e->score);
}
int main()
{
	sqlist L;
	student a, b, c;
	printf("\n********************************\n\n");
	printf("1. ˳����ʼ��                 *\n");
	printf("2. ¼��ѧ����Ϣ                 *\n");
	printf("3. ��ʾѧ����Ϣ                 *\n");
	printf("4. �������������Ҹ�ѧ��         *\n");
	printf("5. ��ʾĳλ�ø�ѧ����Ϣ         *\n");
	printf("6. ��ָ��λ�ò���ѧ����Ϣ       *\n");
	printf("7. ��ָ��λ��ɾ��ѧ����Ϣ       *\n");
	printf("8. ͳ��ѧ������                 *\n");
	printf("0. �˳�                         *\n");
	printf("\n********************************\n\n");
	int x, choose, i, d = 0, id1, id2, id3;

	while (1)
	{
		printf("��ѡ��");
		scanf("%d", &choose);
		if (choose == 0)break;
		switch (choose)
		{
		case 1:if (creat(&L))
			printf("�ɹ�����˳���\n\n");
			  else
			printf("˳�����ʧ��\n\n");
			break;
		case 2:printf("������Ҫ¼��ѧ����������С��100��:");
			scanf("%d", &x);
			for (i = 1; i <= x; i++)
			{
				printf("��%d��ѧ��:\n", i);
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
				puts("�Բ��𣬲��޴���\n");
			printf("");
			break;
		case 5:
			printf("������Ҫ��ѯ��λ��:");
			scanf("%d", &id1);
			b = getelem(&L, id1);
			Output(&b);
			break;
		case 6:
			printf("������Ҫ�����λ��:");
			scanf("%d", &id2);
			printf("������ѧ����Ϣ:\n");
			input(&c);
			if (insert(&L, id2, c))
			{
				x++;
				printf("����ɹ�\n");
				puts("");
			}
			else
			{
				printf("����ʧ��");
				puts("");
			}
			break;
		case 7:
			printf("������Ҫɾ����λ��:");
			scanf("%d", &id3);
			if (Delete(&L, id3))
			{
				x--;
				printf("ɾ���ɹ�");
				puts("");
			}
			else
			{
				printf("ɾ��ʧ��");
				puts("");
			}
			break;
		case 8:
			printf("��¼���ѧ������Ϊ:%d\n\n", L.length);
			break;
		}
	}
}


