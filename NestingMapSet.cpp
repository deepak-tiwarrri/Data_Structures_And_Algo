#include <bits/stdc++.h>
using namespace std;
int main()
{
    // code here
    // map<pair<int, int>, int> m;
    // pair<int, int> p1, p2;
    // p1 = {2, 3};
    // p2 = {4, 5};
    // cout << (p1 > p2);

    // map<set<int, int>, int> m1;
    // set<int> s1, s2;
    // s1 = {2, 3, 4};
    // s2 = {3, 4};
    // cout << (s1 < s2);

    // suppose we are taking input first name and last name and count of marks
    /*  3
        a b 4
        1 2 3 4
        c d 2
        1 2
        d f 3
        2 3 4*/
    map<pair<string, string>, vector<int>> m;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        string fn, ln;
        int ctn;
        cin >> fn >> ln >> ctn;
        for (int j = 0; j < ctn; ++j)
        {
            int x;
            cin >> x;
            m[{fn, ln}].push_back(x);
        }
    }

    return 0;
}