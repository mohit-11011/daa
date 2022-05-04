#include <iostream>
using namespace std;
void merge(int arr[], int p, int q, int r)
{
    int n1 = q - p + 1;
    int n2 = r - q;
    int lm[n1];
    int rm[n2];
    for (int i = 0; i < n1; i++)
    {
        lm[i] = arr[p + i];
    }
    for (int j = 0; j < n2; j++)
    {
        rm[j] = arr[q + 1 + j];
    }
    int i = 0, j = 0, k = p;
    while (i < n1 && j < n2)
    {
        if (lm[i] < rm[j])
        {
            arr[k] = lm[i];
            i = i + 1;
        }
        else
        {
            arr[k] = rm[j];
            j = j + 1;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = lm[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = rm[j];
        j++;
        k++;
    }
}
void merge_sort(int arr[], int p, int r)
{
    if (p < r)
    {
        int q = (p + r) / 2;
        merge_sort(arr, p, q);
        merge_sort(arr, q + 1, r);
        merge(arr, p, q, r);
    }
}
int main()
{
    int size;
    cout << "enter the size of your array : ";
    cin >> size;
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    merge_sort(arr, 0, size - 1);
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}
