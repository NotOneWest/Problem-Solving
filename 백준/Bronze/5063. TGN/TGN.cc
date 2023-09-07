#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int main(){
	int n; cin >> n;
	for(int i=0; i<n; i++){
		int r,e,c; cin >> r >> e >> c;
		if(r == (e-c)) printf("does not matter\n");
		else if(r > (e-c)) printf("do not advertise\n");
		else printf("advertise\n");
	}
	return 0;
}
