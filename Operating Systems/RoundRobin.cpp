// Sajanjit Singh Brar 
// 20124087
// Round Robin Scheduling

#include <iostream>
using namespace std;

int main()
{
    int n, m, time, Ttime, counter;
    time = 0;
    Ttime = 0;
    counter = 0;
    cout << "Sajanjit Singh Brar\n20124087\nOS Lab\nRound Robin\n";
    cout << "Enter the number of processes: ";
    cin >> n;
    int BurstTime[n];
    int ArrivalTime[n];
    cout << "\nEnter the burst time for each process: \n";
    for (int i = 0; i < n; i++)
    {
        cout << "Burst time for process " << i + 1 << " : ";
        cin >> BurstTime[i];
    }
    cout << "\nEnter the arrival time for each process: \n";
    for (int i = 0; i < n; i++)
    {
        cout << "Arrival time for process " << i + 1 << " : ";
        cin >> ArrivalTime[i];
    }
    cout << "\nEnter time quantum size: ";
    cin >> m;
    for (int i = 0; i < n; i++)
    {
        Ttime = Ttime + BurstTime[i];
    }
    cout << "\nTotal time: " << Ttime << " msec.";
    while (time != Ttime)
    {
        for (int i = 0; BurstTime[i] != 0;)
        {
            if (BurstTime[i] <= m && BurstTime[i] > 0 && ArrivalTime[i] <= time)
            {
                cout << "\nProcess" << i + 1 << "...\n";
                time = time + BurstTime[i];
                cout << "P" << i + 1 << " completed in time " << BurstTime[i] << " msec.";
                cout << "\nTurnaround time is " << time;
                BurstTime[i] = 0;
            }
            else if (BurstTime[i] > m && ArrivalTime[i] <= time)
            {
                cout << "\nProcess" << i + 1 << "...\n";
                time = time + m;
                BurstTime[i] = BurstTime[i] - m;
                cout << "Time remaining for P" << i + 1 << " : " << BurstTime[i];
                cout << "\nStarting next remaining process ...";
            }
            if (i < n - 1)
            {
                i++;
            }
            else if (i = n - 1)
            {
                i = 0;
            }
        }
    }
    cout << "\nTotal time taken is " << time << " msec.";
    return 0;
}