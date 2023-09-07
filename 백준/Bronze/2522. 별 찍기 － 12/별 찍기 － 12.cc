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
	for(int i=1; i<n; i++){
		for(int j=0; j<n; j++){
			if(j<n-i) cout << ' ';
			else cout << '*';
		}
		cout << '\n';
	}
	for(int i=n; i>=0; i--){
		for(int j=0; j<n; j++){
			if(j<n-i) cout << ' ';
			else cout << '*';
		}
		if(i>1) cout << '\n';
	}
	return 0;
}
