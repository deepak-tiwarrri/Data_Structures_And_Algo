#include <bits/stdc++.h>
using namespace std;
long long int atMostKDistinctChar(string &s, int k)
{
   int r = 0, l = 0, count = 0;
   int ans = 0;
   // vector<int> charFreq(26,0);
   // while(r<s.size()){
   //    charFreq[s[r]-'a']++;
   //    if(charFreq[s[r]-'a']==1) count++;
   //    while(count>k){
   //       charFreq[s[l]-'a']--;
   //       if(charFreq[s[l]-'a']<=0) count--;
   //       l++;
   //    }
   //    ans+=(r-l+1);
   //    r++;
   // }
   // return ans;
   // both up and down code works for count of k distinct char
   unordered_map<char, int> mpp;
   while (r < s.size())
   {
      mpp[s[r]]++;
      if (mpp[s[r]] == 1)
         count++;
      while (count > k)
      {
         mpp[s[l]]--;
         if (mpp[s[l]] <= 0)
            count--;
         l++;
      }
      ans += (r - l + 1);
      r++;
   }
   return ans;
}
long long int countKDistinctChar(string &s, int k)
{
   return atMostKDistinctChar(s, k) - atMostKDistinctChar(s, k - 1);
}
int myAtoi(string s)
{
   // we will use the concept of character - 0 if it is
   // between 0 to 9 then it is integer if not then return
   // also use result = result*10 + s[i] for number greater than 10
   int i = 0, Min = INT_MIN, Max = INT_MAX;
   int sign = 1;
   long long strToInt = 0;
   while (i < s.size() && s[i] == ' ')
   {
      /* code */
      i++;
   }
   //check for sign here
   if(i<s.size() && (s[i]=='-' || s[i]=='+')){
      sign = s[i]=='-'?-1:1;
      i++;
   }
   while (i < s.size() && isdigit(s[i]))
   {
      strToInt = strToInt * 10 + s[i] - '0';
      if(strToInt<Min)return Min;
      if(strToInt>Max) return Max;
      i++;
   }
   return static_cast<int>(sign*strToInt);

}
int sumOfBeauty(string s) {
	// Write your code here.
	int sum = 0;
	// multiset<int> stt;
	for(int i=0;i<s.size();i++){
	   unordered_map<char,int> mpp;
	   int mini = INT_MAX,maxi = 0;
		for(int j=i;j<s.size();j++){
			mpp[s[j]]++;
         for(auto &it:mpp){
            mini = min(it.second,mini);
            maxi = max(it.second,maxi);
         }
         sum+= (maxi-mini);
		}
	}
	return sum;
}

int main()
{
   // code here
   string s;
   getline(cin, s);
   //  int k;
   //  cin>>k;
   //  long long int res  = countKDistinctChar(s,k);
   //  cout<<res;
   // int res = myAtoi(s);
   int res = sumOfBeauty(s);
   cout << res;
   return 0;
}