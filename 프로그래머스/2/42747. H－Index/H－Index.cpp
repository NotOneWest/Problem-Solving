#include <string>
#include <vector>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    int nums[10001];
    for(int i=0; i<10001; i++) nums[i]=0;
    for(int i=0; i<citations.size(); i++){
        for(int j=0; j<=citations[i]; j++) nums[j]++;
    }
    for(int i=0; i<10001; i++){
        if(i <= nums[i]) answer = max(answer, i);
    }
    return answer;
}