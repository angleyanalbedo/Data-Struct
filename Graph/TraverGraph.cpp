#include<iostream> 
using namespace std;
#include "type.h"

#include"operation.h"
int main()
{
    cout << "\n***第四次实验：图的遍历***\n";
    ALGraph G;
    CreatUDG(G);
    GetNodeDu(G);
    DFS_Travel(G);
    BFS_Travel(G);
}
