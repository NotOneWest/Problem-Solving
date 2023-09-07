#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int main(){
	int t; cin >> t;
	for(int p=0; p<t; p++){
		int n,sum=0; cin >> n;
		int num[n+1]={0,};
		for(int i=2; i<=n; i++){
			for(int j=i; j<=n; j+=i){
				if(num[j]==0) num[j]=1;
				else num[j]=0;
			}
		}
		for(int i=1; i<=n; i++){
			if(num[i]==0) sum++;
		}
		cout << sum << '\n';
	}
	return 0;
}