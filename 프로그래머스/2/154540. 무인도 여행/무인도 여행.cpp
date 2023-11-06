#include <bits/stdc++.h>
using namespace std;

int days[101][101], n, m;
bool visited[101][101];

int bfs(int x, int y){
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    visited[x][y] = true;

    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {1, -1, 0, 0};

    int sum = 0;

    while(!q.empty()){
        int x = q.front().first, y = q.front().second;
        sum += days[x][y];
        q.pop();

        for(int i=0; i<4; i++){
            int nx = x + dx[i], ny = y + dy[i];
            if(nx<0 || nx >=n || ny<0 || ny>=m || visited[nx][ny] || days[nx][ny] == -1) continue;
            q.push(make_pair(nx, ny));
            visited[nx][ny] = true;
        }
    }

    return sum;
}

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    n = maps.size();
    m = maps[0].size();

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(maps[i][j] == 'X') days[i][j] = -1;
            else days[i][j] = (maps[i][j] -'0');
            visited[i][j] = false;
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(days[i][j] == -1 || visited[i][j]) continue;
            int sum = bfs(i, j);
            answer.push_back(sum);
        }
    }
    
    if(answer.size() == 0) answer.push_back(-1);
    else sort(answer.begin(), answer.end());

    return answer;
}
