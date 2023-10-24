#include <bits/stdc++.h>

using namespace std;

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    bool visited[201] = {false, };
    
    while(1){
        int idx = -1;
        for(int i=0; i<n; i++){
            if(!visited[i]){ idx=i; answer++; break;}
        }

        if(idx == -1) break;

        queue<int> q;
        q.push(idx);
        while(!q.empty()){
            int now = q.front();
            visited[now] = true;
            q.pop();
            for(int i=0; i<n; i++){
                if(i == now || visited[i] || !computers[now][i]) continue;
                visited[i] = true; q.push(i);
            }
        }
    }
    
    return answer;
}