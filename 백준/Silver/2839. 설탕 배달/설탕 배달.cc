#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int main(){
	int n, cnt=0; cin >> n;
	if(n<3) cnt=-1;
	else{
		while(n>1){
			if(n%5!=0){
				n-=3;
				cnt++;
			}
			else{
				cnt+=n/5;
				n=n%5;
			}
		}
		if(n==1) cnt=-1;
	}
	cout << cnt;
	return 0;
}
