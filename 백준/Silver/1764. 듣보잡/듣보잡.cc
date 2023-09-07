#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	vector<string> vn, vresult;
	
	for(int i=0; i<n; i++){
        string a; cin>>a;
        vn.push_back(a);
    }
	sort(vn.begin(), vn.end());
	
	for(int i=0; i<m; i++){
		string a; cin>>a;
		if(binary_search(vn.begin(), vn.end(), a)) vresult.push_back(a);
	}
	
	sort(vresult.begin(), vresult.end());
	
	int len = vresult.size();
	printf("%d\n", len);
	for(int i=0; i<len; i++) printf("%s\n", vresult[i].c_str()); 
	
	return 0;
}