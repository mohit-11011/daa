#include <iostream>
using namespace std;
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
    cout << "enter the element to be searched :";
    int search;
    cin >> search;
    int l = 0, r = size - 1;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (arr[mid] == search)
        {
            cout << mid;
            return 0;
        }
        else if(arr[mid]>search)
        {
            r=mid-1;
        }
        else
        {
            l=mid+1;
        }
    }
    cout<<"-1";
}