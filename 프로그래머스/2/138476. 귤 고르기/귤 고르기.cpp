#include <bits/stdc++.h>

using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    int nums[10000001] = {0, };
    for(int i=0; i<10000001; i++) nums[i]=0;
    for(int i=0; i<tangerine.size(); i++) nums[tangerine[i]]++;
    sort(nums, nums+10000001);
    for(int i=10000000; i>0; i--){
        if(nums[i] < k){ answer++; k-=nums[i]; }
        else{ answer++; break; }
    }
    return answer;
}