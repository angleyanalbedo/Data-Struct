#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 100 

// ��ȱ�����Ƿ�
int flag[MAXSIZE];   // �ڽӾ��� 

// ������ȱ�����Ƿ� 
int Vist[MAXSIZE];   // �ڽӾ���

//******************** ���� *****************//
typedef struct Queue {

    int data[MAXSIZE]; // ���д�С 
    int head; // ��ͷ 
    int wei; // ��β 

}Queue;

// �ڽӾ��� 
typedef struct Matrix {

    int V_Data;  // ���������� 
    int E_Data;  // ����������

    int Node[MAXSIZE]; // ��Ŷ������ݣ�Ҳ���Ƕ���� 
    int Weight[MAXSIZE][MAXSIZE];  // ���Ȩ�أ�Ϊ�����������бߵı�Ƿ��� 

}MaTrix, * MATRIX;

// �ڽӾ������ݽṹ�� 
typedef struct Edge {

    int v1;  // ������ŵ�һ������ 
    int v2;  // ������ŵڶ�������
    int weight; // �����������֮��ı�Ƿ�����ΪȨ 
}*EDGE;


//******************** �ڽӾ���*******************//
// �ڽӾ��󡢶���ͱ߳�ʼ�� 
void Init_Matrix(MATRIX S, int Vertex)
{
    S->E_Data = 0;   // ��ʼ��Ϊ0���� 
    S->V_Data = Vertex;  // ��ʼ�������� 

    int i, j;
    for (i = 0; i < Vertex; i++)
    {
        for (j = 0; j < Vertex; j++)
        {
            S->Weight[i][j] = 0;
        }
    }
}

// ��ʼ����ߵ�Ȩ�أ���Ϊ��������֮��ߵı�Ƿ�
void InSerData(MATRIX S, EDGE E)
{
    // ������Ķ���v1��v2֮��ıߣ���Ȩ��Ϊ��ǣ��ھ����б�ʾ
    // ����������ͼ�����Ա�û�з�����Ҫ��������Σ�Ϊv1-v2��v2-v1�� 
    S->Weight[E->v1][E->v2] = E->weight;

    S->Weight[E->v2][E->v1] = E->weight;
}

//***************** ������ȱ����㷨���ڽӾ��� *****************//
void DFS_Begin(MATRIX P, int k, int V)
{
    int i;
    flag[k] = 1; //��ǵ�ǰ���㣬��ʾ�Ѿ�������

    printf("%d ", P->Node[k]); // �����ǰ���� 

    for (i = 0; i < V; i++)
    {
        if (!flag[i] && P->Weight[k][i] != 0)// �����ǰ������ڽ�����ڣ���û�б����� 
        {         // ������ݹ���� 

            DFS_Begin(P, i, V);  // �ݹ������ǰ������ڽ��� 
        }
    }
}

void Init_DFSMatrix(MATRIX P, int V)
{
    int i;
    // ��ʼ����Ƿ����飬ȫΪ0 
    for (i = 0; i < V; i++)
    {
        flag[i] = 0;
    }

    for (i = 0; i < V; i++) // ÿ�����㶼Ҫ����Ƿ������ 
    {
        if (!flag[i]) // �ų������Ѿ������Ķ���
            DFS_Begin(P, i, V);  // ��ʼ��ȱ��� 
    }
    putchar('\n');


}

//***************** ���� *************************************//
// ���г�ʼ�� 
void InitQueue(Queue* q)
{
    q->head = 0;  // ��ʼ����ͷ����β 
    q->wei = 0;
}

// �ж϶����Ƿ�Ϊ��
int EmptyQueue(Queue* q)
{
    if (q->head == q->wei)
        return 1;
    else {
        return 0;
    }
}

// ���
void PushQueue(Queue* q, int t)
{
    if ((q->wei + 1) % MAXSIZE == q->head) // ˵�������Ѿ�����
        return;
    else {
        q->data[q->wei] = t;
        q->wei = (q->wei + 1) % MAXSIZE; // ��β���� 
    }

}

// ����
void PopQueue(Queue* q, int* x)
{
    if (q->wei == q->head) // ������� 
        return;
    else {

        *x = q->data[q->head];
        q->head = (q->head + 1) % MAXSIZE; // ��ͷ����

    }


}

//***************** ������������㷨���ڽӾ��� ****************//
void Init_Bfs(MATRIX S, int V)
{
    int i, j;
    int k;

    Queue Q;

    for (i = 0; i < V; i++)
    {
        Vist[i] = 0; // ��ʼ����Ƿ� 
    }

    InitQueue(&Q); // ���г�ʼ�� 

    for (i = 0; i < V; i++)
    {
        if (!Vist[i]) // �ж����������Ϊ��׼�������ӵ��������� 
        {
            Vist[i] = 1; // ��Ǳ������������ 
            printf("%d ", S->Node[i]);

            PushQueue(&Q, i); // ��� 

            while (!EmptyQueue(&Q)) // �����л������ݣ�˵������������ӵ��������㻹û�б����� 
            {
                PopQueue(&Q, &i); // ���� 

                for (j = 0; j < V; j++)
                {
                    // ���������Ϊ��׼�������������ӵĶ��� 
                    if (!Vist[j] && S->Weight[i][j] != 0)
                    {
                        Vist[j] = 1; // ��֮���ӵĶ������ϱ�ǣ����ں��򶥵�������ͬ�ı��� 
                        printf("%d ", S->Node[j]);// �����֮�������ӵĶ��� 
                        PushQueue(&Q, j); // ����֮���ӵĶ�����λ����� 
                    }
                }
            }
        }
    }
}


// ��ʼ��������� 
int Init_Vertex()
{
    int Vertex;

    printf("�����붥�����: ");
    scanf("%d", &Vertex);
    return Vertex;
}

// ��ʼ���ߵ����� 
int Init_Edge()
{
    int edge;
    printf("������ߵ�����: ");
    scanf("%d", &edge);
    return edge;

}

// ��ʼ�������� 
void InSerEdge_Data(MATRIX S, int edge, int V)
{
    int i, j;

    if (edge > 0) // ��������0��ʱ��Ų������� 
    {
        printf("�����붥���Ȩ��(�ո�ָ�!)\n");
        for (i = 0; i < edge; i++)
        {
            EDGE E;    //�����ڴ棬���ܶ���v1,v2��Ȩ�أ���Ƿ��� 
            E = (EDGE)malloc(sizeof(struct Edge));

            scanf("%d %d %d", &(E->v1), &(E->v2), &(E->weight));

            if (E->v1 == E->v2)
            {
                printf("����ͼ�ڽӾ���Խ���Ϊ0,�������,��������\n");
                exit(-1);
            }

            InSerData(S, E);
        }
        printf("������Ҫ����Ķ��㣬���붥�����: \n");
        for (j = 0; j < V; j++)
        {
            scanf("%d", &(S->Node[j]));
        }


    }
    else {

        printf("����ı�������");
    }

}
// ��ӡ����ͼ�ڽӾ��� 
void Show_Matrix(MATRIX p, int Vertex)
{
    int i, j;
    for (i = 0; i < Vertex; i++)
    {
        for (j = 0; j < Vertex; j++)
        {
            printf("%4d", p->Weight[i][j]); // ��ӡ�ڽӾ��� 
        }
        putchar('\n'); // ���� 
    }
}

int main()
{

    int val;
    int Vertex;
    int edge;

    MATRIX p;  // �ڽӾ���ͷ�ڵ�ָ��

    // ��������ͼ�ڽӾ���      
    Vertex = Init_Vertex();
    edge = Init_Edge();

    p = (MATRIX)malloc(sizeof(MaTrix));  //�����ڴ�ռ� 

    p->V_Data = Vertex;  // ��¼������� 
    p->E_Data = edge;  // ��¼�ߵĸ��� 

    Init_Matrix(p, Vertex); // ��ʼ���ڽӾ��� 

    InSerEdge_Data(p, edge, Vertex); // �������� 

    // ��ӡ����ͼ���ڽӾ��� 
    printf("����ͼ�ڽӾ�������:");
    printf("\n----------------------------------\n\n");
    Show_Matrix(p, Vertex);
    printf("\n----------------------------------\n");

    // ������ȱ������ڽӾ��� 
    printf("��ȱ������ڽӾ�����Ϊ:\n");
    Init_DFSMatrix(p, Vertex);


    // ������ȱ������ڽӾ���
    printf("������ȱ������ڽӾ�����Ϊ: \n");
    Init_Bfs(p, Vertex);

    return 0;
}