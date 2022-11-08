#include <bits/stdc++.h>
using namespace std;
int main()
{
    // vector<int> v(n);
    int n;
    cin >> n;
    int a[n];
    for (auto i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    // sort(a, a + n); // takes two value first value is start index and second value is last+1
    sort(a + 2, a + n); // inbuilt function used by sort method is introsort(merge sort,quick and heap);
    // for vector
    // sort()
    for (auto i = 0; i < n; ++i)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}