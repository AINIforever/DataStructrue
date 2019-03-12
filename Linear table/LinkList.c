//单链表定义
typedef struct LNode{
    ElemType data;
    struct LNode *next;
}LNode, *LinkList;

//采用头插法建立单链表
LinkList List_HeadInsert(LinkList &L){
    LNode *s;
    int x;
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;
    scanf("%d", &x);
    while(x != 9999){
        s = (LNode *)malloc(sizeof(LNode));
        s->data = x;
        s->next = L->next;
        L->next = s;
        scanf("%d",&x);
    }
    return L;
}

//采用尾插法建立单链表
LinkList List_TailInsert(LinkList &L){
    int x;
    L = (LinkList)malloc(sizeof(LNode));
    LNode *s,*r = L;
    scanf("%d",&x);
    while(x != 9999){
        s = (LNode *)malloc(sizeof(LNode));
        s->data = x;
        r->next = s;
        r = s;
        scanf("%d",&x);
    }
    r->next = NULL;
    return L;
}

//按序号查找结点值
LNode GetElem(LinkList L,int i){
    int j = 1;
    LNode *p = L->next;
    if(i=0)
        return L;
    if(i<1)
        return NULL;
    while(p&&j<i){
        p = p->next;
        j++;
    }
    return p;
}

//按值查找结点
LNode *LocateElem(LinkList L, ElemType e){
    LNode *p = L->next;
    while(p->data != e && p != NULL){
        p = p->next;
    }
    return p;
}

//后插
void insertBehind(LinkList L, int i, LNode s){
    p = GetElem(L,i-1);
    s->next = p->next;
    p->next = s;
}

//前插
void insertFront(LinkList L, LNode s, LNode p){
    s->next = p->next;
    p->next = s;
    temp = s->data;
    s->data = p->data;
    p->data = temp;
}

//后删
void delBehind(LinkList L,int i){
    p = GetElem(L,i-1);
    q = p->next;
    p->next = q->next;
    free(q);
}

//前删
void delFront(LinkList L, LNode p){
    q = p->next;
    q->data = q->data;
    p->next = q->next;
    free(q);
}


//设计一个递归算法，删除不带头结点的单链表中x值元素
void Del_x_3(LinkList L,ElemType x){
    LNode *p;
    if(L==NULL)
        return;
    if(L->data == x){
        p=L;
        L = L->next;
        free(p);
        Del_x_3(L,x);
    }
    else
        Del_x_3(L->next,x);
}

//带头结点的单链表，删除所有x值得结点
void Del_x_1(LinkList &L,ElemType x){
    LNode *p = L->next, *pre = L, *q;
    while(p!=NULL){
        if(p->data == x){
            q = p;
            p = p->next;
            pre->next = p;
            free(q);
        }
        else{
            pre = p;
            p = p->next;
        }
    }

}

//删除带表头单链表中最小元素x
LinkList Del_Min(LinkList &L){
    LNode *pre=L, *p = pre->next;
    LNode *minPre=pre, *minP=p;
    while(p!=NULL){
        if(p->data<minP->data){
            minP = p;
            minPre = Pre;
        }
        Pre = p;
        p = p->next;
        
    }
    minPre->next = minP->next;
    free(minP);
    return L;

}

//逆转单链表
LinkList Reverse_1(LinkList L){
    LNode *p,*r;
    p = L->next;
    L->next = NULL;
    while(p != NULL){
        r = p->next;
        p->next = L->next;
        L->next = p;
        p = r;
    }
    return L;
}

//带头结点的单链表排序
void Sort(LinkList &L){
    LNode *p = L->next, *pre;
    LNode *r = p->next;
    p->next = NULL;
    p = r;
    while(p != NULL){
        r = p->next;
        pre = L;
        while(pre->next != NULL && pre->next->data < p->data){
            pre = pre->next;
        }
        p->next = pre->next;
        pre->next = p;
        p = r;
    }
}

//在带表头的无序链表中删除介于给定两值中间的元素
void RangeDelete(LinkList &L, int min, int max){
    LNode *p = L->next, *pre = L;
    while(p != NULL){
        if(p->data>=min && p->data<=max){
            pre->next = p->next;
            free(p);
            p = pre->next;
        }
        else{
            pre = p;
            p = p->next;
        }
    }
}

//找到两条链表的公共链
LinkList Search_1st_Commom(LinkList L1,LinkList L2){
    int len1 = Length(L1), len2 = Length(L2);
    LinkList longList,shortList;
    if(len1<len2){
        longList = L1->next;
        shortList = L2->next;
        dist = len1-len2;
    }
    else{
        longList = L2->next;
        shortList = L1->next;
        dist = len2-len1;
    }
    while(dist--)
        longList = longList-next;
    while(longList && shortList){
        if(longList == shortList)
            return longList;
        else{
            longList = longList->next;
            shortList = shortList->next;
        }
    }
    return NULL;
}

//带表头单链表，按递增输出，并释放结点空间
void Min_Delete(LinkList &head){
    while(head->next != NULL){
        pre = head;
        p = pre->next;
        while(pre->next != NULL){
            if(p->next->data < pre->next->data){
                pre = p;
            }
            p = p->next;
        }
        print(pre->next->data);
        u = pre->next;
        pre->next = u->next;
        free(u);
    }
    free(head);
}

//将一个链表按奇偶分为两个链表
LinkList Dis_creat_1(LinkList &A){
    int i =0;
    B = (LinkList *)malloc(sizeof(LNode));
    B->next = NULL;
    LNode *ra = A, *rb = B;
    p = A->next;
    A->next = NULL;
    while(p != NULL){
        i++;
        if(i%2 == 0){
            rb->next = p;
            rb = p;
        }
        else{
            ra->next = p;
            ra = p;
        }
        p = p->next;
    }
    ra->next = NULL;
    rb->next = NULL;
    return B;
}

//如上题，要求B链表逆转，生成时采用头插法
LinkList Dis_creat_2(LinkList &A){
    LinkList B = (LinkList)malloc(sizeof(LNode));
    B->next = NULL;
    LNode *ra = A; 
    LNode *p = A->next, *q;
    while(p != NULL){
        ra->next = p;
        ra = p;
        p = p->next;
        q = p->next;
        p->next = B->next;
        B->next = p;
        p = q;
    }
    ra->next = NULL;
    return B;
}

//在递增有序链表中删除重复元素
void Del_Same(LinkList &L){
    LNode *p = L->next, *q;
    while(p != NULL){
        q = p->next;
        if(p->data == p->next->data){
            p->next = q->next;
            free(q);
        }
        else
            p = p->next;
        
    }
}

//合并两个有序单链表
void MergeList(LinkList &La, LinkList &Lb){
    LNode *r,*pa = La->next, *pa = Lb->next;
    La->next = NULL;
    while(pa && pb){
        if(pa->data < pb->data){
            r = pa->next;
            pa->next = La->next;
            La->next = pa;

            pa =r;
        }
        else{
            r = pb->next;
            pb->next = La->next;
            La->next = pb;

            pb = r;
        }
    }
    if(pa)
        pb = pa;
    while(pb){
        r = pb->next;
        pb->next = La->next;
        La->next = pb;
        pb = r;
    }
    free(Lb);
}

//A,B递增有序，从A,B的公共元素中产生新链表C
void Get_Common(LinkList A, LinkList B){
    LNode *p = A->next, *q = B->next, *r, *s;
    LinkList C = (LinkList)malloc(sizeof(LNode));
    r = C;
    while(p && q){
        if(p->data<q->data){
            p = p->next;
        }else if(p->data>q->data){
            q = q->next;
        }else{
            s = (LNode *)malloc(sizeof(LNode));
            s->data = p->data;
            r->next = s;
            r = s;
            p = p->next;
            q = q->next;
        }
    }
    r->next = NULL;
}

//A,B递增排列，求交集放入A中
LinkList Union(LinkList &la, LinkList &lb){
    pa = la->next;
    pb = lb->next;
    pc = la;
    while(pa&&pb){
        if(pa->data == pb->data){
            pc->next = pa;
            pc = pa;
            pa = pa->next;
            u = pb;
            pb = pb->next;
            free(u);
        }
        else if(pa->data<pb->data){
            u=pa;
            pa = pa->next;
            free(u);
        }
        else{
            u = pb;
            pb = pb->next;
            free(u);
        }
    }
    while(pa){
        u = pa;
        pa = pa->next;
        free(u);
    }
    while(pb){
        u = pb;
        pb = pb->next;
        free(u);
    }
    pc->next = NULL;
    free(lb);
    return la;
}

//已知两个整数序列A,B，判断B是否为A的子序列
int Pattern(LinkList A, LinkList B){
    LNode *p = A;
    LNode *pre = p;
    LNode *q = B;
    while(p&&q){
        if(p->data == q->data){
            p = p->next;
            q = q->next;
        }
        else{
            pre = pre->next;
            p = pre;
            q = B;
        }
    if(q==NULL)
        return 1;
    else
        return 0;
    }
}

//判断一个带头结点的循环双链表是否对称
int Symmetry(DLinkList L){
    DNode *p = L->next, *q = L->prior;
    while(p!=q && p->next!=q){
        if(p->data == q->data){
            p = p->next;
            q = q->prior;
        }
        else{
            return 0;
        }

    }
    return 1;
}

//拼接两个循环链表，使得拼接后仍为循环链表
LinkList Link(LinkList &h1, LinkList &h2){
    LNode *p, *q;
    p = h1;
    q = h2;
    while(p->next != h1){
        p = p->next;
    }
    while(q->next != h2){
        q = q->next;
    }
    p->next = h2;
    q->next = h1;
    return h1;
}

//反复输出带头结点循环单链表最小值并删除
void Del_All(LinkList &L){
    LNode *p,*pre,*minP,*minPre;
    while(L->next!= L){
        p = L->next;
        pre = L;
        minP = p;
        minPre = pre;
        while(p!=L){
            if(p->data < minP->data){
                minP = p;
                minPre = pre;
            }
            pre = p;
            p = p->next;
        }
        printf("%d",minP->data);
        minPre->next = minP->next;
        free(minP);
    }
    free(L);
}

//将非循环带表头的双链表按访问频度排序，同频度下按最近优先排序
DLinkList Locate(DLinkList &L, ElemType x){
    DNode *p = L->next, *q;
    while(p&&p->data !=x)
        p = p->next;
    if(!p){
        printf("不存在");
        exit(0);
    }
    else{
        p->freq++;
        p->next->pred = p->pred;
        p->pred->next = p->next;
        q=p->pred;
        while(q!=L && q->freq<=p->freq)
            q = q->pred;
        p->next = q->next;
        p->pred = q;
        q->next->pred = p;
        q->next = p;
    }
    return p;
}

//输出带表头结点的单链表的倒数第k个结点
typedef int ElemType;
typedef struct LNode{
    ElemType data;
    struct LNode *link;
}LNode, *LinkList;
int search_k(LinkList list, int k){
    LNode *p = list->link, *q = list->link;
    int count = 0;
    while(p!= NULL){
        if(count<k) count++;
        else q = q->link;
        p = p->link;
    }
    if(count<k)
        reutrn 0;
    else{
        printf("%d",q->data);
        return 1;
    }
}

//对于单链表中绝对值相等的结点，只保存一次，其他的释放
void func(PNode h, int n){
    PNode p = h,r;
    int *q,m;
    q = (int *)malloc(sizeof(int) *(n+1));
    for(int i=0;i<n+1;i++){
        *(q+i) = 0;
    }
    while(p->link != NULL){
        m = p->link->data > 0 ? p->link->data : 1 * -p->link->data;
        if(*(q+m) == 0){
            *(q+m) = 1;
            p = p->link;
        }
        else{
            r = p->link;
            p->link = r->link;
            free(r);
        }
    }
    free(q);
}