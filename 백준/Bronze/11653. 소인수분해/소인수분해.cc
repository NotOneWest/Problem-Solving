#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

void solve(int n){
	if(n==1) return;
	int c=n;
	for(int i=2; i<=n;){
		if(c%i==0){
			printf("%d\n",i);
			c=c/i;
		}
		else i++;
	}
}

int main(){
	int n; cin >> n;
	if(n!=1) solve(n);
	return 0;
}
