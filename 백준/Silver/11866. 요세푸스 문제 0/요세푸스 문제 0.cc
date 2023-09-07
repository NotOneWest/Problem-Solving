#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, k; cin >> n >> k;
	string answer = "<";
	queue<int> q;
	for(int i=1; i<=n; i++) q.push(i);
	while(1){
		if(q.size() == 1) break;
		
		for(int i=0; i<k-1; i++){
			q.push(q.front());
			q.pop();
		}
		answer += (to_string(q.front()) + ", ");
		q.pop();
		if(q.size() == 1) break;
	}
	answer += (to_string(q.front()) + ">");
	printf("%s", answer.c_str());
	return 0;
}