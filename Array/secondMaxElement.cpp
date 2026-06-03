#include <iostream>
#include <vector>
using namespace std;

// Function to find the second maximum element in the array
int secondMaxElement(const vector<int> &arr)
{
   // TODO: Implement this function
   int maxEle = INT_MIN;
   int secondMaxEle = INT_MIN;
   for (auto &ele : arr)
   {
      maxEle = max(maxEle, ele);
   }
   for (auto &ele : arr)
   {
      if (ele > secondMaxEle && ele != maxEle)
      {
         secondMaxEle = ele;
      }
   }
   return secondMaxEle == INT_MIN ? -1 : secondMaxEle; // Placeholder return
}
//optimal approach using single pass
int secondMaxElementII(vector<int> &nums){
   int maxEle = INT_MIN;
   int secondMaxEle = -1;
   for(auto &ele:nums){
      if(ele>maxEle){
         secondMaxEle = maxEle;
         maxEle = ele;
      }else if(ele>=secondMaxEle && ele<maxEle) secondMaxEle = ele;
   }
   // return secondMaxEle==INT_MIN?-1:secondMaxEle;
   return secondMaxEle;
}

int main()
{
   int n;
   cin >> n;

   vector<int> arr(n);
   for (int i = 0; i < n; ++i)
   {
      cin >> arr[i];
   }

   // int result = secondMaxElement(arr);
   int result = secondMaxElementII(arr);
   cout << result << endl;
   return 0;
}