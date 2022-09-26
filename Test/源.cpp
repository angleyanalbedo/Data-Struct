#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<math.h>

#define N 32     //�ؼ��ָ���
#define size 256
#define maxlen 9     //�ؼ������鳤��
#define hashlen 41     //��ϣ����
#define Smax 0.9     //���ƶ�s����ֵ
#define Dmin 2     //D���ξ������ֵ

struct hashtable     //�ṹ�������ϣ��
{
    char* hash1;     //ָ��ؼ��ֵ�ָ��
    int count;     //��¼Ƶ���� 
}hasht[hashlen];

using namespace std;

void Hashfunc(char str[]);     //���ؼ��ָ��ݹ�ϣ���������ϣ���ָ��λ��
int Hashfind(char* words);     //�ڹ�ϣ�������Ƿ��wordΪ�ؼ��֣�����¼Ƶ��
void creathash(void);     //������ϣ��
int readc(char* filename);     //��ȡԴ�����ļ��еĵ���
int isletter(char ch);     //�ж��Ƿ�Ϊ��ĸ
int getkey(char* str, int len);     //��ȡ�õ��ʵĹؼ��� 
void resethash(int n);     //���ù�ϣ��
void copycount(int x[], int n);     //��Ƶ��������������
float Mol(int* x);     //ȡģ����
int Dot(int* x1, int* x2);     //�������
float D(int* x1, int* x2);     //�����D�ĺ��� 
float S(int* x1, int* x2);     //�����Ƶ�S�ĺ���
void check(int* x1, int* x2);     //�������Դ�����Ƿ�����




int main()
{
    char filename1[] = { "d:\\test1.txt" };
    char filename2[] = { "d:\\test12.txt" };
    char filename3[] = { "d:\\test13.txt" };

    int x1[hashlen], x2[hashlen], x3[hashlen];     

    hasht[hashlen];    
    resethash(0);     
    creathash();     
    readc(filename1);      
    copycount(x1, hashlen);    
    resethash(1);     
    readc(filename2);     
    copycount(x2, hashlen);     
    resethash(1);     
    readc(filename3);       
    copycount(x3, hashlen);      
    cout << "\t" << "��ϣ���" << "    \t\t" << "�ؼ���" << "    \t\t" << "Ƶ�� 1" << "    \t\t" << "Ƶ�� 2" << "    \t\t" << "Ƶ�� 3" << endl;
    for (int i = 0; i < 41; i++)
    {
        if (hasht[i].hash1 != NULL)
        {
            cout << "\t" << i << "       \t\t" << hasht[i].hash1 << "       \t\t" << x1[i] << "       \t\t" << x2[i] << "       \t\t" << x3[i] << endl;
        }
    }
    cout << filename1 << "��" << filename2 << "���������Ϊ��";
    check(x1, x2);     //������ƶ� 
    cout << filename1 << "��" << filename3 << "���������Ϊ��";
    check(x1, x3);     //������ƶ�
    cout << filename2 << "��" << filename3 << "���������Ϊ��";
    check(x2, x3);     //������ƶ�
    while (1);
    return 0;
}

void resethash(int n)
{     //���ù�ϣ�� 
    if (n = 0)     
    {
        for (int i = 0; i < 41; i++)
        {
            hasht[i].hash1 = NULL;
            hasht[i].count = 0;
        }
    }
    else if (n = 1)     //��������Ƶ�� 
    {
        for (int i = 0; i < 41; i++)
        {
            hasht[i].count = 0;
        }
    }
}

void copycount(int x[], int n)
{     //����Ƶ�� 
    for (int i = 0; i < n; i++)
    {
        x[i] = hasht[i].count;
    }
}

int getkey(char* str, int len){     
    char key1, key2;
    int key;
    key1 = str[0];//�ؼ�������ĸ 
    key2 = str[len - 1];//�ؼ���β��ĸ 
    key = (int)(key1 * 100 + key2) % 41;
    return key;
}

void creathash(void)
{     
    FILE* fp;           //����ָ���ļ���ָ�� 
    int length;
    char str[size];     //��ʱ�洢�ؼ����ַ������� 
    char* s = NULL;      //����һ��ָ�� 
    for (int i = 0; i < size; i++)
    {
        str[i] = '\0';
    }
    if ((fp = fopen("d:\\keyword.txt", "r")) == NULL)
    {
        cout << "can't creat file!\n";
        exit(0);
    }
    
    while (fgets(str, size, fp) != NULL)   
    {
        if (str == NULL)
        {
            break;
        }
        length = strlen(str);    
        str[length - 1] = '\0';
        Hashfunc(str);  
    }
    fclose(fp);
}

void Hashfunc(char str[])
{     
    int key, len;
    len = strlen(str);     
    key = getkey(str, len);
    while (hasht[key % 41].hash1 != NULL)
    {
        key++;      
    }
    hasht[key % 41].hash1 = (char*)malloc(sizeof(char) * (len + 1));
   
    strcpy(hasht[key % 41].hash1, str);
}

int Hashfind(char* words)
{     
    int key, len, find;
    len = strlen(words);
    key = getkey(words, len);
    while (hasht[key].hash1 == NULL) key++;

    key = key % 41;
    if (strcmp(hasht[key].hash1, words) == 0)//�ж϶�ȡ�ĵ����Ƿ�Ϊ�ؼ��� 
    {
        hasht[key].count++;         //ͳ�ƹؼ��ʵ�Ƶ���� 
        return 1;
    }
    for (find = key + 1; find < hashlen; find++)      
    {     //����̽�ⷨ˳����ҹ�ϣ�����Ƿ��Ѵ��ڹؼ��� 
        if (hasht[find].hash1 != NULL)
        {
            if (strcmp(hasht[find].hash1, words) == 0)
            {
                hasht[find].count++;       //ͳ�ƹؼ��ʵ�Ƶ���� 
                return 1;
            }
        }
    }
    for (find = 0; find < key; find++)
    {
        if (hasht[find].hash1 != NULL)
        {
            if (strcmp(hasht[find].hash1, words) == 0)
            {
                hasht[find].count++;         //ͳ�ƹؼ��ʵ�Ƶ���� 
                return 1;
            }
        }
    }
    return 0;
}

int isletter(char ch)
{    //�ж��Ƿ�chΪ��ĸ  
    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) return 1;
    else return 0;
}

int readc(char* filename)
{     //��ȡԴ�����ļ��еĵ��� 
    FILE* fp1 = NULL;
    char words[maxlen], ch;
    int i;
    if ((fp1 = fopen(filename, "r")) == NULL)
    {
        cout << "can not creat file!\n";//��ʾ���ļ�ʧ�� 
       // printf("open fail errno = %d reason = %s \n", errno, strerror(errno));

        exit(0);
    }
    while (!feof(fp1)) //���ļ�δ��ȡ�꣬ѭ��    //��������1 
    {
        i = 0;
        ch = fgetc(fp1);     
        while (isletter(ch) == 0 && feof(fp1) == 0)//isletter()��Ϊ��ĸʱ����0 
        {
            ch = fgetc(fp1);//fgetc()��������ȡ��һ���ֽ� 
        }
         
        while (isletter(ch) == 1 && feof(fp1) == 0)  //��ȡ��ĸ��δ�� 
        {
            if (i == maxlen)
            {
                while (isletter(ch) == 1 && feof(fp1) == 0)
                {
                    ch = fgetc(fp1);
                }
                i = 0;
                break;
            }     //�������ؼ��ֳ��Ƚ���������ǰʶ�����򣬶�ȡ��һ������
            else
            {
                words[i++] = ch;//����ȡ����ĸ�������� 
                ch = fgetc(fp1);
            }
        }
        words[i] = '\0';
        Hashfind(words);     //���õ��ĸõ��ʵ���Hashfind���������ж��Ƿ�Ϊ�ؼ��֣���ͳ��Ƶ���� ********************* 
    }
    fclose(fp1);//�����ļ����Ķ�ȡ 
    return 0;
}

float Mol(int* x)
{     //ȡģ����
    int i = 0, sum = 0;
    for (i = 0; i < N; i++)
    {
        sum += (x[i] * x[i]);
    }
    return (float)pow((float)sum, 0.5);
}

int Dot(int* x1, int* x2)
{     //�������������� ����������� ����a*����b =a1b1+a2b2+...+anbn 
      //������λ�����ĵ���õ����������ļн�cosֵ��ͨ�����ǿ���֪�������������� 
    int i = 0, sum = 0;
    for (i = 0; i < N; i++)
    {
        sum += x1[i] * x2[i];
    }
    return sum;
}

float S(int* x1, int* x2)
{ // �����ƶ�S   cos(Q)=(a��b)/(|a||b|)
    return Dot(x1, x2) / (Mol(x1) * Mol(x2));
    //����������Ϊ�����㰡a(x11,x21,x31,...,x1n)��b(x21,x22,x23,...,x2n),����ʹ�������ڼн����ҵĸ������������ǵ����ƶȡ� 
}

float D(int* x1, int* x2)
{     //�󼸺ξ��� 
    int x[N], i = 0;
    for (i = 0; i < N; i++)     //�������
    {
        x[i] = x1[i] - x2[i];
    }
    return Mol(x);     //����ģ 
}

void check(int* x1, int* x2)
{//�ļ�����=���ƶ�s>��ֵ&&���ξ���<��ֵ 
    float xs = 0, xd = 0;
    xs = S(x1, x2);
    cout << "���ƶ� xs=" << xs << endl << endl;
    if (xs > Smax)     //���ж�S����S������ֵ�ټ��㼯�Ͼ���
    {
        xd = D(x1, x2);
        cout << "\t���ξ��� xd=" << xd << endl;
        if (xd < Dmin)     //������ξ���С����ֵ���ж�Ϊ����
            cout << "�������ļ�����ȷʵ��������" << endl << endl;
        else
            cout << "�������ļ����ݿ��ܲ�����" << endl << endl;
        return;
    }
    cout << "�������ļ����ݲ�����" << endl << endl;     //��������
    return;
}