#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'isBalanced' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */
unordered_map<int, char> symbols = {{'[', -1}, {'(', -2}, {'{', -3}, {']', 1}, {')', 2}, {'}', 3}};

string isBalanced(string s)
{
    stack<char> st;
    for (char bracket : s)
    {
        if (symbols[bracket] < 0)
        {
            st.push(bracket);
        }
        else
        {
            if (st.empty())
                return "NO";
            char top = st.top();
            st.pop();
            if (symbols[top] + symbols[bracket] != 0)
                return "NO";
        }
    }
    if (st.empty())
        return "YES";
    return "NO";
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        cout << isBalanced(s) << endl;
    }
    return 0;
}