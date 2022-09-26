#pragma once
#include"data.h"
typedef struct
 Map {
    int n = maxsize;
    string position[maxsize] = { "14公寓 ","13公寓 ","西院出口","15公寓 ","16公寓 ","17公寓 ","食堂","大活","图书馆","12号楼 ","11号楼 ","10号楼 "," 9号楼"," 8号楼" };
    char code[maxsize] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n' };
    int edges[maxsize][maxsize] = {
        {0,50,INF,200,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF},
        {50,0,50,INF,INF,200,350,350,INF,INF,INF,INF,INF,INF},
        {INF,50,0,INF,INF,250,400,400,INF,INF,INF,INF,INF,INF},
        {200,INF,INF,0,50,50,INF,INF,INF,INF,INF,INF,INF,INF},
        {INF,INF,INF,50,0,50,60,80,INF,INF,INF,INF,INF,INF},
        {INF,200,250,50,50,0,150,150,INF,INF,INF,INF,INF,INF},
        {INF,350,400,INF,60,150,0,40,INF,INF,INF,INF,INF,INF},
        {INF,350,400,INF,80,150,40,0,100,100,130,150,200,220},
        {INF,INF,INF,INF,INF,INF,INF,100,0,50,70,90,140,160},
        {INF,INF,INF,INF,INF,INF,INF,100,50,0,10,INF,INF,INF},
        {INF,INF,INF,INF,INF,INF,INF,130,70,10,0,10,INF,INF},
        {INF,INF,INF,INF,INF,INF,INF,150,90,INF,10,0,50,INF},
        {INF,INF,INF,INF,INF,INF,INF,200,140,INF,INF,50,0,10},
        {INF,INF,INF,INF,INF,INF,INF,220,160,INF,INF,INF,10,0} };
}Mgraph;

string map[10][7] = {
    {"||         ","           ","           ","           "," 15公寓(d) "," 14公寓(a) ","         ||"},
    {"||         ","  食堂(g)  ","           ","  16公寓(e) ","           ","          ","         ||"},
    {"||         ","           ","           ","           "," 17公寓(f) "," 13公寓(b) ","          /"},
    {"||         ","  大活(h)  ","           ","           ","           ","           "," 西院出口(c)  "},
    {"||12号楼(j)","           ","  图书馆(i) ","           ","           ","          ","          \\"},
    {"||11号楼(k)","           ","           ","           ","           ","           ","         ||"},
    {"||10号楼(l)","           ","           ","           ","           ","           ","         ||"},
    {"||         ","           ","           ","           ","           ","           ","         ||"},
    {"||9 号楼(m)","           ","           ","           ","           ","           ","         ||"},
    {"||8 号楼(n)","           ","           ","           ","           ","           ","         ||"} };



//Dijkstra
void Dijkstra(Mgraph g, int v, int dist[], int path[])
{
    int set[maxsize];
    int i, j, u;
    for (i = 0; i < g.n; i++)
    {
        set[i] = 0;
        dist[i] = g.edges[v][i];
        if (dist[i] < INF && i != v) { path[i] = v; }
        else { path[i] = -1; }
    }
    set[v] = 1;
    //path[v]=-1;
    for (i = 0; i < g.n; i++)
    {
        int min = INF;
        for (j = 0; j < g.n; j++)
        {
            if (dist[j] < min && set[j] == 0)
            {
                u = j;
                min = dist[j];
            }
        }
        set[u] = 1;
        for (j = 0; j < g.n; j++)
        {
            if (set[j] == 0 && (dist[j] > g.edges[u][j] + dist[u]))
            {
                dist[j] = dist[u] + g.edges[u][j];
                path[j] = u;
            }
        }
    }
}



//Floyd
void Floyd(Mgraph g, int A[][maxsize], int path[][maxsize])
{
    int i, j, k;
    for (i = 0; i < g.n; i++)
    {
        for (j = 0; j < g.n; j++)
        {
            A[i][j] = g.edges[i][j];
            if (A[i][j] < INF && i != j) { path[i][j] = i; }
            else path[i][j] = -1;
        }
    }
    for (k = 0; k < g.n; k++)
    {
        for (i = 0; i < g.n; i++)
        {
            for (j = 0; j < g.n; j++)
            {
                if (A[i][k] + A[k][j] < A[i][j])
                {
                    A[i][j] = A[i][k] + A[k][j];
                    path[i][j] = path[k][j];
                }
            }
        }
    }
}



//1. 输出顶点信息：将校园内各景点输出。
//打印地图
void printMap()
{
    cout << "*****************************************************************************" << endl;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            cout << map[i][j];
        }
        cout << endl;
    }
    cout << "*****************************************************************************" << endl;
}



//打印两个位置（若两个位置之间有直接路径）的距离 Distance between two points
//2. 输出边的信息：将校园内每两个位置（若两个位置之间有直接路径）的距离输出。
void printDBTP(Mgraph g)
{
    cout << endl;
    int flag[maxsize][maxsize] = { 0 };
    int tmp = 0, count = 0;
    for (int i = 0; i < g.n; i++)
    {
        for (int j = 0; j < g.n; j++)
        {
            if (g.edges[i][j] != INF && g.edges[i][j] != 0)
            {
                flag[i][j] = 1;
                tmp = 0;
                if (flag[j][i] == 0) { cout << "{" << g.position[i] << "，" << g.position[j] << "}" << "：" << g.edges[i][j] << "m    "; tmp = 1; count++; }
            }
            if (count == 3) { cout << endl; count = 0; }
        }
        if (tmp == 1)
        {
            if (count != 0) { cout << endl; }
            cout << endl;
            count = 0;
        }
    }
}



//3. 修改：修改两个位置（若两个位置之间有直接路径）的距离；
Mgraph function_3(Mgraph g)
{
    cout << endl;
    char array[20];
    int i, j;

    while (true)
    {
        //判断起点
        while (true)
        {
            //array[20]={NULL};
            cout << "请输入第一个位置的代号：";
            cin.get(array, 20);
            cin.clear();//这里清空之前cin缓冲区的数据
            while (cin.get() != '\n') { continue; }
            if (array[1] == '\0')
            {
                for (i = 0; i < g.n; i++) { if (array[0] == g.code[i]) { cout << "第一个位置是：" << g.position[i] << endl; break; } }
                if (i == g.n) { cout << "在地图上找不到该地点！" << endl; continue; }
                break;
            }
            else { cout << "错误的代号格式！" << endl; continue; }
        }

        //判断终点
        while (true)
        {
            //array[20]={NULL};
            cout << "请输入第二个位置的代号：";
            cin.get(array, 20);
            cin.clear();//这里清空之前cin缓冲区的数据
            while (cin.get() != '\n') { continue; }
            if (array[1] == '\0')
            {
                for (j = 0; j < g.n; j++) { if (array[0] == g.code[j]) { cout << "第二个位置是：" << g.position[j] << endl; break; } }
                if (j == g.n) { cout << "在地图上找不到该地点！" << endl; continue; }
                break;
            }
            else { cout << "错误的代号格式！" << endl; continue; }
        }

        if (g.edges[i][j] == INF)
        {
            cout << "这两个位置没有直接距离！" << endl;
            continue;
        }

        while (true)
        {
            cout << "请设置这两个地点之间的新距离：";
            int p;
            if (cin >> p)
            {
                cin.clear();//这里清空之前cin缓冲区的数据
                while (cin.get() != '\n') { continue; }
                g.edges[i][j] = p;
                g.edges[j][i] = p;
                break;
            }
            else {
                cin.clear();//这里清空之前cin缓冲区的数据
                while (cin.get() != '\n') { continue; }
                cout << "输入的数据类型不正确！" << endl;
            }
        }
        break;
    }
    return g;
}



//4.1 求最短路径：输出给定两点之间的最短路径的长度及途经的地点
void function_4_1(Mgraph g) {
    int i = -1, j = -1, tmp;
    cout << endl;
    char array[20];

    //判断起点
    while (true)
    {
        //array[20]={NULL};
        cout << "请输入起点位置的代号：";
        cin.get(array, 20);
        cin.clear();//这里清空之前cin缓冲区的数据
        while (cin.get() != '\n') { continue; }
        if (array[1] == '\0')
        {
            for (i = 0; i < g.n; i++) { if (array[0] == g.code[i]) { cout << "起点是：" << g.position[i] << endl; break; } }
            if (i == g.n) { cout << "在地图上找不到该地点！" << endl; continue; }
            break;
        }
        else { cout << "错误的代号格式！" << endl; continue; }
    }

    //判断终点
    while (true)
    {
        //array[20]={NULL};
        cout << "请输入终点位置的代号：";
        cin.get(array, 20);
        cin.clear();//这里清空之前cin缓冲区的数据
        while (cin.get() != '\n') { continue; }
        if (array[1] == '\0')
        {
            for (j = 0; j < g.n; j++) { if (array[0] == g.code[j]) { cout << "终点是：" << g.position[j] << endl; break; } }
            if (j == g.n) { cout << "在地图上找不到该地点！" << endl; continue; }
            break;
        }
        else { cout << "错误的代号格式！" << endl; continue; }
    }

    int path[maxsize];
    int dist[maxsize];
    Dijkstra(g, i, dist, path);
    stack<string> map;
    // tmp=j;
    // while (true)
    // {
    //     if (tmp==-1){map.push(g.position[i]);break;}
    //     map.push(g.position[tmp]);
    //     tmp=path[tmp];
    // }
    tmp = path[j];
    int flag = 0;
    while (true)
    {
        if (flag == 0) { map.push(g.position[j]); flag = 1; }
        if (tmp != -1) { map.push(g.position[tmp]); }
        else { break; }
        tmp = path[tmp];
    }
    cout << "路线为： ";
    while (true)
    {
        cout << map.top();
        map.pop();
        if (!map.empty()) { cout << " => "; }
        else { break; }
    }
    cout << endl;
    cout << "路程为： " << dist[j] << "m" << endl;
}



//4.2 求最短路径：输出指定一点与其他各点的最短路径。
void function_4_2(Mgraph g)
{
    char array[20];
    int i;
    //判断起点
    while (true)
    {
        cout << "请输入你想查询的出发点代号：";
        cin.get(array, 20);
        cin.clear();//这里清空之前cin缓冲区的数据
        while (cin.get() != '\n') { continue; }
        if (array[1] == '\0')
        {
            for (i = 0; i < g.n; i++) { if (array[0] == g.code[i]) { cout << "出发点是：" << g.position[i] << endl; break; } }
            if (i == g.n) { cout << "在地图上找不到该地点！" << endl; continue; }
            break;
        }
        else { cout << "错误的代号格式！" << endl; continue; }
    }

    int path[maxsize];
    int dist[maxsize];
    Dijkstra(g, i, dist, path);
    int j, tmp;
    stack<string> map;
    for (j = 0; j < g.n; j++)
    {
        tmp = path[j];
        int flag = 0;
        while (true)
        {
            if (i == j) { break; }
            if (flag == 0) { map.push(g.position[j]); flag = 1; }
            if (tmp != -1) { map.push(g.position[tmp]); }
            else { break; }
            tmp = path[tmp];
        }
        if (flag == 0) { continue; }
        while (true)
        {
            cout << map.top();
            map.pop();
            if (!map.empty()) { cout << " => "; }
            else { break; }
        }
        cout << "----【路程为】:" << dist[j] << "m" << endl;
    }
}



//4.3 求最短路径：输出任意一点与其他各点的最短路径。
void function_4_3(Mgraph g)
{
    int A[maxsize][maxsize];
    int path[maxsize][maxsize];
    Floyd(g, A, path);
    int i, j, tmp;
    stack<string> map;
    for (i = 0; i < g.n; i++)
    {
        for (j = 0; j < g.n; j++)
        {
            tmp = path[i][j];
            int flag = 0;
            while (true)
            {
                if (i == j) { break; }
                if (flag == 0) { map.push(g.position[j]); flag = 1; }
                if (tmp != -1) { map.push(g.position[tmp]); }
                else { break; }
                tmp = path[i][tmp];
            }
            if (flag == 0) { continue; }
            while (true)
            {
                cout << map.top();
                map.pop();
                if (!map.empty()) { cout << " => "; }
                else { break; }
            }
            cout << "----【路程为】:" << A[i][j] << "m" << endl;
        }
        cout << endl;
    }
}


