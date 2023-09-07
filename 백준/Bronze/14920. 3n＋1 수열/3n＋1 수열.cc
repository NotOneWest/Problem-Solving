#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end();

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int main(){
	int n ,cnt=1; cin >> n;
	while(n != 1){
		if(n%2==0) n = n/2;
		else n = 3*n + 1;
		cnt++;
	}
	printf("%d", cnt);
	return 0;
}