#include<bits/stdc++.h>
using namespace  std;
vector<int> nextSmallerElement(vector<int> &arr,int n){
   stack<int> st;
   vector<int> nse;
   for(int i=n-1;i>=0;i--){
      while(!st.empty() && arr[st.top()]>=arr[i]) st.pop();
      nse[i] = st.empty()?n:st.top();
      st.push(i);
   }
   return nse;
}
vector<int> prevSmallerEqualElement(vector<int> &arr,int n){
   stack<int> st;
   vector<int> psee;
   for(int i=0;i<n;i++){
      while(!st.empty() && arr[st.top()]>arr[i]) st.pop();
      psee[i] = st.empty()?-1:st.top();
      st.push(i);
   }
   return psee;
}
int sumOfSubMinimum(int n,vector<int> &arr){
   long total = 0;
   const int MOD = 10e9+7;
   vector<int> nSmallerEle = nextSmallerElement(arr,n);
   vector<int> pSmallerEqualEle = prevSmallerEqualElement(arr,n);
   for(int i=0;i<n;i++){
      int right = nSmallerEle[i]-i;
      int left = i-pSmallerEqualEle[i];
      total = static_cast<long long>(total+((right*left*arr[i])%MOD)%MOD);
   }
   return static_cast<int>(total);
}
int main(){
   //code here
    int n;
    cin>>n;
    vector<int> arr;
    for(int i=0;i<n;i++){
      int x;
      cin>>x;
      arr.push_back(x);
    }
    int res = sumOfSubMinimum(n,arr);
    cout<<res<<endl;
    for(auto &it:arr) cout<<it<<" ";
    return 0;

    return 0;
}