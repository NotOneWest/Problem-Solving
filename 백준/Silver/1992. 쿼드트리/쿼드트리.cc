#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

char bw[65][65];

bool check(int n,int si,int sj){
	int first=bw[si][sj], check=0;
	for(int i=si;i<(n+si); i++){
		for(int j=sj; j<(n+sj); j++){
			if(bw[i][j]!=first) return false;
		}
	}
	return true;
}

void solve(int n, int si, int sj){
	if(check(n,si,sj)){
		cout << bw[si][sj];
	}
	else{
		cout << '(';
		solve(n/2,si,sj);
		solve(n/2,si,sj+n/2);
		solve(n/2,si+n/2,sj);
		solve(n/2,si+n/2,sj+n/2);
		cout << ')';
	}
}

int main(){
	int n; cin >> n;
	for(int i=0; i<n; i++){
		string s; cin >> s;
		for(int j=0; j<n; j++){
			bw[i][j]=s[j];
		}
	}
	solve(n,0,0);
	return 0;
}
