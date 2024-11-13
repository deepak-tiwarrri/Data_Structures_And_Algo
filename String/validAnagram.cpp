#include <bits/stdc++.h>
using namespace std;
bool anagramString(string s, string t)
{
   // better approach is sort the string and check if they are equal then they are anaggram
   sort(s.begin(), s.end());
   sort(t.begin(), t.end());

   cout << s << endl;
   cout << t << endl;
   return s == t ? true : false;
}
int main()
{
   // code here
   string s, t;
   cin >> s >> t;
   bool isAnaString = anagramString(s, t);
   cout << isAnaString << endl;

   return 0;
}