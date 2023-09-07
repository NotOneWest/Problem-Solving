#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

vector<pii> edges[10001]; // 기준 노드마다 연결을 저장. 
int visit[10001]={0,};

int prim(int start){
	visit[start]=1;
	priority_queue<pii, vector<pii>, greater<pii>> pq; // w, next v -> w로 정렬
	// 항상 그 연결 노드에서 최소 거리인 연결이 사용되게 된다. 
	for(int i=0; i<edges[start].size(); i++){
		pq.push(mp(edges[start][i].second,edges[start][i].first));
	}
	int weight=0;
	while(!pq.empty()){
		int nextv=pq.top().second;
		int w=pq.top().first;
		pq.pop(); 
		if(visit[nextv]) continue; 
		weight+=w;
		visit[nextv]=1;
		for(int i=0; i<edges[nextv].size(); i++){ // 연결된 v 를 기준으로 또 넣어서 실행. 
			pq.push(mp(edges[nextv][i].second,edges[nextv][i].first));
		} 
	}
	return weight;
}

int main(){
	int v,e; cin >> v >> e;
	for(int i=0; i<e; i++){
		int v1, v2, w; cin >> v1 >> v2 >> w;
		edges[v1].pb(mp(v2,w)); 
		edges[v2].pb(mp(v1,w));
		// merge 하기 때문에 한번에 처리되는 kruskal 과 다르게 
		// prim 은 하나의 v 만 처리하기 때문에 양방향으로 넣어야 한다. 
		 
	}
	cout << prim(1); 
	return 0;
}
