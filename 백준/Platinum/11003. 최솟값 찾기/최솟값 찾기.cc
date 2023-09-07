#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

priority_queue<pii, vector<pii>, greater<pii>> pq; // 작은 순으로 인덱스와 함께 정렬. 

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL); 
	int n,l; cin >> n >> l;
	for(int i=0; i<n; i++){
		int a; cin >> a;
		pq.push(mp(a,i));
		while(pq.top().second<=(i-l)) pq.pop();
		cout << pq.top().first << ' ';	
	}
	return 0;
}
// 인덱스와 정렬해주면서 맨 처음 기준 인덱스 전에 있는 것이 최소라면 pop 해줘 제거해준다. 