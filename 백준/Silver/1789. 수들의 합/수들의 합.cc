#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int main(){
	ll s, n=1, i=1; cin >> s;
	while (n<s){
		n=(i*(i+1))/2;
		if(n>=s) break;
		else i++;
	}
	if(n == s) printf("%d", i);
	else printf("%d", i-1);
	return 0;
}
