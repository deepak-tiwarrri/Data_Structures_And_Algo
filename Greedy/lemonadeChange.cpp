#include <bits/stdc++.h>
using namespace std;
bool lemonadeChange(vector<int> &bills){
    int cnt5=0,cnt10=0;
    for(int i=0;i<bills.size();i++){
        if(bills[i]==5){
            cnt5++;
        }
        else if(bills[i]==10){
            if(cnt5>0){
                cnt10++;
                cnt5--;
            }else return false;
        }else{
            if(cnt10>=1 && cnt5>=1){
                cnt10--;
                cnt5--;
            }else if(cnt5>=3){
                cnt5 = cnt5-3;
            }else return false;
        }
    }
    return true;
}
int main() {
    // code here
   cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    bool isTrue = lemonadeChange(nums);
    if(isTrue) cout<<"possible";
    else cout<<"not possible";
    return 0;
}