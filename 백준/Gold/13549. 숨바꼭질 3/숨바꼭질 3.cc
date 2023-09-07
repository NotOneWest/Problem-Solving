#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int main(){
	int n,k; cin >> n >> k;
	int cnt[100002]={0,};
	for(int i=0; i<100002; i++) cnt[i] = -1;
	queue<int> q;
	q.push(n);
	cnt[n]=0;
	while(!q.empty()){
		int temp = q.front();
		if(temp!=0 && temp*2<=100000 && cnt[temp*2] < 0){
			cnt[temp*2] = cnt[temp];
			q.push(temp*2);
		}
		if(temp > 0){
			if(cnt[temp-1] < 0){
				cnt[temp-1] = cnt[temp]+1;
				q.push(temp-1);	
			}
		}
		if(temp+1<=k && cnt[temp+1] < 0){
			cnt[temp+1] = cnt[temp]+1;
			q.push(temp+1);
		}
		q.pop();
	}
	cout << cnt[k];
	return 0;
}