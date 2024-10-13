#include <bits/stdc++.h>
using namespace std;
// but this code doesn't account for duplicates
// it also print the duplicate permutation
// if duplicate permutation is not allowed then use the
// hashset and store the string/array in it after that
// transfer it into ans vector of vector
void findPermutations(vector<int> &vec, vector<int> &freq, vector<int> &ds, vector<vector<int>> &ans)
{
   if (vec.size() == ds.size())
   {
      ans.push_back(ds);
      return;
   }
   for (int i = 0; i < vec.size(); i++)
   {
      if (!freq[i])
      {
         freq[i] = 1;
         ds.push_back(vec[i]);
         findPermutations(vec, freq, ds, ans);
         ds.pop_back();
         freq[i] = 0;
      }
   }
}
void findPermutationIIApproach(vector<int> &vec, vector<vector<int>> &ans, int indx)
{
   if (indx == vec.size())
   {
      ans.push_back(vec);
      return;
   }
   for (int i = indx; i < vec.size(); i++)
   {
      swap(vec[indx], vec[i]);
      findPermutationIIApproach(vec, ans, indx+1);
      swap(vec[indx], vec[i]);
   }
}
vector<vector<int>> permutations(vector<int> &vec, int size)
{
   // Write your code here.
   vector<vector<int>> ans;
   vector<int> ds;
   vector<int> freq(size, 0);
   // findPermutations(vec, freq, ds, ans);
   findPermutationIIApproach(vec, ans, 0);
   return ans;
}

int main()
{
   // code here
   int n;
   cin >> n;
   vector<int> arr(n, 0);
   for (auto &it : arr)
      cin >> it;

   vector<vector<int>> res = permutations(arr, n);
   for (auto &el : res)
   {
      for (auto &it : el)
         cout << it << " ";
      cout << endl;
   }

   return 0;
}