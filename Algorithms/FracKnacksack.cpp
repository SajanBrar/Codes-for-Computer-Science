// Sajanjit Singh Brar
// 20124087
// IDAA Lab
// Fractional Knapsack

#include <bits/stdc++.h>
using namespace std;
bool compare(pair<int, int> a, pair<int, int> b)
{
    float r1 = (float)a.first / (float)a.second;
    float r2 = (float)b.first / (float)b.second;
    return r1 > r2;
}
int main()
{
    int cap, n;
    cout << "Enter the capacity of the Knapsack: ";
    cin >> cap;
    cout << "Enter the number of Items: ";
    cin >> n;

    vector<pair<int, int>> fkp(n);
    pair<int, int> p1;
    cout << "Enter Value and Weight: " << endl;

    for (int i = 0; i < n; i++)
        cin >> fkp[i].first >> fkp[i].second;

    sort(fkp.begin(), fkp.end(), compare);

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (fkp[i].second <= cap)
        {
            ans += fkp[i].first;
            cap -= fkp[i].second;
        }
        else
        {
            float tmp = (float)fkp[i].first / (float)fkp[i].second;
            ans += (tmp * cap);
            cap = 0;
            break;
        }
    }
    cout << "Maximum Value we can obtain: " << ans;

    return 0;
}