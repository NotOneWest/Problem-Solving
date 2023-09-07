#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int num[101],sum=0;

int main(){
	int n,m; cin >> n >> m;
	for(int i=0; i<n; i++) scanf("%d", &num[i]);
	for(int i=0; i<n-2; i++){
		for(int j=i+1; j<n-1; j++){
			for(int k=j+1; k<n; k++){
				if((num[i]+num[j]+num[k])==m){
					sum=m;
					break;
				}
				else if(sum<(num[i]+num[j]+num[k]) && (num[i]+num[j]+num[k])<m){
					sum=(num[i]+num[j]+num[k]);
				}
			}
			if(sum==m) break;
		}
		if(sum==m) break;
	}
	printf("%d",sum);
	return 0;
}
