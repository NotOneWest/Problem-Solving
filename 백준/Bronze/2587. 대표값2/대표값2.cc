#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int main(){
	int num[5], avg=0;
	for(int i=0; i<5; i++){
		int n; cin >> n;
		num[i]=n;
		avg+=n;
	}
	sort(num, num+5);
	cout << avg/5 << '\n' << num[2];
	return 0;
}
