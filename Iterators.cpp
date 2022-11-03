#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> v = {2, 20, 3, 30, 4, 40};
    // for (int i = 0; i < v.size(); ++i)
    // {
    //     cout << v[i] << " ";
    // }
    cout << endl;
    vector<int>::iterator itr = v.begin();
    // cout << "Vector value using iterators" << endl;
    // for (itr = v.begin(); itr != v.end(); ++itr)
    // {
    //     cout << (*itr) << " ";
    // }
    cout << endl;
    // vector of pair implement using iterators
    vector<pair<int, int>> vecPair = {{1, 2}, {20, 30}, {95, 5}};
    vector<pair<int, int>>::iterator it;
    // for (it = vecPair.begin(); it != vecPair.end(); ++it)
    // {
    //     // cout << (*it).first << " " << (*it).second << endl;
    //     cout << it->first << " " << it->second << endl;
    // }

    // for (pair<int, int> &value : vecPair)
    // {
    //     value.first++;
    //     value.second++;
    //     cout << value.first << " " << value.second << endl;
    // }

    for(auto)
    // for (int &evalue : v)
    // {
    //     evalue++;
    //     cout << evalue << " ";
    // }
    // cout << endl;
    return 0;
}