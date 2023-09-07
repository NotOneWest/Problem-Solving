#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int main(){
	int n, cnt=0, i=0; cin >> n;
	n = 1000 - n;
	int money[6]={500, 100, 50, 10, 5, 1};
	while(n!=0){
		cnt+=n/money[i];
		n = n%money[i];
		i++;
	}
	printf("%d", cnt);
	return 0;
}
