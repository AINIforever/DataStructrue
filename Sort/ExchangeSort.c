//冒泡排序
void BubbleSort(ElemType A[], int n){
    for(int i=0; i<n-1; i++){
        bool flag = false;
        for(int j=n-1;j>i;j--){
            if(A[j-1].key > A[j].key){
                swap(A[j-1],A[j]);
                flag = true;
            }
            if(flag == false)
                return ;
        }
    }
}

//快速排序
void QuickSort(ElemType A[], int low, int high){
    if(low < high){
        int pivotpos = Patition(A,low,high);
        QuickSort(A,low,pivotpos-1);
        QuickSort(A,pivotpos+1,high);
    }
}
int Patition(ElemType A[], int low, int high){
    ElemType pivot = A[low];
    while(low<high){
        while(low<high && A[high]>=pivot) --high;
        A[low] = A[high];
        while(low<high && A[low]<=pivot) ++low;
        A[high] = A[low];
    }
    A[low] = pivot;
    return low;
}

//双向冒泡，正反两个方向交替进行
void BubbleSort2(ElemType A[], int n){
    int low = 0;
    int high = n-1;
    bool flag = true;
    while(low<high && flag){
        flag = false;
        for(int i=low; i<high; i++){
            if(A[i]>A[i+1]){
                swap(A[i],A[i+1]);
                flag = true;
            }
        }
        high--;
        for(int i=high; i>low; i--){
            if(A[i]<A[i-1]){
                swap(A[i],A[i-1]);
                flag = true;
            }
        }
        low++;
    }
}


//基于快排思想将奇数放前，偶数放后
void move(ElemType A[], int n){
    int i=0, j=n-1;
    while(i<j){
        while(i<j && A[i]%2!=0) i++;
        while(i<j && A[j]%2==0) j++;
        if(i<j){
            swap(A[i],A[j]);
            i++;
            j--;
        }
    }
}

//找出数组中第k小的元素
int kth_elem(int A[], int low, int high, int k){
    int low_temp = low;
    int high_temp = high;
    while(low<high){
        while(low<high && A[high]>=pivot)
            high--;
        A[low] = A[high];
        while(low<high && A[low]<=pivot)
            low++;
        A[high] = A[low];
    }
    A[low] = pivot;
    if(low==k)
        return A[low];
    else if(low>k)
        return kth_elem(A,low_temp,low-1,k);
    else
        return kth_elem(A,low+1,high_temp,k-low);
}

//找出一半最小的和一半最大的元素
inr setPartition(int A[], int n){
    int pivotkey, low=0,low0=0,high=n-1,high0=n-1,flag=1,k=n/2,i;
    int s1=0,s2=0;
    while(flag){
        pivotkey = A[low];
        while(low<high){
            while(low<high && A[high]>=pivotkey) --high;
            if(low!=high) A[low] = A[high];
            while(low<high && A[low]<=pivotkey) ++low;
            if(low!=high) A[high] = A[low];
            A[low] = pivotkey;
            if(low==k-1)
                flag = 0;
            else{
                if(low<k-1){
                    low0 = ++low;
                    high = high0;
                }
                else{
                    high0 = --high;
                    low = low0;
                }
                   
            }
        }

    }
    for(i=0;i<k;i++) s1 += A[i];
    for(i=k;i<n;i++) s2 += A[i];
    return s1-s2;
}