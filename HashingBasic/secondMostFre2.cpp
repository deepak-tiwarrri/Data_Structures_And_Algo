#include <bits/stdc++.h>
using namespace std;
int secondMostFrequentElement(vector<int> &nums)
{

  // brute force approach
  unordered_map<int,int> mpp;
        for(auto &it:nums)
            mpp[it]++;
        }
        int maxFreq = 0,secMaxFreq = 0;
        int maxEle = -1,secMaxEle  = -1;
        for(auto &it:mpp){
            int freq = it.second;
            int ele = it.first;
            if(freq>maxFreq){
                secMaxFreq = maxFreq;
                maxFreq = freq;
                secMaxEle = maxEle;
                maxEle = ele;
            }else if(freq==maxFreq){
                maxEle = min(maxEle,ele);
            }else if(freq>secMaxFreq){
                secMaxFreq = freq;
                secMaxEle = ele;
            }else if(freq==secMaxFreq){
                //choose minimum
                secMaxEle = min(secMaxEle,ele);
            }
       }
       return secMaxEle;

  // return secMostFreElement;
}
int main()
{
  // code here
  int n;
  cin >> n;
  vector<int> nums;
  for (int i = 0; i < n; ++i)
  {
    int x;
    cin >> x;
    nums.push_back(x);
  }
  int res = secondMostFrequentElement(nums);
  cout << res;

  return 0;
}