//邻接矩阵法
#define MaxVertexNum 100
typedef char VertexType;
typedef int EdgeType;
typedef struct {
    VertexType Vex[MaxVertexNum];
    EdgeType Edge[MaxVertexNum][MaxVertexNum];
    int vexnum,arcnum;
}MGrapgh;


//邻接表法
#define MaxVertexNum 100
typedef struct ArcNode{
    int adjvex;
    struct ArcNode *next;
}ArcNode;
typedef struct VNode{
    VertexType data;
    ArcNode *first;
}VNode, AdjList[MaxVertexNum];
typedef struct{
    AdjList vertices;
    int vexnum,arcnum;
}ALGraph;

//十字链表法
//tailvex:弧尾顶点；headvex：弧头顶点；hlink：弧头相同的下一条弧；tlink：弧尾相同的下一条弧；
#define MaxVertexNum 100
typedef struct ArcNode{
    int tailvex,headvex;
    struct ArcNode *hlink,tlink;
}ArcNode;
typedef struct VNode{
    VertexType data;
    ArcNode *firstin, *firstout;
}VNode;
typedef struct{
    VNode xlist[MaxVertexNum];
    int vexnum,arcnum;
}GLGraph;

//邻接多重表
//ivex，jvex为该边依附的两个顶点，ilink为依附于ivex的下一条边，jlink为依附于jvex的下一条边
#define MaxVertexNum 100
typedef struct ArcNode{
    bool mark;
    int ivex,jvex;
    struct ArcNode *ilink,*jlink;
}ArcNode;
typedef struct VNode{
    VertexType data;
    ArcNode *firstEdge;
}VNode;
typedef struct{
    VNode adjmulist[MaxVertexNum];
    int vexnum,arcnum;
}AMLGraph;