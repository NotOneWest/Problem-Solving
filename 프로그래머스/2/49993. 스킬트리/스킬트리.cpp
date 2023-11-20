#include <bits/stdc++.h>
using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    
    vector<vector<int>> skill_indexs(skill_trees.size());
    for(int k=0; k<skill_trees.size(); k++){
        for(int i=0; i<skill_trees[k].length(); i++){
            for(int j=0; j<skill.length(); j++){
                if(skill_trees[k][i] == skill[j]){
                    skill_indexs[k].push_back(j);
                }
            }
        }
    }
    
    for(auto skill_index : skill_indexs){
        bool flag = true;
        for(int i=0; i<skill_index.size(); i++){
            if(skill_index[i] != i){
                flag = false; break;
            }
        }
        if(flag) answer++;
    }
    
    return answer;
}