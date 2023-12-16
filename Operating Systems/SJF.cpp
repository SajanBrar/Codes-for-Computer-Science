// Sajanjit Singh Brar
// 20124087
// Shortest Job First Scheduling

#include <iostream>
using namespace std;

int main()
{
    int n, time, indexOfMin, temp;
    time = 0;
    cout << "Sajanjit Singh Brar\n20124087\nOS Lab\nShortest Job First\n";
    cout << "Enter the number of processes: ";
    cin >> n;
    int Process[n];
    int BurstTime[n];
    int ArrivalTime[n];
    cout << "\nEnter the burst time for each process: \n";
    for (int i = 0; i < n; i++)
    {
        cout << "Burst time for process " << i + 1 << " : ";
        cin >> BurstTime[i];
        Process[i] = i + 1;
    }
    // cout << "\nEnter the arrival time for each process: \n";
    // for (int i = 0; i < n; i++)
    // {
    //     cout << "Arrival time for process " << i + 1 << " : ";
    //     cin >> ArrivalTime[i];
    // }
    for (int i = 0; i < n; i++)
    {
        indexOfMin = i;
        for (int j = i + 1; j < n; j++)
        {
            if (BurstTime[j] < BurstTime[indexOfMin])
            {
                indexOfMin = j;
            }
        }
        temp = BurstTime[i];
        BurstTime[i] = BurstTime[indexOfMin];
        BurstTime[indexOfMin] = temp;

        temp = Process[i];
        Process[i] = Process[indexOfMin];
        Process[indexOfMin] = temp;

        temp = ArrivalTime[i];
        ArrivalTime[i] = ArrivalTime[indexOfMin];
        ArrivalTime[indexOfMin] = temp;
    }
    cout << "\nProcess\tBurst Time\tTurnround Time\tWaiting Time\t";
    for (int i = 0; i < n; i++)
    {
        time = time + BurstTime[i];
        cout << "\n"
             << Process[i] << "\t" << BurstTime[i] << "\t\t" << time << "\t\t" << time - BurstTime[i] << "\t";
    }
    cout << "\nTotal time taken is " << time << " msec.";
    return 0;
}