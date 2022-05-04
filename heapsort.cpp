#include <iostream>
using namespace std;
/* A utility function to print array of size n */
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}
void heapify(int arr[], int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest])
        largest = l;
    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i)
    {
        swap(arr[i], arr[largest]);

        heapify(arr, n, largest);
    }
}

// main function to do heap sort
void heapSort(int arr[], int n)
{
    //for all non leaf nodes
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
        printArray(arr,n);
        cout<<endl;

    //deleting root element(largest)
    for (int i = n - 1; i >= 0; i--)
    {
        //deleted root but to maintain complete tree property swapped last leaf node to root
        swap(arr[0], arr[i]);
        printArray(arr,n);

        //as swap deletes the property of max heap so heapifying again
        heapify(arr, i, 0);
        printArray(arr,n);
        cout<<endl;
    }
}



// Driver program
int main()
{
    int arr[] = {1,2,8,7,6,3,2,11,19,18,16,23,12,31};
    int n = sizeof(arr) / sizeof(arr[0]);

    heapSort(arr, n);

    cout << "Sorted array is \n";
    printArray(arr, n);
}
