
//nlogn
#include <bits/stdc++.h>
using namespace std;

void heapify(int arr[],int n,int i){
    int largest=i;
    int left=2*i;
    int right=2*i +1;
    if(left<=n && arr[largest]<arr[left]){
        largest=left;
    }
    if(right<=n && arr[largest]<arr[right]){
        largest=right;
    }
    
    if(largest!=i){
        swap(arr[largest],arr[i]);
        heapify(arr,n,largest);
    }
    
}

void heapsort(int arr[],int n){
    int size=n;
    while(size>1){
        swap(arr[1],arr[size]);
        size--;
        heapify(arr,size,1);
    }
}
void print(int arr[],int n){
    for(int i=1;i<=n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int arr[6]={-1,50,55,54,52,53};
    int n=5;
    for(int i=n/2;i>0;i--){
        heapify(arr,n,i);
    }
    
    cout<<"Heap before sorting: "<<endl;
    print(arr,n);
    cout<<"Heap after sorting: "<<endl;
    heapsort(arr,n);
    print(arr,n);
    
   
}


