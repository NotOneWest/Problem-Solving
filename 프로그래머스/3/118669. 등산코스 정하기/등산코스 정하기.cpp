#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> v[50001];
vector<int> answer;
bool check_summits[50001];
int intensity[50001];

void climb(vector<int> gates){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<pair<int, int>> answer_candidate;
    
    for(int i=0; i<50001; i++) intensity[i] = -1;
    
    for(int i=0; i<gates.size(); i++){
        pq.push(make_pair(0, gates[i]));
        intensity[gates[i]] = 0;
    }
    
    while(!pq.empty()){
        int temp = pq.top().second;
        int w = pq.top().first;
        pq.pop();
        
        if(w > intensity[temp]) continue;
        
        if(check_summits[temp]){
            answer_candidate.push_back(make_pair(w, temp));
            continue;
        }
        
        for(int i=0; i<v[temp].size(); i++){
            int next = v[temp][i].second;
            int nextW = v[temp][i].first;
            if(intensity[next] == -1 || max(w, nextW) < intensity[next]){
                intensity[next] = max(w, nextW);
                pq.push(make_pair(intensity[next], next));
            }
        }
    }
    
    sort(answer_candidate.begin(), answer_candidate.end());
    answer.push_back(answer_candidate[0].second);
    answer.push_back(answer_candidate[0].first);
}



vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    
    
    for(int i=0; i<paths.size(); i++){
        int s=paths[i][0], e=paths[i][1], w=paths[i][2];
        v[s].push_back(make_pair(w, e));
        v[e].push_back(make_pair(w, s));
    }
    
    for(int i=0; i<summits.size(); i++) check_summits[summits[i]] = true;
    
    climb(gates);
    
    return answer;
}