#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    
    pair<int, int> loc;
    for(int i=0; i<park.size(); i++){
        for(int j=0; j<park[i].size(); j++){
            if(park[i][j] == 'S') loc = make_pair(i, j);
        }
    }
    
    for(int t=0; t<routes.size(); t++){
        int flag = 0;
        for(int i=1; i<=(routes[t][2] - '0'); i++){
            int nx = loc.first, ny = loc.second;
            if(routes[t][0] == 'E') ny += i;
            else if(routes[t][0] == 'W') ny -= i;
            else if(routes[t][0] == 'N') nx -= i;
            else nx += i;
                    
            if(nx<0 || nx >= park.size() || ny<0 || ny>=park[0].size() || park[nx][ny] == 'X'){flag = 0; break; }
            else flag = 1;
        }
        if(flag){
            if(routes[t][0] == 'E') loc.second += (routes[t][2] - '0');
            else if(routes[t][0] == 'W') loc.second -= (routes[t][2] - '0');
            else if(routes[t][0] == 'N') loc.first -= (routes[t][2] - '0');
            else loc.first += (routes[t][2] - '0');
        }
    }
    answer.push_back(loc.first);
    answer.push_back(loc.second);
    return answer;
}