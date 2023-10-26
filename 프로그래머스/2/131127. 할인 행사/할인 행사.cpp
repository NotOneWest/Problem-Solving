#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    map<string, int> target;
    for(int i=0; i<want.size(); i++) target.insert({want[i], number[i]});
        
    int t = discount.size() - 9;
    for(int i=0; i<t; i++){
        map<string, int> now;
        for(int j=0; j<10; j++) now[discount[j+i]]++;
        if(target == now) answer++;
    }
    
    return answer;
}