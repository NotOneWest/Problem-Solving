#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int main(){
	int n; cin >> n;
	int num[n];
	for(int i=0; i<n; i++) scanf("%d", &num[i]);
	sort(num,num+n);
	printf("1\n");
	for(int i=2; i<=num[0]; i++){
		int check=0;
		for(int j=0; j<n; j++) check+=(num[j]%i);
		if(check==0) printf("%d\n", i);
	}
	return 0;
}
