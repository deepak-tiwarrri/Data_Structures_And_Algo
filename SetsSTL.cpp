// sets are same as maps but if we remove the value of maps it becomes sets
// sets can be of three types sets,unordered sets and multi sets
// sets are already in sorted order
#include <bits/stdc++.h>
using namespace std;
void print(set<string> &s)
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
    set<string> s;
    s.insert("abcd"); // O(log(n)) same as maps
    s.insert("ghj");
    s.insert("red");
    s.insert("yawk");
    auto it = s.find("ghj");
    if (it != s.end())
    {
        // cout << *it << endl;
        // s.erase(it);// erase method will take the iterator as argument
        s.erase("abcd");
    }
    else
    {
        cout << "value not present" << endl;
    }
    print(s);

    /*
Given N strings,print unique strings
in lexiographical order with their frequency
N <= 10^5
|S| <=100
*/
    set<string> s1;
    int n;
    cin >> n;
    for (auto i = 0; i < n; ++i)
    {
        string str;
        cin >> str;
        s1.insert(str);
    }
    print(s1);

    return 0;
}