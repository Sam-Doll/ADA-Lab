#include <iostream>
using namespace std;

int fact(int n){
    if(n==0 || n==1){
        return 1;
    }
    return n * fact(n-1);
}
int main(){
    int n, r;
    cout<< "enter n: ";
    cin>>n;
    cout<< "enter r: ";
    cin>>r;
    int ans = fact(n)/ fact(r);
    cout<< "nPr = "<< ans << endl;
    return 0; 
}