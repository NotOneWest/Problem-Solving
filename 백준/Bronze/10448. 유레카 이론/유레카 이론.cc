#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int tnum[45];

void find_tnum(){
	for(int i=1; i<45; i++){
		for(int j=1; j<=i;j++){
			tnum[i]+=j;
		}
	}
}

int main(){
	find_tnum();
	int t; cin >> t;
	for(int i=0; i<t; i++){
		int k, check=0; cin >> k;
		for(int a=1; a<45; a++){
			for(int b=1; b<45; b++){
				for(int c=1; c<45; c++){
					if( k == (tnum[a]+tnum[b]+tnum[c]) ){
						check=1;
					}
				}
			}
		}
		if(check) cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}
