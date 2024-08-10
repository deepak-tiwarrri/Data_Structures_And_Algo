#include<bits/stdc++.h>
using namespace  std;
bool checkOperand(char ch){
   if((ch>='A' && ch<='Z') || (ch>='a' && ch<='z') || (ch>='0' && ch<='9')){
      return true;
   }else return false;
}
string preToInfix(string &pre_exp){
   //write your code
   stack<string> st;
   for(int i=pre_exp.size()-1;i>=0;i--){
      if(checkOperand(pre_exp[i]))st.push(string(1,pre_exp[i]));
      else if(pre_exp[i]=='*' || pre_exp[i]=='/' || pre_exp[i]=='+' || pre_exp[i]=='-' || pre_exp[i]=='^'){
         string t1 = st.top();st.pop();
         string t2 = st.top();st.pop();
         string res = "(" + t1+pre_exp[i]+t2+")";
         st.push(res);
      }
   }
   return st.top();
}
int main(){
   //code here
   string str;
   getline(cin,str);
   string res = preToInfix(str);
   cout<<res<<endl;
    return 0;
}