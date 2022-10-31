// STL concepts
#include <bits/stdc++.h>
using namespace std;
int main()
{
    pair<int, string> p;
    // p = make_pair(2, "deepak");
    // pair can also be intialise using
    p = {33, "ramu is bad boy"};
    /*we can also copy the pair with the another pair but the reference is not used it just copy it .....but if we copy the reference using below command*/
    pair<int, string> &p1 = p;
    p1.first = 93; // now the line 16 values will change
    // pair<int, string> p1 = p;
    // p1.first = 93;
    // cout << p1.first << " " << p1.second << endl;
    cout << p.first << " " << p.second << endl;
    return 0;
}