#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int main(){
	int num[3];
	for(int i=0; i<3; i++) cin >> num[i];
	sort(num, num+3);
	for(auto i : num) cout << i << ' ';
	return 0;
}