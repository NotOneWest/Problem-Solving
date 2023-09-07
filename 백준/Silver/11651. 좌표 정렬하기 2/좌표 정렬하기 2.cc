#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	vector< pair<int, int> > v;
	for(int i=0; i<n; i++){
		int a,b;
		scanf("%d %d", &a, &b);
		v.push_back(make_pair(b,a)); // pair에 각각 넣어줌
	}
	sort(v.begin(), v.end());
	for(int i=0; i<n; i++){
		printf("%d %d\n", v[i].second, v[i].first);
	}	
	return 0;
} 