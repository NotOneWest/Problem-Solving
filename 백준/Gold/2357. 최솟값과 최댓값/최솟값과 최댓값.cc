#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);
const int MAX=1000000001;

int num[100001], sgmt[400004], sgmt_max[400004];

void maketree(int node, int start, int end){
	if(start==end){
		sgmt[node]=num[start];
		return;
	}
	else{
		maketree(node*2, start, (start+end)/2);
		maketree(node*2+1, (start+end)/2+1, end);
		sgmt[node] = min(sgmt[node*2], sgmt[(node*2+1)]);
	}
}

void maketree_max(int node, int start, int end){
	if(start==end){
		sgmt_max[node]=num[start];
		return;
	}
	else{
		maketree_max(node*2, start, (start+end)/2);
		maketree_max(node*2+1, (start+end)/2+1, end);
		sgmt_max[node]= max(sgmt_max[node*2], sgmt_max[(node*2+1)]);
	}
}

int find(int node, int start, int end, int left, int right){
	if(left<=start && end<=right) return sgmt[node];
	else if(left>end || right<start) return MAX;
	else{
		return min(find(node*2, start, (start+end)/2, left, right), find(node*2+1, (start+end)/2+1, end, left, right));	
	}
}

int find_max(int node, int start, int end, int left, int right){
	if(left<=start && end<=right) return sgmt_max[node];
	else if(left>end || right<start) return -1;
	else{
		return max(find_max(node*2, start, (start+end)/2, left, right), find_max(node*2+1, (start+end)/2+1, end, left, right));	
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m; cin >> n >> m;
	for(int i=0; i<n; i++) cin >> num[i];
	maketree(1,0,n-1);
	maketree_max(1,0,n-1);
	for(int i=0; i<m; i++){
		int l,r; cin >> l >> r;
		cout << find(1,0,n-1,l-1,r-1) << ' ' << find_max(1,0,n-1,l-1,r-1) << '\n';
	}
	return 0;
}