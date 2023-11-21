#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> keys;
int dp[100001][10][10];

void setLoc(){
    keys.push_back(make_pair(3, 1));
    for(int i=0; i<9; i++) keys.push_back(make_pair(i/3, i%3));
}

int getW(int now, int move){
    int nx = keys[now].first, ny = keys[now].second;
    int mx = keys[move].first, my = keys[move].second;
    
    if(nx == mx && ny == my) return 1;
    if(nx == mx || ny == my) return (abs(nx-mx) + abs(ny-my))*2;
    if(abs(nx-mx) == abs(ny-my)) return abs(nx-mx)*3;
    
    int dx = abs(nx-mx), dy = abs(ny-my);
    return min(dx, dy)*3 + abs(dx-dy)*2;
}

int typing(int left, int right, int idx, const string& numbers){
    if(idx >= numbers.length()) return 0;
    
    if(left == right) return 9999999; // 왼손, 오른손 같으면 오류
    if(dp[idx][left][right] != 0) return dp[idx][left][right]; // 중복 제거
    
    int leftW = getW(left, numbers[idx]-'0');
    int rightW = getW(right, numbers[idx]-'0');
    
    int w1 = leftW + typing(numbers[idx]-'0', right, idx+1, numbers); // 왼손 이동한 경우
    int w2 = rightW + typing(left, numbers[idx]-'0', idx+1, numbers); // 오른손 이동한 경우
    
    dp[idx][left][right] = min(w1, w2);
    return dp[idx][left][right];
}

int solution(string numbers) {
    int answer = 0;
    setLoc();
    for(int i=0; i<numbers.length(); i++){
        for(int j=0; j<10; j++){
            for(int k=0; k<10; k++) dp[i][j][k] = 0;
        }
    }
    answer = typing(4, 6, 0, numbers);
    return answer;
}