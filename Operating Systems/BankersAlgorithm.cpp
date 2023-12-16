// Sajanjit Singh Brar
// 20124087
// OS Lab
// Banker's Algorithm

#include <iostream>
using namespace std;

int SafeState(int A[3], int Al[5][3], int N[5][3])
{
    int SafeSequence[5];
    int counter = 0, z = 0;
    int Work[3], Finish[5];
    Work[0] = A[0];
    Work[1] = A[1];
    Work[2] = A[2];
    for (int i = 0; i < 5; i++)
    {
        Finish[i] = 0;
    }
    for (int k = 0; k < 5; k++)
    {
        for (int i = 0; i < 5; i++)
        {
            int flag = 0;
            for (int x = 0; x < 3; x++)
            {
                if (N[i][x] <= Work[x])
                    counter = 0;
                else
                    flag = 1;
                break;
            }
            if (Finish[i] == 0 && flag == 0)
            {
                SafeSequence[z++] = i;
                for (int x = 0; x < 3; x++)
                {
                    Work[x] = Work[x] + Al[i][x];
                }
                Finish[i] = 1;
            }
        }
    }
    int check = 1;
    for (int i = 0; i < 5; i++)
    {
        if (Finish[i] == 1)
        {
            counter++;
        }
        else
            check = 0;
    }
    if (check == 1)
    {
        cout << "Safe Sequence:\n";
        for (int i = 0; i < 4; i++)
            cout << "P" << SafeSequence[i] << " -> ";
        cout << "P" << SafeSequence[4] << "\n";
        return 1;
    }
    else
        return 0;
}

void ResourceRequest(int A[3], int Al[5][3], int N[5][3], int i, int k1, int k2, int k3)
{
    int ss, Request[5][3];
    Request[i][0] = k1;
    Request[i][1] = k2;
    Request[i][2] = k3;
    int flag = 0;
    int flag1 = 0;
    for (int x = 0; x < 3; x++)
    {
        if (Request[i][x] <= N[i][x])
        {
            flag = 0;
        }
        else
            flag = 1;
    }
    for (int x = 0; x < 3; x++)
    {
        if (Request[i][x] <= A[x])
        {
            flag1 = 0;
        }
        else
            flag1 = 1;
    }
    if (flag == 0)
    {
        if (flag1 == 0)
        {
            for (int x = 0; x < 3; x++)
            {
                A[x] = A[x] - Request[i][x];
                Al[i][x] = Al[i][x] + Request[i][x];
                N[i][x] = N[i][x] - Request[i][x];
            }
            ss = SafeState(A, Al, N);
            if (ss == 1)
                cout << "The transaction can be completed.";
            else
                cout << "\nThe Process must wait. The transaction cannot be completed.";
        }
        else
            cout << "\nThe Process must wait, since the resources are not available.";
    }
    else
        cout << "\nError! The Process has exceeded its maximum claim.";
}

int main()
{
    cout << "Sajanjit Singh Brar\n20124087\nOS Lab\nBanker's Algorithm\n";
    int s;
    int Processes[5] = {0, 1, 2, 3, 4};
    int Total[3] = {10, 5, 7};
    int Max[5][3] = {{7, 5, 3}, {3, 2, 2}, {9, 0, 2}, {2, 2, 2}, {4, 3, 3}};
    int Allocation[5][3] = {{0, 1, 0}, {2, 0, 0}, {3, 0, 2}, {2, 1, 1}, {0, 0, 2}};
    int Available[3];
    int Need[5][3];
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            Need[i][j] = Max[i][j] - Allocation[i][j];
        }
    }
    int Sum[3] = {0, 0, 0};
    for (int i = 0; i < 5; i++)
    {
        Sum[0] = Sum[0] + Allocation[i][0];
        Sum[1] = Sum[1] + Allocation[i][1];
        Sum[2] = Sum[2] + Allocation[i][2];
    }
    Available[0] = Total[0] - Sum[0];
    Available[1] = Total[1] - Sum[1];
    Available[2] = Total[2] - Sum[2];
    cout << "Processes\tAllocation\tMax\t\tNeed\n";
    cout << "\t\tA B C\t\tA B C\t\tA B C\n";
    for (int i = 0; i < 5; i++)
    {
        cout << "P" << Processes[i] << "\t\t" << Allocation[i][0] << " " << Allocation[i][1] << " " << Allocation[i][2] << "\t\t" << Max[i][0] << " " << Max[i][1] << " " << Max[i][2] << "\t\t" << Need[i][0] << " " << Need[i][1] << " " << Need[i][2] << "\n";
    }
    cout << "Available\nA B C\n";
    cout << Available[0] << " " << Available[1] << " " << Available[2] << "\n";
    cout << "\nSafety Algorithm\nTo check whether or not is the system in safe state\n";
    s = SafeState(Available, Allocation, Need);
    if (s == 1)
        cout << "The system is in safe state.";
    else
        cout << "\nThe system is not in safe state.";
    cout << "\n\nResource Request Algorithm\nTo check whether requests can be safely granted\n";
    int i, k1, k2, k3;
    cout << "Enter the process: ";
    cin >> i;
    cout << "Enter the number of instances of the resource type A: ";
    cin >> k1;
    cout << "Enter the number of instances of the resource type B: ";
    cin >> k2;
    cout << "Enter the number of instances of the resource type C: ";
    cin >> k3;
    ResourceRequest(Available, Allocation, Need, i, k1, k2, k3);
    return 0;
}