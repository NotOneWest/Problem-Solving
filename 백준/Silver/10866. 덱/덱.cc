#include <bits/stdc++.h>
using namespace std;

int main(){
	int n; cin >> n;
	deque<int> dq;
	for(int i=0; i<n; i++){
		string s; cin >> s;
		if(s == "push_front"){
			int x; cin >> x;
			dq.push_front(x);
		}
		else if(s == "push_back"){
			int x; cin >> x;
			dq.push_back(x);
		}
		else if(s == "pop_front"){
			if(dq.size() == 0) printf("-1\n");
			else{
				printf("%d\n", dq.front());
				dq.pop_front();
			}
		}
		else if(s == "pop_back"){
			if(dq.size() == 0) printf("-1\n");
			else{
				printf("%d\n", dq.back());
				dq.pop_back();
			}
		}
		else if(s[0] == 's') printf("%d\n", dq.size());
		else if(s[0] == 'e'){
			if(dq.empty()) printf("1\n");
			else printf("0\n");
		}
		else if(s[0] == 'f'){
			if(dq.size() == 0) printf("-1\n");
			else printf("%d\n", dq.front());
		}
		else if(s[0] == 'b'){
			if(dq.size() == 0) printf("-1\n");
			else printf("%d\n", dq.back());
		}
	}
}