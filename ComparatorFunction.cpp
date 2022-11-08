#include <bits/stdc++.h>
using namespace std;
// bool should_i_swap(int a, int b)
// {
//     if (a > b)
//         return true;
//     return false;
// }
// bool should_i_swap(int a, int b)
// {
//     return a > b;
// }

bool should_i_swap_pair(pair<int, int> a, pair<int, int> b)
{
    if (a.first != b.first)
    {
        // just written function according
        a.first > a.second;
    }
    else
        a.second > b.second;
} // same code as above but long format and for better understanding of
// bool should_i_swap_pair(pair<int, int> a, pair<int, int> b)
// {
//     if (a.first != b.first)
//     {
//         if (a.first > b.first)
//         {
//             return false;
//         }
//         return true;
//     }
//     else
//     {
//         if (a.second < b.second)
//             return false;
//         return true;
//     }
// }
int main()
{
    // code here
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> v[i].first >> v[i].second;
    }
    // for (int i = 0; i < n; ++i)
    // {
    //     for (int j = i + 1; j < n; ++j)
    //     {
    //         if (should_i_swap_pair(v[i], v[j]))
    //         {
    //             swap(v[i], v[j]);
    //         }
    //     }
    // }
    sort(v.begin(), v.end(), should_i_swap_pair);
    cout << "Output: " << endl;
    for (int i = 0; i < n; ++i)
    {
        cout << v[i].first << " " << v[i].second << endl;
    }
    // cout << endl;

    return 0;
}