#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <fstream>
#define N 41
//37个关键字
char key[37][10] = { "auto","break","bool","case","char","const","continue","default",
"do","double","else","enum","extern","float","false","for","goto","if","int","inline",
"long","register","return","restrict","short","signed","sizeof","static","struct",
"switch","typedef","true","union","unsigned","void","volatile","while" };


typedef struct mykey {
    char data[10];
    int con;//冲突次数 
    int num;//出现次数，-1表示没有
}mykey;
mykey my[N];      //hash表 
int sum = 0, m, i;           //总的关键字数，m用于选项
FILE* fi;                  //所要读取文件指针 
FILE* fo;                  //所要写的文件指针 
void init();               //初始化结构体数组
bool isChar(char a);       //判断字符是否是字母
void isKey(char str[]);    //判断是否是关键字




void init() {//指针为空，初始化数据
    fi = NULL;
    sum = 0;
    for (int i = 0; i < N; i++) {
        if (my[i].num != -1) {//hash表中该位置是否有关键词 
            my[i].num = 0;
        }
    }
}


bool isChar(char a) {
    if (a >= 'a' && a <= 'z' || a >= 'A' && a <= 'Z')
        return true;
    else
        return false;
}

void isKey(char str[]) {
    int n = strlen(str);
    int y = (str[0] * 100 + str[n - 1]) % N;
    int i = 0;
    do {
        i++;
        if (strcmp(my[y].data, str) == 0) {//与hash表中关键词比较是否相同 
            if (my[y].num == -1)
                break;
            sum++;//相同关键词总数加1 
            my[y].num++;//出现次数加1 
            break;
        }
        else {
            y = (y + 1) % N;
        }
    } while (i <= N);
}
void myprintf() {


    for (int i = 0; i < N; i++) {
        printf("%d", my[i].num);
    }
}


void create() {
    for (i = 0; i < N; i++) {
        my[i].con = 0;
        my[i].num = -1;
    }
    for (i = 0; i < 37; i++) {
        int n = strlen(key[i]);
        int y = (key[i][0] * 100 + key[i][n - 1]) % N; //计算关键词hash值 
        if (my[y].num == -1) {//若不冲突
            my[y].num++;
            strcpy(my[y].data, key[i]);
        }
        else { //冲突
            my[y].con++; //冲突加1
            for (int j = 0; j < N; j++) { //寻找下一个没有存放关键词的地方 
                int x = ++y % N;
                if (my[x].num == -1) { //找到下一个没有存放关键词的地方 
                    my[x].num++;
                    strcpy(my[x].data, key[i]);
                    break;
                }
            }
        }
    }
}






int main()

{
    create();
    fi = NULL;
    sum = 0;
    for (int i = 0; i < N; i++) {
        if (my[i].num != -1) {//hash表中该位置是否有关键词 
            my[i].num = 0;
        }
    }
    char filename[20];
    puts("请输入C文件名：");
    scanf("%s", filename);
    fi = fopen(filename, "r");
    fo = fopen("test.txt", "w");
    if (fi == NULL) {
        printf("no file\n");
    }

    //读取文件 
    char ch;
    while (!feof(fi)) { //feof()函数检测文件是否结束
        char word[20]; //存储一段连续字母
        int i = 0;
        ch = fgetc(fi); //fgetc()从头取一个字符，读多少字节光标后移多少字节
        while (!isChar(ch) && !feof(fi)) //取一个字母
            ch = fgetc(fi);
        while (isChar(ch) && !feof(fi)) { //如果是字母且文件未结束,一次循环读取一段字母
            if (i == 10) {
                while (isChar(ch) && !feof(fi)) {
                    ch = fgetc(fi);
                }
                i = 0;
                break;
            }
            else {
                word[i++] = ch;
                ch = fgetc(fi);
            }
        }
        word[i] = '\0';
        isKey(word); //检测是否为关键字
    }

    printf("文件读取成功");
    printf("你可以做如下操作：\n");
    printf("0.退出，1.打印每个关键字出现的频率，\n"); do {
        printf("请输入正确的操作编号!\n");
        scanf("%d", &m);
    } while (m < 0 || m>2);
    switch (m) {
    case 0:
        printf("感谢使用!");
        exit(0); break;
    case 1:
        myprintf(); break;
    }



}
