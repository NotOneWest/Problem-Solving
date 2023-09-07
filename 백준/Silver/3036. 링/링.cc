#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int gcd(int a, int b){
	if(a==0) return b;
	return gcd(b%a, a);
}

int main(){
	int n; cin >> n;
	int num[n];
	for(int i=0; i<n; i++) scanf("%d", &num[i]);
	for(int i=1; i<n; i++){
		int g = gcd(num[0],num[i]);
		printf("%d/%d\n", num[0]/g, num[i]/g);
	}
	return 0;
}
