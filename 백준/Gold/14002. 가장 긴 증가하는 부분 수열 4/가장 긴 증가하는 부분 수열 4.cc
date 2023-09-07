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
pii ans[1000001];
stack<int> s;

int main(){
	int n,index=0; cin >> n;
	for(int i=0; i<n; i++) cin >> num[i];
	for(int i=0; i<n; i++){
		if(dp.empty() || dp.back()<num[i]){
			dp.pb(num[i]);
			ans[i]={dp.size()-1,num[i]}; // 바로 직전 index 
		}
		else{
			int low=0, high=dp.size()-1;
			while(high>low){
				int mid=(low+high)/2;
				if(dp[mid]<num[i]) low=mid+1;
				else high=mid;
			}
			dp[high]=num[i]; // 같은 값을 처리하거나, 끝에 값만 바꿔주는게 아니라 그냥 바꿔주면 된다.
			ans[i].first=high; // 바로 직전 index 
			ans[i].second=num[i];
		}
	}
	int size=dp.size();
	cout << size << '\n';
	for(int i=n-1; i>=0; i--){
		if(ans[i].first==(size-1)){
			s.push(ans[i].second);
			size--;
		}
	}
	while(!s.empty()){
		cout << s.top() << ' ';
		s.pop();
	}
	return 0;
}
