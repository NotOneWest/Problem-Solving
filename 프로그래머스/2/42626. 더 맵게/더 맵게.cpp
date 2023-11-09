#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int> pq;
    for(int i=0; i<scoville.size(); i++) pq.push(-1 * scoville[i]);
    
    while((pq.top() * -1) < K && pq.size() > 1){
        int a = -1 * pq.top(); pq.pop();
        int b = -1 * pq.top(); pq.pop();

        pq.push(-1 * (a + (b*2)));
        answer++;
    }
    if((pq.top() * -1) < K) answer = -1;
    
    return answer;
}