#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);
const int IntMax = 2147483647;

int n, m, mx=0, city[51][51], selection[14], ans=IntMax;
vector<pii> v[3];

int chickenDistance(){
	int sum=0, sz1=v[1].size(), sz2=v[2].size();
	for(int i=0; i<sz1; i++){
		int temp=IntMax;
		for(int j=0; j<sz2; j++){
			if(selection[j]==0) continue;
			temp=min(temp, (abs(v[1][i].first-v[2][j].first)+abs(v[1][i].second-v[2][j].second)));
		}
		sum+=temp;
	}
	return sum;
}


void selectChickenHouse(int idx, int cnt){
	int sz2=v[2].size();
	if(cnt==m){
		int curr = chickenDistance();
		ans=min(ans, curr);
		return;
	}
	for(int i=idx; i<sz2; i++){
		if(selection[i]==1) continue;
		selection[i]=1;
		city[v[2][i].first][v[2][i].second]=-1;
		selectChickenHouse(i, cnt+1);
		selection[i]=0;
		city[v[2][i].first][v[2][i].second]=2;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin >> city[i][j];
			if(city[i][j]==1) v[1].pb(mp(i,j));
			if(city[i][j]==2) v[2].pb(mp(i,j));
		}
	}
	selectChickenHouse(0, 0);
	cout << ans << '\n';
	return 0;
}
