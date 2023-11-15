#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> nums;

void dfs(int remain, int idx, vector<int> num){
    if(remain <= 0){
        nums.push_back(num);
        return;
    }
    
    for(int i=idx; i<num.size(); i++){
        num[i]++;
        dfs(remain-1, i, num);
        num[i]--;
    }
}

int solution(int k, int n, vector<vector<int>> reqs) {
    int answer = -1;
    vector<int> num(k, 1);
    dfs(n-k, 0, num);
    
    for(auto num : nums){
        int delay = 0;
        priority_queue<int, vector<int>, greater<int>> pq[k];
        
        for(int i=0; i<k; i++){
            for(int j=0; j<num[i]; j++) pq[i].push(0);
            cout << num[i] << " ";
        }
        cout << "\n";
        
        for(auto req : reqs){
            int start = req[0], times = req[1], type = req[2];
            int gone = pq[type-1].top();
            pq[type-1].pop();
            if(gone > start){
                delay += (gone-start);
                pq[type-1].push(gone + times);
            }
            else pq[type-1].push(start + times);
        }
        if(answer == -1) answer = delay;
        else answer = min(answer, delay);
    }
    
    return answer;
}