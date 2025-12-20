#include <bits/stdc++.h>
using namespace std;
// vector<int> NGE(vector<int> &v)
// {
//     vector<int> nge(v.size());
//     stack<int> st;
//     for (int i = 0; i < v.size(); ++i)
//     {
//         while (!st.empty() && v[i] > v[st.top()])
//         {
//             nge[st.top()] == i;
//         }
//         st.push(i);
//         st.pop();
//     }b
//     while (!st.empty())
//     {
//         nge[st.top()] = -1;
//     }
//     return nge;
// }

vector<int> nextGreaterElement(vector<int> &nums){
    stack<int> st;
    vector<int> nge(nums.size(),-1);
    for(int i=nums.size()-1;i>=0;i--){
        while(!st.empty() && st.top()<=nums[i]) st.pop();
        if(!st.empty()){
            nge[i] = st.top();
        }
        st.push(nums[i]);
    }
    return nge;
}
int main()
{
    // code here
    /* 6
       4 5 2 25 7 8
    */
    int n;
    cin >> n;
    vector<int> v(n,0); // vector of size n
    for (auto i = 0; i < n; ++i)
    {
        cin >> v[i];
    }
    // vector<int> nge = NGE(v);
    vector<int> nge = nextGreaterElement(v);
    // for (int i = 0; i < n; ++i)
    // {
    //     cout << v[i] << " " << (nge[i] == -1 ? -1 : v[nge[i]]) << endl;
    // }
    for(auto &it:nge) cout<<it<<"";

    return 0;
}