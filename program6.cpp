#include<iostream>
using namespace std;

int peek(int grid[][2], int row, int col) {
    int leftcol = 0;
    int rightcol = col - 1;
    int midcol = leftcol + (rightcol - leftcol) / 2;
    int maxrow = 0;

    for (int i = 0; i < row; i++) {
        if (grid[i][midcol] > grid[maxrow][midcol]) {
            maxrow = i;
        }
    }

    bool leftbig = (midcol > 0) && (grid[maxrow][midcol - 1] > grid[maxrow][midcol]);
    bool rightbig = (midcol < col - 1) && (grid[maxrow][midcol + 1] > grid[maxrow][midcol]);

    if (!leftbig && !rightbig) {
        return grid[maxrow][midcol];
    }

    if (rightbig) {
        leftcol = midcol + 1;
    }
    else {
        rightcol = midcol - 1;
    }
    return peek(grid, row, col);
}

int main() {
    int arr[2][2] = { {9, 8}, {2, 6} };
    int row = 2, col = 2;
    int result = peek(arr, row, col);
    cout << "Peak element found : " << result << endl;
    return 0;
}
