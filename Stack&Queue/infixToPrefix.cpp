#include <bits/stdc++.h>
using namespace std;
int checkPriority(char c)
{
   if (c == '^')
      return 3;
   else if (c == '*' || c == '/')
      return 2;
   else if (c == '+' || c == '-')
      return 1;
   else
      return -1;
}
string revStringWithBracket(string &s)
{
   int n = s.size();
   int i = 0;
   while (i < n / 2)
   {
      swap(s[i], s[n - i - 1]);
      i++;
   }
   for (int i = 0; i < s.size(); i++)
   {
      if (s[i] == '(')
         s[i] = ')';
      else if (s[i] == ')')
         s[i] = '(';
   }
   return s;
}
bool checkOperand(char ch)
{
   if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9'))
   {
      return true;
   }
   else
      return false;
}
string infixToPostfix(string &s)
{
   string res = "";
   stack<char> st;
   for (int i = 0; i < s.size(); i++)
   {
      if (checkOperand(s[i]))
      {
         res += s[i];
      }
      else if (s[i] == '(')
         st.push(s[i]);
      else if (s[i] == ')')
      {
         while (!st.empty() && st.top() != '(')
         {
            res += st.top();
            st.pop();
         }
         st.pop();
      }
      else
      {
         while (!st.empty() && checkPriority(s[i]) <= checkPriority(st.top()))
         {
            res += st.top();
            st.pop();
         }
         st.push(s[i]);
      }
   }
   while (!st.empty())
   {
      res += st.top();
      st.pop();
   }
   return res;
}
string reverseStr(string &s)
{
   int i = 0;
   while (i < s.size() / 2)
   {
      swap(s[i], s[s.size() - i - 1]);
      i++;
   }
   return s;
}
string infixToPrefix(string &s)
{
   s = revStringWithBracket(s);
   stack<char> st;
   string ans = "";
   for (int i = 0; i < s.length(); i++)
   {
      if (checkOperand(s[i]))
         ans += s[i];
      else if (s[i] == '(')
         st.push(s[i]);
      else if (s[i] == ')')
      {
         while (!st.empty() && st.top() != '(')
         {
            ans += st.top();
            st.pop();
         }
         st.pop();
      }
      else
      {
         if (s[i] == '^')
         {
            while (!st.empty() && checkPriority(s[i]) <= checkPriority(st.top()))
            {
               /* code */
               ans += st.top();
               st.pop();
            }
         }
         else
         {
            while (!st.empty() && checkPriority(s[i]) < checkPriority(st.top()))
            {
               ans += st.top();
               st.pop();
            }
            st.push(s[i]);
         }
      }
   }
   return reverseStr(ans);
}
int main()
{
   // code here
   string s;
   getline(cin, s);
   //  string res = infixToPostfix(s);
   string res = infixToPostfix(s);
   cout << res << endl;

   return 0;
}