#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

bool compare(string a, string b){
	if(a.size() == b.size()){
		int asum=0, bsum=0;
		for(int i=0; i<a.size(); i++){
			if(a[i] < 58 && a[i] > 47) asum += a[i]-48;
			if(b[i] < 58 && b[i] > 47) bsum += b[i]-48;
		}
		if(asum != bsum) return asum < bsum;
		else return a < b;
	}
	else return a.size() < b.size();
}

int main(){
	int n; cin>>n;
	vector<string> v;
	
	for(int i=0; i<n; i++){
		string a; cin>>a;
		v.push_back(a);
	} 
	
	sort(v.begin(), v.end(), compare);
	
	for(int i=0; i<n; i++) printf("%s\n", v[i].c_str());
	return 0;
}