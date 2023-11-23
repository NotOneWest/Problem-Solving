#include <bits/stdc++.h>
using namespace std;

int solution(string dirs) {
    int answer = 0;
    
    map<string, int> m;
    int x=0, y=0, nx, ny;
    for(int i=0; i<dirs.length(); i++){
        if(dirs[i] == 'U'){ nx = x; ny = y+1; }
        else if(dirs[i] == 'D'){ nx = x; ny = y-1; }
        else if(dirs[i] == 'R'){ nx = x+1; ny = y; }
        else{ nx = x-1; ny = y; }
        
        if(nx<-5 || nx>5 || ny<-5 || ny>5) continue;
        
        string route1="", route2="";
        route1 += to_string(x); route1 += to_string(y); route1 += to_string(nx); route1 += to_string(ny);
        route2 += to_string(nx); route2 += to_string(ny); route2 += to_string(x); route2 += to_string(y);
        if(m[route1] == 0 && m[route2] == 0) answer++;
        m[route1]++; m[route2]++;
        x=nx; y=ny;
    }
    
    return answer;
}