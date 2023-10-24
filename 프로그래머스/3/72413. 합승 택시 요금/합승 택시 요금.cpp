#include <bits/stdc++.h>

using namespace std;

int dis[201][201];

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 100000 * n;
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i == j) dis[i][j] = 0;
            else dis[i][j] = answer;
        }
    }
    
    for(int i=0; i<fares.size(); i++){
        int x=fares[i][0], y=fares[i][1], c=fares[i][2];
        dis[x][y] = c; dis[y][x] = c;
    }
    
    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++) 
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
        }
    }
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++) 
            answer = min(answer, dis[i][a]+dis[i][b]+dis[i][s]);
    }
    
    return answer;
}