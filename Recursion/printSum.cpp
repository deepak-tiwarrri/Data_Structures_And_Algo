#include <bits/stdc++.h>
using namespace std;

void reverseArray(int i, int arr[], int n)
{
   // if(l>=r) return;
   // swap(arr[l],arr[r]);
   // reverseArray(l+1,r-1,arr);
   if (i >= n / 2)
      return;
   swap(arr[i], arr[n - i - 1]);
   reverseArray(i + 1, arr, n);
}

void printSum(int i, int arr[], int n, int k, vector<int> &ds, int sum)
{
   if (i == n)
   {
      // print the ds
      if (sum == k)
      {
         for (auto &it : ds)
            cout << it << " ";
         cout << endl;
      }
      return;
   }
   sum += arr[i];
   ds.push_back(arr[i]);
   printSum(i + 1, arr, n, k, ds, sum);
   sum -= arr[i];
   ds.pop_back();
   printSum(i + 1, arr, n, k, ds, sum);
}

bool printOnlyOneSubsequence(int i, int arr[], int n, int k, vector<int> &ds, int sum)
{
   if (i == n)
   {
      if (sum == k)
      {
         for (auto &it : ds)
            cout << it << " ";
         cout << endl;
         return true;
      }
      else
      {
         return false;
      }
   }
   sum += arr[i];
   ds.push_back(arr[i]);
   if (printOnlyOneSubsequence(i + 1, arr, n, k, ds, sum) == true)
   {
      return true;
   }
   sum -= arr[i];
   ds.pop_back();
   if (printOnlyOneSubsequence(i + 1, arr, n, k, ds, sum) == true)
   {
      return true;
   }
   return false;
}
void mergeArray(int low, int mid, int high, int arr[])
{
   vector<int> temp;
   int left = low;
   int right = mid + 1;
   while (left <= mid && right <= high)
   {
      if (arr[left] <= arr[right])
      {
         temp.push_back(arr[left]);
         left++;
      }
      else
      {
         temp.push_back(arr[right]);
         right++;
      }
   }
   while (left <= mid)
   {
      temp.push_back(arr[left]);
      left++;
   }
   while (right <= high)
   {
      temp.push_back(arr[right]);
      right++;
   }
   for (int i = low; i <= high; i++)
   {
      arr[i] = temp[i - low];
   }
}
void mS(int low, int high, int arr[])
{
   if (low == high)
      return;
   int mid = (low + high) / 2;
   mS(low, mid, arr);
   mS(mid + 1, high, arr);
   mergeArray(low, mid, high, arr);
}
void mergeSort(int arr[], int n)
{
   mS(0, n - 1, arr);
}
int findPivotIndex(int low, int high, int arr[], int n)
{
   int pivot = arr[low];
   int i = low;
   int j = high;
   while (i < j)
   {
      while (arr[i] <= pivot && i <= high)
      {
         i++;
      }
      while (arr[j] > pivot && j >= low)
      {
         j--;
      }
      if (i < j)
         swap(arr[i], arr[j]);
   }
   swap(arr[low], arr[j]);
   return j;
}
void quickSort(int arr[], int n, int low, int high)
{
   if (low < high)
   {

      int pivotIndex = findPivotIndex(low, high, arr, n);
      quickSort(arr, n, low, pivotIndex - 1);
      quickSort(arr, n, pivotIndex + 1, high);
   }
}
void combSum(vector<int> &candidates, int target, vector<vector<int>> &sumOfComb, vector<int> &ds, int indx)
{
   if (indx == candidates.size())
   {
      if (target == 0)
      {
         sumOfComb.push_back(ds);
         return;
      }
      else
         return;
   }
   if (candidates[indx] <= target)
   {
      ds.push_back(candidates[indx]);
      combSum(candidates, target-candidates[indx], sumOfComb, ds, indx);
      ds.pop_back();
   }
   combSum(candidates, target, sumOfComb, ds, indx+1);
}
vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
   vector<vector<int>> sumOfComb;
   vector<int> ds;
   combSum(candidates, target, sumOfComb, ds, 0);
   return sumOfComb;
}

int main()
{
   // code here
   int n, target;
   cin >> n >> target;
   // int arr[n];
   vector<int> arr(n, 0);
   for (int i = 0; i < n; i++)
      cin >> arr[i];
   //  reverseArray(0,arr,n);
   // mergeSort(arr,n);
   // quickSort(arr, n, 0, n - 1);
   // for (auto &it : arr)
   //    cout << it << " ";
   // vector<int> ds;
   // printSum(0,arr,n,k,ds,0);
   // printOnlyOneSubsequence(0,arr,n,k,ds,0);
   vector<vector<int>> ans = combinationSum(arr, target);
   for (auto &it : ans)
   {
      for (auto &el : it)
         cout << el << " ";
      cout << endl;
   }
   return 0;
}