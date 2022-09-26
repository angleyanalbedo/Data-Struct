#include"Search.h"
int Search(int a[], int n,int key) {
	int left = 0, right = n - 1,mid = (left+right)/2;
	while (left<=right) {
		if (key == a[mid])return mid;
		if (key > a[mid]) {
			left = mid + 1;
		}
		else {
			
			right = mid - 1;
		}
		mid = (left + right) / 2;
		
	}
	return 0;
	
}
int Search_s(int a[], int left,int right, int key) {
	if (left > right) return 0;
	if (a[(left + right) / 2] == key) {
		return (left + right) / 2;
	}
	else if ((a[(left + right) / 2] > key))
	{
		Search_s(a, left, (left + right) / 2, key);
	}
	else {
		Search_s(a, (left + right) / 2, right, key);
	}

}