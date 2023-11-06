#include <string>
#include <vector>
#include <map>
using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;
    
    map<string, int> rank;
    map<int, string> name;
    for(int i=0; i<players.size(); i++){
        rank[players[i]] = i;
        name[i] = players[i];
    }
    
    for(int i=0; i<callings.size(); i++){
        int ranking = rank[callings[i]];
        name[ranking] = name[ranking-1];
        name[ranking-1] = callings[i];
        rank[name[ranking]] = ranking;
        rank[callings[i]] = ranking-1;
    }
    
    for(int i=0; i<players.size(); i++) answer.push_back(name[i]);
    
    return answer;
}