
void tukeran_dong(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

int partisi(int arr[], int bawah, int atas){
    int tumpu = arr[atas];
    int i = bawah - 1;
    for(int j = bawah; j <= atas; j++){
        if(arr[j] < tumpu){
            i++;
            tukeran_dong(arr[i], arr[j]);
        }
    }
    tukeran_dong(arr[i + 1], arr[atas]);
    return i + 1;
}

void mengheap(int arr[], int n, int i){
    int atas = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if(l < n && arr[l] > arr[atas])
        atas = l;
    if(r < n && arr[r] > arr[atas])
        atas = r;
    if(atas != i){
        tukeran_dong(arr[i], arr[atas]);
        mengheap(arr, n, atas);
    }
}

void merge(int arr[], int bawah, int tengah, int atas){
    int bagSatu = tengah - bawah + 1;
    int bagDua = atas - tengah;
    int sliceSatu[bagSatu];
    int sliceDua[bagDua];
    for(int i = 0; i < bagSatu; i++)
        sliceSatu[i] = arr[bawah + i];
    for(int i = 0; i < bagDua; i++)
        sliceDua[i] = arr[tengah + 1 + i];
        
    int iSatu = 0;
    int iDua = 0;
    int iMerge = bawah;
    while(iSatu < bagSatu && iDua < bagDua){
        if(sliceSatu[iSatu] <= sliceDua[iDua]){
            arr[iMerge] = sliceSatu[iSatu];
            iSatu++;
        }else{
            arr[iMerge] = sliceDua[iDua];
            iDua++;
        }
        iMerge++;
    }
    while(iSatu < bagSatu){
        arr[iMerge] = sliceSatu[iSatu];
        iSatu++;
        iMerge++;
    }
    while(iDua < bagDua){
        arr[iMerge] = sliceDua[iDua];
        iDua++;
        iMerge++;
    }
}
