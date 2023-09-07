#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int main(){
	int get[3] , num[6]={0,}, same=0, index=0;
	for(int i=0; i<3; i++){
		int n; cin >> n;
		get[i]=n;
		num[n-1]++;
	}
	sort(get, get+3);
	for(int i=0; i<3; i++){
		if(num[get[i]-1] > same){
			same = num[get[i]-1];
			index = i;
		}
	}
	if(same == 1) cout << get[2]*100;
	else if(same == 2) cout << get[index]*100+1000;
	else cout << get[index]*1000 + 10000;
	return 0;
}
