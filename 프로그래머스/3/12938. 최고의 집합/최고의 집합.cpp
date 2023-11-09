#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    
    int quotient = s/n, remainder = s%n;
    if(quotient == 0) answer.push_back(-1);
    else{
        for(int i=0; i<n; i++) answer.push_back(quotient);
        int idx = n-1;
        while(remainder > 0){
            answer[idx]++;
            remainder--; idx--;
        }
    }
    
    return answer;
}