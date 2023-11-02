#include <bits/stdc++.h>
using namespace std;

int cnt = -1, answer = 0;
string vowel = "AEIOU";
void dfs(string target, string word){
    cnt++;
    
    if(word == target){ answer = cnt; return; }
    if(word.length() >= 5) return;
    
    for(int i=0; i<5; i++){
        dfs(target, word + vowel[i]);
    }
}

int solution(string word) {
    dfs(word, "");
    return answer;
}