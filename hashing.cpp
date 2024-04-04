#include<bits/stdc++.h>
using namespace  std;
int main(){
    //code here
    // int n;
    // cin>>n;
    // int arr[n];
    // for(int i=0;i<n;i++){
    //     cin>>arr[i];
    // }
    // int hash[13] = {0};
    // for(int i=0;i<n;i++){
    //     hash[arr[i]]+=1;
    // }

    // int q;
    // cin>>q;
    // while (q--)
    // {
    //     int x;
    //     cin>>x;
    //     cout<<hash[x]<<endl;
    // }

    int n;
    cin>>n;//n is size of string
    string s;
    cin>>s;

    //precompute
    int hash[26] = {0};
    for(int i=0;i<n;i++){
        hash[s[i]-'a']++;
    }
    int q;
    cin>>q;
    while(q--){
        char ch;
        cin>>ch;
        //fetch the hash
        cout<<hash[ch-'a']<<endl;
    }

    
    return 0;
}


