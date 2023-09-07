#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int main(){
	int x,y,side;
	cin >> x;
	cin >> y;
	if (x>0 && y>0){
		side=1;
	} else if (x>0 && y<0){
		side=4;
	} else if (x<0 && y>0){
		side=2;
	} else {
		side=3;
	}
	cout << side;
	return 0;
}
