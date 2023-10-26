#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    int day=0;
    while(progresses.size() != 0){
        for(int i=0; i<progresses.size(); i++) progresses[i] += speeds[i];
        int cnt = 0;
        for(int i=0; i<progresses.size(); i++){
            if(progresses[i] >= 100) cnt++;
            else break;
        }
        
        if(cnt != 0) answer.push_back(cnt);
        for(int i=0; i<cnt; i++){
            progresses.erase(progresses.begin());
            speeds.erase(speeds.begin());
        }
    }
    
    return answer;
}