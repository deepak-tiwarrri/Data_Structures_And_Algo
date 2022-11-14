// all_of,none_of,any_of
#include <bits/stdc++.h>
using namespace std;
int main()
{
    // code here
    // this is the lambda function
    cout << [](int x)
    { return x + 2; }(2)
         << endl;

    auto sum = [](int x, int y)
    { return x + y; };
    cout << sum(2, 4) << endl;

    // all of function will return true if the given condition is true in all the cases
    // example // this will return true if all the values are positive or else it will return false otherwise
    vector<int> v = {-1, 5, -31, -5};
    cout << all_of(v.begin(), v.end(), [](int x)
                   { return x > 0; })
         << endl; // 0

    cout << any_of(v.begin(), v.end(), [](int x)
                   { return x > 0; })
         << endl; // 1

    cout << none_of(v.begin(), v.end(), [](int x)
                    { return x > 0; })
         << endl; // 0

    cout << none_of(v.begin(), v.end(), [](int a)
                    { return a % 2 == 0; })
         << endl; // 1
    return 0;
}