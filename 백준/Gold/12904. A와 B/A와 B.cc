#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	string s, t; cin >> s >> t;
	int result=0;
	
	while(1){
		if(s.length() == t.length()){
			result = (s == t);
			break;
		}
		
		if(t[t.length()-1] == 'A') t = t.substr(0, t.length()-1);
		else if(t[t.length()-1] == 'B'){
			t = t.substr(0, t.length()-1);
			reverse(t.begin(), t.end());
		}
	}
	cout << result << '\n';
	return 0;
}