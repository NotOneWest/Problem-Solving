#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int main(){
	int n,k,temp; cin >> n >> k;
	int cnt[100002]={0,}, route[100002]={0,};
	for(int i=0; i<100002; i++){
		cnt[i] = -1;
		route[i] = -1;
	}
	vector<int> v;
	queue<int> q;
	q.push(n);
	cnt[n]=0;
	while(!q.empty()){
		temp = q.front();
		q.pop();
		if(temp > 0){
			if(cnt[temp-1] < 0){
				cnt[temp-1] = cnt[temp]+1;
				route[temp-1] = temp;
				q.push(temp-1);
			}
		}
		if(temp+1<=k && cnt[temp+1] < 0){
			cnt[temp+1] = cnt[temp]+1;
			route[temp+1] = temp;
			q.push(temp+1);
		}
		if(temp!=0 && temp*2<=100000 && cnt[temp*2] < 0){
			cnt[temp*2] = cnt[temp]+1;
			route[temp*2] = temp;
			q.push(temp*2);
		}
	}
	cout << cnt[k] << '\n';
	temp=k;
	v.pb(temp);
	for(int i=0; i<cnt[k]; i++){
		v.pb(route[temp]);
		temp = route[temp];
	}
	for(int i=v.size()-1; i>=0; i--) cout << v[i] <<' ';
	return 0;
}