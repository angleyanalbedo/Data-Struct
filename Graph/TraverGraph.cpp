#include<iostream> 
using namespace std;
#include "type.h"

#include"operation.h"
int main()
{
    cout << "\n***���Ĵ�ʵ�飺ͼ�ı���***\n";
    ALGraph G;
    CreatUDG(G);
    GetNodeDu(G);
    DFS_Travel(G);
    BFS_Travel(G);
}
