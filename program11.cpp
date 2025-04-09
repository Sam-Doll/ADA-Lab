#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

void polynomial(vector<int>& poly, int x)
{
    int sum = 0;
    for(int i = 0; i < poly.size(); i++)
    {
        sum += poly[i] * pow(x, poly.size() - 1 - i);
    }
    cout << "Sum of polynomial is = " << sum << endl;
}

int main()
{
    vector<int> poly = {2, -6, 2, -1};
    int x;
    cout << "Enter the value of x: ";
    cin >> x;
    polynomial(poly, x);
    return 0;
}
