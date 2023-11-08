#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    priority_queue<int> pq;
    for(int i=0; i<works.size(); i++) pq.push(works[i]);
    while(n > 0){
        if(pq.empty()) break;
        int t = pq.top();
        pq.pop();
        if(t > 1) pq.push(t-1);
        n--;
    }
    while(!pq.empty()){
        answer += (pq.top() * pq.top());
        pq.pop();
    }
    
    return answer;
}