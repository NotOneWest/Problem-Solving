#include <bits/stdc++.h>
using namespace std;

map<string, int> m;

void dfs(string target, int cnt, string sub){
    
    if(cnt == target.size()){ // 전체 메뉴 탐색 (O)
        if(sub.length() < 2) return; // 코스는 2개 이상
        m[sub]++; return;
    }
    dfs(target, cnt+1, sub + target[cnt]); // 메뉴 선택
    dfs(target, cnt+1, sub); // 메뉴 미선택
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    
    for(auto order : orders){
        sort(order.begin(), order.end()); // 오름차순 정리
        dfs(order, 0, "");
    } 
    
    int maxFreq[11];
    for(int i=0; i<11; i++) maxFreq[i]=0;
    
    for(auto freq : m) maxFreq[freq.first.length()] = max(maxFreq[freq.first.length()], freq.second);

    for(auto len : course){
        for(auto freq : m){
            if(freq.second < 2) continue;
            if(freq.first.length() == len){
                if(maxFreq[len] == freq.second) answer.push_back(freq.first);
            }
        }
    }
    
    sort(answer.begin(), answer.end());
    return answer;
}