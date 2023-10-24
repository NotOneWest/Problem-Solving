#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int MOD = 1234567;
int dp[100001];

int solution(int n) {
    int answer = 0;
    dp[0]=0; dp[1]=1;
    for(int i=2; i<=n; i++) dp[i] = (dp[i-2] + dp[i-1])%MOD;
    answer = dp[n];
    return answer;
}