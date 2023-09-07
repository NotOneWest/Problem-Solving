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
	int t; cin >> t;
	for(int i=0; i<t; i++){
		string s; cin >> s;
		int len = s.length() , check=0;
		for(int j=0; j<len; j++){
			if(s[j] == '(') check ++;
			else{
				if(check == 0){
					check = -1;
					break;
				}
				else check--;
			}
		}
		if(check == 0) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}
