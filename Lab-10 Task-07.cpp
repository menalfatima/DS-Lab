#include <iostream>
using namespace std;

bool subsetSum(int arr[], int n, int target)
{
    if (target == 0)
        return true;

    if (n == 0)
        return false;

    if (arr[n - 1] > target)
        return subsetSum(arr, n - 1, target);

    return subsetSum(arr, n - 1, target) ||
        subsetSum(arr, n - 1, target - arr[n - 1]);
}

int findMaxIndex(int arr[], int n)
{
    if (n == 1)
        return 0;

    int idx = findMaxIndex(arr, n - 1);

    return (arr[n - 1] > arr[idx]) ? (n - 1) : idx;
}

int magicNumber(int arr[], int n)
{
    if (n == 0)
        return -1;

    int maxIdx = findMaxIndex(arr, n);
    int maxVal = arr[maxIdx];

    int temp[100];
    int j = 0;

    for (int i = 0; i < n; i++)
    {
        if (i != maxIdx)
        {
            temp[j++] = arr[i];
        }
    }
    if (subsetSum(temp, j, maxVal))
    {
        return maxVal;
    }

    arr[maxIdx] = arr[n - 1];

    return magicNumber(arr, n - 1);
}

int main()
{
    int arr[] = { 10, 3, 5, 7, 2 };
    int n = 5;

    cout << "Magic Number: " << magicNumber(arr, n);

    return 0;
}