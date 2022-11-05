#include <bits/stdc++.h>
using namespace std;
void print(multiset<string> &s)
{
    cout << "Size of multiset: " << s.size() << endl;
    for (auto &value : s)
    {
        cout << value << endl;
    }
}
int main()
{
    multiset<string> s;
    s.insert("abc");
    s.insert("ghj");
    s.insert("bcd");
    s.insert("zsdf");
    s.insert("abc");

    auto it = s.find("abc");
    if (it != s.end())
    {
        s.erase(it); // this will erase the value one at time
    }
    s.erase("abc"); // this will erase the whole value present "abc"

    print(s);
    return 0;
}