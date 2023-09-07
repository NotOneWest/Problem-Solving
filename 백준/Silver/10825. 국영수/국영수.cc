#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <utility>
using namespace std;

bool compare(pair< pair<int, int>, pair<int, string> >& a, pair< pair<int, int>, pair<int, string> >& b){
	
	
	if(a.first.first == b.first.first){
		if(a.first.second == b.first.second){
			if(a.second.first == b.second.first){
				return a.second.second > b.second.second;
			}
			return a.second.first < b.second.first;
		}
		return a.first.second > b.first.second;
	}
	return a.first.first < b.first.first;
}


int main(){
	int n;
	scanf("%d", &n);
	vector< pair< pair<int, int>, pair<int, string> > > v;
	
	for(int i=0; i<n; i++){
		string a; cin >> a;
		int b,c,d;
		scanf("%d %d %d", &b, &c, &d);
		v.push_back(make_pair( make_pair(b, c), make_pair(d, a.c_str()) ));
	}
	
	sort(v.begin(), v.end(), compare);
	for(int i=0; i<n; i++) printf("%s\n", v[n-i-1].second.second.c_str());
	return 0;
}