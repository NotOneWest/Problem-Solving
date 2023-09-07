#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end();

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

const int MX = 10000007;
int st[MX];
int pos;

void push(int x){
	st[pos] = x;
	pos++;
}

void pop(){
	if(pos != 0){
		printf("%d\n", st[pos-1]);
		pos--;
	}
	else printf("-1\n");
}

int main(){
	int n; cin >> n;
	for(int i=0; i<n; i++){
		string s; cin >> s;
		if(s == "push"){
			int x; cin >> x;
			push(x);
		}
		else if(s == "pop") pop();
		else if(s == "size") printf("%d\n", pos);
		else if(s == "empty"){
			if(pos == 0) printf("1\n");
			else printf("0\n");
		}
		else{
			if(pos != 0) printf("%d\n", st[pos-1]);
			else printf("-1\n");
		}
	}
	return 0;
}