#include <bits/stdc++.h>
using namespace std;

int main(){
	int n; cin >> n;
	queue<int> q;
	for(int i=1; i<=n; i++) q.push(i);
	while(q.size() != 1){
		printf("%d ", q.front());
		q.pop();
		q.push(q.front());
		q.pop();
	}
	printf("%d", q.front());
	return 0;
}