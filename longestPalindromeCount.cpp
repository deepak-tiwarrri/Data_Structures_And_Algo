#include<bits/stdc++.h>
using namespace  std;
int longestPalindrome(int n,string s){
   unordered_map<char,int> mpp;
   int ans=0;
   for(auto &it:s) mpp[it]++;
   bool isOdd = false;
   for(auto &it:mpp){
      if(it.second%2==0) ans+= ((it.second/2))*2;
      if(it.second==1) isOdd = true;
   }
   isOdd?ans+=1:ans+=0;
   return ans;
}
int main()
{
    int n;
    cin >> n;

    string s;
    cin >> s;

    int ans = longestPalindrome(n, s);
    cout << ans << endl;
    return 0;
}
