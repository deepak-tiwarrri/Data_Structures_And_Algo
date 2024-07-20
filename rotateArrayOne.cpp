#include<bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int> &arr,int n){
    //1,1,2,3,3,4,5,5,5
    // set<int> st;
    // for(auto &it:arr){
    //     st.insert(it);
    // }
    // int index = 0;
    // //1,2,3,4,5
    // for(auto &val:st){
    //     arr[index] = val;
    //     index++;
    // }
    // return index;
    int i=0;
    for(int j=1;j<n;j++){
        if(arr[j]!=arr[i]){
            arr[i+1] = arr[j];
            i++;
        }
    }
    return i+1;
}
void leftRotateArrayOne(vector<int> &arr,int n){
    int temp = arr[0];
    for(int i=1;i<n;i++){
        arr[i-1] = arr[i];
    }
    arr[n-1] = temp;
}
void leftRotateArrayByK(vector<int> &arr,int k,int n){
    // reverse(arr.begin()+(n-k),arr.end());
    // reverse(arr.begin(),arr.begin()+(n-k));
    // reverse(arr.begin(),arr.end());
    k = k%n;
    vector<int> temp (k,0);
    int j=0;
    for(int i=n-k;i<n;i++){
        temp[j] = arr[i];
        j++;
    }
    for(int i=n-k-1;i>=0;i--){
        arr[i+k] = arr[i]; 
    }
    for(int i=0;i<k;i++){
        arr[i] = temp[i];
    }

}
int main(){
    
    int n,k;
    cin>>n>>k;
    vector<int> v1;
    for (int i = 0; i < n; i++)
    {
      int x;
      cin>>x;
      v1.push_back(x);
    }
    int d;
    cin>>d;
   //  int result = removeDuplicates(v1,v1.size());
   //  cout<<result<<endl;
    leftRotateArrayByK(v1,k,v1.size());
    // leftRotateArrayOne(v1,v1.size());
    for(auto &it:v1){
        cout<<it<<" ";
    }
    return 0;
}