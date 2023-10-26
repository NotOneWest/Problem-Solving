#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int k, vector<int> num, vector<vector<int>> links) {
    int answer = 0;
    
    int n = num.size(), start=0, end=0;
    vector<int> parent(n, -1), child(n, 0); // index의 부모, index의 자식 개수
    for(int i=0; i<n; i++){
        end += num[i];
        if(links[i][0] != -1){ parent[links[i][0]] = i; child[i]++; }
        if(links[i][1] != -1){ parent[links[i][1]] = i; child[i]++; }
    }
    
    int mid;
    while(start <= end){
        mid = (start + end)/2;
        queue<int> q;
        vector<int> child_num(n), sum(n, 0); // 매 경우마다 자식 개수 초기화, 그룹의 합
        for(int i=0; i<n; i++){
            child_num[i] = child[i];
            if(child[i] == 0) q.push(i);
        }
        
        int group=0;
        bool small = false;
        
        while(q.size()){
            int cur = q.front();
            q.pop();
            
            if(num[cur] > mid){ small=true; break; } // 기준이 작으면 바로 break
            sum[cur] += num[cur];
            
            int l = links[cur][0], r = links[cur][1];
            if(l != -1 && r != -1){
                if((sum[cur] + sum[l] + sum[r]) <= mid){
                    group--; // 자식, 자식  -> 부모-자식-자식
                    sum[cur] += (sum[l] + sum[r]);
                } else{
                    if(sum[l] < sum[r]){ 
                        if((sum[cur] + sum[l]) <= mid) sum[cur] += sum[l]; // 자식, 자식 -> 자식-부모, 자식
                        else group++; // 자식, 자식 -> 부모, 자식, 자식 (이 부분 처음에 고려 X)
                    } else{
                        if((sum[cur] + sum[r]) <= mid) sum[cur] += sum[r];
                        else group++; // 자식, 자식 -> 부모, 자식, 자식 (이 부분 처음에 고려 X)
                    }
                }
            } else if(l != -1){ // 그룹 수는 그대로 (자식, 자식 -> 자식-부모, 자식)
                if((sum[cur] + sum[l]) <= mid) sum[cur] += sum[l]; // 자식, 자식 -> 자식-부모, 자식
                else group++; // 자식, 자식 -> 부모, 자식, 자식 (이 부분 처음에 고려 X)
            } else if(r != -1){
                if((sum[cur] + sum[r]) <= mid) sum[cur] += sum[r]; // 자식, 자식 -> 자식-부모, 자식
                else group++; // 자식, 자식 -> 부모, 자식, 자식 (이 부분 처음에 고려 X)
            } else group++; // 자식, 자식 -> 부모, 자식, 자식
            
            if(parent[cur] != -1){ // 부모 있는 경우 -> 자식 모두 참조되면 추가 (child_num : 0)
                child_num[parent[cur]]--;
                if(child_num[parent[cur]] == 0) q.push(parent[cur]);
            }
        }
        
        // mid가 크거나, group 수가 k 이하이면 : 기준 이하 / 아니면 : 기준 이상 탐색
        if(!small && group <= k){ answer = mid; end = (mid - 1); }
        else start = (mid + 1); // mid + 1 해줘야 갱신이 됨. (미스)
    }
    return answer;
}

// 생각 정리
// 1. 총 간선에서 k-1 개 자르는 모든 경우 탐색 : 무조건 시간 초과
// 2. 기준 정해서 탐색 (최대 인원이 M명이 되도록)
//       기준 M명을 만족하면서 그룹이 K개 이하면 만족
//          -> K개 이하 그룹에서 K개로 하기 위해 더 자르면 무조건 M명 이하 (모든 그룹)
// 각 노드의 부모와 자식의 개수 기록
// 자식이 없는 노드부터 탐색 (그룹 추가)
// 이후 자식이 있는 노드는 자식들의 인원 더해가며 기준 만족하는지 판별
//      -> 만족하면 한 그룹으로, 아니면 그룹 추가
// 이분 탐색으로 반복하여 최소 기준 탐색
