#include <bits/stdc++.h>
using namespace std;

bool bouquetsRequired(int day, vector<int> &nums, int k, int m)
{
   int noOfBouquet = 0;
   int cnt = 0;
   for (int i = 0; i < nums.size(); i++)
   {
      if (day >= nums[i])
      {
         cnt++;
      }
      else
      {
         noOfBouquet += (cnt / k);
         cnt = 0;
      }
   }
   // atlast calculate the count
   noOfBouquet += (cnt / k);
   if (noOfBouquet >= m)
      return true;
   else
      return false;
}
int roseGarden(int n, vector<int> nums, int k, int m)
{

   // for (int i = minEle; i <= maxEle; i++)
   // {
   //    /* code */
   //    if (bouquetsRequired(i, nums, k, m) == true)
   //       return i;
   // }
   // return -1;

   if (k * m > nums.size())
      return -1;
   int minEle = *min_element(nums.begin(), nums.end());
   int maxEle = *max_element(nums.begin(), nums.end());
   int low = minEle,high= maxEle;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(bouquetsRequired(mid,nums,k,m)==true){
           high = mid-1;it sgit
        }else{
          low = mid+1;
        }
    }
    return low;
}
int main()
{
   // code here
   int n, m, k;
   cin >> n >> m >> k;
   vector<int> nums;
   for (int i = 0; i < n; ++i)
   {
      int x;
      cin >> x;
      nums.push_back(x);
   }
   int res = roseGarden(n, nums, k, m);
   cout << res << endl;

   return 0;
}