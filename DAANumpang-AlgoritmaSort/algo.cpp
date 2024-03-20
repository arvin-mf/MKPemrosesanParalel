#include <iostream>
#include "help.cpp"

#define SIZE 15
using namespace std;

void bubble_s(int[]);
void selection_s(int[]);
void insertion_s(int[]);
void merge_s(int[], int, int);
void quick_s(int[], int, int);
void heap_s(int[]);
void radix_s(int[]);

int main(){
    int set_data[] = {10, 14, 7, 11, 15, 11, 9, 14, 12, 13, 8, 6, 12, 14, 5};
    for (int a : set_data)
        cout << a << "  ";
    cout << endl;

    merge_s(set_data, 0, SIZE - 1);
    // heap_s(set_data);
    
    for (int a : set_data)
        cout << a << "  ";
    cout << endl;

    return 0;
}


void bubble_s(int arr[]){
    for(int i = 0; i < SIZE - 1; i++){
        for(int j = 0; j < SIZE - i - 1; j++){
            if(arr[j + 1] < arr[j]) tukeran_dong(arr[j + 1], arr[j]);
        }
    }
}

void selection_s(int arr[]){
    int cekpoin;
    for(int i = 0; i < SIZE - 1; i++){
        cekpoin = i;
        for(int j = i + 1; j < SIZE; j++){
            if(arr[j] < arr[cekpoin]) cekpoin = j;
        }
        tukeran_dong(arr[cekpoin], arr[i]);
    }
}

void insertion_s(int arr[]){
    int keep;
    for(int i = 1; i < SIZE; i++){
        keep = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > keep){
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = keep;
    }
}

void merge_s(int arr[], int bawah, int atas){
    if(bawah >= atas) return;
    int tengah = bawah + (atas - bawah)/2;
    merge_s(arr, bawah, tengah);
    merge_s(arr, tengah + 1, atas);
    merge(arr, bawah, tengah, atas);
}

void quick_s(int arr[], int bawah, int atas){
    if(bawah < atas){
        int indeks = partisi(arr, bawah, atas);
        quick_s(arr, bawah, indeks - 1);
        quick_s(arr, indeks + 1, atas);
    }
}

void heap_s(int arr[]){
    for(int i = SIZE/2 - 1; i >= 0; i--)
        mengheap(arr, SIZE, i);
    for(int i = SIZE - 1; i >= 0; i--){
        tukeran_dong(arr[0], arr[i]);
        mengheap(arr, i, 0);
    }
}

void radix_s(int arr[]){

}