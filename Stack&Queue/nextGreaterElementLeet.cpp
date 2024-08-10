#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
{
   stack<int> st;
   vector<int> nge(nums1.size(), -1);
   unordered_map<int, int> ngeMap;
   for (int i = nums2.size() - 1; i >= 0; i--)
   {
      while (!st.empty() && st.top() <= nums2[i])
         st.pop();
      ngeMap[nums2[i]] = st.empty()?-1:st.top();
      st.push(nums2[i]);
   }
   for (int i = 0; i < nums1.size(); i++)
   {
      if (ngeMap.find(nums1[i]) != ngeMap.end())
         nge[i] = ngeMap[nums1[i]];
   }
   return nge;
}
vector<int> nextGreaterElementsII(vector<int> &nums)
{
   vector<int> nge(nums.size());
   stack<int> st;
   for (int i = 2 * nums.size() - 1; i >= 0; i--)
   {
      while (!st.empty() && st.top() <= nums[i % nums.size()])
         st.pop();
      if (i < nums.size())
      {
         nge[i % nums.size()] = st.empty() ? -1 : st.top();
      }
      st.push(nums[i % nums.size()]);
   }
   return nge;
}
int main()
{
   // code here
   int n1, n2;
   cin >> n1 >> n2;
   vector<int> arr1(n1), arr2(n2); // vector of size n
   for (int i = 0; i < n1; i++)
   {
      cin >> arr1[i];
   }
   for (int i = 0; i < n2; i++)
      cin >> arr2[i];
   vector<int> res = nextGreaterElementsII(arr2);
   for (auto &it : res)
      cout << it << " ";
   return 0;
}