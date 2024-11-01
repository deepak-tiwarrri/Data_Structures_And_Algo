// Input : s = "BAABAABBBAAA" , k = 2
// Output : 6
// Explanation : we can change the B present at index 0 , 3 (0 base indexing) to A.
// The new string is "AAAAAABBBAAA".
// The substring "AAAAAA" is the longest substring having same letter with length 6.

#include<bits/stdc++.h>
using namespace  std;
int characterReplacement(string s,int k){
    int n = s.size();
    int maxLen = 0;
    // for(int i=0;i<s.size();++i){
    //     int hash[26] = {0};
    //     int maxFreq = 0;
    //     for(int j=i;j<s.size();++j){
    //         hash[s[j]-'A']++;
    //         maxFreq = max(maxFreq,hash[s[j]-'A']);
    //         if((j-i+1)-maxFreq<=k){
    //             maxLen = max(maxLen,j-i+1);
    //         }else{
    //             break;
    //         }   
    //     }
    // }

    int r = 0,l=0;
    int hash[26] = {0};
    int maxFreq = 0;
    while(r<n){
        hash[s[r]-'A']++;
        maxFreq = max(maxFreq,hash[s[r]-'A']);
        if((r-l+1)-maxFreq>k){
            // for(int i=0;i<26;++i) maxFreq = max(maxFreq,hash[s[i]]);
            hash[s[l]-'A']--;
            l++;
        }
        maxLen = max(maxLen,r-l+1);
        r++;
    }
    return maxLen;
    //TC: O(n) and if we use while loop then O(2*n)
}
int main(){
   //code here
    string s;
    int k;
    cin>>s>>k;
    int res = characterReplacement(s,k);
    cout<<res<<endl;

    return 0;
}