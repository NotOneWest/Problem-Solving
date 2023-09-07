#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int main(){
	int l,a,b,c,d; cin >> l >> a >> b >> c >> d;
	int math=b/d, korean=a/c;
	if(a%c!=0) korean++;
	if(b%d!=0) math++;
	if(math>korean) printf("%d", l-math);
	else printf("%d", l-korean);
	return 0;
}
