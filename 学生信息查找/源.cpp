#include<vector>
#include<iostream>
struct Ta {
	std::string name;
	int xuehao;
	int score1;
	int score2;
};
int main() {
	std::vector<Ta> con;
	Ta tmp;
	for (int i = 0; i < 10; ++i) {
		std::cin >> tmp.name;
		std::cin >> tmp.xuehao;
		std::cin >> tmp.score1;
		std::cin >> tmp.score2;
		con.push_back(tmp);
	}
	std::cout << "输入查找的学号" << std::endl;
	int a = 0;
	std::cin >> a;
	for (int i = 0; i < 10; ++1) {
		if (con[i].xuehao == a) {
			std::cout << con[i].score1;
			std::cout << con[i].score2;
		}
	}

}