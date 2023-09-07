#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int dp[101]={0,};

int main(){
	int n;
	for(int i=0; i<101; i++) dp[i] = i*i;
	while(1){
		cin >> n;
		if(n==0) break;
		else{
			int sum=0;
			for(int i=1; i<n+1; i++){
				sum+=dp[i];
			}
			cout << sum << '\n';
		}
	}
	return 0;
}
