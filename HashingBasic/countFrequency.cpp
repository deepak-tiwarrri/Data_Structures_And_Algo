#include <bits/stdc++.h>
using namespace std;
// brute force approach
// vector<pair<int,int>> countFreq(vector<int> &arr,int n){
//     vector<bool> visited(n,false);
//     vector<pair<int,int>> ans;
//     for(int i=0;i<n;i++){
//         if(visited[i]==true)continue;
//         int count=1;
//         for(int j=i+1;j<n;j++){
//             if(arr[i]==arr[j]){
//                 count++;
//                 visited[j]=true;
//             }
//         }
//       ans.push_back({arr[i],count});
//     }
//     return ans;
// }
// find that element which has maximum occuring and if both are same
// for example if 1,4 both occur two times
// then print the smaller one
int mostFrequentElement(vector<int> &nums)
{
    // int visited[10001] = {0};
    // int n = nums.size();
    // int maxCount = 0;
    // int el = -1;
    // for (int i = 0; i < n; i++)
    // {
    //     int count = 0;
    //     if (visited[nums[i]] == 0)
    //     {
    //         visited[nums[i]] = 1;
    //         for (int j = 0; j < n; j++)
    //         {
    //             if (nums[i] == nums[j])
    //             {
    //                 count++;
    //             }
    //         }
    //         if (maxCount < count)
    //         {
    //             maxCount = count;
    //             el = nums[i];
    //         }
    //         else if (maxCount == count )
    //         {
    //             el = min(el,nums[i]);
    //         }
    //     }
    // }
    // return el;
    unordered_map<int,int> mpp;
    int maxOccurence = 0;
    int result = -1;
    for (auto &it : nums)
    {
        mpp[it]++;
    }
    for(auto &it:mpp){
        if(it.second>maxOccurence){
            maxOccurence= it.second;
            result = it.first; 
        }else if(it.second ==maxOccurence){
            result = min(result,it.first);
        }
    }
    return result;
    
}
int main()
{

    int n;
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr.push_back(x);
    }
    // vector<pair<int,int>> res = countFreq(arr,n);
    // for (int i = 0; i < res.size(); i++)
    // {
    //     cout<<res[i].first<<"-> "<<res[i].second<<endl;
    // }

    int res = mostFrequentElement(arr);
    cout << res << endl;
}