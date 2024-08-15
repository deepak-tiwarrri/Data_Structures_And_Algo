#include <bits/stdc++.h>
using namespace std;
string removeKdigits(string num, int k)
{
   stack<char> st;
   string res = "";
   // if(k==num.size()) return "0";
   for (int i = 0; i < num.size(); i++)
   {
      while (!st.empty() && (st.top() - '0') > (num[i] - '0') && k > 0)
      {
         k--;
         st.pop();
      }
      st.push(num[i]);
   }
   // if k haven't been reduced that remove the last kth element from stack
   while (k > 0 && !st.empty())
   {
      st.pop();
      k--;
   }
   // if stack got empty while poping all the element of equal to k
   if (st.empty())
      return "0";
   // putting all the stack element in string
   while (!st.empty())
   {
      res.push_back(st.top());
      st.pop();
   }
   // if back of string has any zero remove all of it then reverse it
   while (res.size() != 0 && res.back() == '0')
   {
      res.pop_back();
   }
   // finally reverse the array
   reverse(res.begin(), res.end());
   // if string is empty then return 0
   if (res.empty())
      return "0";
   return res;
}
int main()
{
   // code here
   string s;
   int k;
   getline(cin, s);
   cin >> k;
   string res = removeKdigits(s, k);
   cout << res << endl;

   return 0;
}