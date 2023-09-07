#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int main(){
	int n, k; cin >> n >> k;
	int num[n-1]={0,}, ans[n-1]={0,}, w=0;
	for(int i=2; i<=n; i++) num[i-2]=i;
	for(int i=2; i<=n; i++){
		for(int j=0; j<n-1; j++){
			if(num[j] !=0 && num[j]%i == 0){
				ans[w]=num[j];
				num[j]=0;
				w++;
			}
		}
	}
	printf("%d", ans[k-1]);
	return 0;
}
