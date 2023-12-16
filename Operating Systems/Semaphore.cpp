// Sajanjit Singh Brar
// 20124087
// Semaphore

#include <iostream>
#include <queue>
using namespace std;

class semaphore
{
    int mutex = 7;
    queue<int> BL, q;

public:
    void down(int p)
    {
        mutex--;
        if (mutex < 0)
        {
            BL.push(p);
            cout << "\nProcess " << p + 1 << " blocked";
        }
        else
        {
            q.push(p);
            cout << "\nProcess " << p + 1 << " running";
        }
        return;
    }
    void up()
    {
        mutex++;
        if (!q.empty())
        {
            cout << "\nProcess " << q.front() + 1 << " removed from critical section";
            q.pop();
        }
        if (mutex <= 0)
        {
            cout << "\nProcess " << BL.front() + 1 << " removed from blocked list";
            BL.pop();
        }
        return;
    }
    void blockP()
    {
        if (BL.empty())
            cout << "\nBlocked List is empty";
        else if (BL.size() > 1)
            cout << "\nP" << BL.front() + 1 << " to P" << BL.back() + 1 << " are blocked";
        else
            cout << "\nP" << BL.front() + 1 << " is blocked";
    }
    int qsize()
    {
        return q.size();
    }
};

int main()
{
    cout << "Sajanjit Singh Brar\n20124087\nOS Lab\nSemaphore Implementation";
    int n;
    cout << "\nEnter number of processes: ";
    cin >> n;
    semaphore S;
    for (int i = 0; i < n; i++)
    {
        S.down(i);
    }
    cout << "\nBlocked process:";
    S.blockP();
    int size = S.qsize();
    for (int i = 0; i < size; i++)
    {
        S.up();
    }
    cout << "\nBlocked process:";
    S.blockP();

    return 0;
}