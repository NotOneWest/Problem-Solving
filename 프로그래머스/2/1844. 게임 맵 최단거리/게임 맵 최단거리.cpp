#include<vector>
#include<queue>
#include <iostream>
using namespace std;

int dist[101][101];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    int n = maps.size(), m = maps[0].size();
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            dist[i][j] = -1;
        }
    }
    
    queue<pair<int, int>> q;
    q.push(make_pair(0, 0));
    dist[0][0] = 1;
    while(!q.empty()){
        int x = q.front().first, y = q.front().second;
        q.pop();
        
        for(int i=0; i<4; i++){
            int nx = x + dx[i], ny = y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(maps[nx][ny] == 0 || dist[nx][ny] != -1) continue;
            dist[nx][ny] = dist[x][y] + 1;
            q.push(make_pair(nx, ny));
        }
    }
    
    answer = dist[n-1][m-1];
    return answer;
}