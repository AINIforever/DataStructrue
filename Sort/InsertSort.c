//直接插入排序
void InsertSort(ElemType A[], int n){
    int i,j;
    for(i=2;i<=n;i++){
        if(A[i].key < A[i-1].key){
            A[0] = A[i];
            for(j = i-1; A[j].key > A[0].key; --j)
                A[j+1] = A[j];
            A[j+1] = A[0];
        }
    }
}

//折半插入排序
void InsertSort2(ElemType A[], int n){
    int i,j,low,high,mid;
    for(i=2;i<=n;i++){
        A[0] = A[i];
        low = 1;
        high = n-1;
        while(low<high){
            mid = (low+high)/2;
            if(A[mid].key > A[0].key) high = mid-1;
            else low = mid+1;
        }
        for(j=i-1;j>=high;--j)
            A[j+1] = A[j];
        A[high+1] = A[0];
    }
}

//希尔排序
void ShellSort(ElemType A[], int n){
    for(int dk=n/2;dk>=1;dk=dk/2){
        for(int i=dk+1;i<=n;i++){
            if(A[i].key < A[i-dk].key){
                A[0] = A[i];
                int j;
                for(j=i-dk;j>0&&A[0].key<A[j].key;j-=dk)
                    A[j+dk] = A[j];
                A[j+dk] = A[0];
            }
        }
    }
}

