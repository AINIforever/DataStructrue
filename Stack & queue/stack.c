//栈的定义
#define ElemType int
#define MaxSize 50
typedef struct{
    ElemType data[MaxSize];
    int top;
} SqStack;

//基本操作
void InitStack(SqStack &S){
    S.top = -1;
}

bool StackEmpty(SqStack SqStack S){
    if(S.top == -1){
        return true;
    }
    else{
        return false;
    }
}

bool Push(SqStack &S, ElemType x){
    if(S.top == MaxSize - 1)
        return false;
    S.data[++S.top] = x;
    return true;
}

bool Pop(SqStack &S, ElemType x){
    if(S.top == -1)
        return false;
    x = S.data[top--];
    return true;
}

bool GetTop(SqStack S, ElemType x){
    if(S.top == -1)
        return false;
    x = S.data[top];
    return true;
} 

//用I和O表示进栈和出栈，判断I、O组成的序列是否合法
int Judge(char A[]){
    int i=0;
    int j=0;
    int k=0;
    while(A[i] != '\0'){
        switch(A[i]){
            case 'I':
                j++;
                break;
            case 'O':
                k++;
                if(k>j){
                    printf("非法");
                    exit(0);
                }
        }
        i++;
    }
    if(j!=k){
        printf("非法");
        return false;
    }
    else{
        printf("合法");
        return true;
    }
}

//用栈判断链表元素是否对称
int dc(LinkList L, int n){
    int i;
    char s[n/2];
    p = L->next;
    for(i=0;i<n/2;i++){
        s[i] = p->data;
        p = p->next;
    }
    i--;
    if(n%2==1)
        p = p->next;
    while(p!=NULL && s[i] == p->data){
        i--;
        p = p->next;
    }
    if(i==-1)
        return 1;
    else 
        return 0; 
}

//定义共享栈并设计基本操作
#define maxsize 100
#define elemtp int
typedef struct {
    elemtp stack[maxsize];
    int top[2];
} stk;
stk s;

int push(int i, elemtp x){
    if(i<0 || i>1){
        printf("栈号不对");
        exit(0);
    }
    if(s.top[1]-s.top[0] == 1){
        printf("栈已满")；
        return 0;
    }
    switch(i){
        case 0:
            s.stack[++s.top[0]] = x;
            return 1;
            break;
        case 1:
            s.stack[--s.top[1]] = x;
            return 1;
    }
        
}

int pop(int i){
    if(i<0 || i>1){
        printf("栈号不对");
        exit(0);
    }
    switch(i){
        case 0:
            if(s.top[0] == -1){
                printf("栈空");
                exit(0);
            }
            else{
                return s.stack[s.top[0]--];
            }
        case 1:
            if(s.top[1] == -1){
                printf("栈空");
                exit(0);
            }
            else{
                return s.stack[s.top[1]+]+;
            }
    }
}

