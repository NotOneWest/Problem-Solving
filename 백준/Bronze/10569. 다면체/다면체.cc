#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end();

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int main(){
	int t; cin >> t;
	for(int i=0; i<t; i++){
		int v,e; cin >> v >> e;
		printf("%d\n", 2+e-v);
	}
	return 0;
}