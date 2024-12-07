#include <bits/stdc++.h>
using namespace std;
int nCr(int n, int r)
{
   long long res = 1;
   for (int i = 0; i < r; i++)
   {
      res = res * (n - i);
      res = res / (i + 1);
   }
   return static_cast<int>(res);
}
// int pascalTriangle(int n, int r)
// {
//    int element = nCr(n - 1, r - 1);
//    return element;
// }
vector<int> generateRow(int row)
{
   // this method will generate pascal number based on the row number
   //  and put into ans vector
   vector<int> ans;
   ans.push_back(1);
   long long res = 1;
   for (int i = 1; i < row; i++)
   {
      res = res * (row - i);
      res = res / i;
      ans.push_back(res);
   }
   return ans;
}
vector<vector<int>> pascalTriangle(int numRows)
{
   vector<vector<int>> ans;
   for (int i = 1; i <= numRows; i++)
   {
      ans.push_back(generateRow(i));
   }
   return ans;
}

int main()
{
   // code here
   int n;
   cin >> n;
   // vector<int> nums;
   // for (int i = 0; i < n; ++i)
   // {
   //    int x;
   //    cin >> x;
   //    nums.push_back(x);
   // }
   int r = 5;
   int c = 3;
   // int res = pascalTriangle(5, 3);
   vector<vector<int>> result = pascalTriangle(n);
   for (auto &it : result)
   {
      for (auto &it1 : it)
      {
         cout << it1 << " ";
      }
      cout << endl;
   }
   // cout << res;

   return 0;
}