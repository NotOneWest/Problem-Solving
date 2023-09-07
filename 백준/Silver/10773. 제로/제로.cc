#include <bits/stdc++.h>
using namespace std;

int main(){
	int k, sum=0; cin>>k;
	stack<int> st;
	for(int i=0; i<k; i++){
		int n; cin>>n;
		if(n!=0) st.push(n);
		else st.pop();
	}
	
	while(st.size() != 0){
		sum+=st.top();
		st.pop();
	}
	printf("%d", sum);
	return 0;
}