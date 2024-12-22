#include <bits/stdc++.h>
using namespace std;
char nextGreatestLetter(vector<char> &letters,char x){
    int low = 0,high = letters.size()-1;
    int ans = letters.size();
    while(low<=high){
        int mid = low + (high-low)/2;
        //find the first number greater than x;
        if((letters[mid]-'a')>(x-'a')){
            ans = letters[mid]-'a';
            high = mid-1;
        }else{
            low = mid+1;
        }
    }
    if(ans==letters.size()) return letters[0];
    return ans+'a';
    
}
int main() {
    // code here
    int n;
    char target;
    cin>>n>>target;
    vector<char> letter;
    for(int i=0;i<n;i++){
        char x;
        cin>>x;
        letter.push_back(x);
    }
    char res = nextGreatestLetter(letter,target);
    cout<<res;

    return 0;
}
