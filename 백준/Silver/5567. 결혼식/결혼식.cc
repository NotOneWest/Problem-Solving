#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

vector<int> v[501]; // 친구인 관계 저장
int friends[501]; // 거리를 저장

void bfs(int start){ // bfs를 이용해 최단거리를 측정하듯이 상근이와 관계 설정
    friends[start]=0;
    queue<int> q;
    q.push(start);
    while(!q.empty()){
        int no = q.front();
        q.pop();
        for(int i=0; i<v[no].size(); i++){
            int next = v[no][i];
            if(friends[next]==-1){
                friends[next] = friends[no]+1;
                q.push(next);
            }
        }
    }
}

int main(){
    int n, m, cnt=0; cin >> n >> m;
    for(int i=0; i<m; i++){
        int x,y; cin >> x >> y;
        v[x].pb(y);
        v[y].pb(x); // 두 사람 모두에세 친구라는 표시 해줌
    }
    fill(friends, friends+501, -1);
    bfs(1);
    for(int i=2; i<=n; i++){
        if(friends[i]==1 || friends[i]==2) cnt++;
    }
    cout << cnt;
	return 0;
}