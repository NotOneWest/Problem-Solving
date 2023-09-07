#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int main(){
	int n; cin >> n;
	int end = (2*n-1)/2;
	for(int i=0; i<n-1; i++){
		for(int j=0; j<2*n-1-i; j++){
			if(j < i) cout << ' ';
			else cout << '*';
		}
		cout << '\n';
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<i+n; j++){
			if(j < (end-i)) cout << ' ';
			else cout << '*';
		}
		if(i<n-1) cout << '\n';
	}
	return 0;
}
