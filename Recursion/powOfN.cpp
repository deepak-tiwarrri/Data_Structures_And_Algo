#include <bits/stdc++.h>
using namespace std;
double myPow(double x, int n)
{
    //brute force approach TC:O(n)
    // double ans = 1.0;
    //if(n<0){
        // n = -1*n;
        // x = 1/x;
    // }
    // for(int i=0;i<n;i++){
    //     ans = ans*x;
    // }
    // return ans;
    
    //brute force iterative approachh
    if(n<0){
        x = 1/x;
        n = -1*n;
    }
    double ans = 1;
    long num = n;
    //made long num cause -1*INT_MIN is out of bound of integer max value
    while(num>0){
        if(num%2==1){
            ans = ans*x;
            //reduced n by 1 ifprevious was 49 then make 48
            num = num-1;
        }else{
            x = x*x;
            num = num/2;
        }
    }
    return ans;
    
}
int main()
{
    // code here
    // std::cout<<myPow(2.0000,10);
        double x;
        int n;
        cin>>x>>n;
        double res = myPow(x,n);
        cout<<res<<endl;

    // cout<<"Hello world";
    // return 0;
}