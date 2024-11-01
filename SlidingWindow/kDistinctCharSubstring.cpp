#include<bits/stdc++.h>
using namespace  std;
int kDistinctChar(string &s,int k){
   //your code goes here
   //brute force appraoch
   // TC: O(n^2) and SC: O(1)
   // unordered_map<char,int> charMap;
   // int maxLen =0;
   // for(int i=0;i<s.length();++i){
   //    charMap.clear();
   //    for(int j=i;j<s.length();++j){
   //       charMap[s[j]]++;
   //       if(charMap.size()<=k){
   //          maxLen = max(maxLen,j-i+1);
   //       }
   //       else break;
   //    }   
   // }

   int maxLen = 0;
   unordered_map<char,int> charMap;
   int r =0,l=0;
        while(r<s.size()){
            charMap[s[r]]++;
            if(charMap.size()<=k){
                maxLen = max(maxLen,r-l+1);
            }else{
                charMap[s[l]]--;
                if(charMap[s[l]]==0) charMap.erase(s[l]);
                l++;
            }
            r++;
        }
        return maxLen;
   // return maxLen;

}
int main(){
   //code here
    string s;
    int k;
    cin>>s>>k;
    int result = kDistinctChar(s,k);
    cout<<result<<endl;

    return 0;
}