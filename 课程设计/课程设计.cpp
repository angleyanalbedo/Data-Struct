// 课程设计.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include"room.h"

void startup() {

    
    std::cout << "开始游戏" << std::endl;
    std::cout << "输入迷宫的长和宽" << std::endl;
    
    
}
void Operation() {
    std::cout << "w代表向上" << std::endl;
    std::cout << "s代表向下" <<std::endl;
    std::cout << "a代表向左" << std::endl;
    std::cout << "d代表向右" << std::endl;
    std::cout << "q代表退出" << std::endl;
}
void Srart() {
    startup();
    Operation();
    int row = 0, clo = 0;
    std::cout << "输入长宽" << std::endl;
    std::cin >> row >> clo;
    char ch;
    Room rom(row,clo);
    rom.PrintRoom();
    std::cout << "开始" << std::endl;
    while (std::cin >> ch && ch != 'q') {
        if (rom.Win()) {
            std::cout << "你赢了" << std::endl;
            break;
        
        };
        switch (ch) {
        case 'w':
            //rom.clearScreen();
            std::cout << "向上移动" << std::endl;
            rom.moveUp();
            rom.PrintRoom();
            break;
        case 's':
            //rom.clearScreen();
            std::cout << "向下移动" << std::endl;
            rom.moveDown();
            rom.PrintRoom();
            break;
        case 'a':
            //rom.clearScreen();
            std::cout << "向左移动" << std::endl;
            rom.moveLeft();
            rom.PrintRoom();
            break;
        case 'd':
            //rom.clearScreen();
            std::cout << "向右移动" << std::endl;
            rom.moveRight();
            rom.PrintRoom();
            break;

        }
    }

}
int main()
{
    /*Room rom(10,10);
    rom.PrintRoom();*/
    Srart();
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
