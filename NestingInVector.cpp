#include <bits/stdc++.h>
using namespace std;

void displayVec(vector<pair<int, int>> &v)
{
    // cout << "size of vector: " << v.size() << endl;
    cout << "Displaying the vector of pair: " << endl;
    for (int i = 0; i < v.size(); ++i)
    {
        cout << v[i].first << " " << v[i].second << endl;
    }
}
int main()
{
    // nesting pair in vector.....it is done generally in competative programming
    vector<pair<int, int>> v;

    // initializing the vector
    // v = {{1, 2}, {2, 3}, {3, 4}}; // we can also define the values like this

    // taking the user input in vector of pair
    int n;
    cout << "Enter the size of vector: " << endl;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int x, y;
        cin >> x >> y;
        // v.push_back({x, y});
        v.push_back(make_pair(x, y));
    }

    displayVec(v);
    return 0;
}