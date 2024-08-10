#include<bits/stdc++.h>
using namespace  std;
bool checkOperand(char ch)
{
   if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9'))
   {
      return true;
   }
   else
      return false;
}
string preToPost(string &pre_exp){
   stack<string> st;
   for(int i=pre_exp.size()-1;i>=0;i--){
      if(checkOperand(pre_exp[i])){
         st.push(string(1,pre_exp[i]));
      }else{
         string t1 = st.top();st.pop();
         string t2 = st.top();st.pop();
         string s = t1+t2+pre_exp[i];
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
   string res = preToPost(s);
   cout << res << endl;

   return 0;
}