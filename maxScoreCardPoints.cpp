#include <bits/stdc++.h>
using namespace std;
int maxScore(vector<int> &cardPoints, int k)
{
   int sum =0,leftSum=0,rightSum=0;
   for(int i=0;i<k;i++) leftSum+= cardPoints[i];
   //leftsum = 6
   if(k==cardPoints.size()) return leftSum;
   sum = leftSum;
   int rightIndex = cardPoints.size()-1;
   while(k>=0){
      leftSum-= cardPoints[k];
      //sum = 3
      rightSum+=cardPoints[rightIndex];//rightSum = 1
      rightIndex--;
      sum = max(rightSum+leftSum,sum);
      k--;
   }
   return sum;

}
//total fruits

  int totalFruits(int N, vector<int> &fruits) {
        int maxLen=0;
      unordered_map<int,int> mpp;
      int r = 0,l = 0;
      while(r<N){
            mpp[fruits[r]]++;
            if(mpp.size()>2){
               while (mpp.size()>2)
               {
                  mpp[fruits[l]]--;
                  if(mpp[fruits[l]]==0)mpp.erase(fruits[l]);
                  l++;
               }
               
            }
            if(mpp.size()<=2) maxLen = max(maxLen,r-l+1);
            r++;
         }
         return maxLen;
         // if(mpp.find(fruits[r])==mpp.end()){
         //    if(mpp.size()<=k){
         //       mpp[fruits[r]]++;
         //       maxLen = max(maxLen,r-l+1);
         //    }else{
         //       mpp[fruits[l]]--;
         //       if(mpp[fruits[l]]==0) mpp.erase(fruits[l]);
         //    }
         // }else{
         //    if(mpp.size()<=k){
         //       maxLen = max(maxLen,r-l+1);
         //    }
         // }
         // mpp[fruits[r]]++;
         // r++;
           //   for(int i=0;i<fruits.size();i++){
      //    unordered_set<int> stt;
      //       for(int j=i;j<fruits.size();j++){
      //          stt.insert(fruits[j]);
      //           if(stt.size()<=2){
      //               maxLen = max(maxLen,j-i+1);
      //           }else break;
      //       }

      //   }
    }
int main()
{
   // code here
   int n, k;
   cin>>n;
   vector<int> nums(n, 0);
   for (int i = 0; i < n; i++)
   {
      int x;
      cin >> x;
      nums.push_back(x);
   }
   // int res = maxScore(nums, k);
   int res = totalFruits(n,nums);
   cout << res << endl;

   return 0;
}