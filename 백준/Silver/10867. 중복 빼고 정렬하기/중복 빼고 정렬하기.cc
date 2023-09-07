#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int num[2002];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >> n;
	for(int i=0; i<n; i++){
		int k; cin >> k;
		num[k+1000]++;
	}
	for(int i=0; i<2002; i++){
		if(num[i]>0) cout << i-1000 << ' ';
	}
	return 0;
}