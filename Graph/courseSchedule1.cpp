#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    bool canFinish(int N, vector<vector<int>> arr) {
        vector<vector<int>> adj(N);
        queue<int> que;
        int cnt = 0;
        for(auto &it:arr){
            adj[it[1]].push_back(it[0]);
        }
        vector<int> indegree(N,0);
        for(int i=0;i<N;i++){
            for(auto &it:adj[i]){
                indegree[it]++;
            }
        }
        for(int i=0;i<N;i++){
            if(indegree[i]==0) que.push(i);
        }
        while(!que.empty()){
            auto node = que.front();
            que.pop();
            cnt++;
            for(auto &it: adj[node]){
                indegree[it]--;
                if(indegree[it]==0) que.push(it);
            }
        }
        if(cnt==N) return true;
        return false;
    }
};
int main() {
    // code here
    

    return 0;
}