#include <bits/stdc++.h>
#include <stack>
using namespace std;
int main()
{
    // code here
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(33);
    s.push(44);
    // cout << s.top() << endl; // 40 output
    while (!s.empty())
    {
        cout << s.top() << endl;
        s.pop();
    }
    queue<string> q;
    q.push("deepak");
    q.push("sakshi");
    q.push("shilpa");
    q.push("ghi");

    while (!q.empty())
    {
        cout << q.front() << endl;
        q.pop();
    }
    return 0;
}