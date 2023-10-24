#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(), people.end());
    
    int start=0;
    while((people.size()-start) > 1){
        int now = (people[start] + people[people.size()-1]);
        if(now > limit){ answer++; people.pop_back(); }
        else{ answer++; people.pop_back(); start++; }
    }
    if((people.size()-start) != 0) answer++;
    
    return answer;
}