#include <bits/stdc++.h>
using namespace std;

bool comp(vector<int> a, vector<int> b){ return a[2] < b[2]; }

int getP(int idx, vector<int> parents){
    if(parents[idx] == idx) return idx;
    return getP(parents[idx], parents);
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    sort(costs.begin(), costs.end(), comp);
    vector<int> parents;
    for(int i=0; i<n; i++) parents.push_back(i);
    
    for(int i=0; i<costs.size(); i++){
        int st = getP(costs[i][0], parents);
        int end = getP(costs[i][1], parents);
        if(st != end){
            answer += costs[i][2];
            parents[end] = st;
        }
    }
    
    return answer;
}