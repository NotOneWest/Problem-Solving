#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    answer.push_back(0); answer.push_back(0);
    for(int i=1; i<words.size(); i++){
        if(words[i-1].back() != words[i].front()){
            answer[0] = (i%n + 1);
            answer[1] = (i/n + 1);
            break;
        }
        
        for(int j=0; j<i; j++){
            if(words[i] == words[j]){
                answer[0] = (i%n + 1);
                answer[1] = (i/n + 1);
                break;
            }
        }
        
        if(answer[0] != 0 && answer[1] != 0) break;
    }
    return answer;
}