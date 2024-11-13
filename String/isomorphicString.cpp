#include <bits/stdc++.h>
using namespace std;
// Given two strings s and t, determine if they are isomorphic. Two strings s and t are isomorphic if the characters in s can be replaced to get t.

// All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself

// Input : s = "egg" , t = "add"
// Output : true
// Explanation : The 'e' in string s can be replaced with 'a' of string t.
// The 'g' in string s can be replaced with 'd' of t.
// Hence all characters in s can be replaced to get t.

bool isomorphicString(string s, string t)
{
   // code here
   // map first string to second and second to first
   // e->a and a->e
   // g->d and d->g
   // for s = "apple" and t="bbnbm"
   // a->b and b->a || p->b and but b is already map to a

   int sMap[256] = {0}, tMap[256] = {0};
   for (int i = 0; i < s.length(); ++i)
   {
      // map the element
      if (sMap[s[i]] != 0 || tMap[t[i]] != 0)
      {
         // it means that element is already there in map
         // now if already there element then check for
         if (sMap[s[i]] != t[i] + 1 || tMap[t[i]] != s[i] + 1)
         {
            return false;
         }
      }
      sMap[s[i]] = t[i] + 1;
      tMap[t[i]] = s[i] + 1; //+1 is because if encouter ascii value of '0' then it should not be recognized because intially all values are zero
   }
   return true;
}
int main()
{
   // code here
   string s, t;
   cin >> s >> t;
   bool isIsomorphic = isomorphicString(s, t);
   cout << isIsomorphic << endl;

   return 0;
}