/* same as maps but can store in unordered format and does not take the vector , pair as the input data type. unordered map as all the same methods as map but it is unordered format*/

/* multimap can be used to store the duplicate values*/

#include <bits/stdc++.h>
using namespace std;

void printValue(unordered_map<string, int> &m)
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
    // declaring unordered map
    // unordered_map<int, string> m;
    // unordered_map<pair<int, int>, string> m;// it can't be compile
    // m[1] = "abcd"; // unordered map follows hash tables // time complexity: O(1)
    // m[2] = "deepak";
    // m[5] = "ghj";
    // m[20] = "nishtha";
    // for (auto &it : m)
    // {
    //     cout << it.first << " " << it.second << endl;
    // }
    // printValue(m);

    /* Given  N String and Q queries. In each query you are given a string print frequency of that string print the frequency of that string
        N <=10^6
        |S| <=100
        Q <=10^6
    */

    // code here// we use unordered set to decrease the time complexity same thing can be implemented using map
    unordered_map<string, int> m;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        string s;
        cin >> s;
        m[s]++;
    }
    int q;
    cin >> q;
    while (q--)
    {
        string s;
        cin >> s;
        cout << m[s] << endl;
    }
    printValue(m);
}