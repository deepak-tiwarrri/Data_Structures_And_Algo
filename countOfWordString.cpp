#include<bits/stdc++.h>
using namespace  std;

//input : 
//3
//car bus car
// 2
//output:
// car
// bus
bool cmp(pair<int,string> p1,pair<int,string> p2){
   if(p1.first == p2.first){
      return p1.second < p2.second;
   }   
   return p1.first > p2.first;
}
vector<string> frequentWords(vector<string> & words, int k){
   vector<string> ans;
   unordered_map<string,int> mp;
   for(int i=0;i<words.size();i++){
      mp[words[i]]++;
   }
   vector<pair<int,string>> v;
   for(auto i:mp){
      v.push_back({i.second,i.first});
   }
   sort(v.begin(),v.end(),cmp);
   for(int i=0;i<k;i++){
      ans.push_back(v[i].second);
   }
   return ans;  
}
int main(){
   //code here
    return 0;
}