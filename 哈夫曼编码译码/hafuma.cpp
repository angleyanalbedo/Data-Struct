#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#include <stdlib.h>

#include <string.h>



#define n 65

void PHUM(char* file, char* s);

char s[30000] = { 3 };



// ���������ڵ�洢�ṹ

typedef struct {

	char data;

	int weight;

	int lchild;

	int rchild;

	int parent;

}Htnode;



typedef Htnode HuffmanT[129];



// �����������Ĵ洢�ṹ

typedef struct {

	char ch; // ���汻������ַ�

	char bits[n + 1]; // �ַ�����λ��

}CodeNode;



typedef CodeNode HuffmanCode[n];





// 0-9Ϊ���֣�10-35ΪСд��ĸ��36-61Ϊ��д��ĸ��62-64Ϊ�����ַ�

void InitHT(HuffmanT T) // ��ʼ��

{

	char sz = '0';

	char xzm = 'a';

	char dzm = 'A';

	char kong = ' ';

	char dh = ',';

	char jh = '.';



	for (int i = 0; i < n; i++)

	{

		T[i].lchild = T[i].rchild = T[i].parent = -1;

		T[i].weight = 0;

		if (i >= 0 && i <= 9)

		{

			T[i].data = sz;

			sz++;

		}

		if (i >= 10 && i <= 35)

		{

			T[i].data = xzm;

			xzm++;

		}

		if (i >= 36 && i <= 61)

		{

			T[i].data = dzm;

			dzm++;

		}

		if (i >= 62 && i <= 64)

		{

			T[62].data = kong;

			T[63].data = dh;

			T[64].data = jh;

		}

	}



	for (int j = n; j < 2 * n - 1; j++)

	{

		T[j].weight = 0;

		T[j].lchild = T[j].rchild = T[j].parent = -1;

	}



	printf("initHT over\n");

}



void InputW(HuffmanT T) // �����ļ����ַ�������Ȩֵ

{

	FILE* fp;

	char ch;

	char Filename[20];



	printf("input the filename:");

	scanf("%s", Filename);



	if ((fp = fopen(Filename, "r")) == NULL) printf("faild\n");

	ch = fgetc(fp);



	while (ch != EOF)

	{

		for (int i = 0; i < n; i++)

		{

			if (T[i].data == ch) T[i].weight++;

		}

		ch = fgetc(fp);

	}



	for (int i = 0; i < n; i++)

	{

		printf("%c weight is:", T[i].data);

		printf("%d\n", T[i].weight);

	}



	fclose(fp);



	printf("inputW over\n");

}



void SelectMin(HuffmanT T, int length, int* p1, int* p2) // ѡ��Ȩֵ��С������Ԫ�أ������±�

{

	int min1, min2; // min1�����С��min2��Ǵ�С

	int i = 0;

	int k, j = 0;

	for (j; j < length; j++)

	{

		if (T[j].parent == -1)

		{

			min1 = j;

			break;

		}

	}



	for (k = min1 + 1; k < length; k++)

	{

		if (T[k].parent == -1)

		{

			min2 = k;

			break;

		}

	}



	while (i < length)

	{

		if (T[i].parent == -1)

		{



			if (T[i].weight < T[min1].weight)

			{

				min2 = min1;

				min1 = i;

			}

			else if ((i != min1) && (T[i].weight < T[min2].weight))

			{

				min2 = i;

			}

		}



		i++;

	}



	*p1 = min1;

	*p2 = min2;

}



void CreartHT(HuffmanT T) // ���������������

{

	int i, p1, p2;

	int wei1, wei2;

	InitHT(T); // ��ʼ��

	InputW(T); // ����Ȩֵ

	for (i = n; i < 129; i++)

	{

		SelectMin(T, i, &p1, &p2);

		wei1 = T[p1].weight;

		wei2 = T[p2].weight;

		T[p1].parent = i;

		T[p2].parent = i;

		T[i].lchild = p1;

		T[i].rchild = p2;

		T[i].weight = wei1 + wei2;

	}



	printf("creatHT over\n");

}



void CharSetHuffmEncoding(HuffmanT T, HuffmanCode H) // ���ݹ�������������������H

{

	int c, p, i; // c��p�ֱ�ָʾT�к��Ӻ�˫��λ��

	char cd[n + 1]; // ��ʱ��ű���

	int start; // ָʾ������cd�е�λ��

	cd[n] = '\0'; // ���������

	for (i = 0; i < n; i++)

	{

		H[i].ch = T[i].data;

		start = n;

		c = i;

		while ((p = T[c].parent) >= 0) // ���ݵ�T[c]������λ��

		{

			cd[--start] = (T[p].lchild == c) ? '0' : '1'; // T[c]��T[p]�����ӣ����ɴ���0��������1

			c = p;

		}

		strcpy(H[i].bits, &cd[start]);

	}

	printf("creatHcode over\n");

}







// ���ļ����ַ��Ĺ����������ӡ����������д��ָ��txt�ļ�

void PrintHUffmancode(HuffmanCode H)

{



	FILE* fp;

	char ch;

	char Filename[80];

	char file[80];



	printf("output the Huffmancode of which file:");

	scanf("%s", Filename);

	if ((fp = fopen(Filename, "r")) == NULL) printf("failda\n");

	ch = fgetc(fp);

	int L = 0;

	//printf("1");

	while (ch != EOF)

	{



		for (int i = 0; i < n; i++)

		{

			if (H[i].ch == ch)

			{

				printf("%s", H[i].bits);

				sprintf(s + L, "%s", H[i].bits);

				L = strlen(s);

			}

		}



		ch = fgetc(fp);

	}

	printf("\n");



	for (int k = 0; k < n; k++)

	{

		printf("%c-%s\n", H[k].ch, H[k].bits);

	}



	fclose(fp);

	printf("stand by\n");



	PHUM(file, s);



}



void PHUM(char* file, char* s)

{

	FILE* fp;

	int i = 0;

	printf("save your Huffmancode to the file:");

	scanf("%s", file);

	if ((fp = fopen(file, "w")) == NULL) printf("faild\n");



	while (s[i] != '\0')

	{

		fprintf(fp, "%c", s[i]);

		i++;

	}



	fclose(fp);

	printf("write over\n");

}



void Printftxt(HuffmanT T, char a[]) // ��0��1

{

	int root, c;

	int i = 0;

	FILE* fp;

	char ch;

	char Filename[30];



	printf("print words acroding to Huffmancode:");

	scanf("%s", Filename);

	if ((fp = fopen(Filename, "r")) == NULL) printf("faild\n");



	// printf("1\n");

	for (int j = 0; j < 129; j++) //�ҵ����ڵ�

	{

		if (T[j].parent == -1)

		{

			root = j;

			break;

		}

	}



	ch = fgetc(fp);

	while (ch != EOF)

	{

		c = root;



		while ((T[c].lchild != -1) || (T[c].rchild != -1))

		{

			if (ch == '0')

			{

				c = T[c].lchild;

				ch = fgetc(fp);

			}

			else if (ch == '1')

			{

				c = T[c].rchild;

				ch = fgetc(fp);

			}

			// printf("2");

		}



		printf("%c", T[c].data);



		// ch = fgetc(fp);



	}



	fclose(fp);

}



int main()

{

	HuffmanT T;

	HuffmanCode H;



	CreartHT(T); //�����ļ�����һ������������ʼ��������Ȩֵ ������ַ�Ȩֵ

	CharSetHuffmEncoding(T, H); //���ݹ��������������������������ַ��ı���

	PrintHUffmancode(H); //���ĳ���ļ����ı��Ĺ��������룬������������ָ���ļ���



	Printftxt(T, s); //���ݹ����������ӡ�ı��ļ��ַ�



}