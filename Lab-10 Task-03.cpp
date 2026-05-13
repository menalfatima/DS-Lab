#include <iostream>
using namespace std;

int findMax(int arr[], int size)
{
    if (size == 1)
    {
        return arr[0];
    }
    int maxInRest = findMax(arr + 1, size - 1);

    return (arr[0] > maxInRest) ? arr[0] : maxInRest;
}

int main()
{
    int arr[] = { 12, 5, 18, 7, 3 };
    int size = 5;

    cout << "Maximum element: " << findMax(arr, size);

    return 0;
}