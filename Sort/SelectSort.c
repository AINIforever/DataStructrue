#define ElemType int

//简单选择排序
void SelectSort(ElemType A[], int n){
    for(int i=0;i<n-1;i++){
        int min = i;
        for(int j=i+1;j<n;j++){
            if(A[j]<A[min]) min = j;
        }
        if(min != i) swap(A[i],A[min]);
    }
}

//建立大根堆
void BuildMaxHeap(ElemType A[], int len){
    for(int i=len/2;i>0;i--){
        AdjustDown(A,i,len);
    }
}
void AdjustDown(ElemType A[], int k, int len){
    A[0] = A[k];
    for(int i=2*k;i<=len;i++){
        if(i<len && A[i]<A[i+1])
            i++;
        if(A[0]>A[i]) break;
        else{
            A[k] = A[i];
            k = i;
        }
    }
    A[k] = A[0];
}

//堆排序算法
void HeapSort(ElemType A[], int len){
    BuildMaxHeap(A,len);
    for(int i=len;i>1;i--){
        swap(A[i],A[1]);
        AdjustDown(A,1,i-1);
    }
}

//归并排序
ElemType *B = (ElemType *)malloc((n+1)*sizeof(ElemType));

void Merge(ElemType A[], int low, int high, int mid){
    for(int k = low; k <= high; k++)
        B[k] = A[k];
    int k;
    int i,j;
    for(i = low, j = mid+1, k = i; i <= mid && j <= high; k++){
        if(B[i]<=B[j]){
            A[k] = B[i];
            i++;
        }
        else{
            A[k] = B[j];
            j++;
        }
    }
    while(i<mid) A[k++] = B[i++];
    while(j<high) A[k++] = B[j++];
}

void MergeSort(ElemType A[], int low, int high){
    if(low<high){
        int mid = (low+high)/2;
        MergeSort(A,low,mid);
        MergeSort(A,mid+1,high);
        MergeSort(A,low,high);
    }
}
