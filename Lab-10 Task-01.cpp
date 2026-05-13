#include<iostream>
using namespace std;

int sum(int arr[], int size) {

	if (size==0) {
		return 0;
	}
	else {
		return arr[0]+sum(arr+1,size-1);
	}
}
int main() {
	int arr[] = { 2,3,4,5 };
	int size = 4;
	cout << "Sum of array using recursion is: " << sum(arr, size);
	return 0;
}