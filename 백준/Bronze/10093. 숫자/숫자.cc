#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int main(){
	ll a,b; cin >> a >> b;
	if(a>b) swap(a,b);
	
	if(a==b) printf("0");
	else{
		printf("%d\n", b-a-1);
	}
	for(int i=a+1; i<b; i++) printf("%d ", i);
	return 0;
}
