//删除顺序表中最小元素
bool Del_Min(sqList &L, ElemType &value){
    if(L.length==0)
        return false;
    value = L.data[0];
    int pos = 0;
    for(int i=1;i<L.length,i++){
        if(L.data[i]<value){
            value = L.data[i];
            pos = i;
        }
    }
    L.data[pos] = L.data[L.length-1];
    L.length--;
    return true;
}

//将顺序表逆转
void Reverse(Sqlist &L){
    Elemtype temp;
    for(int i=0; i<L.length/2;i++){
        temp = L.data[i];
        L.data[i] = L.data[L.length-i-1];
        L.data[L.length-i-1] = temp;
    }
}

//删除所有元素值为x的元素
//解法一：用k记录不等于x的元素个数
void del_x_1(Sqlist &L, ElemType x){
    int k = 0;
    for(int i=0; i<L.length; i++){
        if(L.data[i] != x){
            k++;
            L.data[k] = L.data[i];
        }
    }
}
//解法二：用k记录等于x的元素个数
void del_x_2(Sqlist &L, ElemType x){
    int k = 0;
    for(int i=0; i<L.length; i++){
        if(L.data[i] == x)
            k++;
        else
            L.data[i-k] = L.data[i];
    }
    L.length = L.length - k;
}

//在有序表中删除在给定s、t之间的值
bool del_x_t2(Sqlist &L, ElemType s, ElemType t){
    int i,j;
    if(s>=t || L.length == 0)
        return false;
    for(i=0;i<L.length&&L.data[i]<s;i++);
    if(i = L.length)
        return false;
    for(j=i;j<L.length&&L.data[j]<=t;j++);
    for(;j<L.length;i++;j++){
        L.data[i] = L.data[j];
    }
    L.length = i;
    return true;
}

//在顺序表中删除s、t之间的值
bool del_s_t(Sqlist &L, ElemType s, ElemType t){
    int i,k = 0;
    if(L.length==0 || s >= t)
        return false;
    for(i=0;i<L.length;i++){
        if(L.data[i]>=s && L.data[i]<=t)
            k++;
        else
            L.data[i-k] = L.data[i];
    }
    L.length -= k;
    return true;
}

//有序表中删除重复元素
bool Delete_Same(Sqlist &L){
    if(L.length == 0)
        return false;
    int i,j;
    for(i=0,j=1;j<L.length;j++){
        if(L.data[i] != L.data[i])
            L.data[++i] = L.data[j];
    }
    L.length = i+1;
    return true;
}

//将两个有序表合并成一个有序表
bool Merge(Sqlist &A, Sqlist &B, Sqlist &C){
    if(A.length + B.length>C.maxSize)
        reutrn false;
    int i=0,j=0,k=0;
    while(i<A.length && j<B.length){
        if(A.data[i]<=B.data[j])
            C.data[k++] = A.data[i++];
        else
            C.data[k++] = B.data[j++];
    }
    while(i<A.length)
        C.data[k++] = A.data[i++];
    while(j<B.length)
        C.data[k++] = B.data[j++];

    C.length = k;
    return true;
}

//两个子线性表拼接成的线性表，互换两个子线性表的位置
//算法：将ab原地逆转后再分别逆转-b，-a
typedef int DataType;
void Reverse(DataType A[],int left,int right,int arraySize){
    if(left>=right || right>=arraySize)
        return;
    int mid = (left+right)/2;
    for(int i=0;i<mid;i++){
        DataType temp = A[i];
        A[left+i] = A[right-i];
        A[right-i] = temp;
    }
}
void exchange(DataType A[],int m,int n, int arraySize){
    Reverse(A,0,m+n-1,arraySize);
    Reverse(A,0,n-1,arraySize);
    Reverse(A,n,m+n-1,arraySize);
}

//用最少时间再递增顺序表中找出值为x的元素,并将其与后继元素交换，否则插入它使顺序表仍保持有序
void SearchExchangeInsert(Elemtype A[], Elemtype x){
    int low = 0, high = n-1,mid;
    while(low<high){
        mid = (low+high)/2;
        if(A[mid] == x) break;
        else if(A[mid]<x) low = mid+1;
        else high = mid - 1;
    }
    if(A[mid] == x && mid!=n-1){
        t = A[mid];
        A[mid] = A[mid]+1;
        A[mid+1] = t;
    }
    if(low>high){
        for(i=n-1;i>high;i--)
            A[i+1] = A[i];
        A[i+1] = x;
    }
}

//求两等长升序数列的中位数
int M_search(int A[], int B[], int n){
    int s1=0,d1=n-1,m1,s2=0,d2=n-1,m2;
    while(s1!=d1 || s2 != d2){
        m1 = (s1+d1)/2;
        m2 = (s2+d2)/2;
        if(A[m1] = B[m2])
            return A[m1];
        if(A[m1]<B[m2]){
            if((s1+d1)%2 == 0){
                s1 = m1;
                d2 = m2;
            }
            else{
                s1 = m1+1;
                d2 = m2;
            }
        }
        else{
            if((s2+d2)%2 == 0){
                s2 = m2;
                d1 = m1;
            }
            else{
                s2 = m2+1;
                d1 = m1;
            }
        }
    }
    return A[s1]<B[S2]?A[s1]:B[s2];
}

//数组中出现次数多于一半的为主元素，输出一个数组的主元素
int Majority(int A[],int n){
    int i,c,count=1;
    c = A[0];
    for(i=1;i<n;i++){
        if(A[i] == c)
            count++;
        else{
            if(count>0)
                count--;
            else{
                c = A[i];
                count=1;
            }
        }
    
    }
    if(count>0){
        for(i=count=0;i<n;i++){
            if(A[i] == c){
                count++;
            }
        }

    }
    if(count>n/2) return c;
    else return -1;
}

//求数组中未出现过的最小正整数
int FindMissMin(int A[],int n){
    int i,*B;
    B = (int *)malloc(sizeof(int) *n);
    memset(B,0,sizeof(int) *n);
    for(i=0;i<n;i++){
        if(A[i]>0 && A[i]<=n){
            B[A[i]-1] = 1;
        }
    }
    for(i=0;i<n;i++){
        if(B[i] == 0) break;
    }
    return i+1;

}