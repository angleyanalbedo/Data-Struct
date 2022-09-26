#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

class Line {
public:
	int a = f();
	Line() {
		printf("kaishi\n");
	}
	Line(const Line& obj) {
		printf("kaibei");
	}
	int f() {
		printf("aaaa\n");
		return 1;
	}
};


Line fun1(Line l1) {
	return l1;
}
int main()
{
	Line l1;
	
}