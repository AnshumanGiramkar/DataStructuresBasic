#include<stdio.h>
#include<stdlib.h>
void swap(int *x,int *y){
    int temp=*x;
    *x=*y;
    *y=temp;
}
int partition(int array[], int low, int high){
    int pivot_value=array[high];
    int i=low;
    for(int j=low; j<=high; j++){
        if(array[j]<pivot_value){
            swap(&array[i],&array[j]);
            i++;
        }
    }
    swap(&array[i],&array[high]);
    return i;
}

void quicksort(int array[], int low, int high){
    if(low<high){
        int p=partition(array,low,high);
        quicksort(array,low,p-1);
        quicksort(array,p+1,high);
    }
}

int main(){
    int a[]={11,35,2,24,35,69,1,17,4,901,7};
    int N=(sizeof(a)/sizeof(a[0]));

    quicksort(a,0,N-1);
    for(int i=0;i<N;i++){
        printf("%d,",a[i]);
    }
    return 0;
}