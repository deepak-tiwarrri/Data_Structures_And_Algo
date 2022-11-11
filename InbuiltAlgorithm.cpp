#include <bits/stdc++.h>
using namespace std;
int main()
{
    // code here
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> v[i];
    }
    // min element
    int min = *min_element(v.begin(), v.end());
    cout << min << endl;
    // for max element
    int max = *max_element(v.begin(), v.end());
    cout << max << endl;

    // // for sum of all the elements use accumulate function
    int sum = accumulate(v.begin(), v.end(), 0); // here 0 is the initial sum
    cout << sum << endl;

    // count method will count of the number of element in the array
    int ctn = count(v.begin(), v.end(), 12);
    cout << ctn << endl;

    // find element will find the element and return the iterator of that value
    // vector<int>::iterator itr;
    auto itr = find(v.begin(), v.end(), 2);
    // itr = find(v.begin(), v.end(), 2);
    if (itr != v.end())
        cout << *itr << endl;
    else
        cout << "value not found!!" << endl;

    // reverse method
    reverse(v.begin(), v.end());
    for (auto &value : v)
    {
        cout << value << " ";
    }
    cout << endl;

    // reversing the string
    string s = "abcdefghj";
    reverse(s.begin() + 1, s.end());
    cout << s << endl;
    // for (int i = 0; i < n; ++i)
    // {
    //     cout << v[i] << " ";
    // }

    return 0;
}