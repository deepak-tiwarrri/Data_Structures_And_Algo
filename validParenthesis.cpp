#include<bits/stdc++.h>
using namespace  std;
class ValidParenthesis 
{
	public:
		// Implement your solution here
		string isValid(string s) 
		{
			stack<char> st;
			for(auto &val:s){
            if(val=='(' || val=='{'|| val =='['){
               st.push(val);
            }else{
               if(st.empty()) return "false";
               char ch = st.top();
               st.pop();
               if((val==']' and ch=='[')or(val==')' and ch=='(')or (val=='}' and ch=='{')) continue;
               else{
                  return "false";
               }
            }
         }
         return "true";
		}
};

int main(){
   //code here
    

    return 0;
}