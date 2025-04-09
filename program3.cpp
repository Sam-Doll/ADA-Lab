#include <iostream>
using namespace std;

void generateTF(bool com[], int n, int index) {
    if (index == n) {
        for (int i = 0; i < n; i++) {
            cout << com[i] << " "; 
        }
        cout << endl;
        return;
    }
    
    com[index] = false;
    generateTF(com, n, index + 1);

    com[index] = true;
    generateTF(com, n, index + 1);
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    
    bool com[n]; 
    generateTF(com, n, 0);
    
    return 0;
}

