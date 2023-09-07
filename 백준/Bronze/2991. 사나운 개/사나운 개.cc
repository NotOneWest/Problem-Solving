#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int main(){
	int a,b,c,d; cin >> a >> b >> c >> d;
	int pmn[3], pmnc[3]={0,};
	for(int i=0; i<3; i++){
		int n; cin >> n;
		pmn[i]=n;
		pmnc[i]=n;
	}
	int at[3]={0,};
	for(int i=0; i<3; i++){
		while(pmn[i]>0){
			if(pmn[i]<=a) at[i]++;
			pmn[i]-=(a+b);
		}
		while(pmnc[i]>0){
			if(pmnc[i]<=c) at[i]++;
			pmnc[i]-=(c+d);
		}	
	}
	for(auto i : at) cout << i << '\n';
	return 0;
}
