#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;
    int sy=50, sx=50, ey=0, ex=0;
    for(int i=0; i<wallpaper.size(); i++){
        for(int j=0; j<wallpaper[i].length(); j++){
            if(wallpaper[i][j] == '#'){
                sy = min(sy, i);
                sx = min(sx, j);
                ey = max(ey, i+1);
                ex = max(ex, j+1);
            }
        }
    }
    
    answer.push_back(sy);
    answer.push_back(sx);
    answer.push_back(ey);
    answer.push_back(ex);
    
    return answer;
}