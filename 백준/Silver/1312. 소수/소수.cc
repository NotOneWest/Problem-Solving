#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int main(){
	int a,b;
	ll n, res;
	cin >> a >> b >> n;
	for(int i=0; i<n; i++){
		if((a%=b)==0){
			res=0;
			i=n;
		}else{
			a=(a%=b);
			res = (a*10)/b;
			a=a*10;
			a=(a%=b);	
		}
	}
	cout << res;
	return 0;
}
