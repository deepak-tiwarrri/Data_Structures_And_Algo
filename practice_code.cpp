#include<bits/stdc++.h>
using namespace std;
int add(int a,int b){
   return (a+b);
}
int main(){
   int n = 4;
   string s(n,'.');
   vector<string> board(n);
   for(int i=0;i<n;i++){
      board[i] = s;
   }
   for(auto &it:board){
      cout<<it<<" ";
   }
   // cout<<s<<endl;
   return 0;
}