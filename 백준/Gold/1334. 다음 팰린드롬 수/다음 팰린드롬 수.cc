#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	string n, ans=""; cin >> n;
	
	for(int i=0; i<n.length(); i++){
		if(i < (n.length()/2)) ans += n[i];
		else ans += n[n.length() - i - 1];
	}
	
	if(n == "9") ans="11";
	else{
		if(ans <= n){
			if(ans[ans.length()/2] != '9'){
				ans[ans.length()/2]++;
				if(n.length()%2 == 0) ans[ans.length()/2 - 1]++;
			} else{
				string temp = ans.substr(0, ans.length()/2);
				
				int carry = 1;
				for(int i=(temp.length() - 1); i>=0; i--){
					if(carry){
						if(temp[i] == '9') temp[i] = '0';
						else{ temp[i]++; carry = 0; }
					} else break;
				}
				
				if(temp[0] == '0'){ ans = "1"; ans += temp; }
				else ans = temp;
				
				if(n.length()%2) ans += '0';
				for(int i=(n.length()/2-1); i>=0; i--) ans += ans[i];
			}
		}
	}
	
	cout << ans << '\n';
	return 0;
}