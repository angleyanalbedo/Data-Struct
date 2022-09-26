#pragma once
Status LocateVex(ALGraph G, VerTexType x)//CreateUDG里面用到的查找函数 
{
    for (int i = 0; i < G.vexnum; i++)
    {
        if (G.vertices[i].data == x)
            return i;
    }
    return -1;
}

void CreatUDG(ALGraph& G)
{
    cout << "输入总顶点数，总边数：\n";
    cin >> G.vexnum >> G.arcnum;//输入顶点数和边数
    cout << "请输入各点信息:";

    int i, j, k;
    char v1, v2;

    for (i = 0; i < G.vexnum; ++i)
    {
        cout << "请输入顶点值:\n";
        cin >> G.vertices[i].data;
        G.vertices[i].firstarc = NULL;
    }

    ArcNode* p1, * p2;

    for (k = 0; k < G.arcnum; ++k)
    {
        cout << "请输入一条边依附的两个顶点:\n";
        cin >> v1 >> v2;
        i = LocateVex(G, v1);
        j = LocateVex(G, v2);

        p1 = new ArcNode;
        p1->adjvex = j;
        p1->nextarc = G.vertices[i].firstarc;
        G.vertices[i].firstarc = p1;

        p2 = new ArcNode;
        p2->adjvex = i;
        p2->nextarc = G.vertices[j].firstarc;
        G.vertices[j].firstarc = p2;
    }
}

void GetNodeDu(ALGraph G)
{
    int Du, i;
    ArcNode* p;

    for (i = 0; i < G.vexnum; i++)
    {
        Du = 0;
        p = G.vertices[i].firstarc;

        while (p)
        {
            p = p->nextarc;
            Du++;
        }
        cout << "结点" << G.vertices[i].data << "的度为" << Du << "\n";
    }
}
//无向图的邻接链表的第i个顶点的DFS
void DFS(ALGraph G, int i)
{
    visited[i] = true;
    cout << "顶点" << G.vertices[i].data;

    ArcNode* p;
    p = G.vertices[i].firstarc;

    while (p)
    {
        if (!visited[p->adjvex])
            DFS(G, p->adjvex);
        p = p->nextarc;
    }
}

//对整个邻接表进行DFS
void DFS_Travel(ALGraph G)
{
    int i;
    cout << "\n开始进行深度优先搜索\n\n";

    for (i = 0; i < G.vexnum; i++)
        visited[i] = false;
    cout << "无向图的邻接链表DFS结果为：\n\n";
    for (i = 0; i < G.vexnum; i++)
        if (!visited[i])
            DFS(G, i);
}

void BFS(ALGraph G, int i)
{
    int j;
    ArcNode* p;
    int queue[MVNum];
    int front, rear;
    front = rear = 0;//证明被访问过

    visited[i] = 1;
    queue[rear++] = i; //将访问过的节点加入列队中

    cout << "顶点" << i;
    while (rear > front)
    {
        j = queue[front++];
        p = G.vertices[j].firstarc;
        while (p)
        {
            if (visited[p->adjvex] == 0)
            {
                cout << "顶点" << p->adjvex;
                queue[rear++] = p->adjvex;
                visited[p->adjvex] = 1;
            }
            p = p->nextarc;
        }
    }
}
//对整个邻接表进行DFS
void BFS_Travel(ALGraph G)
{
    int index;
    for (index = 0; index < G.vexnum; ++index)
    {
        visited[index] = 0;
    }
    cout << "\n\n开始进行广度优先搜索\n\n";
    cout << "无向图的邻接链表BFS结果为：\n\n";
    for (index = 0; index < G.vexnum; index++)
    {
        if (!visited[index])
            BFS(G, index);
    }
}