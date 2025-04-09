#include <iostream>
using namespace std;

int localPeak(int arr[], int n, int s, int l ){
    if (s>l) return -1;
    int mid = s + (l-s)/2;
    if((mid==0 || arr[mid]>= arr[mid-1]) &&
    (mid==n-1 || arr[mid]>= arr[mid+1])){
        return arr[mid];
    }

    if(mid>0 && arr[mid]<arr[mid-1]){
        return localPeak(arr,n,s,mid-1);
    }
    return localPeak(arr,n,mid+1,l);
}

int main(){
    int n;
    cout<<"Enter number of elements: ";
    cin>> n;
    int arr[n];
    cout<<"Enter elements in the array: ";
    for(int i=0;i<n;i++){
        cin>> arr[i];
    }
    int ans = localPeak(arr, n, 0, n-1);
    cout<<"Local peak is: "<< ans; 
    return 0;
}