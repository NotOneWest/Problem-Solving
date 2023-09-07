#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

bool compare(pair<pii,int> a, pair<pii,int> b){return a.second < b.second;}
vector<pair<pii,int>> es;
int check[10001]={0,}; // 연결 확인용. 

int parent(int a){ // 연결된 것들 중 가장 위에 있는 것 찾기. 
	if(a==check[a]) return a;
	return check[a]=parent(check[a]);
}

void merge(int a, int b){ // 거리 짧은거로 합치기. 
	a=parent(a);
	b=parent(b);
	if(a!=b) check[b]=a;
}

int kruskal(){
	int weight=0;
	for(auto x : es){
		int v1=x.first.first, v2=x.first.second, w=x.second;
		if(parent(v1)!=parent(v2)){
			merge(v1, v2);
			weight += w;
		}
	}
	return weight;
}

int main(){
	int v,e; cin >> v >> e;
	for(int i=0; i<e; i++){
		int v1, v2, w; cin >> v1 >> v2 >> w;
		es.pb(mp(mp(v1,v2),w));
	}
	for(int i=0; i<=v; i++) check[i]=i;
	sort(all(es),compare);
	cout << kruskal();
	return 0;
}
