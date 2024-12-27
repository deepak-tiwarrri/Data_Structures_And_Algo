#include <bits/stdc++.h>
#define ll long long;
#define ld long double;
using namespace std;
void solve(){
    int n;
    cin>>n;

    vector<int> a1(n),b1(n);
    for(int i=0;i<n;i++) cin>>a1[i];
    for(int i=0;i<n;i++) cin>>b1[i];

    int res = a1.back();
    for(int i=1;i<n;i++){
        res+= max(0,a1[i-1]-b1[i]);
    }
    cout<<res<<endl;
    
}
int main() {
    // code here
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        solve();
    }

    return 0;
}