#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int main(){
	int b[3], v[2];
	for(int i=0; i<5; i++){
		if(i<3) scanf("%d", &b[i]);
		else scanf("%d", &v[i-3]);
	}
	sort(b,b+3);
	sort(v,v+2);
	printf("%d", b[0]+v[0]-50);
	return 0;
}
