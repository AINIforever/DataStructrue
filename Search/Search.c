//一般线性表的顺序查找
#define ElemType int
typedef struct{
    ElemType *elem;
    int TableLen;
}SSTable;
int Search_Seq(SSTable ST, ElemType key){
    ST.elem[0] = key;
    int i;
    for(i=ST.TableLen; ST.elem[i] != key; --i);
    return i;
}

//折半查找
int Binary_Search(SeqList L, ElemType key){
    int low = 0, high = L.TableLen - 1,mid;
    while(low<=high){
        mid = (low+high)/2;
        if(L.elem[mid] == key)
            return mid;
        else if(L.elem[mid] > key)
            high = mid-1;
        else
            low = mid+1;
    }
    return -1;
}

//折半查找的递归算法
int BinSearchRec(SSTable ST,ElemType key, int low,int high){
    if(low>high)
        return -1;
    int mid = (low+high)/2;
    if(key == ST.elem[mid])
        return mid;
    else if(key > ST.elem[mid])
        return BinSearchRec(ST,key,mid+1,high);
    else
        return BinSearchRec(ST,key,low,mid-1);
}

