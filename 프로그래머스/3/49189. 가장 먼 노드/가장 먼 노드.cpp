#include <bits/stdc++.h>
using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    vector<vector<int>> v(n+1);
    vector<int> dist(n+1, -1);
    for(int i=0; i<edge.size(); i++){
        v[edge[i][0]].push_back(edge[i][1]);
        v[edge[i][1]].push_back(edge[i][0]);
    }
    
    queue<int> q;
    q.push(1);
    dist[1] = 0;
    while(!q.empty()){
        int now = q.front();
        q.pop();
        for(int i=0; i<v[now].size(); i++){
            if(dist[v[now][i]] != -1) continue;
            q.push(v[now][i]);
            dist[v[now][i]] = dist[now] + 1;
        }
    }
    
    int MAX = -1;
    for(int i=1; i<=n; i++) MAX = max(MAX, dist[i]);
    for(int i=1; i<=n; i++) answer += (MAX == dist[i]);
    
    return answer;
}