#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int main(){
	int n,w,h; cin >> n >> w >> h;
	for(int i=0; i<n; i++){
		int l, check=0; cin >> l;
		
		if((l*l)<=(w*w+h*h) || l<=w || l<=h) cout << "DA\n";
		else cout << "NE\n";
	}
	return 0;
}
