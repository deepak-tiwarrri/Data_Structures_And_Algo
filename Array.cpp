#include <bits/stdc++.h>
using namespace std;
int main()
{
    // code here
    int arr[100];           // initializing the array
    int a[100] = {1, 2, 3}; // some default values
    // for (auto i = 0; i < sizeof(a) / sizeof(a[0]); ++i)
    // {
    //     cout << a[i] << endl;
    // }
    // string fruits[] = {"mango", "banana", "gauva", "orange"};
    // cout << fruits[0] << endl;
    // for (auto &&value : fruits)
    // {
    //     cout << value << endl;
    // }

    int marks[100];
    int n;
    cout << "Enter how many marks you want to enter: " << endl;
    cin >> n;
    // input
    for (int i = 0; i < n; ++i)
    {
        cin >> marks[i];
    }

    // output
    for (int i = 0; i < n; ++i)
    {
        cout << marks[i] << ", ";
    }
    cout << endl;

    return 0;
}