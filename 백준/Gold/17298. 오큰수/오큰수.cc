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
	int num[n], ans[n];
	for(int i=0; i<n; i++) scanf("%d", &num[i]);
	stack<int> st;
	st.push(1000001);
	for(int i=n-1; i>=0; i--){
		while(st.top() <= num[i]) st.pop();
		if(st.top() > 1000000) ans[i] = -1;
		else ans[i] = st.top();
		st.push(num[i]);
	}
	for(auto i : ans) printf("%d ", i);
	return 0;
}
