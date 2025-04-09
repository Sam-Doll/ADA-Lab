#include <iostream>
using namespace std;

bool isMagicSquare(int grid[][3], int n)
{
    if (n == 0)
        return false;

    int sum1 = 0, sum2 = 0;
    for (int i = 0; i < n; i++)
    {
        sum1 += grid[i][i];
        sum2 += grid[i][n - i - 1];
    }

    if (sum1 != sum2)
        return false;

    for (int i = 0; i < n; i++)
    {
        int rowSum = 0, colSum = 0;
        for (int j = 0; j < n; j++)
        {
            rowSum += grid[i][j];
            colSum += grid[j][i];
        }
        if (rowSum != sum1 || colSum != sum1)
            return false;
    }
    return true;
}

int main()
{
    int grid[3][3] = {
        {2, 7, 6},
        {9, 5, 1},
        {4, 3, 8}
    };

    int n = 3; // Size of the matrix
    if (isMagicSquare(grid, n))
        cout << "Magic Square" << endl;
    else
        cout << "Not a Magic Square" << endl;

    return 0;
}
