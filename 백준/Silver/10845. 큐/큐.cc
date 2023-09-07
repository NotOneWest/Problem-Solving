#include <bits/stdc++.h>
using namespace std;

int main(){
	int n; cin >> n;
	queue<int> q;
	for(int i=0; i<n; i++){
		string s; cin >> s;
		if(s[1] == 'u'){
			int x; cin >> x;
			q.push(x);
		}
		else if(s[1] == 'o'){
			if(q.size() == 0) printf("-1\n");
			else{
				printf("%d\n", q.front());
				q.pop();
			}
		}
		else if(s[0] == 's') printf("%d\n", q.size());
		else if(s[0] == 'e'){
			if(q.empty()) printf("1\n");
			else printf("0\n");
		}
		else if(s[0] == 'f'){
			if(q.size() == 0) printf("-1\n");
			else printf("%d\n", q.front());
		}
		else{
			if(q.size() == 0) printf("-1\n");
			else printf("%d\n", q.back());
		}
	}
}