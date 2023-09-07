#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int main(){
	int t;cin >> t;
	for(int p=0; p<t; p++){
		int n,m,cnt=0; cin >> n >> m;
		queue< pii > q;
		priority_queue<int> pq;
		for(int i=0; i<n; i++){
			int num; cin >> num;
			q.push(mp(i,num)); // 위치 기억하고 값 비교하기 위한 것 (중복 처리) 
			pq.push(num); // 가중치 순서 처리 
		}
		while(!q.empty()){
			int index=q.front().first;
			int weights=q.front().second;
			q.pop();
			if(pq.top()==weights){
				pq.pop();
				cnt++;
				if(index==m){ // 중복 값 처리. 
					cout << cnt << '\n';
					break;
				}
			}
			else q.push(mp(index, weights)); // 중요도에 따른 재배치
		}
	}
	return 0;
}
