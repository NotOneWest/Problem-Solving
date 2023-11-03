#include <bits/stdc++.h>
using namespace std;

int answer = 0;
bool visited[8];
string mems = "ACFJMNRT";

void dfs(string s, int n, vector<string> data){
    if(s.length() == 8){
        for(int i=0; i<n; i++){
            int first_idx = -1, second_idx = -1;

            for(int j=0; j<8; j++){
                if(s[j] == data[i][0]) first_idx = j;
                if(s[j] == data[i][2]) second_idx = j;
                if(first_idx != -1 && second_idx != -1) break;
            }

            int nums = abs(first_idx - second_idx) - 1;
            if(data[i][3] == '=' && nums != (data[i][4]-'0')) return;
            if(data[i][3] == '>' && nums <= (data[i][4]-'0')) return;
            if(data[i][3] == '<' && nums >= (data[i][4]-'0')) return;
        }
        answer++;
        return;
    }

    for(int i=0; i<8; i++){
        if(!visited[i]){
            visited[i] = true;
            dfs(s + mems[i], n, data);
            visited[i] = false;
        }
    }
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data) {
    answer = 0;
    for(int i=0; i<8; i++) visited[i] = false;
    dfs("", n, data);
    return answer;
}