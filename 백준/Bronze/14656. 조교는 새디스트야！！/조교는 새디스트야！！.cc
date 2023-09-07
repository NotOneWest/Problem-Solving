#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end();

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int main(){
	int n, cnt=0; cin >> n;
	for(int i=1; i<=n; i++){
		int stu; cin >> stu;
		if(stu != i) cnt++;
	}
	printf("%d", cnt);
	return 0;
}