#include <bits/stdc++.h>
using namespace std;
vector<int> nextSmallerElement(vector<int> &arr)
{
   stack<int> st;
   int n = arr.size();
   vector<int> nse(n);
   for (int i = n - 1; i >= 0; i--)
   {
      while (!st.empty() && arr[st.top()] >= arr[i])
      {
         st.pop();
      }
      nse[i] = st.empty() ? n : st.top();
      st.push(i);
   }
   return nse;
}
vector<int> prevSmallerEqualEle(vector<int> &arr)
{
   stack<int> st;
   int n = arr.size();
   vector<int> psee(n);
   for (int i = 0; i < n; i++)
   {
      while (!st.empty() && arr[st.top()] > arr[i])
      {
         st.pop();
      }
      psee[i] = st.empty() ? -1 : st.top();
      st.push(i);
   }
   return psee;
}
int sumSubarrayMins(vector<int> &arr)
{
   long long sum = 0;
   long long MOD = 1000000007;
   int n = arr.size();
   vector<int> nse = nextSmallerElement(arr);
   vector<int> psmallerEqual = prevSmallerEqualEle(arr);
   for (int i = 0; i < n; i++)
   {
      int right = nse[i] - i;
      int left = i - psmallerEqual[i];
      long long freq = (right * left * 1LL);
      int val = (freq * arr[i] * 1LL) % MOD;
      sum = (sum + val) % MOD;
   }
   return static_cast<int>(sum);
}
//brute force appraoch
int findSumOfSubMin(vector<int> &arr)
{
   int sum = 0;
   for(int i=0;i<arr.size();i++){
      int mini = arr[i];
      for(int j=i;j<arr.size();j++){
         mini = min(mini,arr[j]);
         sum += mini;
      }
   }
   return sum;
}
int main()
{
   // code here
   int n;
   cin >> n;
   vector<int> arr;
   for (int i = 0; i < n; i++)
   {
      int x;
      cin >> x;
      arr.push_back(x);
   }
   // int res = sumSubarrayMins(arr);
   int res = findSumOfSubMin(arr);
   cout << res << endl;
   for (auto &it : arr)
      cout << it << " ";

   return 0;
}