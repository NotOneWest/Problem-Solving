#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    
    map<string, set<string>> m;
    map<string, int> m2;
    for(int i=0; i<report.size(); i++){
        string a="", b="";
        bool flag = false;
        for(int j=0; j<report[i].length(); j++){
            if(report[i][j] == ' ') flag = true;
            else{
                if(flag) b += report[i][j];
                else a += report[i][j];
            }
        }
        m[a].insert(b);
    }
    
    for(int i=0; i<id_list.size(); i++){
        for(auto x : m[id_list[i]]) m2[x]++;
    }
    
    for(int i=0; i<id_list.size(); i++){
        int cnt = 0;
        for(auto x : m[id_list[i]]){
            if(m2[x] >= k) cnt++; 
        }
        answer.push_back(cnt);
    }
    
    return answer;
}