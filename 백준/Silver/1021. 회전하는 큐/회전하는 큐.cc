#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end();

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int main(){
	int n, m; cin >> n >> m;
	int num[m], cnt=0;
	for(int i=0; i<m; i++) scanf("%d", &num[i]);
	deque<int> dq;
	for(int i=1; i<=n; i++) dq.push_back(i);
	int i=0;
	while(i<m){
		int index=0;
		deque<int>::iterator iter;
		for(auto iter=dq.begin(); iter!=dq.end(); iter++){
			if(*iter == num[i]) break;
			index++;
		}
		if(num[i] == dq.front()){
			dq.pop_front();
			i++;
		}
		else{
			if(index > dq.size()-index){
				while(num[i] != dq.front()){
					dq.push_front(dq.back());
					dq.pop_back();
					cnt++;
				}
			}
			else{
				while(num[i] != dq.front()){
					dq.push_back(dq.front());
					dq.pop_front();
					cnt++;
				}
			}
		}
	}
	printf("%d", cnt);
	return 0;
}