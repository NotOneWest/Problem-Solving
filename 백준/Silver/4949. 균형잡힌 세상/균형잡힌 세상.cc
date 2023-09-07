#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	while(1){
		string s;
		getline(cin, s); 
		stack<char> st;
		int size = s.size();
		bool check = true;
		if(size == 1 && s[0] == '.') break;
		for(int i=0; i<size; i++){
			if(s[i] == '(' || s[i] == '[') st.push(s[i]);
			else if(s[i] == ')'){
				if(!st.empty() && st.top() == '(') st.pop();
				else {
					check = false;
					break;
				}
			}
			else if(s[i] == ']'){
				if(!st.empty() && st.top() == '[') st.pop();
				else {
					check = false;
					break;
				}
			}
		}
		if(check && st.empty()) cout << "yes\n";
		else cout << "no\n";
	}
	return 0;
}