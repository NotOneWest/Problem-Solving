#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

ll refib(int n){
	if(n==0) return 0;
	if(n==1 || n==2) return 1;
	else return refib(n-1) + refib(n-2);
}


int main(){
	int n; cin >> n;
	cout << refib(n);
	return 0;
}
