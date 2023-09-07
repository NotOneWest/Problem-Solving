#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end();

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int main(){
	int n; cin >> n;
	int tower[n], ans[n]={0,};
	for(int i=0; i<n; i++) scanf("%d", &tower[i]);
	stack<pii> st;
	st.push(mp(0,tower[0]));
	for(int i=1; i<n; i++){
		while(!st.empty() && st.top().second < tower[i]) st.pop();
		if(st.size() == 0) ans[i] = 0;
		else ans[i] = st.top().first+1;
		st.push(mp(i,tower[i]));
	}
	for(auto i : ans) printf("%d ", i);
	return 0;
}