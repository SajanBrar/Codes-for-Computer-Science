#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x1, y1, x2, y2;
    cout << "Enter start pt: ";
    cin >> x1 >> y1;
    cout << "Enter end pt: ";
    cin >> x2 >> y2;
    float p1, p2, p3, p4, q1, q2, q3, q4;
    int dx = (x2 - x1);
    int dy = (y2 - y1);
    p1 = -dx;
    p2 = dx;
    p3 = -dy;
    p4 = dy;
    int xmin = x1;
    int xmax = x1 + dx;
    int ymin = y1;
    int ymax = y1 + dy;
    cout << "Enter xmax: ";
    cin >> xmax;
    cout << "Enter xmin: ";
    cin >> xmin;
    cout << "Enter ymax: ";
    cin >> ymax;
    cout << "Enter ymin: ";
    cin >> ymin;
    q1 = x1 - xmin;
    q2 = xmax - x1;
    q3 = y1 - ymin;
    q4 = ymax - y1;
    if (p1 == 0 && q1 < 0)
    {
        cout << "Line Eliminated";
        return 0;
    }
    if (p2 == 0 && q2 < 0)
    {
        cout << "Line Eliminated";
        return 0;
    }
    if (p3 == 0 && q3 < 0)
    {
        cout << "Line Eliminated";
        return 0;
    }
    if (p4 == 0 && q4 < 0)
    {
        cout << "Line Eliminated";
        return 0;
    }
    vector<float> r1;
    vector<float> r2;
    r1.push_back(0);
    r2.push_back(1);
    if (p1 < 0)
    {
        float rt = q1 / p1;
        r1.push_back(rt);
    }
    if (p2 < 0)
    {
        float rt = q2 / p2;
        r1.push_back(rt);
    }
    if (p3 < 0)
    {
        float rt = q3 / p3;
        r1.push_back(rt);
    }
    if (p4 < 0)
    {
        float rt = q4 / p4;
        r1.push_back(rt);
    }
    float u1 = *max_element(r1.begin(), r1.end());
    if (p1 > 0)
    {
        float rt = q1 / p1;
        r2.push_back(rt);
    }
    if (p2 > 0)
    {
        float rt = q2 / p2;
        r2.push_back(rt);
    }
    if (p3 > 0)
    {
        float rt = q3 / p3;
        r2.push_back(rt);
    }
    if (p4 > 0)
    {
        float rt = q4 / p4;
        r2.push_back(rt);
    }
    float u2 = *min_element(r2.begin(), r2.end());
    cout << "u1: " << u1 << ", u2: " << u2 << "\n";
    if (u1 > u2)
    {
        cout << "Line Eliminated";
        return 0;
    }
    else
    {
        cout << "End points of clipped line: "
             << "(" << x1 + dx * u1 << ", " << y1 + dy * u1 << ")"
             << " and "
             << "(" << x1 + dx * u2 << ", " << y1 + dy * u2 << ")";
    }
    return 0;
}