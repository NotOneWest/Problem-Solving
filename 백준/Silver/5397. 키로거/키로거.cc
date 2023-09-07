#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end();

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >> n;
	for(int i=0; i<n; i++){
		string s; cin >> s;
		list<char> lc;
		auto cur = lc.begin();
		for(int j=0; j<s.size(); j++){
			if(s[j] == '<'){
				if(cur != lc.begin()) cur--;
			}
			else if(s[j] == '>'){
				if(cur != lc.end()) cur++;
			}
			else if(s[j] == '-'){
				if(cur != lc.begin()){
					auto temp = cur;
					cur--;
					lc.erase(cur);
					cur = temp;
				}
			}
			else lc.insert(cur, s[j]);
		}
		for(auto t : lc) cout << t <<"";
		if(i<n-1) cout<<'\n';
	}
	return 0;
}