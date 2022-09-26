#pragma once
Status LocateVex(ALGraph G, VerTexType x)//CreateUDG�����õ��Ĳ��Һ��� 
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
    cout << "�����ܶ��������ܱ�����\n";
    cin >> G.vexnum >> G.arcnum;//���붥�����ͱ���
    cout << "�����������Ϣ:";

    int i, j, k;
    char v1, v2;

    for (i = 0; i < G.vexnum; ++i)
    {
        cout << "�����붥��ֵ:\n";
        cin >> G.vertices[i].data;
        G.vertices[i].firstarc = NULL;
    }

    ArcNode* p1, * p2;

    for (k = 0; k < G.arcnum; ++k)
    {
        cout << "������һ������������������:\n";
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
        cout << "���" << G.vertices[i].data << "�Ķ�Ϊ" << Du << "\n";
    }
}
//����ͼ���ڽ�����ĵ�i�������DFS
void DFS(ALGraph G, int i)
{
    visited[i] = true;
    cout << "����" << G.vertices[i].data;

    ArcNode* p;
    p = G.vertices[i].firstarc;

    while (p)
    {
        if (!visited[p->adjvex])
            DFS(G, p->adjvex);
        p = p->nextarc;
    }
}

//�������ڽӱ����DFS
void DFS_Travel(ALGraph G)
{
    int i;
    cout << "\n��ʼ���������������\n\n";

    for (i = 0; i < G.vexnum; i++)
        visited[i] = false;
    cout << "����ͼ���ڽ�����DFS���Ϊ��\n\n";
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
    front = rear = 0;//֤�������ʹ�

    visited[i] = 1;
    queue[rear++] = i; //�����ʹ��Ľڵ�����ж���

    cout << "����" << i;
    while (rear > front)
    {
        j = queue[front++];
        p = G.vertices[j].firstarc;
        while (p)
        {
            if (visited[p->adjvex] == 0)
            {
                cout << "����" << p->adjvex;
                queue[rear++] = p->adjvex;
                visited[p->adjvex] = 1;
            }
            p = p->nextarc;
        }
    }
}
//�������ڽӱ����DFS
void BFS_Travel(ALGraph G)
{
    int index;
    for (index = 0; index < G.vexnum; ++index)
    {
        visited[index] = 0;
    }
    cout << "\n\n��ʼ���й����������\n\n";
    cout << "����ͼ���ڽ�����BFS���Ϊ��\n\n";
    for (index = 0; index < G.vexnum; index++)
    {
        if (!visited[index])
            BFS(G, index);
    }
}