#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int q[2000000];
int head=0, tail=0;

void push(int x){
	q[tail]=x;
	tail++;
}

void pop(){
	if(head==tail) cout << "-1\n";
	else{
		cout << q[head] << "\n";
		head++;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n; cin >> n;
	for(int i=0; i<n; i++){
		string s; cin >> s;
		if(s == "push"){
			int x; cin >> x;
			push(x);
		}else if(s == "pop"){
			pop();
		}else if(s == "front"){
			if((tail-head)==0) cout << "-1\n";
			else cout << q[head] << "\n";
		}else if(s == "back"){
			if((tail-head)==0) cout << "-1\n";
			else cout << q[tail-1] << "\n";
		}else if(s == "size"){
			cout << (tail-head) << "\n";
		}else{
			if((tail-head)==0) cout << "1\n";
			else cout << "0\n";
		}
	}
	return 0;
}
