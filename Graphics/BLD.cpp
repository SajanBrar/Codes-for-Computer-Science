// Sajanjit Singh Brar
// 20124087
// Bresenham Line Drawing Algorithm
// End Sem Practical Exam

#include <bits/stdc++.h>
using namespace std;

void line(int x1, int y1, int x2, int y2)
{
    int dx = (x2 - x1);
    int dy = (y2 - y1);
    int d = 2 * dy - dx;
    int length = dx > dy ? dx : dy;
    float m = dy / dx;
    int x = x1, y = y1;
    if (m <= 1)
    {
        int i = 1;
        while (i <= length)
        {
            if (d <= 0)
            {
                cout << x << " " << y << endl;
                d = d + 2 * dy;
                x = x + 1;
                y = y;
            }
            else if (d > 0)
            {
                cout << x << " " << y << endl;
                d = d + 2 * (dy - dx);
                x = x + 1;
                y = y + 1;
            }
            i++;
        }
        cout << x2 << " " << y2 << endl;
    }
    else if (m > 1)
    {
        d = 2 * dx - dy;
        int i = 1;
        while (i <= length)
        {
            if (d <= 0)
            {
                cout << x << " " << y << endl;
                d = d + 2 * dx;
                x = x;
                y = y + 1;
            }
            else if (d > 0)
            {
                cout << x << " " << y << endl;
                d = d + 2 * (dx - dy);
                x = x + 1;
                y = y + 1;
            }
            i++;
        }
        cout << x2 << " " << y2 << endl;
    }
}

int main()
{
    int x1, y1, x2, y2;
    cout << "Enter Coordinate 1: ";
    cin >> x1 >> y1;
    cout << "Enter Coordinate 2: ";
    cin >> x2 >> y2;
    cout << "Selected Coordinates: " << endl;
    line(x1, y1, x2, y2);
    return 0;
}