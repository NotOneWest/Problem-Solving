#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int tower[1000002], cnt[1000002];

int main(){
	int f,s,g,u,d; cin >> f >> s >> g >> u >> d;
	
	for(int i=0; i<=f; i++) cnt[i] = -1;
	queue<int> q;
	q.push(s);
	cnt[s]=0;
	while(!q.empty()){
		int temp = q.front();
		q.pop();
		if(temp+u<=f && cnt[temp+u]<0){
			q.push(temp+u);
			cnt[temp+u]=cnt[temp]+1;
		}
		if(temp-d>=1){
			if(cnt[temp-d]<0){
				q.push(temp-d);
				cnt[temp-d]=cnt[temp]+1;
			}
		}
	}
	if(cnt[g]==-1) cout << "use the stairs";
	else cout << cnt[g];
	return 0;
}
