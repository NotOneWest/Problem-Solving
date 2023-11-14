#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int x, int y, int n) {
    int answer = -1;
    
    queue<pair<int, int>> q;
    q.push(make_pair(y, 0));
    while(!q.empty()){
        pair<int, int> temp = q.front();
        q.pop();
        
        if(temp.first == x) return temp.second;
        
        if(temp.first > x){
            if(temp.first%3 == 0) q.push(make_pair(temp.first/3, temp.second + 1));
            if(temp.first%2 == 0) q.push(make_pair(temp.first/2, temp.second + 1));
            q.push(make_pair(temp.first-n, temp.second + 1));
        }
    }
    return answer;
}