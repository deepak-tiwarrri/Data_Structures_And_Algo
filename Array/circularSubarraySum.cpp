#include<bits/stdc++.h>
using namespace std;

// Function to find maximum sum of non-circular subarray using Kadane's algorithm
int kadane(vector<int>& arr) {
    int maxSoFar = arr[0];
    int currMax = arr[0];
    
    for(int i = 1; i < arr.size(); i++) {
        currMax = max(arr[i], currMax + arr[i]);
        maxSoFar = max(maxSoFar, currMax);
    }
    return maxSoFar;
}

// Function to find maximum circular subarray sum
int maxCircularSubarraySum(vector<int>& arr) {
    int n = arr.size();
    
    // Case 1: get the maximum sum using standard kadane's algorithm
    int maxNormalSum = kadane(arr);
    
    // If all elements are negative, return the maximum normal sum
    if(maxNormalSum < 0)
        return maxNormalSum;
    
    // Case 2: compute the maximum circular sum
    // First, compute total array sum
    int arraySum = 0;
    for(int i = 0; i < n; i++) {
        arraySum += arr[i];
        // Invert the array (multiply by -1)
        arr[i] = -arr[i];
    }
    
    // Add arraySum to the maximum sum of inverted array
    int maxCircularSum = arraySum + kadane(arr);
    
    // Return the maximum of the two sums
    return max(maxNormalSum, maxCircularSum);
}

int main() {
    // Example usage
    vector<int> arr = {8, -8, 9, -9, 10, -11, 12};
    
    cout << "Array: ";
    for(int x : arr) {
        cout << x << " ";
    }
    cout << "\n";
    
    int maxSum = maxCircularSubarraySum(arr);
    cout << "Maximum circular subarray sum is: " << maxSum << endl;
    
    return 0;
}
