#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end();

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int main(){
	string s; cin >> s;
	int cnt=0;
	stack<char> st;
	for(int i=0; i<s.length(); i++){
		if(st.size() == 0 && s[i] == '(') st.push(s[i]);
		else if(s[i] == '(') st.push(s[i]);
		else{
			st.pop();
			if(s[i-1] == '(') cnt += st.size();
			else cnt++;
		}
	}
	printf("%d", cnt);
	return 0;
}