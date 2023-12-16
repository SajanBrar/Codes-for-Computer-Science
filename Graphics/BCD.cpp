// Sajanjit Singh Brar
// 20124087
// Bresenham Circle Drawing Algorithm
// End Sem Practical Exam

#include <bits/stdc++.h>
using namespace std;

void circleAlgo(int x, int y, int r)
{
    int x1 = 0;
    int xk = x1;
    int y1 = r;
    int yk = y1;
    int d0 = 3 - 2 * r;
    int dk = d0;
    vector<int> x_arr;
    vector<int> y_arr;
    while (xk < yk)
    {
        if (dk < 0)
        {
            xk = xk + 1;
            yk = yk;
            dk = dk + 4 * xk + 6;
        }
        else if (dk >= 0)
        {
            xk = xk + 1;
            yk = yk - 1;
            dk = dk + 4 * (xk - yk) + 10;
        }
        x_arr.push_back(xk);
        y_arr.push_back(yk);
        int n = x_arr.size();
        for (int j = 0; j < n; j++)
        {
            x_arr.push_back(y_arr[j]);
            y_arr.push_back(x_arr[j]);
        }
    }
    cout << "\nFirst Quadrant:\n";
    cout << "[" << x1 + x << ", " << y1 + y << "], ";
    for (int i = 0; i < x_arr.size(); i++)
    {
        cout << "[" << x + x_arr[i] << ", " << y + y_arr[i] << "], ";
    }
    cout << "\nSecond Quadrant:\n";
    cout << "[" << (-1) * x1 + x << ", " << y1 + y << "], ";
    for (int i = 0; i < x_arr.size(); i++)
    {
        cout << "[" << x + (-1) * x_arr[i] << ", " << y + y_arr[i] << "], ";
    }
    cout << "\nThird Quadrant:\n";
    cout << "[" << (-1) * x1 + x << ", " << (-1) * y1 + y << "], ";
    for (int i = 0; i < x_arr.size(); i++)
    {
        cout << "[" << x + (-1) * x_arr[i] << ", " << y + (-1) * y_arr[i] << "], ";
    }
    cout << "\nFourth Quadrant:\n";
    cout << "[" << x1 + x << ", " << (-1) * y1 + y << "], ";
    for (int i = 0; i < x_arr.size(); i++)
    {
        cout << "[" << x + x_arr[i] << ", " << y + (-1) * y_arr[i] << "], ";
    }
}

int main()
{
    int x, y, r;
    cout << "Enter the co-ordinates of the center and the radius: ";
    cin >> x >> y >> r;
    circleAlgo(x, y, r);
    return 0;
}