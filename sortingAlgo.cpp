#include<bits/stdc++.h>
using namespace std;

int findPivotAndSort(vector<int> &v,int low, int high) {
   int pivotElement= v[low];//make first element as pivotElement
   //now make two pointer start and end
   int i = low;
   int j = high;
   //if i<j loop,and find the first greater element 
   //from left and first smallest element at right and 
   //after finding swap them
   while(i<j) {
      while(v[i]<=pivotElement && i<=high-1)
         i++;
      while(v[j]>pivotElement && j>=low)
         j--;
      if(i<j)
         swap(v[i], v[j]);
   }
   swap(v[low], v[j]);
   return j;
}
void quickSortMain(vector<int> &v,int low,int high) {
   if(low<high){
      int pivotIndex = findPivotAndSort(v,low,high);
      quickSortMain(v,low,pivotIndex-1);
      quickSortMain(v,pivotIndex+1,high);
   }
}
void quickSort(vector<int> &v,int n){
   quickSortMain(v, 0, n - 1);
}
void selectionSort(vector<int> &v,int n){

   for(int i=0;i<n-2;i++){
      int mini = i;
      for(int j=i;j<=n-1;j++){
         if(v[j]<v[mini])
            mini = j;
      }
      swap(v[mini], v[i]);
   }
}
void recursiveBubble(vector<int> &v,int n){
   if(n==1) return;
   for (int j = 0; j < n-2; j++)
   {
      if(v[j]>v[j+1]){
         int temp = v[j];
         v[j] = v[j+1];
         v[j+1] = temp;
      }
   }
   
   recursiveBubble(v,n-1);
}
void bubbleSort(vector<int> &v,int n){

   // for (int i = n - 1; i >= 0; i--)
   // {
   //    int didSwap = 0;
   //    for (int j = 0; j <=i-1; j++)
   //    {
   //       if (v[j]>v[j+1])
   //       {
   //          swap(v[j], v[j + 1]);
   //          didSwap = 1;
   //       }
         
   //    }
   //    if(didSwap==0)
   //       break;

   //    cout << "runs\n";
   // }

   for (int i = 1; i < n; i++)
   {
      int didSwap = 0;
      for (int j = 0; j < n-i; j++)
      {
         if(v[j]>v[j+1])
         {
               swap(v[j], v[j + 1]);
               didSwap = 1;
         }
      }
      if(didSwap==0) break;
      cout << "Runs\n";
   }
   
}

void insertionSort(vector<int> &v,int n){
   for (int i = 0;i<=n-1;i++){
      // for (int j = i; j >0; j--)
      // {
      //    if(v[j-1]>v[j])
      //       swap(v[j - 1], v[j]);
      // }
      int j=i;
      int didSwap = 0;
      while(j>0 && v[j-1]>v[j]){
         swap(v[j-1],v[j]);
         didSwap = 1;
         j--;
      }
      if(didSwap==0)
         break;
   }
}
void mergeArray(vector<int> &v,int low,int mid,int high){
   int left = low;
   int right = mid + 1;
   vector<int> temp;
   while(left<=mid && right<=high){
      if(v[left]<=v[right]){
         temp.push_back(v[left]);
         left++;
      }else{
         temp.push_back(v[right]);
         right++;
      }
   }
   while(left<=mid){
       temp.push_back(v[left]);
         left++;
   }
   while(right<=high){
      temp.push_back(v[right]);
      right++;
   }
   for (int i = low; i <= high;i++){
      v[i] = temp[i - low];
   }
}
void mergeSortFun(vector<int> &v,int low,int high){
   if(low>=high)
      return;
   int mid = (low+high)/2;
   mergeSortFun(v, low, mid);
   mergeSortFun(v, mid + 1, high);
   mergeArray(v,low,mid,high);
}

void mergeSort(vector<int> &v,int n){
   mergeSortFun(v, 0, n - 1);
}
int main(){
   int n;
   cin>>n;
   vector<int> v1(n);
   for(auto &it:v1)
      cin >> it;

   // selectionSort(v1, n);
   // bubbleSort(v1, n);
   // cout << "Ouput is \n";
   // insertionSort(v1,n);
   // mergeSort(v1, n);
   quickSort(v1, n);
   for(auto &it:v1)
      cout << it << " ";

  return 0;
};