#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

ll maketree(vector<ll> &num, vector<ll> &sgmt, int node, int start, int end){
	if(start==end) return sgmt[node]=num[start];
	else{
		return sgmt[node]=(maketree(num, sgmt, node*2, start, (start+end)/2) + maketree(num, sgmt, (node*2)+1, ((start+end)/2)+1, end));
	}
}

void change(vector<ll> &num, vector<ll> &sgmt, int node, int start, int end, int loc, ll diff){
	if(loc<start || loc>end) return;
	sgmt[node]+=diff;
	if(start!=end){
		change(num, sgmt, node*2, start, (start+end)/2, loc, diff);
		change(num, sgmt, (node*2)+1, ((start+end)/2)+1, end, loc, diff);
	}
}

ll sum(vector<ll> &num, vector<ll> &sgmt, int node, int start, int end, int left, int right){
	if(left>end || right<start) return 0;
	else if(left<=start && right>=end) return sgmt[node];
	else{
		return sum(num, sgmt, node*2, start, (start+end)/2, left, right) + sum(num, sgmt, (node*2)+1, ((start+end)/2)+1, end, left, right);
	}
}

int main(){
	int n,m,k; cin >> n >> m >> k;
	vector<ll> num, sgmt(n*4);
	for(int i=0; i<n; i++){
		ll number; cin >> number;
		num.pb(number);
	}
	maketree(num, sgmt, 1,0,n-1);
	for(int t=0; t<(m+k); t++){
		ll a,b,c; cin >> a >> b >> c;
		if(a==1){
			ll diff = c-num[b-1];
			num[b-1]=c;
			change(num, sgmt, 1, 0, n-1, b-1, diff);
		}
		else cout << sum(num, sgmt, 1, 0, n-1, b-1, c-1) << '\n';
	}
	return 0;
}
