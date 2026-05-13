#include <iostream>
using namespace std;

bool isPalindrome(string str, int left, int right)
{
    if (left >= right)
    {
        return true;
    }

    if (str[left] != str[right])
    {
        return false;
    }

    return isPalindrome(str, left + 1, right - 1);
}

int main()
{
    string str;

    cout << "Enter a string: ";
    cin >> str;

    int n = str.length();

    if (isPalindrome(str, 0, n - 1))
    {
        cout << "Palindrome";
    }
    else
    {
        cout << "Not Palindrome";
    }

    return 0;
}