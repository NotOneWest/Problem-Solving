#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 1, sum=0, prev=1;;
    
    for(int i=1; i<=((n + 1)/2); i++){
        sum += i;
        if(sum >= n){
            while(sum > n){ sum -= prev; prev++; }
            if(sum == n) answer++;
        }
    }
    if(n == 1) answer = 1;
    
    return answer;
}