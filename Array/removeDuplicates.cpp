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

int main(){
    
    vector<int> v1 = {1,1,2,3,3,4,5,5,5};
    // int result = removeDuplicates(v1,v1.size());
    // cout<<result<<endl;
    leftRotateArrayOne(v1,v1.size());
    for(auto &it:v1){
        cout<<it<<" ";
    }
    return 0;
}