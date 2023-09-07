#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int zero[42], one[42];

void fib(){
	zero[0]=1;
	zero[1]=0;
	one[0]=0;
	one[1]=1;
	for(int i=2; i<=40; i++){
		zero[i]=(zero[i-1]+zero[i-2]);
		one[i]=(one[i-1]+one[i-2]);
	}
}

int main(){
	fib();
	int t; cin >> t;
	for(int i=0; i<t; i++){
		int n; cin >> n;
		cout << zero[n] << ' ' << one[n] << '\n';
	}
	return 0;
}
