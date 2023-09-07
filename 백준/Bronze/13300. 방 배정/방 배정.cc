#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end();

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, k; cin >> n >> k;
	int m[6]={0,}, w[6]={0,}, room=0;
	for(int i=0; i<n; i++){
		int gender, age; cin >> gender >> age;
		if(gender == 0) w[age-1]++;
		else m[age-1]++;
	}
	for(int i=0; i<6; i++){
		room+=(m[i]/k + m[i]%k);
		room+=(w[i]/k + w[i]%k);
	}
	cout<< room;
	return 0;
}