
#include<iostream>
#include<string>
#include<stack>
#include"base.h"


//主函数
int main()
{
    Mgraph g;
    printMap();

    int flag;
    while (true)
    {
        cout << "\n" << endl;
        cout << "1. 输出校园内各位置" << endl;
        cout << "2. 将校园内每两个位置（若两个位置之间有直接路径）的距离输出" << endl;
        cout << "3. 修改两个位置（若两个位置之间有直接路径）的距离" << endl;
        cout << "4. 输出给定两点之间的最短路径的长度及途经的地点" << endl;
        cout << "5. 输出指定一点到其他各点的最短路径" << endl;
        cout << "6. 输出任意一点到其他各点的最短路径" << endl;
        cout << "0. 退出程序" << endl;
        cin >> flag;
        cin.clear();//这里清空之前cin缓冲区的数据
        while (cin.get() != '\n') { continue; }
        if (flag == 1) { printMap(); }
        else if (flag == 2) { printDBTP(g); }
        else if (flag == 3) { g = function_3(g); }
        else if (flag == 4) { function_4_1(g); }
        else if (flag == 5) { function_4_2(g); }
        else if (flag == 6) { function_4_3(g); }
        else { break; }
    }
    return 0;
}
