// Given a sorted dictionary of an alien language having N words and K starting alphabets of a standard dictionary. Find the order of characters in the alien language.

// There may be multiple valid orders for a particular test case, thus you may return any valid order as a string. The output will be True if the order returned by the function is correct, else False denoting an incorrect order. If the given arrangement of words is inconsistent with any possible letter ordering, return an empty string "".

// Example 1:
// Input: N = 5, K = 4, dict = ["baa","abcd","abca","cab","cad"]

// Output: b d a c

// Explanation: 

// Compare every pair of consecutive words and consider only their first differing characters:

// "baa" and "abcd" first differ at index 0: b vs. a. Since "baa" appears first, b must come before a.
// "abcd" and "abca" first differ at index 3: d vs. a. Therefore, d must come before a.
// "abca" and "cab" first differ at index 0: a vs. c. Therefore, a must come before c.
// "cab" and "cad" first differ at index 2: b vs. d. Therefore, b must come before d.
// These constraints produce the valid ordering [b, d, a, c].

// Example 2:
#include <bits/stdc++.h>
using namespace std;
class Solution {
    private:
    vector<int> findTopoSort(int V,vector<int> adj[]){
        queue<int> que;
        vector<int> result;
        vector<int> indegree(V,0);
        for(int i=0;i<V;i++){
            for(auto &it: adj[i]){
                indegree[it]++;
            }
        }
        for(int i=0;i<V;i++){
            
        }

    }
public:
	string findOrder(string dict[], int N, int K) {
		//find the toposort
        //u-> v then u comes first.
        //find the indegreee

	}
};

int main() {
    // code here
    int N,K;
    cin>>N>>K;
    string dict[N];
    for(int i=0;i<N;i++){
        string word;
        cin>>word;
        dict[i] = word;
    }
    Solution sol;
    string res = sol.findOrder(dict,N,K);
    cout<<res;

    return 0;
}