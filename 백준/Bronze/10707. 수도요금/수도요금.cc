#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end();

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int main(){
	int a, b, c, d, p;
	cin >> a >> b >> c >> d >> p;
	int x=0, y=0;
	x = a*p;
	if(p<=c) y = b;
	else{
		y = b + (p-c)*d;
	}
	if(x<y) printf("%d", x);
	else printf("%d", y);
	return 0;
}
