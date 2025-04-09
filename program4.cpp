#include <iostream>
using namespace std;

int power(int n, int r){
    if (r==0)
    return 1;
    return n* power(n, r-1);
}

int main(){
    int n, r;
    cout<<"Enter n: ";
    cin>>n;
    cout<< "Enter r: ";
    cin>>r;
    int ans = power(n,r);
    cout<< ans;
    return 0;
}