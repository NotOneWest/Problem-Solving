#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int main(){
	for(int i=0; i<3; i++){
		int zero=0, one=0;
		for(int j=0; j<4; j++){
			int n; cin >> n;
			if(n == 1) one++;
			else zero++;
		}
		if(zero == 1 && one == 3) printf("A\n");
		else if(zero == 2 && one == 2) printf("B\n");
		else if(zero == 3 && one == 1) printf("C\n");
		else if(zero == 4 && one == 0) printf("D\n");
		else if(zero == 0&& one == 4)printf("E\n");
	}
	return 0;
}
