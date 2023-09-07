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
	if(n<25) cout << n/5;
	else if(n<125) cout << n/5+n/25;
	else cout << n/5+n/25+n/125;
	return 0;
}