//队列定义
#define MaxSize 50
#define ElemType int
typedef struct {
    ElemType data[MaxSize];
    int front,rear;
} SqQueue;

//循环队列基本操作
void InitQueue(SqQueue &Q){
    Q.rear = Q. front = 0;
}

bool isEmpty(SqQueue Q){
    if(Q.rear == Q.front)
        return true;
    else
        return false;
}

bool EnQueue(SqQueue &Q, ElemType x){
    if((Q.rear+1)%MaxSize == Q.front) return false;
    Q.data[Q.rear] = x;
    Q.rear = (Q.rear + 1) % MaxSize;
    return true;
}

bool DeQueue(SqQueue &Q, ElemType &x){
    if(Q.rear == Q.front) return false;
    x = Q.data[Q.front];
    Q.front = (Q.front + 1)%MaxSize;
    return true;
}


//链栈
typedef struct{
    ElemType data;
    struct LinkNode *next;
} LinkNode;
typedef struct{
    LinkNode *front,*rear;
}LinkQueue;

void InitQueue(LinkQueue &Q){
    Q.front=Q.rear=(LinkNode*)malloc(sizeof(LinkNode));
    Q.front->next = NULL;
}

bool IsEmpty(LinkQueue Q){
    if(Q.front==Q.rear)
        return true;
    else
        return false;
}

void EnQueue(LinkQueue &Q, ElemType x){
    LinkNode *s = (LinkNode *)malloc(sizeof(LinkNode));
    s->data = x;
    s->next = NULL;
    Q.rear->next = x;
    Q.rear = s;
}

bool DeQueue(LinkQueue &Q, ElemType &x){
    if(Q.front==Q.rear)
        return false;
    LinkNode *p = Q.front->next;
    x = p->data;
    Q.front->next = p->next;
    if(Q.rear == p)
        Q.rear = Q.front;
    free(p);
    return true;
}

//使用tag的循环队列，设计出队进队算法
int EnQueue1(SqQueue &Q, ElemType x){
    if(Q.front == Q.rear && Q.tag == 1){
        return 0;
    }
    Q.data[Q.rear] = x;
    Q.rear = (Q.rear+1)%MaxSize;
    Q.tag = 1;
    return 1;
}

int DeQueue1(SqQueue &Q, ElemType &x){
    if(Q.front == Q.rear && Q.tag == 0){
        return 0;
    }
    x = Q.data[Q.front];
    Q.front = (Q.front + 1)%MaxSize;
    Q.tag = 0;
    return 1;
}

//用空栈S将队列Q中元素逆置
void Inverse(Stack S, Queue Q){
    while(!QueueEmpty(Q)){
        ElemType x = DeQueue(Q);
        Push(S,x);
    }
    while(!(StackEmpty(S))){
        Pop(S,x);
        EnQueue(Q,x);
    }
}

