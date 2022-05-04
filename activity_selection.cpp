#include <bits/stdc++.h>
using namespace std;
struct job
{
    int start;
    int finish;
};
int main()
{
    cout << "enter the number of acitivites: ";
    int num_of_acitivites;
    cin >> num_of_acitivites;
    job activities[num_of_acitivites];
    for (int i = 0; i < num_of_acitivites; i++)
    {
        cout << "enter the start time of job " << i + 1<<":  ";
        cin >> activities[i].start;
        cout << "enter the finish time of job " << i + 1<<":  ";
        cin >> activities[i].finish;
    }
    for (int i = 0; i < num_of_acitivites; i++)
    {
        for (int j = i + 1; j < num_of_acitivites; j++)
        {
            if (activities[j].finish < activities[i].finish)
            {
                job temp;
                temp.start = activities[j].start;
                temp.finish = activities[j].finish;
                activities[j].start = activities[i].start;
                activities[j].finish = activities[i].finish;
                activities[i].start = temp.start;
                activities[i].finish = temp.finish;
            }
        }
    }

    int selected = 0;
    cout << "jobs selected are" << endl;
    cout << selected+1 << endl;
    int rest;
    for (rest = 1; rest < num_of_acitivites; rest++)
    {
        if (activities[rest].start >= activities[selected].finish)
        {
            cout << rest+1 << endl;
            selected = rest;
        }
    }
}
