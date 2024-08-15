#include <bits/stdc++.h>
using namespace std;
class StockSpanner
{
public:
   int indx = -1;
   stack<pair<int, int>> st;
   // stack<int> st;
   // vector<int> arr;
   // int cnt =1;
   StockSpanner()
   {
      // brute force approach
      indx = -1;
      while (!st.empty())
      {
         st.pop();
      }
   }

   int next(int price)
   {
      // find the next greater element
      // brute force approach
      // arr.push_back(price);
      // for(int i=arr.size()-2;i>=0;i--){

      //    if(arr[i]<=price) cnt++;
      //    else break;
      // }
      // return cnt;
      indx = indx + 1;
      while (!st.empty() && st.top().first <= price)
         st.pop();
      int ans = indx - (st.empty() ? -1 : st.top().second);
      st.push({price, indx});
      return ans;
   }
   vector<int> stockSpan(vector<int> prices, int n)
   {
      vector<int> ans;
      stack<pair<int, int>> st;
      //it has same logic of above one but 
      // here one thing can be changed
      // prices[st.top()]<=prices[i] and push(i);
      // so don't have to make pair of stack only stack<int> st;
      //find the previous greater element indx and subtract it from given number index
      for (int i = 0; i < n; i++)
      {
         while (!st.empty() && st.top().first <= prices[i])
         {
            st.pop();
         }
         int res = i - (!st.empty() ? st.top().second : -1);
         ans.push_back(res);
         st.push({prices[i], i});
      }
      return ans;
   }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
int main()
{
   // code here
   StockSpanner sp;
   int res = sp.next(100);
   cout << res << endl;
   res = sp.next(80);
   cout << res << endl;
   res = sp.next(60);
   cout << res << endl;
   res = sp.next(70);
   cout << res << endl;
   res = sp.next(60);
   cout << res << endl;
   res = sp.next(75);
   cout << res << endl;
   res = sp.next(85);
   cout << res << endl;

   return 0;
}