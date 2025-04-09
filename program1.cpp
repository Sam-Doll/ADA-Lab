#include <iostream>
using namespace std;

int sum(int arr[], int n){
    if(n==0){
        return 0;
    }
    return arr[n-1] + sum(arr, n-1);
}

int main(){
    int n;
    cout << "Enter n: ";
    cin>>n;
    int arr[n];
    cout << "Enter numbers: "<< endl;
    for(int i=0; i<n; i++){
        cin>> arr[i];
    }
    int result = sum(arr, n);
    cout<< "Sum is = " << result <<endl;
    return 0;
}