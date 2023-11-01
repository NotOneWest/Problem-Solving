#include <bits/stdc++.h>
using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    
    map<string, int> m;
    int now = 27, i = 0; 
    string temp = "";
    
    while(1){
        if(i == msg.length()) break;
        temp += msg[i];
        int j = i;
        while(1){
            if(j == msg.length()) break;
            j++; temp += msg[j];
            if(m[temp] == 0){
                if((j-i) == 1) answer.push_back(temp[0] - 'A' + 1);
                else answer.push_back(m[temp.substr(0, (j-i))]);
                m[temp] += now; now++; temp=""; i = j; break;
            }
        }
    }
    
    return answer;
}