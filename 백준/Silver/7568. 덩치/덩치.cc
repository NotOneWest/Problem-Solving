#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
  vector< pii > v;
  int n; cin >> n;
	int rank[n];
  for(int i=0; i<n; i++){
    int x,y; cin >> x >> y;
    v.push_back(pii(x,y));
  }
  for(int i=0; i<n; i++){
		int cnt=1;
		for(int j=0; j<n; j++){
			if(i==j) continue;
			if(v[i].second < v[j].second){
				if(v[i].first < v[j].first) cnt++;
			}
		}
		rank[i]=cnt;
  }
	for(int i=0; i<n; i++){
		cout << rank[i] << ' ';
	}
	return 0;
}
