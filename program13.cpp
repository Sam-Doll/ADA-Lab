#include<iostream>
#include<stack>
using namespace std;

int partition(int arr[], int s, int e)
{
    int start = s;
    int end = e;
    int pivot = arr[s];

    while(start <= end)
    {
        while(arr[start] <= pivot)
        {
            start++;
        }
        while(arr[end] > pivot)
        {
            end--;
        }
        if(start < end)
        {
            swap(arr[start], arr[end]);
        }
    }
    swap(arr[s], arr[end]);
    return end; // return pivot's index
}

void quickSort(int arr[], int n)
{
    stack<int> st;
    int s = 0, e = n - 1;
    st.push(s);
    st.push(e);

    while(!st.empty())
    {
        int end = st.top();
        st.pop();
        int start = st.top();
        st.pop();

        int p = partition(arr, start, end);

        if(p - 1 > start) // if left list is greater, then push to stack
        {
            st.push(start);
            st.push(p - 1);
        }

        if(p + 1 < end) // if right list is greater, then push to stack
        {
            st.push(p + 1);
            st.push(end);
        }
    }
}

int main()
{
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, n);

    cout << "Sorted array: " << endl;
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
