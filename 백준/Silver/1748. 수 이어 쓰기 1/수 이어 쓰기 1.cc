#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int main(){
	int n, cnt=0; cin >> n;
	int dp[9]={9,};
	for(int i=1; i<8; i++) dp[i] = 9*(i+1)*pow(10,i);
	dp[8]=9;
	int j = to_string(n).length();
	for(int i=0; i<j-1; i++){
		cnt+=dp[i];
	}
	cnt += (n-pow(10,j-1)+1)*j;
	printf("%d", cnt);
	return 0;
}