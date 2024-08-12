// You are given an integer array nums. The range of a subarray of nums is the difference between the largest and smallest element in the subarray.
// Return the sum of all subarray ranges of nums.
// A subarray is a contiguous non-empty sequence of elements within an array.

// Example 1:

// Input: nums = [1,2,3]
// Output: 4
// Explanation: The 6 subarrays of nums are the following:
// [1], range = largest - smallest = 1 - 1 = 0
// [2], range = 2 - 2 = 0
// [3], range = 3 - 3 = 0
// [1,2], range = 2 - 1 = 1
// [2,3], range = 3 - 2 = 1
// [1,2,3], range = 3 - 1 = 2
// So the sum of all ranges is 0 + 0 + 0 + 1 + 1 + 2 = 4.

#include <bits/stdc++.h>
using namespace std;
vector<int> nextGreaterElement(vector<int> &arr)
{
   stack<int> st;
   vector<int> nge(arr.size());
   for(int i=arr.size()-1;i>=0;i--){
      while(!st.empty() && arr[st.top()]<=arr[i]){
         st.pop();
      }
      nge[i] = st.empty()?arr.size():st.top();
      st.push(i);
   }
   return nge;
}
vector<int> prevGreaterEqualEle(vector<int> &arr){
   stack<int> st;
   vector<int> pgee(arr.size());
   for(int i=0;i<arr.size();i++){
      while(!st.empty() && arr[st.top()]<arr[i]){
         st.pop();
      }
      pgee[i] = st.empty()?-1:st.top();
      st.push(i);
   }
   return pgee;
}
int sumSubarrayMax(vector<int> &arr){
   // long long MOD = 1000000007;
   long long total = 0;
   vector<int> nextGreaterEle = nextGreaterElement(arr);
   vector<int> prevGreaterEqEle = prevGreaterEqualEle(arr);
   for(int i=0;i<arr.size();i++){
      int right = nextGreaterEle[i]-i;
      int left = i-prevGreaterEqEle[i];
      long long freq = (right*left*1LL);
      long long val = (freq*arr[i]*1LL);
      total= (total+val);
   }
   return (total);
}
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
   // long long MOD = 1000000007;
   int n = arr.size();
   vector<int> nse = nextSmallerElement(arr);
   vector<int> psmallerEqual = prevSmallerEqualEle(arr);
   for (int i = 0; i < n; i++)
   {
      int right = nse[i] - i;
      int left = i - psmallerEqual[i];
      long long freq = (right * left * 1LL);
      long long val = (freq * arr[i] * 1LL);
      sum = (sum + val);
   }
   return (sum);
}
long long subArrayRanges(vector<int> &nums)
{
   return sumSubarrayMax(nums)-sumSubarrayMins(nums);
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
   int res = subArrayRanges(arr);
   cout << res << endl;
   for (auto &it : arr)
      cout << it << " ";

   return 0;
}