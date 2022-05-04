#include <iostream>
using namespace std;
struct job
{
    int deadline;
    int profit;
};
int main()
{
    cout << "enter the number of jobs: ";
    int num_of_jobs;
    cin >> num_of_jobs;
    job jobs[num_of_jobs];
    for (int i = 0; i < num_of_jobs; i++)
    {
        cout << "enter the deadline of job " << i + 1 << ": ";
        cin >> jobs[i].deadline;
        cout << "enter the profit of job " << i + 1 << ": ";
        cin >> jobs[i].profit;
    }
    for (int i = 0; i < num_of_jobs; i++)
    {
        for (int j = i + 1; j < num_of_jobs; j++)
        {
            if (jobs[j].profit > jobs[i].profit)
            {
                job temp;
                temp.deadline = jobs[j].deadline;
                temp.profit = jobs[j].profit;
                jobs[j].deadline = jobs[i].deadline;
                jobs[j].profit = jobs[i].profit;
                jobs[i].deadline = temp.deadline;
                jobs[i].profit = temp.profit;
            }
        }
    }
    for (int i = 0; i < num_of_jobs; i++)
    {
        cout << "job:" << i + 1 << " deadline:" << jobs[i].deadline << " profit:" << jobs[i].profit << endl;
    }
    int ans[num_of_jobs];
    int free[num_of_jobs] = {0};
    for (int i = 0; i < num_of_jobs; i++)
    {
        for (int j = jobs[i].deadline - 1; j >= 0; j--)
        {
            if (free[j] == 0)
            {
                ans[j] = i;
                free[j] = 1;
                break;
            }
        }
    }
    for (int i = 0; i < num_of_jobs; i++)
    {
        if (free[i] == 1)
        {
            cout << ans[i] + 1 << " ";
        }
    }
}