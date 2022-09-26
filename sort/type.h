#pragma once
#define MAXSIZE 101
#include<iostream>
#include<stdlib.h>
#include<time.h>
typedef int KeyType;
typedef char InfoType;
typedef struct {
	KeyType key;
	InfoType otherinfo;
}RedType;
typedef struct {
	RedType r[MAXSIZE];
	int length;
}SqList;
 
/*
 注意SqList的r[0]号用来中作为交换的临时变量不要对其赋值
*/
void InsertSort(SqList& L);
void BInsertSort(SqList& L);
void ShellInsert(SqList& L,int dk);
void ShellSort(SqList& L, int dt[], int t);