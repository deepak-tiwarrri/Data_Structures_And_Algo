// STL concepts
// #include <algorithm>
#include <bits/stdc++.h>
using namespace std;

// method printVec
void printVec(vector<string> &v)
{
    // cout << "size of vector: " << v.size() << endl; // example of size method in vector
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}
int main()
{
    // pair<int, string> p;
    // p = make_pair(2, "deepak");

    // pair can also be intialise using
    // p = {33, "ramu is bad boy"};

    /*we can also copy the pair with the another pair but the reference is not used it just copy it .....but if we copy the reference using below command*/
    // pair<int, string> &p1 = p;
    // p1.first = 93; // now the line 16 values will change

    // pair<int, string> p1 = p;
    // p1.first = 93;
    // cout << p1.first << " " << p1.second << endl;

    // cout << p.first << " " << p.second << endl;

    // int a[] = {1, 2, 3};
    // int b[] = {3, 2, 1};
    // pair<int, int> pairArr[3];
    // pairArr[0] = {1, 3};
    // pairArr[1] = {2, 2};
    // pairArr[2] = {3, 1};
    // swap(pairArr[0], pairArr[2]);

    // Taking the input of pair
    // pair<int, string> p1;
    // cin >> p1.first;
    // cin >> p1.second;
    // cout << p1.first << " " << p1.second << endl;

    // for (int i = 0; i < 3; i++)
    // {
    //     /* code */
    //     cout << pairArr[i].first << " " << pairArr[i].second << endl;
    // }

    // Vectors examples and codes
    // declaring a vector
    // vector<int> v(5, 4); // vector of size 5 with empty values
    // int n;
    // cin >> n;
    // for (int i = 0; i < n; i++)
    // {
    //     int x;
    //     cin >> x;
    //     v.push_back(x);
    // }

    /* sort method in vector*/
    // sort(v.begin(), v.end());

    // cout << "Sorted vector: " << endl;
    // creating another vector and copy the existing one
    // vector<int> v2 = v;
    // v2.push_back(23);
    // v2.push_back(93);
    // v2.push_back(5);

    // v = v2;
    // printVec(v);
    // v2.push_back(104);
    // printVec(v2);

    // EXAMPLE OF STRING VECTOR
    vector<string> v;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        string s;
        cin >> s;
        v.push_back(s);
    }

    printVec(v);

    return 0;
}