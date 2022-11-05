// when order is not maintain in the set use unordered set cause it reduce the time complexity by O(1)
#include <bits/stdc++.h>
using namespace std;
void print(unordered_set<string> &s)
{
    cout << "Size of set: " << s.size() << endl;
    for (auto &value : s)
    {
        cout << value << endl;
    }
}
int main()
{
    // code here
    //  define sets
    // unordered_set<string> s;
    // s.insert("abcd"); // O(1)
    // s.insert("ghj");  // O(1)
    // s.insert("red");
    // s.insert("yawk");
    // auto it = s.find("ghj"); // O(1)
    // if (it != s.end())
    // {
    //     // cout << *it << endl;
    //     // s.erase(it);// erase method will take the iterator as argument
    //     s.erase("abcd");
    // }
    // else
    // {
    //     cout << "value not present" << endl;
    // }
    // print(s);

    /*
Given N strings and Q queries.
In each query you are given a string print
yes if string is present else print no.
N <= 10^6
|S| <=100
Q <=10 ^6
*/
    unordered_set<string> s1;
    int n;
    cin >> n;
    for (auto i = 0; i < n; ++i)
    {
        string str;
        cin >> str;
        s1.insert(str);
    }
    // print(s1);
    int q;
    cin >> q;
    while (q--)
    {
        string s;
        cin >> s;
        if (s1.find(s) == s1.end())
        {
            cout << "no\n";
        }
        else
        {
            cout << "yes\n";
        }
    }

    return 0;
}