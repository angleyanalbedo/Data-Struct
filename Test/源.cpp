#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<math.h>

#define N 32     //关键字个数
#define size 256
#define maxlen 9     //关键字数组长度
#define hashlen 41     //哈希表长度
#define Smax 0.9     //相似度s的阈值
#define Dmin 2     //D几何距离的阈值

struct hashtable     //结构体数组哈希表
{
    char* hash1;     //指向关键字的指针
    int count;     //记录频度数 
}hasht[hashlen];

using namespace std;

void Hashfunc(char str[]);     //将关键字根据哈希函数放入哈希表的指定位置
int Hashfind(char* words);     //在哈希表中找是否该word为关键字，并记录频度
void creathash(void);     //创建哈希表
int readc(char* filename);     //读取源程序文件中的单词
int isletter(char ch);     //判断是否为字母
int getkey(char* str, int len);     //读取该单词的关键词 
void resethash(int n);     //重置哈希表
void copycount(int x[], int n);     //将频数拷贝到数组里
float Mol(int* x);     //取模函数
int Dot(int* x1, int* x2);     //点积函数
float D(int* x1, int* x2);     //求距离D的函数 
float S(int* x1, int* x2);     //求相似的S的函数
void check(int* x1, int* x2);     //检查两个源程序是否相似




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
    cout << "\t" << "哈希序号" << "    \t\t" << "关键字" << "    \t\t" << "频数 1" << "    \t\t" << "频数 2" << "    \t\t" << "频数 3" << endl;
    for (int i = 0; i < 41; i++)
    {
        if (hasht[i].hash1 != NULL)
        {
            cout << "\t" << i << "       \t\t" << hasht[i].hash1 << "       \t\t" << x1[i] << "       \t\t" << x2[i] << "       \t\t" << x3[i] << endl;
        }
    }
    cout << filename1 << "和" << filename2 << "的相似情况为：";
    check(x1, x2);     //检查相似度 
    cout << filename1 << "和" << filename3 << "的相似情况为：";
    check(x1, x3);     //检查相似度
    cout << filename2 << "和" << filename3 << "的相似情况为：";
    check(x2, x3);     //检查相似度
    while (1);
    return 0;
}

void resethash(int n)
{     //重置哈希表 
    if (n = 0)     
    {
        for (int i = 0; i < 41; i++)
        {
            hasht[i].hash1 = NULL;
            hasht[i].count = 0;
        }
    }
    else if (n = 1)     //仅仅重置频数 
    {
        for (int i = 0; i < 41; i++)
        {
            hasht[i].count = 0;
        }
    }
}

void copycount(int x[], int n)
{     //拷贝频数 
    for (int i = 0; i < n; i++)
    {
        x[i] = hasht[i].count;
    }
}

int getkey(char* str, int len){     
    char key1, key2;
    int key;
    key1 = str[0];//关键词首字母 
    key2 = str[len - 1];//关键词尾字母 
    key = (int)(key1 * 100 + key2) % 41;
    return key;
}

void creathash(void)
{     
    FILE* fp;           //声明指向文件的指针 
    int length;
    char str[size];     //暂时存储关键字字符的数组 
    char* s = NULL;      //声明一个指针 
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
    if (strcmp(hasht[key].hash1, words) == 0)//判断读取的单词是否为关键词 
    {
        hasht[key].count++;         //统计关键词的频度数 
        return 1;
    }
    for (find = key + 1; find < hashlen; find++)      
    {     //线性探测法顺序查找哈希表中是否已存在关键字 
        if (hasht[find].hash1 != NULL)
        {
            if (strcmp(hasht[find].hash1, words) == 0)
            {
                hasht[find].count++;       //统计关键词的频度数 
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
                hasht[find].count++;         //统计关键词的频度数 
                return 1;
            }
        }
    }
    return 0;
}

int isletter(char ch)
{    //判断是否ch为字母  
    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) return 1;
    else return 0;
}

int readc(char* filename)
{     //读取源程序文件中的单词 
    FILE* fp1 = NULL;
    char words[maxlen], ch;
    int i;
    if ((fp1 = fopen(filename, "r")) == NULL)
    {
        cout << "can not creat file!\n";//提示打开文件失败 
       // printf("open fail errno = %d reason = %s \n", errno, strerror(errno));

        exit(0);
    }
    while (!feof(fp1)) //当文件未读取完，循环    //结束返回1 
    {
        i = 0;
        ch = fgetc(fp1);     
        while (isletter(ch) == 0 && feof(fp1) == 0)//isletter()不为字母时返回0 
        {
            ch = fgetc(fp1);//fgetc()返回所读取的一个字节 
        }
         
        while (isletter(ch) == 1 && feof(fp1) == 0)  //读取字母且未完 
        {
            if (i == maxlen)
            {
                while (isletter(ch) == 1 && feof(fp1) == 0)
                {
                    ch = fgetc(fp1);
                }
                i = 0;
                break;
            }     //超过最大关键字长度将会跳过当前识别区域，读取下一个单词
            else
            {
                words[i++] = ch;//将读取的字母存入数组 
                ch = fgetc(fp1);
            }
        }
        words[i] = '\0';
        Hashfind(words);     //将得到的该单词调入Hashfind函数，来判断是否为关键字，并统计频度数 ********************* 
    }
    fclose(fp1);//结束文件流的读取 
    return 0;
}

float Mol(int* x)
{     //取模函数
    int i = 0, sum = 0;
    for (i = 0; i < N; i++)
    {
        sum += (x[i] * x[i]);
    }
    return (float)pow((float)sum, 0.5);
}

int Dot(int* x1, int* x2)
{     //向量数量积函数 （点积函数） 向量a*向量b =a1b1+a2b2+...+anbn 
      //两个单位向量的点积得到两个向量的夹角cos值，通过它们可以知道向量的相似性 
    int i = 0, sum = 0;
    for (i = 0; i < N; i++)
    {
        sum += x1[i] * x2[i];
    }
    return sum;
}

float S(int* x1, int* x2)
{ // 求相似度S   cos(Q)=(a·b)/(|a||b|)
    return Dot(x1, x2) / (Mol(x1) * Mol(x2));
    //对于两个多为样本点啊a(x11,x21,x31,...,x1n)和b(x21,x22,x23,...,x2n),可以使用类似于夹角余弦的概念来衡量他们的相似度。 
}

float D(int* x1, int* x2)
{     //求几何距离 
    int x[N], i = 0;
    for (i = 0; i < N; i++)     //向量相减
    {
        x[i] = x1[i] - x2[i];
    }
    return Mol(x);     //再求模 
}

void check(int* x1, int* x2)
{//文件相似=相似度s>阈值&&几何距离<阈值 
    float xs = 0, xd = 0;
    xs = S(x1, x2);
    cout << "相似度 xs=" << xs << endl << endl;
    if (xs > Smax)     //先判断S，若S大于阈值再计算集合距离
    {
        xd = D(x1, x2);
        cout << "\t几何距离 xd=" << xd << endl;
        if (xd < Dmin)     //如果几何距离小于阈值则判断为相似
            cout << "这两个文件内容确实可能相似" << endl << endl;
        else
            cout << "这两个文件内容可能不相似" << endl << endl;
        return;
    }
    cout << "这两个文件内容不相似" << endl << endl;     //否则不相似
    return;
}