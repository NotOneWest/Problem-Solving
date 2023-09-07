#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int main(){
	string s; cin >> s;
	if(s[0]=='x') cout << 1;
	else if(s[0]=='-' && s[1]=='x') cout << -1;
	else{
		int i=-1;
		for(int t=0; t<s.length();t++){
			if(s[t]=='x'){
				i=t;
				break;
			}
		}
		if(i==-1) cout << 0;
		for(int j=0; j<i; j++) cout << s[j];
	}
	return 0;
}
