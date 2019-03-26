//广度优先搜索
bool visited[MAX_VERTEX_NUM];
void BFSTraverse(Graph G){
    for(int i=0;i<G.vexnum;i++)
        visited[i] = FALSE;
    InitQueue(Q);
    for(int i=0;i<G.vexnum;i++){
        if(!visited[i])
            BFS(G,i);
    }
}
void BFS(Graph G, int v){
    visit(v);
    visited[v] = TRUE;
    Enqueue(Q,v);
    while(!isEmpty(Q)){
        Dequeue(Q,v);
        for(w = FirstNeighbor(G,v); w >= 0; w = NextNeighbor(G,v,w)){
            if(!visited[w]){
                visit(w);
                visited[w] = TRUE;
                Enqueue(Q,w);
            }
        }
    }
}

//BFS求解单源最短路径
#define INFINITY 99999
void BFS_MIN_Distance(Grapgh G, int u){
    for(int i=00;i<G.vexnum;i++)
        d[i] = INFINITY;
    visited[u] = TRUE;
    d[u] = 0;
    Enqueue(Q,u);
    while(!isEmpty(Q)){
        Dequeue(Q,u);
        for(w = FirstNeighbor(G,u); w>=0; w = NextNeighbor(G,u,w)){
            if(!visited(w)){
                visit(w);
                visited[w] = TRUE;
                d[w] = d[u] + 1;
                Enqueue(Q,w);
            }
        }
    }
}

//深度优先搜索
bool visited[MAX_VERTEX_NUM];
void DFSTraverse(Grapgh G){
    for(v=0; v<G.vexnum;v++)
        visited[v] = FALSE;
    for(v=0;v<G.vexnum;v++){
        if(!visited[v])
            DFS(G,v);
    }
}
void DFS(Graph G, int v){
    visit(v);
    visited[v] = TRUE;
    for(w=FirstNeighbor(G,v); w>=0; w=NextNeighbor(G,v,w)){
        if(!visited[w])
            DFS(G,w);
    }
}

//判断无向图是否为一棵树
bool isTree(Graph& G){
    ofr(int i=1;i<=G.numi++)
        visited[i] = FALSE;
    int vnum = 0, Enum = 0;
    DFS(G,1,vnum,Enum,visited);
    if(vnum == G.vexnum && Enum == 2*(G.vexnum-1))
        return TRUE;
    else return FALSE;
}
void DFS(Graph& G,int v,int& vnum,int& Enum,int visited[]){
    visited[v] = TRUE;
    vnum++;
    int w = FirstNeighbor(G,v);
    while(w != -1){
        Enum++;
        if(!visited[w])
            DFS(G,w,vnum,Enum,visited);
        w = NextNeighbor(G,v,w);
    }
}

//深度优先搜索的非递归实现
void DFS_Non_RC(AGraph& G, int v){
    int w;
    InitStack(S);
    for(int i=0;i<G.vexnum;i++)
        visited[i] = FALSE;
    Push(S,v);
    visited[v] = TRUE;
    while(!isEmpty(S)){
        k = Pop(S);
        visit(k);
        for(w=FirstNeighbor(G,k);w>=0;w=NextNeighbor(G,k,w)){
            if(!visited[w]){
                Push(S,w);
                visited[w] = TRUE;
            }
        }
    }
}

//判断以邻接表存储的图中是否有vi到vj的路径
//广度优先：
int visited[MAXSIZE] = {0};
int Exist_Path_BFS(ALGraph G,int i,int j){
    InitQueue(Q);
    Enqueue(Q,i);
    while(!isEmpty){
        Dequeue(Q,u);
        visited[u] = 1;
        for(w = FirstNeighbor(G,u); w>=0; w = NextNeighbor(G,u,w)){
            k = w.adjvex;
            if(k == j)
                return 1;
            if(!visited[k])
                Enqueue(Q,k);
        }
    }
    return 0;
}

//深度优先
int Exist_Path_DFS(ALGraph G, int i; int j){
    int p;
    if(i == j)
        return 1;
    else{
        visited[i] = 1;
        for(p = FirstNeighbor(G,i);i>=0;i=NextNeighbor(G,i,p)){
            k = p.adjvex;
            if(!visited[p] && Exist_Path_DFS(G,p,j))
                return 1;
        }
    }
    return 0;
}

//输出从vi到vj的简单路径
void FindPath(AGraph *G, int u, int v, int path[], int d){
    int w,i;
    ArcNode *p;
    d++;
    path[d] = u;
    visited[u] = 1;
    if(u == v)
        print(path[]);
    p = G->adjlist[u].firstArc;
    while(p!=NULL){
        w = p->adjvex;
        if(!visited[w])
            FindPath(G,w,v,path,d);
        p = p->nextarc;
    }
    visited[u] = 0;
}