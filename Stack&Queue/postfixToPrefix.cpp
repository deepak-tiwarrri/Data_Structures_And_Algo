#include <bits/stdc++.h>
using namespace std;
bool checkOperand(char ch)
{
   if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9'))
   {
      return true;
   }
   else
      return false;
}
string postToPre(string post_exp)
{
   // Write your code here
   stack<string> st;
   for(int i=0;i<post_exp.size();i++){
      if(checkOperand(post_exp[i])){
         st.push(string(1,post_exp[i]));
      }else{
         string t1 = st.top();st.pop();
         string t2 = st.top();st.pop();
         string s = post_exp[i]+t2+t1;
         st.push(s);
      }
   }
   return st.top();
}
int main()
{
   // code here
   string s;
   getline(cin, s);
   string res = postToPre(s);
   cout << res << endl;

   return 0;
}