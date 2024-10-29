#include<bits/stdc++.h>
using namespace  std;
int maxScore(vector<int> &cardScore,int k){
   int leftSum = 0,rightSum = 0;
   int maxSum  =0;
   int rIndex = cardScore.size()-1;
   for(int i=0;i<k;i++) {
      leftSum+= cardScore[i];
      maxSum = max(maxSum,leftSum);
   }
   for(int i=k-1;i>=0;i--){
      leftSum-= cardScore[i];
      rightSum += cardScore[rIndex];
      rIndex--;
      maxSum = max(maxSum,leftSum+rightSum);
   }
   return maxSum;
}
int main(){
   //code here
    int n,k;
    cin>>n>>k;
    vector<int> cardScore;
    for(int i=0;i<n;i++){
      int x;
      cin>>x;
      cardScore.push_back(x);
    }
    int res = maxScore(cardScore,k);
    cout<<res;

    return 0;
}