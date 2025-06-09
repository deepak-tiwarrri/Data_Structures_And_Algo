#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int> &arr, int n)
{
    // 1,1,2,3,3,4,5,5,5
    // set<int> uniqueNoSet;
    // for (auto &it : arr)
    // {
    //     uniqueNoSet.insert(it);
    // }
    // int index = 0;
    // for (auto &ele : uniqueNoSet)
    // {
    //     arr[index] = ele;
    //     index++;
    // }
    // return index;

    int i = 0, j = i + 1;
    while (j < n)
    {
        if (arr[i] != arr[j])
        {
            i++;
            arr[i] = arr[j];
        }
        else
        {
            j++;
        }
    }
    return i + 1;
    // int i=0;
    // for(int j=1;j<n;j++){
    //     if(arr[j]!=arr[i]){
    //         arr[i+1] = arr[j];
    //         i++;
    //     }
    // }
    // return i+1;
}
void leftRotateArrayOne(vector<int> &arr, int n)
{
    int temp = arr[0];
    for (int i = 1; i < n; i++)
    {
        arr[i - 1] = arr[i];
    }
    arr[n - 1] = temp;
}

int main()
{

    int n;
    cin >> n;
    vector<int> nums;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        nums.push_back(x);
    }

    int result = removeDuplicates(nums, n);
    cout << result << endl;
    // leftRotateArrayOne(v1,v1.size());
    for (auto &it : nums)
    {
        cout << it << " ";
    }
    return 0;
}