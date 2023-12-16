// Sajanjit Singh Brar
// 20124087
// IDAA Lab
// Matrix Multiplication

#include <iostream>
using namespace std;

int i = 0, j = 0, k = 0;

void MatrixMultiplication(int m1, int n1, int A[10][10], int m2, int n2, int B[10][10], int C[10][10])
{
    // static int i = 0, j = 0, k = 0;
    cout << "i: " << i << ", j: " << j << ", k: " << k << "\n";
    if (i >= m1)
    {
        return;
    }
    else if (i < m1)
    {
        if (j < n2)
        {
            if (k < n1)
            {
                C[i][j] = C[i][j] + (A[i][k] * B[k][j]);
                k++;
                MatrixMultiplication(m1, n1, A, m2, n2, B, C);
            }
            k = 0;
            j++;
            MatrixMultiplication(m1, n1, A, m2, n2, B, C);
        }
        j = 0;
        i++;
        MatrixMultiplication(m1, n1, A, m2, n2, B, C);
    }
}

int main()
{
    int m1, n1, m2, n2;
    int A[10][10], B[10][10], C[10][10];
    cout << "Enter number of rows for Matrix A: ";
    cin >> m1;
    cout << "Enter number of columns for Matrix A: ";
    cin >> n1;
    cout << "Enter number of rows for Matrix B: ";
    cin >> m2;
    cout << "Enter number of columns for Matrix B: ";
    cin >> n2;
    if (n1 != m2)
    {
        cout << "\nMatrix multiplication is not possible in this case.";
    }
    else
    {
        cout << "\nEnter elements of Matrix A:\n";
        for (int i = 0; i < m1; i++)
        {
            for (int j = 0; j < n1; j++)
            {
                cout << "Element [" << i << "][" << j << "]: ";
                cin >> A[i][j];
            }
        }
        cout << "\nEnter elements of Matrix B:\n";
        for (int i = 0; i < m1; i++)
        {
            for (int j = 0; j < n1; j++)
            {
                cout << "Element [" << i << "][" << j << "]: ";
                cin >> B[i][j];
            }
        }
    }
    for (int i = 0; i < m1; i++)
    {
        for (int j = 0; j < n1; j++)
        {
            C[i][j] = 0;
        }
    }
    cout << "\nMatrix Multiplication of A and B gives:\n";
    MatrixMultiplication(m1, n1, A, m2, n2, B, C);
    for (int i = 0; i < m1; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            cout << C[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}