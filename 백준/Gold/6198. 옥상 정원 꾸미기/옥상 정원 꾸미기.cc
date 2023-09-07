#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;

int main(){
	int N;cin>>N;
	int h[N];
	long long sum=0;
	for(int i=0; i<N; i++) scanf("%d", &h[i]);
	
	stack<int> s;
	s.push(h[0]);
	
	for(int t=1; t<N;t++){
		while(!s.empty() && s.top()<=h[t]) s.pop();
		sum += s.size();
		s.push(h[t]);
	}
	printf("%lld", sum);
	return 0;
}