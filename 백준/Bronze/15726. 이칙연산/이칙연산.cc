#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int main(){
	double a,b,c; cin >> a >> b >> c;
	cout << (ll)max(a*b/c, ((a/b)*c));
	return 0;
}
