#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int main(){
	int ans[5]={0,}, sum=0;
	vector<pii> v;
	for(int i=1; i<=8; i++){
		int score; cin >> score;
		v.pb(mp(score, i));
	}
	sort(all(v));
	for(int i=3; i<8; i++){
		sum += v[i].first;
		ans[i-3] = v[i].second;
	}
	sort(ans, ans+5);
	printf("%d\n", sum);
	for(auto i: ans) printf("%d ", i);
	return 0;
}
