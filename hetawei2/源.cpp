#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <fstream>
#define N 41
//37���ؼ���
char key[37][10] = { "auto","break","bool","case","char","const","continue","default",
"do","double","else","enum","extern","float","false","for","goto","if","int","inline",
"long","register","return","restrict","short","signed","sizeof","static","struct",
"switch","typedef","true","union","unsigned","void","volatile","while" };


typedef struct mykey {
    char data[10];
    int con;//��ͻ���� 
    int num;//���ִ�����-1��ʾû��
}mykey;
mykey my[N];      //hash�� 
int sum = 0, m, i;           //�ܵĹؼ�������m����ѡ��
FILE* fi;                  //��Ҫ��ȡ�ļ�ָ�� 
FILE* fo;                  //��Ҫд���ļ�ָ�� 
void init();               //��ʼ���ṹ������
bool isChar(char a);       //�ж��ַ��Ƿ�����ĸ
void isKey(char str[]);    //�ж��Ƿ��ǹؼ���




void init() {//ָ��Ϊ�գ���ʼ������
    fi = NULL;
    sum = 0;
    for (int i = 0; i < N; i++) {
        if (my[i].num != -1) {//hash���и�λ���Ƿ��йؼ��� 
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
        if (strcmp(my[y].data, str) == 0) {//��hash���йؼ��ʱȽ��Ƿ���ͬ 
            if (my[y].num == -1)
                break;
            sum++;//��ͬ�ؼ���������1 
            my[y].num++;//���ִ�����1 
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
        int y = (key[i][0] * 100 + key[i][n - 1]) % N; //����ؼ���hashֵ 
        if (my[y].num == -1) {//������ͻ
            my[y].num++;
            strcpy(my[y].data, key[i]);
        }
        else { //��ͻ
            my[y].con++; //��ͻ��1
            for (int j = 0; j < N; j++) { //Ѱ����һ��û�д�Źؼ��ʵĵط� 
                int x = ++y % N;
                if (my[x].num == -1) { //�ҵ���һ��û�д�Źؼ��ʵĵط� 
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
        if (my[i].num != -1) {//hash���и�λ���Ƿ��йؼ��� 
            my[i].num = 0;
        }
    }
    char filename[20];
    puts("������C�ļ�����");
    scanf("%s", filename);
    fi = fopen(filename, "r");
    fo = fopen("test.txt", "w");
    if (fi == NULL) {
        printf("no file\n");
    }

    //��ȡ�ļ� 
    char ch;
    while (!feof(fi)) { //feof()��������ļ��Ƿ����
        char word[20]; //�洢һ��������ĸ
        int i = 0;
        ch = fgetc(fi); //fgetc()��ͷȡһ���ַ����������ֽڹ����ƶ����ֽ�
        while (!isChar(ch) && !feof(fi)) //ȡһ����ĸ
            ch = fgetc(fi);
        while (isChar(ch) && !feof(fi)) { //�������ĸ���ļ�δ����,һ��ѭ����ȡһ����ĸ
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
        isKey(word); //����Ƿ�Ϊ�ؼ���
    }

    printf("�ļ���ȡ�ɹ�");
    printf("����������²�����\n");
    printf("0.�˳���1.��ӡÿ���ؼ��ֳ��ֵ�Ƶ�ʣ�\n"); do {
        printf("��������ȷ�Ĳ������!\n");
        scanf("%d", &m);
    } while (m < 0 || m>2);
    switch (m) {
    case 0:
        printf("��лʹ��!");
        exit(0); break;
    case 1:
        myprintf(); break;
    }



}
