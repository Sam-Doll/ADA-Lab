#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

void add(vector<vector<int>> &matrixA, vector<vector<int>> &matrixB, vector<vector<int>> &matrixC, int newMSize)
{
    for(int i = 0; i < newMSize; i++)
    {
        for(int j = 0; j < newMSize; j++)
        {
            matrixC[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
}

void sub(vector<vector<int>> &matrixA, vector<vector<int>> &matrixB, vector<vector<int>> &matrixC, int newMSize)
{
    for(int i = 0; i < newMSize; i++)
    {
        for(int j = 0; j < newMSize; j++)
        {
            matrixC[i][j] = matrixA[i][j] - matrixB[i][j];
        }
    }
}

void printMatrix(vector<vector<int>> matrix, int size)
{
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
}

void strassenR(vector<vector<int>> &matrixA, vector<vector<int>> &matrixB, vector<vector<int>> &matrixC, int mSize)
{
    // base case: if matrix size is 1x1
    if(mSize == 1)
    {
        matrixC[0][0] = matrixA[0][0] * matrixB[0][0];
        return;
    }

    // divide matrix size by 2
    int newMSize = mSize / 2;
    vector<int> innerVector(newMSize, 0);

    // initialize matrices
    vector<vector<int>> matrixA11(newMSize, innerVector);
    vector<vector<int>> matrixA12(newMSize, innerVector);
    vector<vector<int>> matrixA21(newMSize, innerVector);
    vector<vector<int>> matrixA22(newMSize, innerVector);

    vector<vector<int>> matrixB11(newMSize, innerVector);
    vector<vector<int>> matrixB12(newMSize, innerVector);
    vector<vector<int>> matrixB21(newMSize, innerVector);
    vector<vector<int>> matrixB22(newMSize, innerVector);

    vector<vector<int>> matrixC11(newMSize, innerVector);
    vector<vector<int>> matrixC12(newMSize, innerVector);
    vector<vector<int>> matrixC21(newMSize, innerVector);
    vector<vector<int>> matrixC22(newMSize, innerVector);

    vector<vector<int>> s1(newMSize, innerVector);
    vector<vector<int>> s2(newMSize, innerVector);
    vector<vector<int>> s3(newMSize, innerVector);
    vector<vector<int>> s4(newMSize, innerVector);
    vector<vector<int>> s5(newMSize, innerVector);
    vector<vector<int>> s6(newMSize, innerVector);
    vector<vector<int>> s7(newMSize, innerVector);
    vector<vector<int>> s8(newMSize, innerVector);
    vector<vector<int>> s9(newMSize, innerVector);
    vector<vector<int>> s10(newMSize, innerVector);

    vector<vector<int>> p1(newMSize, innerVector);
    vector<vector<int>> p2(newMSize, innerVector);
    vector<vector<int>> p3(newMSize, innerVector);
    vector<vector<int>> p4(newMSize, innerVector);
    vector<vector<int>> p5(newMSize, innerVector);
    vector<vector<int>> p6(newMSize, innerVector);
    vector<vector<int>> p7(newMSize, innerVector);

    vector<vector<int>> tempMatrixA(newMSize, innerVector);
    vector<vector<int>> tempMatrixB(newMSize, innerVector);

    // divide matrices A and B into 4 sub-matrices
    for(int i = 0; i < newMSize; i++)
    {
        for(int j = 0; j < newMSize; j++)
        {
            matrixA11[i][j] = matrixA[i][j];
            matrixA12[i][j] = matrixA[i][j + newMSize];
            matrixA21[i][j] = matrixA[i + newMSize][j];
            matrixA22[i][j] = matrixA[i + newMSize][j + newMSize];

            matrixB11[i][j] = matrixB[i][j];
            matrixB12[i][j] = matrixB[i][j + newMSize];
            matrixB21[i][j] = matrixB[i + newMSize][j];
            matrixB22[i][j] = matrixB[i + newMSize][j + newMSize];
        }
    }

    // s1 = B12 - B22
    sub(matrixB12, matrixB22, s1, newMSize);

    // s2 = A11 + A12
    add(matrixA11, matrixA12, s2, newMSize);

    // s3 = A21 + A22
    add(matrixA21, matrixA22, s3, newMSize);

    // s4 = B21 - B11
    sub(matrixB21, matrixB11, s4, newMSize);

    // s5 = A11 + A22
    add(matrixA11, matrixA22, s5, newMSize);

    // s6 = B11 + B22
    add(matrixB11, matrixB22, s6, newMSize);

    // s7 = A12 - A22
    sub(matrixA12, matrixA22, s7, newMSize);

    // s8 = B21 + B22
    add(matrixB21, matrixB22, s8, newMSize);

    // s9 = A11 - A21
    sub(matrixA11, matrixA21, s9, newMSize);

    // s10 = B11 + B12
    add(matrixB11, matrixB12, s10, newMSize);

    // p1 = A11 * s1
    strassenR(matrixA11, s1, p1, newMSize);

    // p2 = s2 * B22
    strassenR(s2, matrixB22, p2, newMSize);

    // p3 = s3 * B11
    strassenR(s3, matrixB11, p3, newMSize);

    // p4 = A22 * s4
    strassenR(matrixA22, s4, p4, newMSize);

    // p5 = s5 * s6
    strassenR(s5, s6, p5, newMSize);

    // p6 = s7 * s8
    strassenR(s7, s8, p6, newMSize);

    // p7 = s9 * s10
    strassenR(s9, s10, p7, newMSize);

    // C11 = p5 + p4 - p2 + p6
    add(p5, p4, tempMatrixA, newMSize);
    add(tempMatrixA, p6, tempMatrixB, newMSize);
    sub(tempMatrixB, p2, matrixC11, newMSize);

    // C12 = p1 + p2
    add(p1, p2, matrixC12, newMSize);

    // C21 = p3 + p4
    add(p3, p4, matrixC21, newMSize);

    // C22 = p5 + p1 - p3 - p7
    add(p5, p1, tempMatrixA, newMSize);
    sub(tempMatrixA, p3, tempMatrixB, newMSize);
    sub(tempMatrixB, p7, matrixC22, newMSize);

    // combine results
    for(int i = 0; i < newMSize; i++)
    {
        for(int j = 0; j < newMSize; j++)
        {
            matrixC[i][j] = matrixC11[i][j];
            matrixC[i][j + newMSize] = matrixC12[i][j];
            matrixC[i + newMSize][j] = matrixC21[i][j];
            matrixC[i + newMSize][j + newMSize] = matrixC22[i][j];
        }
    }
}

void strassen(vector<vector<int>> &matrixA, vector<vector<int>> &matrixB, vector<vector<int>> &result, int mSize)
{
    // call recursive Strassen multiplication function
    strassenR(matrixA, matrixB, result, mSize);
}

int main()
{
    int mSize;
    cout << "Enter the size of the square matrix: ";
    cin >> mSize;

    // make matrixA
    vector<vector<int>> matrixA(mSize, vector<int>(mSize));
    cout << "Enter the elements of matrix A: ";
    for (int i = 0; i < mSize; i++)
    {
        for (int j = 0; j < mSize; j++)
        {
            cin >> matrixA[i][j];
        }
    }

    // make matrixB
    vector<vector<int>> matrixB(mSize, vector<int>(mSize));
    cout << "Enter the elements of matrix B: ";
    for (int i = 0; i < mSize; i++)
    {
        for (int j = 0; j < mSize; j++)
        {
            cin >> matrixB[i][j];
        }
    }

    // validate matrix size constraints
    if (mSize < 1 || mSize > 256)
    {
        cout << "ERROR: n must be between 1 and 256 (inclusive)" << endl;
        return 0;
    }
    else if (ceil(log2(mSize)) != floor(log2(mSize)))
    {
        cout << "ERROR: matrix size must be a power of 2" << endl;
        return 0;
    }

    // declare and initialize result matrix
    vector<vector<int>> result(mSize, vector<int>(mSize));

    // run Strassen matrix multiplication algorithm
    strassen(matrixA, matrixB, result, mSize);

    cout << "The resulting matrix after multiplication is: " << endl;
    printMatrix(result, mSize);

    return 0;
}
