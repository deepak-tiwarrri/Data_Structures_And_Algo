#include <bits/stdc++.h>
using namespace std;
int celebrity(vector<vector<int>> &mat)
{
   // code here
   int n = mat.size();
   // vector<int> Iknow(n,0);
   // vector<int> KnowMe(n,0);
   // for(int i=0;i<n;i++){
   //    for(int j=0;j<n;j++){
   //       // if(i==j) continue;
   //       if(mat[i][j]=1){
   //          Iknow[i]++;
   //          KnowMe[j]++;
   //       }
   //    }
   // }
   // for(int i=0;i<n;i++){
   //    if(Iknow[i]==0 && KnowMe[i]==n-1) return i;
   // }
   // return -1;
   int top=0,down=n-1;
   while(top<down){
      if(mat[top][down]==1) top = top+1;
      else if(mat[down][top]==1) down = down-1;
      else{
         top = top+1;
         down = down-1;
      }
   }
   if(top>down) return -1;
   for(int i=0;i<n;i++){
      if(top==i) continue;
      if(mat[top][i]==0 && mat[i][top]==1) continue;
      else return -1;

   }
   return top;
}
int main()
{
   // code here
   int m;
   vector<vector<int>> mat(m, vector<int>(m, 0));
   for (int i = 0; i < m; i++)
   {
      for (int j = 0; j < m; j++)
      {
         cin>>mat[i][j];
      }
   }
   int res = celebrity(mat);
   cout << res << endl;

   return 0;
}