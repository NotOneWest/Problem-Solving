#include <string>
#include <vector>
using namespace std;

bool visited[1<<17];
int answer;

void dfs(int state, vector<int> &info, vector<vector<int>> &v){
    // bitmasking으로 각 번호의 방문 여부 check (0번은 항상 1)
    // visited를 통해 중복 방지 (2^17 이라 범위 o)
    if(visited[state]) return;
    visited[state] = 1;
    
    int sheep = 0, wolf = 0;
    for(int i=0; i<info.size(); i++){
        if(state & (1 << i)){
            if(info[i]) wolf++;
            else sheep++;
        }
    }
    
    if(wolf >= sheep) return;
    answer = max(answer, sheep);
    
    for(int i=0; i<info.size(); i++){
        if(!(state & (1 << i))) continue;
        for(int j=0; j<v[i].size(); j++) dfs(state | (1 << v[i][j]), info, v);
    }
}

int solution(vector<int> info, vector<vector<int>> edges) {
    answer = 0;
    vector<vector<int>> v(info.size());
    for(int i=0; i<edges.size(); i++) v[edges[i][0]].push_back(edges[i][1]);
    dfs(1, info, v);
    return answer;
}