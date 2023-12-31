#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map<string, int> m;
    for(int i=0; i<clothes.size(); i++){
        m[clothes[i][clothes[i].size() - 1]]++;
    }
    
    for(auto i : m) answer *= (i.second + 1);
    
    return answer-1;
}