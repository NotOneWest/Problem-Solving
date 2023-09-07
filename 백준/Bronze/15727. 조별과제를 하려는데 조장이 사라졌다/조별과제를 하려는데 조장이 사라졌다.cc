#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int main(){
	int n,t=0; cin >> n;
	while(n>0){
		t++;
		n-=5;
	}
	cout << t;
	return 0;
}
