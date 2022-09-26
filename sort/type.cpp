/*
引用 数据结构 人民邮电出版社
*/
#include"type.h"
void InsertSort(SqList& L) {
	int i = 0, j = 0;
	for (i = 2; i <= L.length; ++i) {
		L.r[0] = L.r[i];
		L.r[i] = L.r[i - 1];
		for (j = i - 2; L.r[0].key < L.r[j].key; --j)
			L.r[j + 1] = L.r[j];
		L.r[j + 1] = L.r[0];
	}

}
void BInsertSort(SqList& L) {
	int i = 0, j = 0, m = 0;
	int low = 0, high = 0;
	for (i = 2; i <= L.length; ++i) {
		L.r[0] = L.r[i];
		low = 1; high = i - 1;
		while (low<high)
		{
			m = (low + high) / 2;
			if (L.r[0].key < L.r[m].key) high = m - 1; else low = m + 1;
		}
		for (j = i - 1; j >= high + 1; --j) L.r[j + 1] = L.r[j];
		L.r[high + 1] = L.r[0];
	}
}
void ShellInsert(SqList& L,int dk) {
	int i = 0, j = 0;
	for (i = dk + 1; i < L.length; ++i) 
		if (L.r[0].key < L.r[i - dk].key) {
			L.r[0] = L.r[i];
			for (j = j - dk; j > 0 && L.r[0].key < L.r[j].key; j -= dk)
				L.r[j + dk] = L.r[j];
			L.r[j + dk] = L.r[0];
		}
	
}
void ShellSort(SqList& L, int dk[], int t) {
	for (int k = 0; k < t; ++k) {
		ShellInsert(L, dk[k]);
	}
}