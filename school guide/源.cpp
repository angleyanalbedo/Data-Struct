
#include<iostream>
#include<string>
#include<stack>
#include"base.h"


//������
int main()
{
    Mgraph g;
    printMap();

    int flag;
    while (true)
    {
        cout << "\n" << endl;
        cout << "1. ���У԰�ڸ�λ��" << endl;
        cout << "2. ��У԰��ÿ����λ�ã�������λ��֮����ֱ��·�����ľ������" << endl;
        cout << "3. �޸�����λ�ã�������λ��֮����ֱ��·�����ľ���" << endl;
        cout << "4. �����������֮������·���ĳ��ȼ�;���ĵص�" << endl;
        cout << "5. ���ָ��һ�㵽������������·��" << endl;
        cout << "6. �������һ�㵽������������·��" << endl;
        cout << "0. �˳�����" << endl;
        cin >> flag;
        cin.clear();//�������֮ǰcin������������
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
