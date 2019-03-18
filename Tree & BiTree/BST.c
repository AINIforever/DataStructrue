#define KeyType int
typedef struct BSTNode{
    KeyType data;
    struct BSTNode *lchild, *rchild;
}

//二叉排序树非递归查找
BSTNode *BST_Search(BiTree T, ElemType key, BSTNode *p){
    p = NULL;
    while(T != NULL && key != T->data){
        p = T;
        if(key < T->data)
            T = T->lchild;
        else
            T = T->rchild;
    }
    return T;
}

//插入
int BST_insert(BiTree &T, KeyType k){
    if(T==NULL){
        T = (BiTree)malloc(sizeof(BiTree));
        T->key = k;
        T->lchild = T->rchild = NULL;
        return 1;
    }
    else if(k == T->key)
        return 0;
    else if(k<T->key)
        return BST_insert(T->lchild,k);
    else
        return BST_insert(T->rchild,k);
}

//二叉排序树的构造
void Create_BST(BiTree &T,KeyType str[],int n){
    T=NULL;
    int i = 0;
    while(i<n){
        BST_insert(T,str[i]);
        i++;
    }
}

//判断一棵树是否为二叉排序树（中序遍历为递增）
KeyType predt = -32767;
int JudgeBST(BiTree bt){
    int b1,b2;
    if(bt == NULL)
        return 1;
    else{
        b1 = JudgeBST(bt->lchild);
        if(b1 == 0 || predt>=bt->data)
            return 0;
        predt = bt->data;
        b2 = JudgeBST(bt->rchild);
        return b2;
    }
}

//求指定结点在二叉排序树中的层次
int level(BiTree bt, BSTNode *p){
    int n = 0;
    BiTree t = bt;
    if(bt != NULL){
        n++;
        while(p->data != t->data){
            if(p->data <= t->data)
                t = t->lchild;
            else
                t = t->rchild;
            n++;
        }
    }
    return n;
}

//判断二叉树是否为平衡二叉树
void Judge_AVL(BiTree bt, int &balance, int &h){
    int bl = 0, br = 0, hl = 0, hr = 0;
    if(bt == NULL){
        h = 0;
        balance = 1;
    }
    else if(bt->lchild == NULL && bt->rchild == NULL){
        h = 1;
        balance = 1;
    }
    else{
        Judge_AVL(bt->lchild,bl,hl);
        Judge_AVL(bt->rchild,br,hr);
        h = (hl>hr?hl:hr) + 1;
        if(abs(hl-hr)<2)
            balance = bl && br;
        else
            balance = 0;
    }
}

//找出二叉排序树中最小和最大关键字
KeyType MinKey(BSTNode *bt){
    while(bt->lchild != NULL)
        bt = bt->lchild;
    return bt->data;
}

KeyType MaxKey(BSTNode *bt){
    while(bt->rchild != NULL)
        bt = bt->rchild;
    return bt->data;
}

//从大到小输出二叉排序树中关键字不小于key的关键字
void OutPut(BSTNode *bt, KeyType k){
    if(bt == NULL)
        return;
    if(bt->rchild != NULL)
        OutPut(bt->rchild, k);
    if(bt->data>=k)
        orintf("%d",bt->data);
    if(bt->lchild!= NULL)
        OutPut(bt->lchild,k);
}

//查找二叉排序树中第k小的数,时间复杂度为log（n）
BSTNode *Search_Small(BSTNode *t,int k){
    if(k<1 || k>t->count) return NULL;
    if(k->lchild == NULL){
        if(k == 1) return t;
        else return Search_Small(t->rchild,k-1);
    }
    else{
        if(t->lchild->count == k-1) return t;
        else if(t->lchild->count > k-1) return Search_Small(t->lchild,k);
        else return Search_Small(t->rchild,k - (t->lchild->count+1));
    }
}



