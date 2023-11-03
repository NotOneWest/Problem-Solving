#include <bits/stdc++.h>
using namespace std;

int solution(int n, int k, vector<int> enemy) {
    int answer = 0;
    priority_queue<int> pq;
    for(answer=0; answer<enemy.size(); answer++){
        if(n >= enemy[answer]){
            n -= enemy[answer]; pq.push(enemy[answer]);
        } else{
            if(k){
                k--;
                if(!pq.empty()){
                    if(pq.top() >= enemy[answer]){
                        n += (pq.top() - enemy[answer]);
                        pq.pop(); pq.push(enemy[answer]);
                    }
                }
            } else break;
        }
    }
    return answer;
}