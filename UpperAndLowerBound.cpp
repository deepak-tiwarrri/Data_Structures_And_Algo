// to find lower bound or upper bound array or vector should be in sorted format ascending order
#include <bits/stdc++.h>
using namespace std;
int main()
{
    // int n;
    // cin >> n;
    // // int a[n];
    // vector<int> a(n);
    // for (int i = 0; i < n; ++i)
    // {
    //     cin >> a[i];
    // }
    // sort(a.begin(), a.end());

    // for (int i = 0; i < n; ++i)
    // {
    //     cout << a[i] << " ";
    // }
    // cout << endl;
    // // int *ptr = lower_bound(a, a + n, 8);
    // auto itr = upper_bound(a.begin(), a.end(), 8);

    // if ((itr) == (a.end()))
    // {
    //     cout << "Not found";
    //     return 0;
    // }
    // cout << *itr << endl;

    // map & sets
    int n;
    cin >> n;
    set<int> s;
    map<int, int> m; // time complexity of log(n)
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        s.insert(x);
    }
    // this has the time complexity of O(n) not O(log(n))
    // auto itr = lower_bound(s.begin(), s.end(), 29);
    auto itr = s.upper_bound(5);
    cout << (*itr) << endl;

    return 0;
}