#include <bits/stdc++.h>
using namespace std;
int totalFruits(vector<int> &fruits)
{
   // your code goes here
   int n = fruits.size();
   int maxLen = 0;
   // for (int i = 0; i < n; i++)
   // {
   //    set<int> basketSet;
   //    for (int j = i; j < n; j++)
   //    {
   //       basketSet.insert(fruits[j]);
   //       if (basketSet.size() > 2)
   //          break;
   //       else
   //       {
   //          maxLen = max(maxLen, j - i + 1);
   //       }
   //    }
   // }
   int r =0,l=0;
   unordered_map<int,int> freqMap;
   while(r<n){
      freqMap[fruits[r]]++;
      if(freqMap.size()<=2){
         //if its within the window then find the maxLen
         maxLen = max(maxLen,r-l+1);
      }
      //if it's greater than 2 element in the basket
      //then remove the left elment and update the hashmap
      //below line is for better solutions
      // while(freqMap.size()>2){

      // }
      if(freqMap.size()>2){
         freqMap[fruits[l]]--;
         if(freqMap[fruits[l]]==0) freqMap.erase(fruits[l]);
         l++;
      }
      r++;
   }
   return maxLen;
}
int main()
{
   // code here
   int n;
   cin >> n;
   vector<int> fruits(n, 0);
   for (int i = 0; i < n; i++)
   {
      cin >> fruits[i];
   }
   int result = totalFruits(fruits);
   cout << result;
   return 0;
}