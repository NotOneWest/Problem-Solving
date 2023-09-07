#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int num[1000001]; 
vector<int> dp;

int main(){
	int n,index=0; cin >> n;
	for(int i=0; i<n; i++) cin >> num[i];
	for(int i=0; i<n; i++){
		if(dp.empty() || dp.back()<num[i]) dp.pb(num[i]);
		else{
			int low=0, high=dp.size();
			while(high>low){
				int mid=(low+high)/2;
				if(dp[mid]<num[i]) low=mid+1;
				else high=mid;
			}
			dp[high]=num[i];
		}
	}
	cout << dp.size();
	return 0;
}
