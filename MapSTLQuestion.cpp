/*
Given N strings,print unique strings
in lexiographical order with their frequency
N <= 10^5
|S| <=100
*/

#include <bits/stdc++.h>
using namespace std;
int main()
{
    // code here
    int N;
    cin >> N;
    map<string, int> m;
    for (int i = 0; i < N; i++)
    {
        string s;
        cin >> s;
        m[s]++;
    }
    cout << "Printing the values: " << endl;
    for (auto &pr : m)
    {
        cout << pr.first << " " << pr.second << endl;
    }

    return 0;
}