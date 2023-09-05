#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    
    int sum=sequence[0], start=0, end=0, sublen=sequence.size()+1;
    pair<int, int> res;
    while(1){
        if(start > end || end >= sequence.size()) break;
        
        if(sum < k) { end++; sum += sequence[end]; }
        else if(sum == k){
            if((end-start+1) < sublen) { sublen = (end-start+1); res = make_pair(start, end); }
            else if((end-start+1) == sublen){
                if(start < res.first) res = make_pair(start, end);
            }
            sum -= sequence[start]; start++; // 부분 수열 찾아도 갱신해야 하는 것을 잊음..
        } else{
            sum -= sequence[start]; start++;
        }
    }
    
    answer.push_back(res.first);
    answer.push_back(res.second);
    
    return answer;
}