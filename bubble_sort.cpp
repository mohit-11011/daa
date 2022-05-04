#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream fin;
    int number;
    int arr[10000];
    int i = 0;
    int n = 10000;

    fin.open("input.txt");
    while (fin >> number)
    {
        arr[i] = number;
        i++;
    }
    fin.close();
    for (i = 0; i < n; i++)
    {
        for (int j = 0; j <= n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    
    return 0;
}
