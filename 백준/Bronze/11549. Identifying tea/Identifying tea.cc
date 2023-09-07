#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end();

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int main(){
	int t, type[5]={0,}, cnt=0; cin >> t;
	for(int i=0; i<5; i++) scanf("%d", &type[i]);
	sort(type, type+5);
	for(int i=0; i<5; i++){
		if(type[i] == t) cnt++;
	}
	printf("%d", cnt);
	return 0;
}