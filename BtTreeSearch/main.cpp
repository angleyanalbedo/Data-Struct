#include"Search.h"
int a[] = { 1,2,3,4,5,6,7,8,9,10,11 };
int x = 0;
int main() {
	std::cout << "输入需要查找的数字" << std::endl;
	std::cin >> x;
	std::cout << "没有使用递归查找的位置" << std::endl;
	std::cout << Search(a, 11, x) + 1 << std::endl;;
	std::cout << "使用发非递归查找的位置" << std::endl;
	std::cout << Search_s(a, 0, 10, x) + 1;
	return 0;
}