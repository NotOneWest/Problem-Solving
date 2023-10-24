#include <bits/stdc++.h>

using namespace std;

bool visited[1000001]={false,};

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    priority_queue<pair<int, int> > pq;
    priority_queue<pair<int, int> > pq2;
    for(int i=0; i<operations.size(); i++){
        if(operations[i][0] == 'I'){
            int num = stoi(operations[i].substr(2, operations[i].size()-2));
            pq.push(make_pair(num, i));
            pq2.push(make_pair(-num, i));
            visited[i] = true;
        }
        else{
            if(operations[i][2] == '1'){
                while(!pq.empty() && !visited[pq.top().second]){ pq.pop(); }
                if(!pq.empty()){
                    visited[pq.top().second]=false; pq.pop();
                }
            }
            else{
                while(!pq2.empty() && !visited[pq2.top().second]){ pq2.pop(); }
                if(!pq2.empty()){
                    visited[pq2.top().second]=false; pq2.pop();
                }
            }
        }
    }
    
    while(!pq.empty() && !visited[pq.top().second]){ pq.pop(); }
    while(!pq2.empty() && !visited[pq2.top().second]){ pq2.pop(); }
    if(pq.empty() && pq2.empty()){ answer.push_back(0); answer.push_back(0); }
    else{ answer.push_back(pq.top().first); answer.push_back(-pq2.top().first);}
    
    return answer;
}