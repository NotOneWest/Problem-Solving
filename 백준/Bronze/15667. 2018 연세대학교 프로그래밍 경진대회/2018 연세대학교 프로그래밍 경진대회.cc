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
	for(int i=1; i<101; i++){
		if((1+i+i*i) == n){
			cout << i;
			break;
		}
	}
	return 0;
}
