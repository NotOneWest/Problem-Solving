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
		for(int j=0; j<i; j++) cout << '*';
		cout << '\n';
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<n-i; j++) cout << '*';
		if(i<n-1) cout << '\n';
	}
	return 0;
}
