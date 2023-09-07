#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n; cin >> n;
	ll k, standard=pow(2, n-1), next=standard/2; cin >> k;
	int from=1, by=2, to=3;
	while(1){
		
		if(k == standard) {cout << from << " " << to << "\n"; break;}
		else if(k < standard) {int temp=to; to=by; by=temp; standard-=next;}
		else {int temp=by; by=from; from=temp; standard+=next;}
		next /= 2;
	}
	return 0;
}