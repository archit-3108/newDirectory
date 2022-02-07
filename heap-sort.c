#include<stdio.h>

void swap(int a[], int i, int largest){
    int temp = a[i];
    a[i] = a[largest];
    a[largest] = temp;
}

void heapify(int a[], int n, int i){
    int largest=i;
    int l = 2*i;
    int r = 2*i + 1;
    if(l<=n && a[l]>a[largest]){
        largest = l;
    }
    if(r<=n && a[r]>a[largest]){
        largest = r;
    }
    if(largest != i){
        swap(a,i,largest);
        heapify(a,n,largest);
    }
    
}

void build_max(int a[], int n){
    for(int i = n/2; i > 0; i--)
    {
        heapify(a,n,i);
    }
    
}

void heap_sort(int a[], int n){
    build_max(a,n);
    for (int i = n; i>1; i--)
    {
        swap(a,1,i);
        heapify(a,i-1,1);
    }
    
}

int main(){
    int n;
    printf("Enter size: ");
    scanf("%d",&n);
    int a[n+1];
    printf("\n\nEnter array: ");
    for (int i = 1; i <=n; i++)
    {
        scanf("%d",&a[i]);
    }

    heap_sort(a,n);

    printf("\n\nSoted array is: ");
    for(int i=1;i<=n;i++){
        printf("%d ",a[i]);
    }
     

    return 0;
}