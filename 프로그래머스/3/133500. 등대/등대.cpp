#include <string>
#include <vector>
using namespace std;

int answer = 0;
bool light[100001] = {false, };

void dfs(int node, int parent, vector<vector<int>> &info){
    for(int i=0; i<info[node].size(); i++){
        if(info[node][i] != parent){
            dfs(info[node][i], node, info);
            
            if(!light[info[node][i]] && !light[node]){
                light[node] = true;
                answer++;
            }
        }
    }
}


int solution(int n, vector<vector<int>> lighthouse) {
    answer = 0;
    
    vector<vector<int>> info(n+1);
    for(int i=0; i<(n-1); i++){
        info[lighthouse[i][0]].push_back(lighthouse[i][1]);
        info[lighthouse[i][1]].push_back(lighthouse[i][0]);
    }
    dfs(1, 1, info);
    
    return answer;
}