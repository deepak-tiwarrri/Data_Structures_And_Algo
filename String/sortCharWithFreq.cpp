#include<bits/stdc++.h>
using namespace  std;
static bool comparator(pair<int,char> p1,pair<int,char> p2){
   //if first char is smaller than second return false
   if(p1.first < p2.first) return false;
   if(p1.first> p2.first) return true;
   if(p1.first == p2.first){
      //if frequencies are equal sort by alphabet
      if(p1.second<p2.second) return true;
   }
   return false;
}
vector<char> frequencySort(string &s){
   //store in the format of {0,'a'} {0,'b'} {0,'c'}
   pair<int,char> freq[26];
   for(int i=0;i<26;++i){
      freq[i] = {0,i+'a'};
   }
   for(int i=0;i<s.length();++i){
      freq[s[i]-'a'].first++;
   }
   sort(freq,freq+26,comparator);
   vector<char> ans;
   for(int i=0;i<26;i++){
      //when to push in array when first elment is not zero 
      //if it's zero that means after that all the elements are zero
      if(freq[i].first!=0) ans.push_back(freq[i].second);
   }
   return ans;

}
int main(){
   //code here
    string s;
    cin>>s;
    vector<char> res = frequencySort(s);
    for (auto &it:res)
    {
      cout<<it<<" ";
    }
    

    return 0;
}