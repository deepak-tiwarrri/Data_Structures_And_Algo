#include<bits/stdc++.h>
using namespace std;
string largeOddNum(string &s){
    int startIndex = 0;
    int endIndex = -1;
    //iterate the string from end to beginning
    for(int i=s.size()-1;i>=0;i--){
        //if string is odd from end take that end index
        if((s[i]-'0')%2==1){
            endIndex=i;
            break;
        }else{
            continue;
        }
    }
    if(endIndex==-1) return "";
    // for(int i=startIndex;i<=endIndex;i++){
    //     if(s[i]=='0') continue;
    //     else{
    //         startIndex = i;
    //         break;
    //     }
    // }
    while(startIndex<=endIndex && s[startIndex]=='0') startIndex++;
    return s.substr(startIndex,endIndex-startIndex+1);//startindex to length of the string
}
int main(){
  
  //code here
    string s;
    cin>>s;
    string res  = largeOddNum(s);
    cout<<res<<endl;
  
  return 0;
}