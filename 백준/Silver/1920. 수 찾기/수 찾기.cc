#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int num[100001], num2[100001];

bool bs(int k, int low, int high){
	int check=0;
	while(low<=high){
		int mid=(low+high)/2;
    // cout << low << " \\ "<< high << " \\ " << mid << "[]\n";
		if(k>num2[mid]) low=mid+1;
		else if(k<num2[mid]) high=mid-1;
		else{
			check=1;
			break;
		}
	}
	if(check) return true;
	else return false;
}

int main(){
	int n,m; cin >> n;
	for(int i=0; i<n; i++) cin >> num2[i];
	cin >> m;
	for(int i=0; i<m; i++) cin >> num[i];
	sort(num2,num2+n);
	for(int i=0; i<m; i++){
		if(bs(num[i],0,n-1)) cout << 1 << '\n';
		else cout << 0 << '\n';
	}
  // for(int i=0; i<n+1; i++) cout << num2[i] << " = ";

	return 0;
}
