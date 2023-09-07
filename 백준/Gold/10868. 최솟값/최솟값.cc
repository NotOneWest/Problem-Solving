#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);
const int MAX=1000000001;

int num[100001], sgmt[400004];

void maketree(int node, int start, int end, int min){
	if(start==end){
		sgmt[node]=num[start];
		return;
	}
	else{
		for(int i=start; i<=end; i++){
			if(min>num[i]) min=num[i];	
		}
		sgmt[node]=min;
		maketree(node*2, start, (start+end)/2, MAX);
		maketree(node*2+1, (start+end)/2+1, end, MAX);
	}
}

int find(int node, int start, int end, int left, int right){
	if(left<=start && end<=right) return sgmt[node];
	else if(left>end || right<start) return MAX;
	else{
		return min(find(node*2, start, (start+end)/2, left, right), find(node*2+1, (start+end)/2+1, end, left, right));	
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m; cin >> n >> m;
	for(int i=0; i<n; i++) cin >> num[i];
	maketree(1,0,n-1,MAX);
	for(int i=0; i<m; i++){
		int l,r; cin >> l >> r;
		cout << find(1,0,n-1,l-1,r-1) << '\n';
	}
	return 0;
}
