// //rotate string given string to achieve "goal" string 
// //we it is not matching goal string after ever rotate return false;
// //else return true;

// Given two strings s and goal, return true if and only if s can become goal after some number of shifts on s.
// A shift on s consists of moving the leftmost character of s to the rightmost position.
// For example, if s = "abcde", then it will be "bcdea" after one shift.
// Example 1
// Input : s = "abcde" , goal = "cdeab"
// Output : true
// Explanation : After performing 2 shifts we can achieve the goal string from string s.
// After first shift the string s is => bcdea
// After second shift the string s is => cdeab.


#include<bits/stdc++.h>
using namespace std;
bool rotateString(string &s,string goal){
    // if(s.length()!=goal.length()) return false;
    // for(int i=0;i<s.length();++i){
    //     //first i to n and add (0 to i)
    //     string rotated = s.substr(i) + s.substr(0,i);
    //     if(rotated==goal) return true;
    // }
    // return false;
    

    //optimal code
    //make the string double abcde+abcde = abcdeabcde
    //now find the goal in this string using find method 
    string doubleString = s+s;
    return doubleString.find(goal)!=string::npos;
}
int main(){
  
  //code here
    string s,goal;
    cin>>s>>goal;
    bool res = rotateString(s,goal);
    cout<<res<<endl;
  
  return 0;
}