#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

const int MOD = 1000000007;
typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

ll maketree(vector<ll> &num, vector<ll> &sgmt, int node, int start, int end){
	if(start==end) return sgmt[node]=num[start];
	else{
		return sgmt[node]=(maketree(num, sgmt, node*2, start, (start+end)/2)*maketree(num, sgmt, (node*2)+1, ((start+end)/2)+1, end))%MOD;
	}
}

ll change(vector<ll> &sgmt, int node, int start, int end, int loc, ll d){
	if(loc<start || loc>end) return sgmt[node];
	if(start==end) return sgmt[node]=d; // 0 이 들어왔을때 다 0이 되는 상황이라 위에서 부터 돌리면 0을 다른 값으로 바꿔도 0이됨, 따라서 밑에서부터 돌려야한다. 
	return sgmt[node]=(change(sgmt, node*2, start, (start+end)/2, loc, d)*change(sgmt, (node*2)+1, ((start+end)/2)+1, end, loc, d))%MOD;
}

ll mult(vector<ll> &sgmt, int node, int start, int end, int left, int right){
	if(left>end || right<start) return 1;
	else if(left<=start && right>=end) return sgmt[node]%MOD;
	else{
		return (mult(sgmt, node*2, start, (start+end)/2, left, right)*mult(sgmt, (node*2)+1, ((start+end)/2)+1, end, left, right))%MOD;
	}
}

int main(){
	int n,m,k; cin >> n >> m >> k;
	vector<ll> num, sgmt(n*4);
	for(int i=0; i<n; i++){
		int number; cin >> number;
		num.pb(number);
	}
	maketree(num, sgmt, 1,0,n-1);
	for(int t=0; t<(m+k); t++){
		ll a,b,c; cin >> a >> b >> c;
		if(a==1) change(sgmt, 1, 0, n-1, b-1, c);
		else cout << mult(sgmt, 1, 0, n-1, b-1, c-1) << '\n';
	}
	return 0;
}