#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, num=0; cin>>n;
	for(int i=0; i<n; i++){
		string s; cin>>s;
		stack<char> st;
		st.push(s[0]);
		int len = s.length();
		for(int j=1; j<len; j++){
			if(st.empty()) st.push(s[j]);	
			else {
				if(s[j] == st.top()) st.pop();
				else st.push(s[j]);
			}
		}
		if(st.size() == 0) num++;
	}
	printf("%d", num);
	return 0;
}