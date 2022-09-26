#pragma once
#define MaxInt 32767      //表示极大值，即∞
#define MVNum 100       //最大顶点数
#define Status int
#define ok 1
#define OtherInfo char
#define VerTexType char
#define MVNum 100          	//最大顶点数
int visited[MVNum];
typedef struct ArcNode {       //边结点 
    int adjvex;             //该边所指向的顶点的位置 
    struct ArcNode* nextarc;    	//指向下一条边的指针 
    OtherInfo info;              //和边相关的信息 
}ArcNode;

typedef struct VNode {
    VerTexType data;             	//顶点信息 
    ArcNode* firstarc;             	//指向第一条依附该顶点的边的指针 
}VNode, AdjList[MVNum];          	//AdjList表示邻接表类型

typedef struct {
    AdjList vertices;                 	//邻接表 
    int vexnum, arcnum;              	//图的当前顶点数和边数 
}ALGraph;
