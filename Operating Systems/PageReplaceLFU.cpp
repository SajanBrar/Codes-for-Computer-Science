// Sajanjit Singh Brar 
// 20124087
// OS Lab
// LFU Page Replacement

#include <iostream>
using namespace std;

int main()
{
    cout << "Sajanjit Singh Brar\n20124087\nOS Lab\n";
    int noofpages;
    cout << "Enter number of pages: ";
    cin >> noofpages;
    int pages[noofpages];
    for (int i = 0; i < noofpages; i++)
    {
        cout << "Entering Process " << i + 1 << "\n";
        pages[i] = i + 1;
    }
    int counter[noofpages];
    for (int i = 0; i < noofpages; i++)
    {
        counter[i] = 0;
    }
    for (int i = 0; i < noofpages; i++)
    {
        counter[i] = rand();
        cout << "Frequency value for process " << i + 1 << ": " << counter[i] << "\n";
    }
    int noofnewprocesses;
    cout << "Enter number of new processes: ";
    cin >> noofnewprocesses;

    int min, minflag;
    min = counter[0];
    minflag = 0;
    for (int i = 0; i < noofnewprocesses; i++)
    {
        min = counter[0];
        minflag = 0;
        for (int j = 0; j < noofpages; j++)
        {
            if (min > counter[j])
            {
                min = counter[j];
                minflag = j;
            }
        }
        counter[minflag] = 1000000;
        pages[minflag] = noofpages + i + 1;
        cout << "Entering Process " << noofpages + i + 1 << " in place of Process " << minflag + 1 << "\n";
    }
    return 0;
}
