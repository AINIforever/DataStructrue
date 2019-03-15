//求孩子兄弟法存储的森林中叶子节点个数
typedef struct node{
    ElemType data;
    struct node *fch,*nsib;
}*Tree;
int Leaves(Tree t){
    if(t == NULL)
        return 0;
    if(t->fch == NULL)
        return Leaves(t->nsib);
    else
        return Leaves(t->fch) + Leaves(t->nsib);
}

//求以孩子兄弟存储结构的树的高度
int Height(CSTree bt){
    int hc, hs;
    if(bt == NULL)
        return 0;
    return Height(bt->fch)+1 > Height(bt->nsib) ? Height(bt->fch)+1 : Height(bt->nsib)
}

//已知一棵树的层次序列和每个节点的度，构造此树的孩子兄弟链表
#define maxNodes 15
void createCSTree_Degree(CSTree &T, DataType e[], int degree[], int n){
    CSNode *pointer = new CSNode[maxNodes];
    int i,j,d,k = 0;
    for(i=0;i<n;i++){
        pointer[i] = new CSNode;
        pointer[i]->data = e[i];
        pointer[i]->lchild = pointer[i]->rsibling = NULL;
    }
    for(i=0;i<n;i++){
        d = degree[i];
        if(d){
            k++;
            pointer[i]->lchild = pointer[k];
            for(j=2;j<d;j++){
                k++;
                pointer[k-1]->rsibling = pointer[k];
            }
        }
    }
    T = pointer[0];
    delete [] pointer;
}