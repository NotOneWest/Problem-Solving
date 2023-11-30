#include <bits/stdc++.h>
using namespace std;

int n, s;
int num[41];
map<int, int> cnt;
long long ans = 0;

void rightSum(int index, int sum){
	if(index == n){ cnt[sum]++; return; }
	rightSum(index + 1, sum + num[index]);
	rightSum(index + 1, sum);
}

void leftSum(int index, int sum){
	if(index == (n/2)){ ans += cnt[s-sum]; return; }
	leftSum(index + 1, sum + num[index]);
	leftSum(index + 1, sum);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> s;
	for(int i=0; i<n; i++) cin >> num[i];
	
	ans = 0;
	// sum 계산하는 함수 합치려했으나 n/2 조건이 겹쳐 나눠야했음. 
	rightSum(n/2, 0);
	leftSum(0, 0);	
	
	if(s == 0) ans--; // s가 0인 경우는 전부 선택 안한 경우 빼줘야 함. 
	cout << ans;
	return 0;
}
