#include<bits/stdc++.h>
using namespace  std;
string stringChallenge(string str){
  

   // string varOcg = "";
   // string prev = "";
   // for(char c:str){
   //    if(isupper(c)){
   //       if(c=='M'){
   //          varOcg+=prev;
   //          varOcg+=prev;
   //       }else if(c=='N') continue;
   //    }else{
   //       prev = tolower(c);
   //       varOcg+=tolower(c);
   //    }
   // }
   // return varOcg;
    string result = "";
    char prev = '\0'; // '\0' represents null character
    bool skipNext = false;

    for (char c : str) {
        if (isupper(c)) {
            if (c == 'M') {
                if (prev != '\0') {
                    result += prev;
                }
            } else if (c == 'N') {
                skipNext = true;
            }
        } else {
            if (!skipNext) {
                result += c;
            } else {
                skipNext = false;
            }
            prev = c;
        }
    }

    return result;
}
int main(){
   //code here
    string str = "abcNdgM";
    string result = stringChallenge(str);
    cout<<result;

    return 0;
}