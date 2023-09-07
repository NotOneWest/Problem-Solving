#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
#include <string>
#include <iostream>
using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	
	vector< pair<int, pair<int, string> > > v;
	
	for(int i=0; i<n; i++){
		int age;
		scanf("%d", &age);
		string name; cin >> name;
		v.push_back(make_pair(age, make_pair(i, name)));
	}
	sort(v.begin(), v.end());
	
	for(int i=0; i<n; i++) printf("%d %s\n", v[i].first, v[i].second.second.c_str());
	
	return 0;
}