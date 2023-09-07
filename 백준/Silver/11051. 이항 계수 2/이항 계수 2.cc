#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int com[1001][1001], mod=10007;

void combination(){
	for(int i=1; i<=1000; i++){
		for(int j=0; j<1001; j++){
			if(j==0 || i==j) com[i][j]=1;
			else{
				com[i][j] = (com[i-1][j-1]+com[i-1][j])%mod;
			}
		}
	}
}

int main(){
	int n,k; cin >> n >> k;
	combination();
	cout << com[n][k];
	return 0;
}