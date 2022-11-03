/* map stores key value pair and store the value in lexographical order means in sorted format
map can't store double value ...it just replace the value pair of key*/
#include <bits/stdc++.h>
using namespace std;
void printValue(map<int, string> &m)
{
    cout << "Size of map : " << m.size() << endl;
    // iterators
    for (auto &it : m)
    {
        cout << it.first << " " << it.second << endl;
    }
}
int main()
{
    // code here
    map<int, string> m;
    m[1] = "abcd"; // O(log(n)) time complexity of map is very large as it follows red black tree
    m[2] = "deepak";
    m[5] = "sakshi";
    m[10] = "nishtha";
    // m[5] = "shilpa"; // map will replace the value of sakshi with shilpa
    // m[6]; // this will declared map of size zero
    m.insert({4, "ghj"});
    m.insert(make_pair(3, "jhk"));

    // another method of maps
    auto it = m.find(10); // return value of find method is iterator// this will print 10 nishtha
    // if (it == m.end())
    // {
    //     cout << "No value" << endl;
    // }
    // else
    // {
    //     cout << it->first << " " << it->second << endl;
    // }

    //  erase method
    // m.erase(10); // can take two values as argument first key second iterators
    if (it != m.end())
        m.erase(11); // can take two values as argument first key second iterators
    // m.clear();       // clear all the values of map

    // cout << m[5] << endl;// this will print the values of m

    // printing the value of maps
    // for (auto itr = m.begin(); itr != m.end(); ++itr)
    // {
    //     cout << itr->first << " " << itr->second << endl;
    // }

    // can be printed like below
    // for (auto &it : m)
    // {
    //     cout << it.first << " " << it.second << endl;
    // }

    // map of string and it's time complexity
    map<string, string> mString;
    mString["abcd"] = "abcde"; // string.size()* log(N)
    printValue(mString);
    // printValue(m);
    return 0;
}