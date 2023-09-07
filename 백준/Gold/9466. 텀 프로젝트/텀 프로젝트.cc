#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

#define MX 100001

int student[MX], visit[MX], route[MX], cnt=0;
vector<int> v;

void setting(){
	for(int i=0; i<MX; i++){
		student[i]=0;
		visit[i]=0;
		route[i]=0;
	}	
}

void team(int leader){
	visit[leader]=1;
	int next = student[leader];
	v.push_back(next);
	if(visit[next] == 0){
		team(next);
	}
	if(route[next] == 0){
		if(next == leader) cnt++;
		else{
			for(int i=0; i<v.size(); i++){
				if(v[i] == student[next]){
					cnt += v.size()-i;
					break;
				}
			}
		}
	}
	v.clear();
	route[leader]=1;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	for(int k=0; k<t; k++){
		int n; cin >> n;
		setting();
		for(int i=1; i<n+1; i++) cin >> student[i];
		for(int i=1; i<n+1; i++){
			if(visit[i] == 0) team(i);
		}
		cout << n-cnt << '\n';
		cnt=0;
	}
	return 0;
}