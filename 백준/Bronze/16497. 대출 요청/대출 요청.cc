#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int days[32];

int main(){
	int n; cin >> n;
	for(int i=0; i<n; i++){
		int get, back; cin >> get >> back;
		for(int j=get; j<back; j++) days[j]++;	
	} 
	int k,check=0; cin >> k;
	for(int i=1; i<32; i++){
		if(days[i] > k){
			check=1;
			break;
		}
	}
	if(check) cout << 0;
	else cout << 1;
	return 0;
}
