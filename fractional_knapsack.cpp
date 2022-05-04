#include <bits/stdc++.h>
using namespace std;
struct item
{
    int value;
    int weight;
    float ratio;
};
int main()
{
    int weight, num_of_items;
    cout << "enter the weight of knapsack:";
    cin >> weight;
    cout << "enter the number of items:";
    cin >> num_of_items;
    item items[num_of_items];
    for (int i = 0; i < num_of_items; i++)
    {
        cout << "enter the value of item " << i + 1 << ":";
        cin >> items[i].value;
        cout << "enter the weight of item " << i + 1 << ":";
        cin >> items[i].weight;
        items[i].ratio=(float)items[i].value/items[i].weight;
    }
    /*for(int i=0;i<num_of_items;i++)
    {
        cout<<items[i].ratio<<" ";
    }*/
    for (int i = 0; i < num_of_items; i++)
    {
        for (int j = i + 1; j < num_of_items; j++)
        {
            
            if (items[i].ratio <items[j].ratio)
            {
                item temp;
                temp.value = items[j].value;
                temp.weight = items[j].weight;
                temp.ratio=items[j].ratio;
                items[j].value = items[i].value;
                items[j].weight = items[i].weight;
                items[j].ratio=items[i].ratio;
                items[i].value = temp.value;
                items[i].weight = temp.weight;
                items[i].ratio=temp.ratio;
            }
        }
    }
    for (int i = 0; i < num_of_items; i++)
    {
        cout << "item:" << i + 1 << " weight:" << items[i].weight << " value:" << items[i].value << endl;
    }
    int preswt = 0;
    float best = 0;
    int chosen[num_of_items] = {0};
    for (int i = 0; i < num_of_items; i++)
    {
        if (preswt + items[i].weight <= weight)
        {
            preswt = preswt + items[i].weight;
            best = best + items[i].value;
            chosen[i] = 1;
        }
        else
        {
            best = best + (items[i].value * ((float)((weight - preswt) / (float)items[i].weight)));
            chosen[i] = 2;
            break;
        }
    }
    cout << "****** final value=" << best << "******" << endl;
    for (int i = 0; i < num_of_items; i++)
    {
        if (chosen[i] == 0)
        {
            cout << "item:" << i + 1 << " not chosen" << endl;
        }
        else if (chosen[i] == 1)
        {
            cout << "item:" << i + 1 << " fully chosen" << endl;
        }
        else if (chosen[i] == 2)
        {
            cout << "item:" << i + 1 << " partially chosen" << endl;
        }
    }
}
