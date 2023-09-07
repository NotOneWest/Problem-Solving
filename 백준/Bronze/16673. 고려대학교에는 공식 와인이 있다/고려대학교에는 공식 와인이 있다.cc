#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int main(){
	int c,k,p,sum=0; cin >> c >> k >> p;
	for(int i=1; i<=c; i++){
		sum+=(k*i+p*i*i);
	}
	cout << sum;
	return 0;
}
