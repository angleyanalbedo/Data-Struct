#include"Search.h"
int a[] = { 1,2,3,4,5,6,7,8,9,10,11 };
int x = 0;
int main() {
	std::cout << "������Ҫ���ҵ�����" << std::endl;
	std::cin >> x;
	std::cout << "û��ʹ�õݹ���ҵ�λ��" << std::endl;
	std::cout << Search(a, 11, x) + 1 << std::endl;;
	std::cout << "ʹ�÷��ǵݹ���ҵ�λ��" << std::endl;
	std::cout << Search_s(a, 0, 10, x) + 1;
	return 0;
}