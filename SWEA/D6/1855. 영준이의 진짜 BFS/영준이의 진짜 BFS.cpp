#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int n, m;
int depth[100001];
int parent[100001][20];
vector<int> alist[100001];

int LCA(int a, int b){
	if(depth[a] < depth[b]) swap(a, b);
	
	int diff = (depth[a] - depth[b]);
	for(int i=0; diff!=0; i++){
		if(diff%2) a = parent[a][i];
		diff/=2;
	}
	
	// 깊이 같아지면
	if(a != b){
		// 점프할 수 있는 최대 거리부터 탐색 
		for(int i = 19; i>=0; i--){
			// Tree 범위이고, 부모가 다르면 점프 
			if(parent[a][i] != -1 && parent[a][i] != parent[b][i]){
				a = parent[a][i];
				b = parent[b][i];
			}
		}
		// 최대로  점프한 곳의 바로 위 -> LCA 
		a = parent[a][0];
	} 
	return a; 
}

int main(int argc, char** argv) {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int test_case;
	int T; cin>>T;
	//freopen("input.txt", "r", stdin);
	for(test_case = 1; test_case <= T; ++test_case) {
		cin >> n;
		for(int i=0; i<100001; i++){
			for(int j=0; j<20; j++) parent[i][j] = -1;
			alist[i].clear();
		}
		for(int i=0; i<=n; i++) depth[i] = -1;
		depth[1] = 0;
		
		for(int i=2; i<=n; i++){
			int p; cin >> p;
			parent[i][0] = p;
			depth[i] = depth[p] + 1;
			alist[p].push_back(i);
		}
		
		// 2^j 번째 부모 연결 
		for(int i=1; i<20; i++){
			for(int j=2; j <= n; j++){
				if(parent[j][i-1] != -1) parent[j][i] = parent[parent[j][i-1]][i-1];
			}	
		}
		
		long long ans = 0;
		queue<int> q;
		q.push(1);
		while(!q.empty()){
			int from = q.front(); q.pop();
			for(int to : alist[from]) q.push(to);
			
			if(q.empty()) break;
			
			// 경로는 from - same - to
			// from의 깊이 + to의 깊이 - (공통 조상의 깊이 * 2)
			// 루트에서 from, 루트에서 to 거리에서 공통 조상 거리를 2번 빼면
			// from -> to 이동 거리와 같다. 
			int same = LCA(from, q.front());
			ans += (depth[from] + depth[q.front()] - depth[same]*2);
		}
		cout << "#" << test_case << " " << ans << "\n";
	}
	return 0;
}