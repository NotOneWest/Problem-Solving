#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

vector<pair<pii,int>> st;
int n, dp[1001][1001], visit[101];

int rpg(int str, int intel){
	if(dp[str][intel]!=-1) return dp[str][intel];
	int points=0, cnt=0;
	vector<int> v;
	for(int i=0; i<n; i++){
		if(str>=st[i].first.first || intel>=st[i].first.second){
			if(visit[i]==0){
				points+=st[i].second;
				visit[i]=1;
				v.pb(i);
			}
			cnt++;
		}
	}
	// 미리 초기화를 돌려주며 재귀를 돌리면 시간초과. 
	int maxcan=cnt; 
	if(points>0){ // 얻은 point 없으면 돌릴 필요가 없다. 
		for(int i=0; i<=points; i++){
			int nstr=min(1000,str+i);
			int nint=min(1000,intel+points-i);
			maxcan=max(maxcan, rpg(nstr, nint));
		}
	}
	for(int i=0; i<v.size(); i++) visit[v[i]]=0; // 이 때 초기화 해도 중간에 초기화가 되어 최대가 나오게 된다. 
	dp[str][intel]=maxcan;
	return maxcan;
}

int main(){
	cin >> n;
	int point=0;
	for(int i=1; i<=n; i++){
		int str, intel, pnt;
		scanf("%d %d %d", &str, &intel, &pnt);
		st.pb(mp(mp(str,intel),pnt));
	}
	for(int i=0; i<1001; i++) fill(dp[i], dp[i]+1001, -1);
	cout << rpg(1,1); 
	return 0;
}
