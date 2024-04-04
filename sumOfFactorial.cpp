#include <bits/stdc++.h>
using namespace std;
void multiply(vector<int> &nums, int &size, int multiplier)
{
   int carry = 0;
   nums[0]  = 1;
   for(int i=0;i<size;i++){
      int result = nums[i]*multiplier;
      result = result+carry;
      nums[i] = result%10;
      carry /=10;
   }
   while(carry>0){
      nums[size] = carry%10;
      size++;
      carry = carry/10;
   }  
}
vector<int> findFactorial(int n)
{
   vector<int> nums(10000, 0);
   int size = 1;
   int fact = n;
   nums[0] = 1;
   vector<int> result;
   for (int multiplier = 2; multiplier <= fact; multiplier++)
   {
      multiply(nums, size, n);
   }
   for (int i = size - 1; i >= 0; i--)
   {
      result.push_back(nums[i]);
   }
   return result;
}
int factorialDigitSum(int n)
{
   int sum =0;
   vector<int> factorials = findFactorial(n);
   for(int i=0;i<factorials.size();i++){
      sum = sum +  factorials[i];
   }
   return sum;
}
int main()
{
   // code here
   int ans = factorialDigitSum(10);
   cout << ans;  

   return 0;
}