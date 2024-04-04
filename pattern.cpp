#include<bits/stdc++.h>
using namespace  std;

void print1(int n){
  //0  *
  //1 ** 
  //2 ***
  //3 ****
  for(int i=0;i<n;i++){
      for(int j=0;j<i;j++){
          cout<<"* ";
      }
      cout<<endl;
  }
}

int main(){
   //code here
    print1(5);
    return 0;
}
