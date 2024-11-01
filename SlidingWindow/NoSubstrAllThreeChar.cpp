// Given a string s , consisting only of characters 'a' , 'b' , 'c'.Find the number of substrings that contain at least one occurrence of all these characters 'a' , 'b' , 'c'.

// Example 1
// Input : s = "abcba"

// Output : 5

// Explanation : The substrings containing at least one occurrence of the characters 'a' , 'b' , 'c' are "abc" , "abcb" , "abcba" , "bcba" , "cba".

#include <bits/stdc++.h>
using namespace std;
int numberOfSubstrings(string &s)
{
    // brute force appraoch
    // make substring and find if all three are there or not
    //
    // int count =0;
    // // int hash[3];
    // for (int i = 0; i < s.size(); ++i)
    // {
    //      int hash[3] = {0};
    //     for(int j=i;j<s.size();++j){
    //         hash[s[j]-'a'] = 1;
    //         if(hash[0]+hash[1]+hash[2]==3){
                // count++;
                //can be optimed slighlity
                //if the string is bbacba
                //if bbac has all three then no need to count for rest of the 'ba'
                // count = count + (s.size()-j);
                // break;
                // count = count + (n-j);
                //break;
    //         }
    //     }
    // }
    // return count;
}
int main()
{
    // code here
    string s;
    cin >> s;
    int result = numberOfSubstrings(s);
    cout << result;

    return 0;
}