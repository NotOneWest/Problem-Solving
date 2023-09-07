#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

vector< pii > v;

void hanoi(int n, int from, int by, int to){
	if(n==1) v.pb(mp(from,to));
	else{
		hanoi(n-1,from,to,by);
		v.pb(mp(from,to));
		hanoi(n-1,by,from,to);
	}
}

int main(){
	int n; cin >> n;
	hanoi(n,1,2,3);
	cout << v.size() << '\n'; 
	for(auto i : v) cout << i.first << ' ' << i.second << '\n';
	return 0;
}
