#pragma once
#define MaxInt 32767      //��ʾ����ֵ������
#define MVNum 100       //��󶥵���
#define Status int
#define ok 1
#define OtherInfo char
#define VerTexType char
#define MVNum 100          	//��󶥵���
int visited[MVNum];
typedef struct ArcNode {       //�߽�� 
    int adjvex;             //�ñ���ָ��Ķ����λ�� 
    struct ArcNode* nextarc;    	//ָ����һ���ߵ�ָ�� 
    OtherInfo info;              //�ͱ���ص���Ϣ 
}ArcNode;

typedef struct VNode {
    VerTexType data;             	//������Ϣ 
    ArcNode* firstarc;             	//ָ���һ�������ö���ıߵ�ָ�� 
}VNode, AdjList[MVNum];          	//AdjList��ʾ�ڽӱ�����

typedef struct {
    AdjList vertices;                 	//�ڽӱ� 
    int vexnum, arcnum;              	//ͼ�ĵ�ǰ�������ͱ��� 
}ALGraph;
