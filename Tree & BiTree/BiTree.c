#define ElemType int

typedef struct BiTNode{
    ElemType data;
    struct BiTNode *lchild, *rchild;
}BiTNode,
 *BiTree;

//在顺序存储的二叉树中，给定编号为i和j的两个结点，找出其最近公共祖先
ElemType Comm_Ancestor(SqTree T, int i, int j){
    if(T[i]!='#'&&T[j]!='#'){
        while(i!=j){
            if(i>j)
                i = i/2;
            else
                j = j/2;
        }
        return T[i];
    }
}

//二叉树的三种遍历
void PreOrder(BiTree T){
    if(T != NULL){
        visit(T);
        PreOrder(T->lchild);
        PreOrder(T->rchild);
    }
}

void InOrder(BiTree T){
    if(T != NULL){
        InOrder(T->lchild);
        visit(T);
        InOrder(T->rchild);
    }
}

void PostOrder(BiTree T){
    if(T != NULL){
        PostOrder(T->lchild);
        PostOrder(T->rchild);
        visit(T);
    }
}

//中序遍历的非递归算法
void InOrder2(BiTree T){
    InitStack(S);
    BiTree p = T;
    while(p||!IsEmpty(S)){
        if(p){
            Push(S,p);
            p = p->lchild;
        }
        else{
            Pop(S,p);
            visit(p);
            p = p->rchild;
        }
    }
}

//先序
void PreOrder2(BiTree T){
    InitStack(S);
    BiTree p = T;
    while (p || !IsEmpty(S))
    {
        if (p)
        {
            visit(p)
            Push(S, p);
            p = p->lchild;
        }
        else
        {
            Pop(S, p);//回溯至父亲节点
            p = p->rchild;
        }
    }
}

//后序
//非递归后序遍历
void PostOrder(BiTree T)
{
    BiTree p = T, q = NULL;//q作用，记录p上次访问的节点
    InitStack(S);
    Push(S, T);//根节点压栈
    while (!IsEmpty(S))//栈不空循环进行
    {
        if (p && p != q)
        {
            Push(S, p);
            p = p->lchild;//找最左节点
        }
        else
        {
            Pop(S, p);
            if (!IsEmpty(S))//判断栈非空，如果栈空代表根节点已经出栈
            {
                if (p->rchild && p->rchild != q)
                {
                    Push(S, p);//将节点重新压回栈
                    p = p->rchild;//进入右子树
                }
                else
                {
                    visit(p);
                    q = p;//防止节点多次重复进栈，陷入死循环
                }
            }
        }
    }
}

//层次遍历
void LevelOrder(BiTree T){
    InitQueue(Q);
    BiTree p;
    EnQueue(Q,T);
    while(!IsEmpty(Q)){
        DeQueue(Q,p);
        visit(p);
        if(p->lchild != NULL)
            EnQueue(Q,p->lchild);
        if(p->rchild != NULL)
            EnQueue(Q,p->rchild);
    }
}

//线索二叉树
typedef struct ThreadNode{
    ElemType data;
    struct ThreadNode *lchild,*rchild;
    int ltag,rtag;
}ThreadNode, *ThreadTree;
//中序线索化
void InThread(ThreadTree &p, ThreadTree, &pre){
    if(p != NULL){
        InThread(p->lchild,pre);
        if(p->lchild == NULL){
            p->lchild = pre;
            p->ltag = 1;
        }
        if(pre != NULL && pre->rchild == NULL){
            pre->lchild = p;
            pre->rtag = 1;
        }
        pre = p;
        InThread(p->rchild,pre);
    }
}

void CreateInThread(Thread T){
    ThreadTree pre = NULL;
    if(T != NULL){
        InThread(T,pre);
        pre->rchild = NULL;
        pre->rtag = 1;
    }
}

//设计二叉树从下到上，从右到左的算法
void InvertLevel(BiTree bt){
    Stack s;
    Queue q;
    if(bt != NULL){
        InitStack(s);
        InitQueue(q);
        EnQueue(q,bt);
        while(IsEmpty(q) == false){
            DeQueue(q,p);
            Push(s,p);
            if(p->lchild)
                EnQueue(q,p->lchild);
            if(p->rchild)
                EnQueue(q,p->rchild);
        }
        while(!IsEmpty(s)){
            Pop(s,p);
            visit(p);
        }
    }
}

//非递归算法求二叉树高度
int BtDepth(BiTree T){
    if(!T)
        return 0;
    int front = -1, rear = -1;
    int last = 0, level = 0;
    BiTree Q[MaxSize];
    Q[++rear] = T;
    BiTree p;
    while(front<rear){
        p = Q[++front];
        if(p->lchild)
            Q[++rear] = p->lchild;
        if(p->rchild)
            Q[++rear] = p->rchild;
        if(front == last){
            level++;
            last = rear;
        }
    }
    return level;
}

//递归求二叉树高度
int BtDepth2(BiTree T){
    if(T == NULL)
        return 0;
    int ldep = BtDepth2(T->lchild);
    int rdep = BtDepth2(T->rchild);
    return ldep > rdep ? ldep+1 : rdep+1;
}

//已知先序和中序序列，构造二叉树
BiTree PreInCreate(ElemType A[], ElemType B[], int l1, int h1, int l2, int h2){
    BiTNode *root = (BiTNode *)malloc (sizeof(BiTNode));
    root->data = A[l1];
    int i;
    for(i=l2;B[i]!= root->data;i++);
    int llen = i-l2;
    int rlen = h2-i;
    if(llen)
        root->lchild = PreInCreate(A,B,l1+1,l1+llen,l2,l2+llen-1);
    else
        root->lchild = NULL;
    if(rlen)
        root->rchild = PreInCreate(A,B,h1-rlen+1,h1,h2-rlen+1,h2);
    else
        root->rchild = NULL;
    return root;
}

//判断二叉树是否为完全二叉树
bool IsComplete(BiTree T){
    InitQueue(Q);
    if(!T)
        return 1;
    EnQueue(Q,T);
    while(!IsEmpty(Q)){
        DeQueue(Q,p);
        if(p){
            EnQueue(Q,p->lchild);
            EnQueue(Q,p->rchild);
        }
        else{
            while(!IsEmpty(Q)){
                DeQueue(Q,p);
                if(p)
                    return 0;
            }
        }
    }
}

//计算所有度为2的结点个数
int DsonNodes(BiTree b){
    if(b == NULL){
        return 0;
    }
    else if(b->lchild != NULL && b->rchild != NULL)
        return DsonNodes(b->lchild) + DsonNodes(b->rchild) + 1;
    else
        return DsonNodes(b->lchild) + DsonNodes(b->rchild);
}

//用递归实现交换左右子树
void swap(BiTree b){
    if(b){
        swap(b->lchild);
        swap(b->rchild);
        temp = b->lchild;
        b->lchild = b->rchild;
        b->rchild = temp;
    }
}

//查找二叉树先序遍历中第k个结点
int i = 1;
ElemType PreNode(BiTree b, int k){
    if(b == NULL)
        return '#';
    if(i == k)
        return b->data;
    i++;
    char ch = PreNode(b->lchild,k);
    if(ch!='#')
        return ch;
    ch = PreNode(b->rchild, k);
    return ch;
}

//删去以元素x为根的子树
void DeleteXTree(BiTree bt){
    if(bt){
        DeleteXTree(bt->lchild);
        DeleteXTree(bt->rchild);
        free(bt);
    }
}

void Search(BiTree bt, ElemType x){
    BiTree Q[];
    if(bt){
        if(bt->data == x){
            DeleteXTree(bt);
            exit(0);
        }
        InitQueue(Q);
        EnQueue(Q,bt);
        while(!IsEmpty(Q)){
            DeQueue(Q,p);
            if(p-lchild){
                if(p->lchild->data == x){
                    DeleteXTree(p->lchild);
                    p->lchild = NULL;
                }
                else
                    EnQueue(Q,p->lchild);
            }
            if(p->rchild){
                if(p->rchild->data == x){
                    DeleteXTree(p->rchild);
                    p->rchild = NULL;
                }
                else
                    EnQueue(Q,p->rchild);
            }
        }
    }
}

//找出x结点的所有祖先
typedef struct{
    BiTree t;
    int tag;
}stack;
void Search(BiTree bt, ElemType x){
    stack s[];
    int top = 0;
    while(bt!=NULL || top>0){
        while(bt != NULL && bt->data != x){
            s[++top].t = bt;
            s[top].tag = 0;
            bt = bt->lchild;
        }
        if(bt->data == x){
            printf("所有祖先为：");
            for(i=1;i<=top;i++)
                printf("%d",s[i].t->data);
            exit(0);
        }
        while(top!=0 && s[top].tag ==1)
            top--;
        if(top != 0){
            s[top].tag = 1;
            bt = s[top].t->rchild;
        }
    }
}

//找出p和q最近公共祖先
typedef struct{
    BiTree t;
    int tag;
}stack;
stack s[],s1[];
BiTree Ancestor(BiTree root, BiTNode *p, BiTNode *q){
    top = 0;
    bt = root;
    while(bt != NULL || top>0){
        while(bt != NULL && bt != p && bt != q){
            while(bt != NULL){
                s[++top].t = bt;
                s[top].tag = 0;
                bt = bt->lchild;
            }
        }
        while(top != 0 && s[top].tag == 1){
            if(s[top].t == p){
                for(i=1;i<=top;i++)
                    s1[i] = s[i];
                top1 = top;
            }
            if(s[top].t == q){
                for(j=top1;j>0;j--){
                    if(s1[j].t == s[i].t)
                        return s[i].t;
                }
            top--;
            }

        }
        if(top != 0){
            s[top].tag = 1;
            bt = s[top].t->rchild;
        }
        
    }
}

//用层次遍历求二叉树宽度(每一层宽度最大者)
typedef struct{
    BiTree data[MaxSize];
    int level[MaxSize];
    int front, rear;
}Qu;
int BTWidth(BiTree b){
    BiTree p;
    int k,max,i,n;
    Qu.front = Qu.rear = -1;
    Qu.rear++;
    Qu.data[Qu.rear] = b;
    Qu.level[Qu.rear] = 1;
    while(Qu.front<Qu.rear){
        Qu.front++;
        p = Qu.data[front];
        k = Qu.level[front];
        if(p->lchild != NULL){
            Qu.rear++;
            Qu.data[Qu.rear] = p->lchild;
            Qu.level[Qu.rear] = k+1;
        }
        if(p->rchild != NULL){
            Qu.rear++;
            Qu.data[QU.rear] = p->rchild;
            QU.level[Qu.rear] = k+1;
        }
    }
    max=0;
    i=0;
    k=1;
    while(i<Qu.rear){
        n=0;
        while(i<=Qu.rear && QU.level[i]==k){
            n++;
            i++;
        }
        k = Qu.level[i];
        if(n>max) 
            max = n;
    }
    return max;
}

//根据满二叉树的先序序列输出后序序列
void PreToPost(ElemType pre[], int l1, int h1, ElemType post[], int l2, int h2){
    int half;
    if(1>=l1){
        post[h2] = pre[l1];
        half = (h1-l1)/2;
        PreToPost(pre,l1+1,l1+half,post,l2,l2+half-1);
        PreToPost(pre,l1+half+1,h1,post,l2+half,h2-1);
    }
}

//将二叉树的叶结点从左到右连成单链表
LinkedList head, pre = NULL;
LinkedList InOrder(BiTree bt){
    if(bt){
        InOrder(bt->lchild);
        if(bt->lchild == NULL && bt->rchild == NULL){
            if(pre==NULL){
                head = bt;
                pre = bt;
            }
            else{
                pre->rchild = bt;
                pre = bt;
            }
        }
        InOrder(bt->rchild);
        pre->rchild = NULL;
    }
    return head;
}

//比较两颗树是否相似
int similar(BiTree T1, BiTree T2){
    int leftS, rightS;
    if(T1==NULL && T2==NULL)
        return 1;
    else if(T1 == NULL || T2 == NULL)
        return 0;
    else{
        leftS = similar(T1->lchild,T2->lchild);
        rightS = similar(T1->rchild,T2->rchild);
        return leftS && rightS;
    }
}

//在中序二叉树中，找指定结点在后序的前驱结点
BiThrTree InPostPre(BiThrTree t,BiThrTree p){
    BiThrTree q;
    if(q->rtag ==0){
        q = p->rchild;
    }
    else if(p->ltag == 0)
        q = p->lchild;
    else if(p->lchild==NULL)
        q = NULL;
    else{
        while(p->ltag == 1 && p->lchild != NULL)
            p = p->lchild;
        if(p->ltag ==0)
            q = p->lchild;
        else
            q = NULL;
    }
    return q;
}

//求二叉树的带权路径长度
typedef struct{
    int weight;
    struct BiTNode *lchid,*rchild;
}BiTNode, *BiTree;

int WPL(BiTree root){
    return wpl_PreOrder(root,0);
}
int wpl_PreOrder(BiTree root, int deep){
    static int wpl = 0;
    if(root->lchid==NULL && root->rchild==NULL)
        wpl += deep * root->weight;
    if(root->lchid)
        wpl_PreOrder(root->lchid, deep+1);
    if(root->rchild)
        wpl_PreOrder(root->rchild,deep+1);
    return wpl;
}

//将给定二叉树转换成等价中缀表达式，并用括号表示运算优先级
void BitreeToE(BTree *root){
    BitreeToExp(root,1);
}
void BitreeToExp(BiTree *root, int deep){
    if(root==NULL)
        return;
    else if(root->left==NULL && root->rchild==NULL)
        printf("%s",root->data);
    else{
        if(deep>1)
            printf("(");
        BitreeToExp(root->lchild, deep+1);
        printf("%s",root->data);
        BitreeToExp(root->rchild, deep+1);
        if(deep>1) printf(")");
    }
}

